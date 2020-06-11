int		ft_is_length(char *s)
{
	if (*s == 'h' || *s == 'l' || *s == 'L')
		return (1);
	return (0);
}
