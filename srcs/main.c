/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 02:43:28 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/09 17:29:07 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

int				main(int argc, const char *argv[])
{
	t_all		all;

	all = parse(argc, argv);
	while (all.n_path)
	{
		--all.n_path;
		ft_putstr(all.path[all.n_path]);
		ft_putstr("\n");
	}
	if (all.flag & ALL_)
		ft_putstr("all ");
	if (all.flag & LST_)
		ft_putstr("lst ");
	if (all.flag & REC_)
		ft_putstr("rec ");
	if (all.flag & REV_)
		ft_putstr("rev ");
	if (all.flag & TIM_)
		ft_putstr("time ");
	return (0);
}
