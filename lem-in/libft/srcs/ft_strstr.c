#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	size;
	size_t	n_size;
	size_t	i;

	if (*haystack)
	{
		i = 0;
		size = ft_strlen(haystack);
		n_size = ft_strlen(needle);
		if (!n_size)
			return ((char *)haystack);
		if (n_size > size)
			return (NULL);
		while (haystack[i] && (i + n_size) <= (size + n_size))
		{
			if (haystack[i] == *needle)
				if (!ft_strncmp(&haystack[i], needle, n_size))
					return ((char *)&haystack[i]);
			i++;
		}
	}
	return (haystack == needle ? (char *)needle : NULL);
}
