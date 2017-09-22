#include "../../includes/ft_select.h"

/*
** receives one element of the params list
** properly shows the parameter element
*/

void            show_elem(t_params *tmp_param)
{
    if (tmp_param->select)
        tputs(tgetstr("mr", NULL), 1, putintc);          
    if (tmp_param->current)
        tputs(tgetstr("us", NULL), 1, putintc); // underlne mode on
    ft_putstr(tmp_param->filename); // TESTING
    if (tmp_param->current)
        tputs(tgetstr("ue", NULL), 1, putintc); // underline mode off
    if (tmp_param->select)
        tputs(tgetstr("me", NULL), 1, putintc);
}

/*
** outputs the parameters
*/

void            out_params(t_shell *shell)
{
    t_params    *tmp_param;
    int         words;
    int         i;

    tmp_param = shell->list;
    // discern words per line
    // print that amount of words
    // set a newline

    words = words_per_line(shell);
    i = 0;
    while (tmp_param)
    {
        if (i == words)
        {
            i = 0;
            ft_putendl("");
        }

        show_elem(tmp_param);
        ft_putstr(" ");

        tmp_param = tmp_param->next;
        i++;
    }
}