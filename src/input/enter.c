#include "../../includes/ft_select.h"

void print_selected(t_shell *shell)
{
    t_params *tmp;

    tmp = shell->list;

	tcsetattr(0, TCSADRAIN, shell->termold);
	tputs(tgetstr("te", NULL), 1, putintc);
	tputs(tgetstr("ve", NULL), 1, putintc);
    tputs(tgetstr("cl", NULL), 1, putintc);
    while (tmp)
    {
        if (tmp->select == TRUE)
        {
            ft_putstr(tmp->og_name);
            ft_putstr(" ");
        }
        tmp = tmp->next;
    }
    free_shell(shell); // TESTING
    exit (0); // TESTING
  //  exit_handler();
}