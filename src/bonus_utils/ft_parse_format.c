/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:56:33 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/24 21:23:54 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus_utils.h"

static int	ft_hasone_zero(const char *str, const char *dot_ptr)
{
	char	*part1;
	int		ret;

	ret = 0;
	part1 = ft_substr(str, 0, dot_ptr - str + 1);
	if (ft_strchr(part1, '0')
		&& ft_strchr(part1, '0') == ft_strrchr(part1, '0')
		&& !ft_isdigit(*(dot_ptr - 1))
	)
		ret = 1;
	free(part1);
	return (ret);
}

static int	ft_get_minwidth(const char *str, const char *dot_ptr)
{
	if (!str)
		return (-1);
	if (!dot_ptr)
		dot_ptr = str + ft_strlen(str) - 1;
	if (dot_ptr < str)
		return (-1);
	if (ft_hasone_zero(str, dot_ptr))
		return (-1);
	while (dot_ptr > str)
	{
		if (!ft_isdigit(*(dot_ptr - 1)))
			break ;
		dot_ptr--;
	}
	return (ft_atoi(dot_ptr));
}

static int	ft_get_maxwidth(const char *str, char *dot_ptr)
{
	if (!str || !dot_ptr)
		return (-1);
	return (ft_atoi(dot_ptr + 1));
}

static int	ft_has_zero_flag(const char *str)
{
	while (str && *str && *str != '.')
	{
		if (ft_isdigit(*str) && *str != '0')
			return (0);
		else if (*str == '0')
			return (1);
		str++;
	}
	return (0);
}

int	ft_parse_format(const char *str, t_format *format)
{
	char	first_char;
	char	last_char;
	char	*set;
	char	*dot_ptr;

	set = "cspdiuxX";
	if (!str)
		return (0);
	first_char = str[0];
	last_char = str[ft_strlen(str) - 1];
	if (first_char != '%' || !ft_strchr(set, last_char))
		return (0);
	if (ft_strchr(str, ' '))
		format->flags.blank = 1;
	if (ft_strchr(str, '+'))
		format->flags.plus = 1;
	if (ft_strchr(str, '-'))
		format->flags.minus = 1;
	if (ft_strchr(str, '#'))
		format->flags.hash = 1;
	format->flags.zero = ft_has_zero_flag(str);
	dot_ptr = ft_strchr(str, '.');
	format->min_width = ft_get_minwidth(str, dot_ptr);
	format->max_width = ft_get_maxwidth(str, dot_ptr);
	return (1);
}
