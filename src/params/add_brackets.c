#include "../../includes/ft_select.h"

/*
** receives an int and returns
** a string of spaces with the amount
** requested
*/

char            *make_space_str(int amt)
{
    char        *spaces;
    int         i;

    i = 0;
    spaces = NULL;
    if (!amt)
        fatal("Error (make_space_str)");
    spaces = ft_strnew(amt);
    while (i < amt)
    {
        spaces[i] = ' ';
        i++;
    }
    spaces[i] = '\0';
    return (spaces);
}

/*
** makes a param string with brackets around it
** and padded with spaces
** all padding corresponds to the longest_len
** string
*/

char    *bracks_to_elem(t_params *tmp, int longest_len)
{
    char        *spaces;
    char        *brack_fl_name;
    int         spaces_needed;

    spaces = NULL;
    brack_fl_name = NULL;
    spaces_needed = 0;
    spaces_needed = longest_len - 2 - ft_strlen(tmp->filename);
    brack_fl_name = ft_strnew(longest_len);
    brack_fl_name = ft_strcat(brack_fl_name, "[");
    brack_fl_name = ft_strcat(brack_fl_name, tmp->filename);
    spaces = make_space_str(spaces_needed);
    brack_fl_name = ft_strcat(brack_fl_name, spaces);
    brack_fl_name = ft_strcat(brack_fl_name, "]");
    free(spaces);
    return (brack_fl_name);
}

/*
** makes all the strings uniform by
** padding every string to the len of the longest one
** delimiting with brackets
*/

t_params        *make_brackets_list(t_params *params, int longest_len)
{
    t_params    *tmp;
    t_params    *ret;
    char        *brack_fl_name;

    ret = NULL;
    brack_fl_name = NULL;
    if (!params || !longest_len)
        fatal("Error (make_brackets_list)");
    tmp = params;
    longest_len += 3;
    while (tmp)
    {
        brack_fl_name = bracks_to_elem(tmp, longest_len);
        ft_push_back_param(&ret, brack_fl_name);
        free(brack_fl_name);
        tmp = tmp->next;
    }
    return (ret);
}

/*
** figures out the longest string
** and makes all the params uniform by adding
** brackets to the params list
** frees the old list to make a new one
*/

t_params        *add_brackets(t_params *params)
{
    t_params    *tmp;
    t_params    *ret;
    int         longest_len;

    tmp = NULL;
    ret = NULL;


  //  print_params(params);

    longest_len = 0;
    if (!params)
        fatal("Error in (add_brackets)");
    tmp = params;
    if (tmp && tmp->next)
        tmp = tmp->next;
    longest_len = find_max_str(tmp);
    ret = make_brackets_list(tmp, longest_len);



    // out of the from tmp to pointed list figure out
        // the len of the lognest string


    // TODO free params
    return (ret); // TESTING
}
