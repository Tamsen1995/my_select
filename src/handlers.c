#include "../includes/ft_select.h"

/*
** handles the signal case 
** where the window size changes
*/

void            win_handler(void)
{
    t_shell *shell;

    shell = get_shell();
    update_window_size(shell);
    tputs(tgetstr("cl", NULL), 1, putintc); // TESTING
    out_params(shell);
}


/*
** receives a signal number inside
** the signal function
** and redirects it to its corresponding
** handler
*/

void            handlers(int sig)
{
    if (sig == SIGWINCH)
        win_handler();


}
