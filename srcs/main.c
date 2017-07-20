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
	
	
	
	// test :
	/*
	while (all.n_path)
	{
		--all.n_path;
		ft_putstr(all.path[all.n_path]);
		ft_putstr("\n");
	}
	if (all.flag & ALL_)
		ft_putstr("all \n");
	if (all.flag & LST_)
		ft_putstr("lst \n");
	if (all.flag & REC_)
		ft_putstr("rec \n");
	if (all.flag & REV_)
		ft_putstr("rev \n");
	if (all.flag & TIM_)
		ft_putstr("time \n");
	*/
	return (0);
}
