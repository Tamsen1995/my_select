#include "../../includes/ft_select.h"

/*
** allocatesa param element and returns it
*/

t_params		*ft_add_param(char *filename)
{
	t_params	*param;
	
    param = NULL;
	if (!(param = (t_params *)malloc(sizeof(t_params))))
		return (NULL);
	param->filename = ft_strdup(filename);
    param->next = NULL;
    param->select = FALSE;
    param->current = FALSE;
	return (param);
}

/*
** pushes a param to the back of the list
*/

void            ft_push_back_param(t_params **begin_list, char *filename)
{
    t_params *tmp;
    t_params *new;

    tmp = NULL;
    new = NULL;
	new = ft_add_param(filename);
	if (!*begin_list)
	{
		*begin_list = new;
		return ;
	}
    tmp = *begin_list;    
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = new;
    tmp->next->prev = tmp;
}

/*
** receives list of arguments
** and then allocates them into a list
*/

t_params        *init_params(char **av)
{
    t_params *param_list;

    int i;

    i = 0;
    param_list = NULL;
    while (av[i])
    {
        ft_push_back_param(&param_list, av[i]);
        i++;
    }
    return (param_list);
}
