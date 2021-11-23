/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint2hexa8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:00:07 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 16:35:04 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

char	*ft_uint2hexa8(uint32_t a, int uppercase)
{
	char	*base;

	base = "0123456789abcdef";
	if (uppercase)
		base = "0123456789ABCDEF";
	if (a < 16)
		return (ft_char2str(base[a]));
	return (ft_strjoin_free(
			ft_uint2hexa8(a / 16, uppercase),
			ft_uint2hexa8(a % 16, uppercase)));
}
