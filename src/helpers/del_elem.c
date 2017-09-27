#include "../../includes/ft_select.h"

/*
** properly deletes an element
** from the list
** and frees its space
*/

void             del_elem(t_params *del)
{
    ft_strfree(del->filename);
    free(del);
    del = NULL;
}