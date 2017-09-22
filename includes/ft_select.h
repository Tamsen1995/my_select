#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <termcap.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "../includes/libft.h"
#include "../includes/ft_ls.h"
# define MAX_BUF_SIZE 2048

typedef struct		s_params
{
	struct s_params	*next;
	struct s_params	*prev;
	char			*filename;
	T_BOOL			current; // indicates if the elem is the current elem the cursor is pointing to
	T_BOOL 			select; // indicates if the elem is selected
}					t_params;

typedef struct		s_shell
{
	struct winsize		*sz;
	struct termios		*termold;
	struct termios		*term;
	t_params			*list;

}					t_shell;

/*
** have each file have their own block of declared functions
** in the header
*/

//void            handlers(int sig);
void            catch_signals(void);
int             words_per_line(t_shell *shell);
int             putintc(int c);
void            out_params(t_shell *shell); // TESTING
t_shell			*get_shell(void);
void            handle_input(t_shell *shell, char *buf);
t_params        *add_brackets(t_params *params);
int				find_max_str(t_params *params);
void			update_window_size(t_shell *shell);
void            apply_mode(t_shell *shell);
t_shell         *make_shell(void);
t_params		*ft_add_param(char *filename);
void            ft_push_back_param(t_params **begin_list, char *filename);
t_params        *init_params(char **av);

#endif