/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 04:59:19 by tfontain          #+#    #+#             */
/*   Updated: 2017/08/04 09:11:16 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static inline char			*add_slash(const char *path, const char *name)
{
	char					*tmp;
	int						n;
	size_t					size;

	if (path == NULL || name == NULL)
		exit(-1);
	size = ft_strlen(path) + ft_strlen(name) + 1 + 1;
	if ((tmp = malloc(size)) == NULL)
		exit_perror(NULL);
	n = 0;
	while (*path)
	{
		tmp[n++] = *path;
		++path;
	}
	tmp[n++] = '/';
	while (*name)
	{
		tmp[n++] = *name;
		++name;
	}
	tmp[size - 1] = '\0';
	return (tmp);
}

static inline t_elem		*generate_link(void)
{
	t_elem					*list;

	list = malloc(sizeof(t_elem));
	ft_bzero(list, sizeof(t_elem));
	return (list);
}

t_elem						*get_elemlist(const char *path) // path doit etre simplifie (ne doit pas terminer par '/')
{
	DIR						*dir;
	t_elem					*list;
	t_elem					*head;
	struct dirent			*st_dir;

	(dir = opendir(path)) == NULL ? exit_perror(path) : 0;
	(head = generate_link()) == NULL ? exit_perror(NULL) : 0;
	list = head;
	(st_dir = readdir(dir)) == NULL ? exit_perror(NULL) : 0;
	list->path = add_slash(path, st_dir->d_name);
	while ((st_dir = readdir(dir)))
	{
		(list->nxt = generate_link()) == NULL ? exit_perror(NULL) : 0;
		list->nxt->path = add_slash(path, st_dir->d_name);
		list = list->nxt;
	}
	closedir(dir);
	return (head);
}

static inline const char	*simplify_path(const char *path)
{
	size_t					tmp;

	tmp = ft_strlen(path) - 1;
	if (path[tmp] != '/')
		return (path);
	while (path[tmp] == '/')
		--tmp;
	((char*)path)[tmp + 1] = '\0';
	return (path);
}

/*#include <stdio.h> // test
int main(int argc, const char *argv[])
{
	if (argc != 2)
		return (0);
	t_elem *head = get_elemlist(simplify_path(argv[1]));
	t_elem *curr = head;

	while (curr)
	{
		puts(curr->path);
		curr = curr->nxt;
	}
	return 0;
}*/
