#include "asm.h"
#include "ft_printf.h"

void	ft_printf_error(char *line)
{
	ft_printf("%WError in line %d: %s\n", 2, g_current_string, line);
}

void	error_file(int code)
{
	if (code == ERR_NO_AC)
		ft_putendl_fd("Usage: ./asm <champ.s>", 2);
	else if (code == ERR_FILE_NOT_S)
		ft_putendl_fd("Error: champion's file should be with .s extension", 2);
	else if (code == ERR_NO_FILE)
		ft_putendl_fd("Error: champion's file not exists", 2);
	else if (code == ERR_FILE_NOT_CREATED)
		ft_putendl_fd("Error: file .cor can't be created", 2);
	else if (code == ERR_NO_NEW_LINE)
		ft_putendl_fd("Error: champion's file not ends with \\n", 2);
}

void	error_format(int code)
{
	if (code == ERR_UNEXP_SYM)
		ft_printf_error("unexpected symbols");
	else if (code == ERR_UNEXP_EOF)
		ft_printf_error("unexpected EOF");
	else if (code == ERR_DOUBLE_NAME)
		ft_printf_error("champion's name was defined earlier");
	else if (code == ERR_DOUBLE_COMMENT)
		ft_printf_error("champion's comment was defined earlier");
	else if (code == ERR_NAME_LENGTH)
		ft_putendl_fd("Error: champion's name is too long", 2);
	else if (code == ERR_COMMENT_LENGTH)
		ft_putendl_fd("Error: champion's comment is too long", 2);
	else if (code == ERR_NULL_HEADER)
		ft_putendl_fd("Error: there is no name or comment", 2);
	else if (code == ERR_NO_CODE)
		ft_putendl_fd("Error: there is no exec code champion", 2);
}

void	error_asm(int code)
{
	if (code == ERR_LABEL_CHARS)
		ft_printf_error("forbidden symbols are used in label");
	else if (code == ERR_EMPTY_LABEL)
		ft_printf_error("label can't be empty");
}

void	error_exit(int code)
{
	if (code < 10)
		error_file(code);
	else if (code < 20)
		error_format(code);
	else if (code < 30)
		error_asm(code);
	exit(-1);
}
