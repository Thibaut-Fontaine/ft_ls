/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 03:54:53 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/10 05:38:03 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void	display_usage(void)
{
	write(1, "usage: ls [-Ralrt] [file ...]", 29);
}

void	error_path(const char *filename)
{
	write(1, "ls: ", 4);
	write(1, filename, ft_strlen(filename));
	write(1, ": No such file or directory", 27);
}

void	error_flag(const char option)
{
	write(1, "ls: illegal option -- ", 23);
	write(1, &option, 1);
	write(1, "\n", 1);
	display_usage();
	exit(-1);
}
