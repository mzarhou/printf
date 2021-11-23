/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:57:51 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 01:46:34 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_makeint(va_list args)
{
	return (ft_lstnew(ft_itoa(va_arg(args, int))));
}

t_list	*ft_makestr(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str)
		return (ft_lstnew(ft_strdup(str)));
	return (ft_lstnew(ft_strdup("(null)")));
}

t_list	*ft_makeaddr(va_list args)
{
	uintptr_t	uptr;

	uptr = (uintptr_t)va_arg(args, void *);
	return (ft_lstnew(ft_strjoin_free(ft_strdup("0x"), ft_uint2hexa(uptr))));
}

t_list	*ft_makehexa(va_list args, int uppercase)
{
	return (ft_lstnew(ft_uint2hexa8(va_arg(args, int), uppercase)));
}

t_list	*ft_makeuint(va_list args)
{
	return (ft_lstnew(
			ft_utoa(va_arg(args, unsigned int))
		));
}
