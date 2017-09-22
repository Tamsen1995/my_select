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

void            cursor_down(t_shell *shell)
{
    int wrd_p_line;
    
    wrd_p_line = 0;
    if (!shell)
        fatal("Error (cursor_down)");
    wrd_p_line = words_per_line(shell);

    ft_putnbr(wrd_p_line); // TESTING
    ft_putendl("");

}