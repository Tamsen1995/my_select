#include "../../includes/ft_select.h"

/*
** receives one element of the params list
** properly shows the parameter element
*/

void            show_elem(t_params *tmp_param)
{
    // tputs(tgetstr("us", NULL), 1, putintc); // TESTING
        // TODO make the cursor move properly and then only fire this line
            // if the current element is the selected one.
    // tputs(tgetstr("us", NULL), 1, putintc); // TESTING
    ft_putstr(tmp_param->filename); // TESTING
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