#include "asm.h"

char			*get_champ_string(t_champion **champ, char *line, int i)
{
	int			len;
	int			start;
	char		*str;

	len = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '"')
		error_exit(ERR_UNEXP_SYM);
	start = ++i;
	while (line[i] != '"')
	{
		if (line[i] == '\0')
			go_to_new_line(champ, &line);
		i++;
		len++;
	}
	check_end_of_line(line, i + 1);
	str = ft_strnew(len);
	str = ft_strncpy(str, &line[start], len);
	ft_strdel(&line);
	return (str);
}

char			*find_name(t_champion **champ, char *line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n' || \
			line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
		return (NULL);
	while (line[i] == NAME_CMD_STRING[j])
	{
		i++;
		j++;
	}
	if (NAME_CMD_STRING[j] == '\0')
		return (get_champ_string(champ, line, i));
	return (NULL);
}

char			*find_comment(t_champion **champ, char *line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n' || \
			line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
		return (NULL);
	while (line[i] == COMMENT_CMD_STRING[j])
	{
		i++;
		j++;
	}
	if (COMMENT_CMD_STRING[j] == '\0')
		return (get_champ_string(champ, line, i));
	return (NULL);
}

int				check_name_line(t_champion **champ, char *line)
{
	char		*tmp_name;
	char		*tmp_comment;

	tmp_name = find_name(champ, line);
	if (tmp_name)
	{
		if ((*champ)->name)
			error_exit(ERR_DOUBLE_NAME);
		(*champ)->name = tmp_name;
		return (1);
	}
	tmp_comment = find_comment(champ, line);
	if (tmp_comment)
	{
		if ((*champ)->comment)
			error_exit(ERR_DOUBLE_COMMENT);
		(*champ)->comment = tmp_comment;
		return (1);
	}
	if (!is_space_line(line))
		error_exit(ERR_UNEXP_SYM);
	ft_strdel(&line);
	return (0);
}

void			get_name_comment(t_champion **champ)
{
	char		*line;
	int			flag_found;

	line = NULL;
	flag_found = 0;
	g_current_string = 0;
	(*champ)->name = NULL;
	(*champ)->comment = NULL;
	while (flag_found < 2 && gnl_spec((*champ)->fd, &line) > 0)
	{
		g_current_string++;
		flag_found += check_name_line(champ, line);
	}
	if ((*champ)->name && ft_strlen((*champ)->name) > PROG_NAME_LENGTH)
		error_exit(ERR_NAME_LENGTH);
	if ((*champ)->comment && ft_strlen((*champ)->comment) > COMMENT_LENGTH)
		error_exit(ERR_COMMENT_LENGTH);
}
