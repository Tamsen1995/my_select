#include "../includes/ft_select.h"

/*
** inputs an arbitrary int into
** the stdin
*/

int             putintc(int c)
{
    write(STDIN_FILENO, &c, 1);
    return (0);
}

/*
** Called everytime
**
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

/*
** the core of the program
*/

void            coreloop(t_params *params)
{
    char buf[BUFF_SIZE];
    t_shell *shell;

    shell = NULL;
    shell = get_shell();
    catch_signals();
    while (1)
    {
        tputs(tgetstr("cl", NULL), 1, putintc); // TESTING
        shell->list = add_brackets(params);
        handle_input(shell, buf); // TESTING
        out_params(shell); // TESTING
        read(0, buf, 4);
        update_window_size(shell); // TESTING
    }
    
    // TODO free shell
    // TODO free list
}

/*
** allocates the linked list from the arguments
** and then 
*/

int             main(int ac, char **av)
{
    t_params    *params;
    char        **av_tmp;
    char        *term_name;
    char        buf[MAX_BUF_SIZE];

    if (ac <= 1)
        return (0);
    av_tmp = copy_twod_arr(av);
    params = init_params(av_tmp);
    term_name = ft_secure_getenv("TERM");
    if (tgetent(buf, term_name) == -1)
        fatal("Error with tgetent (main)");
    coreloop(params);
    return (0);
}
