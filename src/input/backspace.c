#include "../../includes/ft_select.h"

/*
** advances to the current element,
** and resets the current element to the next one in
** the list
*/

static t_params         *reset_current(t_shell *shell)
{
    t_params *tmp;

    tmp = shell->list;
    while (tmp->current == FALSE && tmp)
        tmp = tmp->next;
    // set the next item to the current one
    if (tmp->next)
        tmp->next->current = TRUE;
    else
        shell->list->current = TRUE;
    tmp->current = FALSE;
    return (tmp);
}

/*
** properly deletes an element
** from the list
** and frees its space
*/

static void             del_elem(t_params *del)
{
    ft_strfree(del->filename);
    free(del);
}

/*
** removes an item from the list
*/

void                    remove_elem(t_shell *shell)
{
    t_params *tmp;
    t_params *del;

    tmp = reset_current(shell);
    del = tmp;
    // if there is an element before the one we're at then 
    // point its next pointer to the next item
    if (tmp->prev && tmp->next)
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    else if (!tmp->prev)
    {
        shell->list = shell->list->next;
        shell->list->prev = NULL;
    }
    else if (!tmp->next)
        tmp->prev->next = NULL;
    del_elem(del);
    // delete item here
}
