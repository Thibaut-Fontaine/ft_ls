#include "../includes/ls.h"

void      get_name(struct dirent *st_dir, t_all *all)
{
  all->name = st_dir->d_name;
}
