/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint2hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:00:07 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 16:33:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

char	*ft_uint2hexa(uintptr_t a)
{
	char	*base;

	base = "0123456789abcdef";
	if (a < 16)
		return (ft_char2str(base[a]));
	return (ft_strjoin_free(
			ft_uint2hexa(a / 16),
			ft_uint2hexa(a % 16)));
}
