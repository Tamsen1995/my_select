#include "../includes/ft_select.h"


/*
** Moves the cursor in the programm shell
** to the right
*/

void            cursor_right(t_shell *shell)
{


    ft_putnbr(shell->sz->ws_row);
    ft_putendl("");
    ft_putnbr(shell->sz->ws_col); //  columns
    ft_putendl("");
}

/*
** ** if an arrow key is recognized
** the flow is directed into here
*/

static void     arrow_keys(t_shell *shell, char *buf)
{
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0)
        ft_putendl("UP"); // TESTING
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0)
        ft_putendl("DOWN"); // TESTING
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
        ft_putendl("LEFT"); // TESTING
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
        cursor_right(shell); // TESTING
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
        ft_putendl("SPACE"); // TESTING

}
