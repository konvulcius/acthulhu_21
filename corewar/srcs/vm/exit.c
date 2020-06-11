#include "ft_corewar.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <errno.h>

void	vm_exit_success(t_vm *vm)
{
	vm_free(vm);
	exit(EXIT_SUCCESS);
}

void	vm_exit_failure(t_vm *vm)
{
	vm_free(vm);
	exit(EXIT_FAILURE);
}

void	vm_exit_malloc_failure(t_vm *vm)
{
	perror("Malloc:");
	vm_free(vm);
	exit(EXIT_FAILURE);
}

void	vm_exit_sys_failure(t_vm *vm, char *string)
{
	if (errno != 0)
		perror("Error");
	else
		ft_putstr_fd(string, 2);
	vm_free(vm);
	exit(EXIT_FAILURE);
}

void	usage_exit(t_vm *vm)
{
	ft_printf("%{green}Usage:%{eoc}\t%{yellow}./corewar %{eoc}[-n N] ");
	ft_printf("%{yellow}<champion1.cor>%{eoc} [-n N] ");
	ft_printf("%{yellow}<...>%{eoc} [-a -d N -s N -i N -v]\n");
	ft_printf("\t%{yellow}-a  \t: Prints output from \"aff\"%{eoc}\n");
	ft_printf("%{green}#### TEXT OUTPUT MODE ###################%{eoc}");
	ft_printf("%{green}#####################################%{eoc}\n");
	ft_printf("\t%{yellow}-dump N : Dumps memory after N cycles then%{eoc} ");
	ft_printf("%{yellow}exits%{eoc}\n");
	ft_printf("\t%{yellow}-d N\t: Same as -dump but 64 per line%{eoc}\n");
	ft_printf("\t%{yellow}-s N\t: Dumps memory each N cycles%{eoc}\n");
	ft_printf("\t%{yellow}-v N\t: Verbosity levels, can be added%{eoc} ");
	ft_printf("%{yellow}together to enable several%{eoc}\n");
	ft_printf("\t\t%{yellow}- 1 : Show cycles%{eoc}\n");
	ft_printf("\t\t%{yellow}- 2 : Show operations (Params are NOT%{eoc} ");
	ft_printf("%{yellow}litteral ...)%{eoc}\n");
	ft_printf("\t\t%{yellow}- 4 : Show deaths%{eoc}\n");
	ft_printf("\t\t%{yellow}- 8 : lld of size 4%{eoc} ");
	ft_printf("%{yellow}(std corewar bug fix)%{eoc}\n");
	ft_printf("%{green}#### VISUAL MODE ############################%{eoc}");
	ft_printf("%{green}#################################%{eoc}\n");
	ft_printf("\t%{yellow}-q%{eoc}\n");
	vm_exit_success(vm);
}
