#include "../includes/libft.h"

/*
** simply takes in an amount of desired arrays
** and allocs a null terminated twod array
*/

char           **ft_alloc_twod_arr(int amt)
{
    char **new;

    new = NULL;
    if (!(new = (char **)malloc(sizeof(char *) * amt + 1)))
        fatal("Error in (ft_alloc_twod_arr)");
    new[amt] = NULL;
    return (new);
}

