int		ft_is_flag(char *s)
{
	if (*s == '-' || *s == '0' || *s == '+' || *s == ' ' || *s == '#')
		return (1);
	return (0);
}
