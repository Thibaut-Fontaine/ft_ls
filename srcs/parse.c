/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 03:07:22 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/09 05:59:36 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

inline int		check_flag(const char *s)
{
	int		ret;

	if (s[0] != '-')
		return (PATH_);
	++s;
	ret = 0;
	while (*s)
	{
		if (*s == 'l')
			ret |= LST_;
		else if (*s == 'a')
			ret |= ALL_;
		else if (*s == 'r')
			ret |= REV_;
		else if (*s == 'R')
			ret |= REC_;
		else if (*s == 't')
			ret |= TIM_;
		else
			error_flag(*s);
		++s;
	}
	return (ret);
}

inline t_all		parse(int argc, const char *argv[])
{
	t_all	all;
	int		tmp;
	int		n;

	all.flag = 0;
	all.path = NULL;
	all.n_path = 0;
	n = 0;
	++argv;
	--argc;
	while (n < argc)
	{
		if ((tmp = check_flag(argv[n])) == PATH_)
			break ;
		else
			all.flag |= tmp;
		++n;
	}
	all.path = &(argv[n]);
	all.n_path = argc - n;
	return (all);
}
