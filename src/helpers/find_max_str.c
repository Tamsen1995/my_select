#include "../../includes/ft_select.h"

/*
** takes in a list of parameters
** and returns the length of the longest one
*/

int     find_max_str(t_params *params)
{
    int         ret;
    t_params    *tmp_list;
    int         len;

    ret = 0;
    tmp_list = params;
    len = 0;
    while (tmp_list)
    {
        len = ft_strlen(tmp_list->filename);
        if (ret <= len)
            ret = len;
        tmp_list = tmp_list->next;
    }
    return (ret);
}