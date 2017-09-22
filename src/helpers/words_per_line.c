#include "../../includes/ft_select.h"

/*
** receives shell and figures out how many
** words can be printed in one row
** does this by discerning from the columns 
** and the uniform string length
*/

int             words_per_line(t_shell *shell)
{
    int ret;
    int word_len;
    t_params *tmp_params;
    
    ret = 0;
    tmp_params = NULL;
    if (!shell || !shell->list)
        fatal("Error in (words_per_line)");
    tmp_params = shell->list;
    word_len = ft_strlen(tmp_params->filename);
   // word_len++;

    ret = shell->sz->ws_col / word_len;

    // divide the columns by wor

    // TODO finish this function
    return (ret);
}