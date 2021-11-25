/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:47:05 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/25 03:35:59 by mzarhou          ###   ########.fr       */
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

t_list	*ft_makechar(t_list **list_ptr, va_list args, const t_format *format)
{
	char	c;
	char	*str;
	int		len;

	c = va_arg(args, int);
	str = ft_char2str(c);
	str = ft_assign_free(str, make_it(str, format));
	if (c == 0)
	{
		len = ft_strlen(str);
		if (len > 0)
			str[len - 1] = 0;
		if (format->flags.minus)
		{
			ft_lstadd_back(list_ptr, ft_lstnew(0));
			return (ft_lstnew(str));
		}
		ft_lstadd_back(list_ptr, ft_lstnew(str));
		return (ft_lstnew(0));
	}
	return (ft_lstnew(str));
}
