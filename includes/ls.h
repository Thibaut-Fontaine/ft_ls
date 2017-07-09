/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 02:44:04 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/09 04:53:08 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "../libft/includes/libft.h"

/*
** flags
*/

# define _ALL_ (1 << 0)
# define _LST_ (1 << 1)
# define _REC_ (1 << 2)
# define _REV_ (1 << 3)
# define _TIM_ (1 << 4)
# define _PATH_ (1 << 6)

typedef int t_flag;

typedef struct
{
	t_flag		flag;
	const char	**path;
	int			n_path;
}				t_all;

void		error_flag(const char option);
void		error_path(const char *filename);
t_all		parse(int argc, const char *argv[]);
int			check_flag(const char *s);

#endif
