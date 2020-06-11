#include "ft_lemin.h"

t_list		*ft_lstrev(t_list *start)
{
	t_list	*temp;

	if (start && start->next)
	{
		temp = ft_lstrev(start->next);
		start->next->next = start;
		start->next = NULL;
		return (temp);
	}
	else
		return (start);
}

long long	ft_atoll(const char *str)
{
	unsigned long long	value;
	int					minus;

	minus = 1;
	value = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - 48);
		str++;
	}
	if (value > MAX_LL && minus > 0)
		return (-1);
	if (value > MAX_LL + 1ULL && minus < 0)
		return (0);
	return (value * minus);
}

t_list		*ft_list_find(t_list *begin_list, void *data_ref, size_t data_size,
		int (*cmp)())
{
	t_list	*slider;

	if (!begin_list || !data_ref)
		return (NULL);
	slider = begin_list;
	while (slider)
	{
		if (cmp(slider->content, data_ref, data_size) == 0)
			return (slider);
		slider = slider->next;
	}
	return (NULL);
}

int			ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void		ft_delete_content(void *content, size_t size)
{
	if (size)
		free(content);
}
