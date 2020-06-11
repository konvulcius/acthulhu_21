/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <yaroslavfedorchuk@mail.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:57:40 by acthulhu          #+#    #+#             */
/*   Updated: 2020/06/03 00:13:58 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "libft.h"
#include <fcntl.h>

static int		buff_int_from_chars(int32_t fd)
{
	char	buff[4];
	int32_t	r;
	char	*rr;

	read(fd, buff, 4);
	rr = (char *)&r;
	rr += 3;
	*rr-- = *buff;
	*rr-- = *(buff + 1);
	*rr-- = *(buff + 2);
	*rr = *(buff + 3);
	return (r);
}

static void		champ_error(t_vm *vm, t_champ *champ, int32_t fd, char *string)
{
	ft_putstr_fd(string, 2);
	close(fd);
	free(champ->header);
	free(champ);
	vm_exit_failure(vm);
}

static int		read_the_part(int fd, void *dst, uint32_t size)
{
	uint32_t	count;

	ft_bzero(dst, size + 1);
	count = read(fd, dst, size);
	return (count < size ? 0 : 1);
}

static void		read_champ(t_vm *vm, t_champ *champ, char *filename)
{
	int32_t		fd;
	char		buff[1];

	if ((fd = open(filename, O_RDONLY)) < 0)
		vm_exit_sys_failure(vm, "Error: Can not open file\n");
	if (buff_int_from_chars(fd) != COREWAR_EXEC_MAGIC)
		vm_exit_sys_failure(vm, "Wrong magic\n");
	if (!read_the_part(fd, champ->header->prog_name, PROG_NAME_LENGTH))
		champ_error(vm, champ, fd, "Error: File is too small\n");
	lseek(fd, 4, SEEK_CUR);
	if ((champ->header->prog_size = buff_int_from_chars(fd)) > CHAMP_MAX_SIZE)
		champ_error(vm, champ, fd, "Error: File program code is too long\n");
	if (!read_the_part(fd, champ->header->comment, COMMENT_LENGTH))
		champ_error(vm, champ, fd, "Error: File is too small\n");
	lseek(fd, 4, SEEK_CUR);
	if (!(champ->code = (uint8_t *)malloc(sizeof(uint8_t) * \
		(champ->header->prog_size + 1))))
		vm_exit_malloc_failure(vm);
	if (!read_the_part(fd, champ->code, champ->header->prog_size))
		champ_error(vm, champ, fd, "Error: Wrong file's code\n");
	if (read(fd, buff, 1) > 0)
		champ_error(vm, champ, fd, "Error: champion has a wrong code size\n");
	close(fd);
}

t_champ			*parse_champ(t_vm *vm, char *filename, int id)
{
	t_champ		*champ;

	if (!(champ = (t_champ*)malloc(sizeof(t_champ))) ||
		!(champ->header = (t_header*)malloc(sizeof(t_header))))
		vm_exit_malloc_failure(vm);
	read_champ(vm, champ, filename);
	champ->id = id;
	champ->next = NULL;
	add_champ_to_list(vm, champ);
	return (champ);
}
