#ifndef VM_STRUCTS_H
# define VM_STRUCTS_H

/*
**  flags
*/
# define USAGE		1
# define NCURSES	2
# define DUMP_GO	4
# define AFF		8
# define DUMP_64	16

/*
**  instructions
*/
# define CYCLES		1
# define OPERATIONS	2
# define DEATHS		4
# define LLD4		8

# define NO_CHANGE	8192
# define CLAIM_WINNER "Player %d (%s) won\n"

typedef struct s_sp		t_sp;
typedef struct s_vm		t_vm;
typedef	struct s_champ	t_champ;

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_op
{
	char			*name;
	int				p_qnty;
	int				params[3];
	uint8_t			op_code;
	int				cycles_to_exec;
	char			*hr_name;
	int				t_dir_size;
	t_bool			args_code;
	void			(*f)(t_vm *vm, t_sp *sp);
}					t_op;

extern t_op			g_op_tab[17];

struct				s_champ
{
	uint8_t			id;
	t_header		*header;
	uint8_t			*code;
	t_champ			*next;
};

struct				s_sp
{
	size_t			stepfather_id;
	size_t			identifier;
	t_champ			*champ;
	int32_t			reg[REG_NUMBER + 1];
	int				op_code;
	int				last_change;
	uint8_t			op_arg_types[3];
	int				cycle_claimed_alive;
	int				cycles_to_exec_op;
	t_bool			carry;
	int				pc;
	struct s_sp		*next;
};

struct				s_vm
{
	uint8_t			*arena;
	uint8_t			last_hero;
	t_sp			*sp_list;
	int				live_checks_num;
	int32_t			champs_num;
	int32_t			new_sp_num;
	int32_t			cycle_to_die;
	int32_t			prev_cycle_to_die;
	int32_t			curr_cycle;
	int32_t			cycle_total;
	int32_t			claimed_alive_total;
	int32_t			cycle_to_dump;
	int32_t			rise_dump;
	int				flags;
	int				instructions;
	t_champ			*champ_list;
};

#endif
