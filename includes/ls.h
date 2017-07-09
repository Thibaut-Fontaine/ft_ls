/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 02:44:04 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/09 05:56:18 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "../libft/includes/libft.h"
# define _
/*
** flags
*/

# define ALL_ (1 << 0)
# define LST_ (1 << 1)
# define REC_ (1 << 2)
# define REV_ (1 << 3)
# define TIM_ (1 << 4)
# define PATH_ (1 << 6)

typedef struct
{
	int			flag;
	const char	**path;
	int			n_path;
}				t_all;

void		error_flag(const char option);
void		error_path(const char *filename);
t_all		parse(int argc, const char *argv[]);
int			check_flag(const char *s);

#endif
