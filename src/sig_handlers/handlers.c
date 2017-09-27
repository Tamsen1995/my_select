#include "../../includes/ft_select.h"

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

static void     handlers(int sig)
{
    if (sig == SIGWINCH)
        win_handler();
    if (sig == SIGINT)
        exit_handler();


}

/*
** Called everytime
** the termianl emits a 
** signal into the programs
*/

void            catch_signals(void)
{
    int     i;

    i = 0;
    while (i < 33)
    {
        signal(i, handlers);
        i++;
    }

}