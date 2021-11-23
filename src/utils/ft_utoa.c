/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:37:56 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 16:33:23 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include <stdlib.h>
#include <limits.h>

static unsigned int	ft_getnbr_length(unsigned int nbr)
{
	unsigned int	count;

	count = 1;
	while (nbr / 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_utoa(unsigned int nb)
{
	char			*res;
	unsigned int	i;
	unsigned int	nb_len;

	if (nb == 0)
		return (ft_strdup("0"));
	nb_len = ft_getnbr_length(nb);
	res = (char *)ft_calloc(nb_len + 1, 1);
	if (!res)
		return (0);
	i = nb_len - 1;
	while (i > 0)
	{
		res[i--] = nb % 10 + '0';
		nb /= 10;
	}
	res[i] = nb % 10 + '0';
	res[nb_len] = '\0';
	return (res);
}
