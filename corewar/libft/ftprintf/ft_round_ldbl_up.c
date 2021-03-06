#include "ft_printf.h"
#include "libft.h"

void	ft_round_ldbl_up(char *buff_int, char *buff_fraction)
{
	int	len;
	int sum;

	sum = 1;
	len = ft_strlen(buff_fraction);
	while (len > 0)
	{
		len--;
		sum += *(buff_fraction + len) - '0';
		*(buff_fraction + len) = (sum % 10) + '0';
		if (sum < 10)
			break ;
		sum /= 10;
	}
	if ((len == 0) && (*buff_fraction == '0' || !(*buff_fraction)))
		ft_add_figure_to_buff(buff_int, 1);
}
