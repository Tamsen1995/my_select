#include "../../includes/ft_select.h"

/*
** Moves the cursor in the programm shell
** to the right
*/

void            cursor_right(t_shell *shell)
{
    t_params *tmp;

    tmp = NULL;
    if (!shell || !shell->list)
        fatal("ERROR (cursor_right)");
    tmp = shell->list;
    while (tmp->current == FALSE && tmp)
        tmp = tmp->next;
    if (tmp->next)
        tmp->next->current = TRUE;
    tmp->current = FALSE;
    if (!tmp->next)
    {
        tmp->current = FALSE;
        shell->list->current = TRUE;
    }
}

/*
** Moves the cursor in the programm shell
** to the left
*/

void            cursor_left(t_shell *shell)
{
    t_params *tmp;

    tmp = NULL;
    if (!shell || !shell->list)
        fatal("ERROR (cursor_right)");
    tmp = shell->list;
    while (tmp->current == FALSE && tmp)
        tmp = tmp->next;
    if (tmp->prev)
        tmp->prev->current = TRUE;
    tmp->current = FALSE;
    if (!tmp->prev)
    {
        tmp->current = FALSE;
        while (tmp->next)
            tmp = tmp->next;
        tmp->current = TRUE;
    }
}
