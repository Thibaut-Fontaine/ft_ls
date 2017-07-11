/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/28 14:30:41 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"
#include "stdio.h"

static char      *get_entry_path(const char *path, struct dirent *st_dir)
{
  char *entry_path;

  entry_path = ft_strjoin(path, "/");
  return (ft_strjoin(entry_path, st_dir->d_name));
}

static void 			fill_all(const char *path, t_all *all)
{
  char            *entry_path;
  if (!(all->st_stat = ft_memalloc(sizeof(all->st_stat))))
    exit(0);
  entry_path = get_entry_path(path, all->st_dir);
  //printf("%s ", entry_path);
  stat(entry_path, all->st_stat);
  //ft_putchar(' ');
  //printf("%ju\n", (uintmax_t)all->st_stat->st_ino);
}

static void	  		ft_ls(const char *path, t_all *all)
{
  DIR			        *dir;
  
  if (!path)
    path = ".";
  dir = opendir(path);
  if (dir)
  {
    ft_putstr(path);
    ft_putendl(":");
    while ((all->st_dir = readdir(dir)))
      fill_all(path, all); 
    closedir(dir);
  }
}
