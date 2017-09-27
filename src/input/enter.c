#include "../../includes/ft_select.h"

void print_selected(t_shell *shell)
{
    t_params *tmp;

    tmp = shell->list;
    while (tmp)
    {
        if (tmp->select == TRUE)
        {
            ft_putstr(tmp->og_name);
            ft_putstr(" ");
        }
        tmp = tmp->next;
    }
  //  exit_handler();
}