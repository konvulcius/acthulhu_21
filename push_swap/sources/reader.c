#include "push_swap.h"

static void	split_string(t_list **start, char *string)
{
	char		**splited_arg;
	int			i;
	long long	value;

	if (!(splited_arg = ft_strsplit(string, ' ')))
		allocation_error();
	i = 0;
	while (splited_arg[i])
	{
		if (!only_dig_validation(splited_arg[i]))
		{
			while (splited_arg[i])
				i++;
			ft_delete_two_dimensional(&splited_arg, i);
			the_error();
		}
		value = ft_atoll(splited_arg[i++]);
		ft_lstadd(start, ft_lstnew(&value, sizeof(long long)));
	}
	ft_delete_two_dimensional(&splited_arg, i);
}

t_list		*arguments_reader(int last, char **argv)
{
	int			num;
	t_list		*start;

	num = 0;
	start = NULL;
	while (num < last)
		split_string(&start, argv[num++]);
	if (!start)
		stop();
	if (!ft_lstiter_int(start, check_same))
	{
		ft_lstdel(&start, content_del);
		the_error();
	}
	return (ft_lstrev(start));
}

t_list		*instructions_reader(int fd)
{
	t_list	*start;
	char	*instruction;

	start = NULL;
	while (get_next_line(fd, &instruction))
	{
		ft_lstadd(&start, ft_lstnew(instruction, ft_strlen(instruction) + 1));
		ft_strdel(&instruction);
		instructions_validation(start);
	}
	return (ft_lstrev(start));
}
