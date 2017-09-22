#include "../includes/libft.h"

/*
** a wrapper around opendir to make it safer
** in case the function fails it safely exits the programs
*/

DIR   *safe_opendir(char *dir_path)
{
    DIR *dir;

    dir = NULL;
    if (!(dir = opendir(dir_path)))
        fatal("Could not open directory in (check_dir_paths)");
    return (dir);
}