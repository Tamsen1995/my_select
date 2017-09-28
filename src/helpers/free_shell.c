#include "../../includes/ft_select.h"

/*
** receives shell and removes everything
** accordingly
*/

void         free_shell(t_shell *shell)
{
    t_params *params; // To free the params with

    params = shell->list;
    while (params && params_present(shell))
    {
        del_elem(params);
        params = params->next;
    }
}
