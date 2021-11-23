/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makehexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:05 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 16:31:27 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

t_list	*ft_makehexa(va_list args, int uppercase)
{
	return (ft_lstnew(ft_uint2hexa8(va_arg(args, int), uppercase)));
}
