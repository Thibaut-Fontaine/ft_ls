/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 02:43:28 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/09 04:54:32 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

int				main(int argc, const char *argv[])
{
	t_all	all;

	all = parse(argc, argv);
	// test :
	while (all.n_path)
	{
		ft_putstr(all.path[all.n_path]);
		--all.n_path;
	}
	return (0);
}
