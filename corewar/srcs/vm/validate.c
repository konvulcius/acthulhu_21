#include "ft_corewar.h"
#include "libft.h"

t_bool	file_is_champ(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len > 4 && !ft_strcmp(&filename[len - 4], ".cor"))
		return (TRUE);
	return (FALSE);
}

int32_t	ft_only_dig_validation(char *string)
{
	int32_t	count;

	if (!string)
		return (0);
	if (*string == '-' || *string == '+')
		string++;
	count = 0;
	while (*string)
	{
		if (count == 11 || !ft_isdigit(*string))
			return (0);
		++count;
		if (count == 1 && !ft_strncmp(string, "0", 1))
			--count;
		++string;
	}
	if (count == 0 && (*(string - 1) - '0'))
		return (0);
	return (1);
}
