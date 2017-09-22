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



void            sel_mode_off(t_shell *shell)
{
	tcsetattr(0, TCSADRAIN, shell->termold);
	tputs(tgetstr("te", NULL), 1, putintc);
	tputs(tgetstr("ve", NULL), 1, putintc);
}

void            exit_handler()
{
    t_shell *shell;

    shell = get_shell();
    sel_mode_off(shell);
    exit(0);

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