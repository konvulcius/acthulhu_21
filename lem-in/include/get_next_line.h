/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:30:43 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/24 22:38:01 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2048

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
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
