#include "ft_corewar.h"
#include "ft_printf.h"
#include "libft.h"

size_t	get_champs_num(int ac, char **av)
{
	size_t	num;
	size_t	i;

	i = 1;
	num = 0;
	while (i < (size_t)ac)
	{
		if (file_is_champ(av[i]))
			num += 1;
		++i;
	}
	return (num);
}

void	place_champ(t_vm *vm, t_sp *sp, size_t i)
{
	sp->pc = (MEM_SIZE / vm->champs_num) * i;
	ft_memcpy(&vm->arena[sp->pc],
			sp->champ->code,
			sp->champ->header->prog_size);
}

void	introduce_champ(t_vm *vm, t_sp *sp, size_t i)
{
	char	*name;
	char	*comment;
	int32_t	id;

	name = sp->champ->header->prog_name;
	comment = sp->champ->header->comment;
	i = sp->champ->header->prog_size;
	id = sp->champ->id;
	(void)vm;
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",\
		id, i, name, comment);
}
