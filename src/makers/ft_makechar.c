/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:02 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/24 16:10:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

static char	*make_it(char *str, const t_format *format)
{
	if (format->flags.minus > 0 && format->min_width > -1)
		str = ft_padd_right(str, ' ', format->min_width - ft_strlen(str));
	else if (format->min_width > -1)
		str = ft_padd_left(str, ' ', format->min_width - ft_strlen(str));
	else
		str = ft_strdup(str);
	return (str);
}

t_list	*ft_makechar(va_list args, const t_format *format)
{
	char	c;
	char	*str;

	c = va_arg(args, int);
	if (c == 0)
		//! this will not work
		return (ft_lstnew(0));
	str = ft_char2str(c);
	return (ft_lstnew(make_it(str, format)));
}
