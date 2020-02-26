#include "libft.h"

void	ft_delete_two_dimensional(char ***array, size_t length)
{
	size_t		index;

	if (*array)
	{
		index = 0;
		if ((*array)[index])
		{
			while ((*array)[index] && index < length)
			{
				free((*array)[index]);
				(*array)[index++] = NULL;
			}
		}
		free(*array);
		*array = NULL;
	}
}
