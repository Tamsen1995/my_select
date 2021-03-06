#include "../includes/ft_select.h"


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

/*
** ** if an arrow key is recognized
** the flow is directed into here
*/

static void     arrow_keys(t_shell *shell, char *buf)
{
    t_shell *tmp;// TESTING

    tmp = NULL;
    if (!shell || !buf)
        fatal("ERROR (arrow_keys)");
    tmp = shell;
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0)
        ft_putendl("UP"); // TESTING
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0)
        ft_putendl("DOWN"); // TESTING
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
        cursor_left(shell);
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
        cursor_right(shell);
}


/*
** looks for the elem the cursor is currently
** pointing to and marks it as selected
*/

void            select_elem(t_shell *shell)
{
    t_params *tmp;

    tmp = NULL;
    if (!shell || !shell->list)
        fatal("ERROR (select_elem)");
    tmp = shell->list;
    while (tmp->current == FALSE && tmp)
        tmp = tmp->next;
    if (tmp->select == TRUE)
        tmp->select = FALSE;
    else if (tmp->select == FALSE)
        tmp->select = TRUE;
    tmp->current = FALSE;
    if (tmp->next)
        tmp->next->current = TRUE;
    else if (!tmp->next)
        shell->list->current = TRUE;
}

/*
** checks the received buffer for its input
** and determines what kind of input it is
*/

void            handle_input(t_shell *shell, char *buf)
{
    if (buf[0] == 27)
        arrow_keys(shell, buf);
    if (buf[0] == 10 )
        ft_putendl("ENTER"); // TESTING
    if (buf[0] == 32)
        select_elem(shell);
}
