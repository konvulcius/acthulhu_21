#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	if (!(area = malloc(size)))
		return (NULL);
	ft_bzero(area, size);
	return (area);
}
