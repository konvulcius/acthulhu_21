#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, size_t data_size,
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
