/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:37:45 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/16 12:48:06 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2048

# include "libft.h"
# include <unistd.h>
# include <sys/uio.h>

typedef struct		s_box
{
	int				fd;
	char			*content;
	struct s_box	*next;
	struct s_box	*prev;
}					t_box;

int					get_next_line(const int fd, char **line);

#endif
