#ifndef DIS_ASM_H
# define DIS_ASM_H

# include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef struct		s_type
{
	char			*name;
	int				count_args;
	char			bit_args[3];
	int				number;
}					t_type;

typedef struct		s_instr
{
	struct s_type	*type;
	char			args[3];
	char			*string;
}					t_instr;

typedef struct		s_struct
{
	char			*name;
	char			*file_name;
	char			*comment;
	int				fd_creat_file;
}					t_struct;

extern t_type		g_type_tab[17];

void				ft_opening(char *str, t_struct *data);
char				*invert(char *str, int i);
char				*ft_strjoin_sp(char **str, char *buf, size_t len);
void				ft_arg_one_dir(int fd, t_instr *data);
void				ft_check_args(t_instr *data, int fd);
void				ft_args_type(char *str, t_instr *data);
void				ft_creat_file(t_struct *data);
char				*ft_quotes(char *str);
void				ft_init(t_instr *data);
void				free_string(t_instr *data);

#endif
