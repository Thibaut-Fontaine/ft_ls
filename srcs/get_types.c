#include "../includes/ls.h"

void			get_type(struct dirent *st_dir, t_all *all)
{
	all->type = st_dir->d_type;
}
