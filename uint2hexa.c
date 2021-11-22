/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint2hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:00:07 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/22 20:36:15 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uint2hexa(uintptr_t a, int uppercase)
{
	char	*base;

	base = "0123456789abcdef";
	if (uppercase)
		base = "0123456789ABCDEF";
	if (a < 16)
		return (ft_char2str(base[a]));
	return (ft_strjoin_free(ft_uint2hexa(a / 16, uppercase), ft_uint2hexa(a % 16, uppercase)));
}

char	*ft_uint2hexa8(uint32_t a, int uppercase)
{
	char	*base;

	base = "0123456789abcdef";
	if (uppercase)
		base = "0123456789ABCDEF";
	if (a < 16)
		return (ft_char2str(base[a]));
	return (ft_strjoin_free(ft_uint2hexa8(a / 16, uppercase), ft_uint2hexa8(a % 16, uppercase)));
}
