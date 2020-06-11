#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

char		*ft_ldbl_one_buff_to_rule_them_all\
	(t_data *data, char *buff_int, char *buff_fraction)
{
	int		len_int;
	int		len_f;
	int		len_total;
	char	*buff;

	len_f = ft_strlen(buff_fraction);
	len_int = ft_strlen(buff_int);
	buff = NULL;
	if (!len_int && len_f)
		len_int = 1;
	len_total = len_int + (len_f ? len_f + 1 : 0);
	if (len_total)
	{
		if (!(buff = (char *)malloc(sizeof(char) * len_total + 1)))
			return (NULL);
		buff[len_total] = '\0';
		if (!buff_int && len_total)
			*buff = '0';
		else
			ft_strcpy_reverse(buff, buff_int);
		if (len_f || (data->flags & PRECISION_IS_THERE && data->flags & HASH))
			*(buff + len_int) = '.';
		ft_strcpy((buff + len_int + 1), buff_fraction);
	}
	return (buff);
}
