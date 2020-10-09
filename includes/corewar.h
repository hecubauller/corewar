#ifndef VM_H
# define VM_H

# include "../libft/includes/libft.h"
# include <inttypes.h>
# include <errno.h>
# include "op.h"
# include <ncurses.h>
# include <curses.h>
# include <stdio.h> //vi
# include <unistd.h> //vi

# define MODA(x)         (x % MEM_SIZE < 0 ? x % MEM_SIZE + MEM_SIZE : x % MEM_SIZE)
# define MODX(x)         (x % IDX_MOD)

# define OPC_LEN        (1)
# define ABC_LEN        (1)
# define BYT_LEN        (1)

# define EXT            ".cor"
# define ON             (1)
# define OFF            (0)

/*
** Flags
*/

# define DUMP_32        FT_BIT(0)
# define DUMP_64        FT_BIT(1)
# define NUM            FT_BIT(2)
# define VIS            FT_BIT(3)
# define AFF            FT_BIT(4)

/*
** Error code
*/

# define USAGE          (-1)
# define ERRABC         (1)
# define ERRARG         (2)

int id_cursors;

/*
** struct arena
*/


/*
 * Visualizer
 */

# define PLAYERS_NAMES "PAUSE"
# define ARENA      1
# define BAR   2



typedef struct      s_op
{
    char            *name;
    int             args_num;
    int             args_type[3];
    int             code;
    int             cycles;
    char            *description;
    int             args_type_code;
    int             carry;
    int             t_dir_size;
}                   t_op;

typedef struct      s_cursor
{
    int             id;
    int             carry;
    int             op_code;
    int             last_live;
    int             cycles_to_exec;
    int             pc;
    int             step;
    int             reg[REG_NUMBER];
    int             args_type[3];
    t_op            *op;
    struct s_cursor *next;
}                   t_cursor;

typedef struct      s_player
{
    char            name[PROG_NAME_LENGTH + 1];
    char            comment[COMMENT_LENGTH + 1];
    uint8_t         instr[CHAMP_MAX_SIZE];
    int             isntr_size;
    int             id;
    int             location;
    struct s_player *next;
}                   t_player;

typedef struct      s_vm
{
    uint8_t         arena[MEM_SIZE];
    t_player        *players[MAX_PLAYERS];
    t_cursor        *cursor;
    t_player        *last_alive;
    int             players_num;
    int             cursors_num;
    int             flags;
    int             dump;
    int             id;
    int             total_cycles;
    int             nbr_live;
    int             nbr_checks;
    int             cycles_to_die;
    int             cycles_to_check;
    t_op            op_tab[17];

}                   t_vm;

/*
** Initialization functions
*/

void        init_vm(t_vm *vm);
void        set_op_tab(t_vm *vm);
t_player    *creat_champion(int id);
void        init_arena(t_vm *vm);
void        init_cursor(t_vm *vm);
t_cursor    *push_top_cursor(t_vm *vm);
void        copy_cursor(t_cursor *dst, t_cursor *src);

/*
** Parse functions
*/

void        parse_champion(t_vm *vm, char *file, int id);
void        parse_args_byte_code(t_vm *vm, t_cursor *cursor);
void        add_champion(t_vm *vm, t_player *player);
void        ft_parse_args(t_vm *vm, char **argv);
void        parse_dump(t_vm *vm, char ***av);
void        parse_aff(t_vm *vm, char ***av);
int         parse_id_champ(t_vm *vm, char *av);
int         is_extension(char *av, char *ext);
void        update_champion_id(t_vm *vm);
int         is_number(char *str);
// int         bytecode_to_int(uint8_t *buffer, int size);

/*
** Playing corewar
*/

void        play_corewar(t_vm *vm);
int         get_operation(t_vm *vm, t_cursor *cursor);
int8_t      get_byte(t_vm *vm, int index);
int         get_step(t_op *operation, int type_arg);
int         get_all_steps(t_cursor *cursor);
void        move_cursor(t_cursor *cursor);
int         validate_instr(t_vm *vm, t_cursor *cursor);
int         get_arg_instr(t_vm *vm, t_cursor *cursor, int t_arg, int idx_mod);
int         is_register(int reg_id);
void        set_int_by_addres(t_vm *vm, int addres, int value, int size);
int         bytecode_arg_to_int(t_vm *vm, int pc, int size);
void        check_ctd_and_cursor(t_vm *vm);

/*
** Instruction
*/

void        ft_live(t_vm *vm, t_cursor *cursor);
void        ft_ld(t_vm *vm, t_cursor *cursor);
void        ft_st(t_vm *vm, t_cursor *cursor);
void        ft_add(t_vm *vm, t_cursor *cursor);
void        ft_sub(t_vm *vm, t_cursor *cursor);
void        ft_and(t_vm *vm, t_cursor *cursor);
void        ft_or(t_vm *vm, t_cursor *cursor);
void        ft_xor(t_vm *vm, t_cursor *cursor);
void        ft_zjmp(t_vm *vm, t_cursor *cursor);
void        ft_ldi(t_vm *vm, t_cursor *cursor);
void        ft_sti(t_vm *vm, t_cursor *cursor);
void        ft_fork(t_vm *vm, t_cursor *cursor);
void        ft_lld(t_vm *vm, t_cursor *cursor);
void        ft_lldi(t_vm *vm, t_cursor *cursor);
void        ft_lfork(t_vm *vm, t_cursor *cursor);
void        ft_aff(t_vm *vm, t_cursor *cursor);

/*
** Error processing & print functions
*/

void        print_usage();
void        intro_player(t_vm *vm);
void        print_arena(t_vm *vm);
void        print_winner(t_vm *vm);
void        ft_free(t_vm *vm);
void		ft_exit(t_vm *vm, int code);

/*
 * Visualizer
 */

void viz_main(t_vm *vm);


#endif