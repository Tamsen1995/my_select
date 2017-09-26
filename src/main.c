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
** Checks the params for
** to see if there are still any
** if no then it will call an exit 
** to the program
*/

void            check_params(t_shell *shell)
{
    t_params *tmp;
    int i;

    tmp = shell->list;
    i = 0;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    if (i == 0)
        exit_handler();
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
    shell->list = add_brackets(params);
    shell->list->current = TRUE;
    while (1)
    {
        tputs(tgetstr("cl", NULL), 1, putintc); // TESTING
        handle_input(shell, buf); // TESTING
       // check_params(shell); // 
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
