#include "../includes/libft.h"

/*
** copies a twod array and allocates 
** a new one to return
*/

char            **copy_twod_arr(char **arr)
{
    char    **copied;
    int     amt_needed;
    int     i;

    amt_needed = 0;
    i = 0;
    copied = NULL;
    while (arr[amt_needed])
        amt_needed++;
    copied = ft_alloc_twod_arr(amt_needed);
    while (arr[i] && i <= amt_needed)
    {
        copied[i] = arr[i];
        i++;
    }
    return (copied);
}

