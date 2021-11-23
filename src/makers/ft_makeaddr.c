/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeaddr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:02 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 21:44:35 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

static char	*make_it(char *str, t_format format)
{
	if (format.flags.minus > 0 && format.min_width > -1)
		str = ft_padd_right(str, ' ', format.min_width - ft_strlen(str));
	else if (format.min_width > -1)
		str = ft_padd_left(str, ' ', format.min_width - ft_strlen(str));
	else
		str = ft_strdup(str);
	return (str);
}

t_list	*ft_makeaddr(va_list args, t_format format)
{
	uintptr_t	uptr;
	char		*str;

	uptr = (uintptr_t)va_arg(args, void *);
	str = ft_strjoin_free(
			ft_strdup("0x"),
			ft_uint2hexa(uptr)
		);
	return (ft_lstnew(make_it(str, format)));
}
