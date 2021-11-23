/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeaddr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:02 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 17:04:21 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

t_list	*ft_makeaddr(va_list args)
{
	uintptr_t	uptr;

	uptr = (uintptr_t)va_arg(args, void *);
	return (ft_lstnew(ft_strjoin_free(ft_strdup("0x"), ft_uint2hexa(uptr))));
}
