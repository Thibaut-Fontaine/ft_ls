/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 03:07:22 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/09 04:49:48 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

inline int		check_flag(const char *s)
{
	int		ret;

	if (s[0] != '-')
		return (_PATH_);
	++s;
	ret = 0;
	while (*s)
	{
		if (*s == 'l')
			ret |= _LST_;
		else if (*s == 'a')
			ret |= _ALL_;
		else if (*s == 'r')
			ret |= _REV_;
		else if (*s == 'R')
			ret |= _REC_;
		else if (*s == 't')
			ret |= _TIM_;
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

	n = 0;
	++argv;
	--argc;
	while (n < argc)
	{
		if ((tmp = check_flag(argv[n])) == _PATH_)
			break ;
		else
			all.flag |= tmp;
		++n;
	}
	all.path = &(argv[n]);
	all.n_path = argc - n;
	return (all);
}
