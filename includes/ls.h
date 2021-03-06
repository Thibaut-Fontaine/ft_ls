/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 02:44:04 by tfontain          #+#    #+#             */
/*   Updated: 2017/08/04 07:03:01 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "../libft/includes/libft.h"
# include "dirent.h"
# include <sys/stat.h>
# include <stdio.h>

/*
** flags
*/

# define ALL_		(1 << 0)
# define LST_		(1 << 1)
# define REC_		(1 << 2)
# define REV_		(1 << 3)
# define TIM_		(1 << 4)

# define PATH_		(1 << 6)
# define TILD_		(1 << 7)

typedef struct		s_elem
{
	const char		*path;
	struct s_elem	*nxt;
}					t_elem;

typedef struct
{
	int				flag;
	const char		**path;
	int				n_path;
}					t_all;

void				error_flag(const char option);
void				error_path(const char *filename);
void				exit_perror(const char *filename);
t_all				parse(int argc, const char *argv[]);

#endif
