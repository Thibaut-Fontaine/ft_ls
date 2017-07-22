#include <../includes/ls.h>

t_file		*generate_link(void)
{
	t_file	*list;

	list = malloc(sizeof(t_file));
	ft_bzero(list, sizeof(t_file));
	return (list);
}

t_file		*get_filelist(const char *path)
{
	DIR		*dir;
	t_file	*list;
	t_file	*head;

	head = generate_link();
	list = head;
	dir = opendir(path);
	while ((list->file = readdir(dir)))
	{
		list->nxt = generate_link();
		list = list->nxt;
	}
	return (head);
}
