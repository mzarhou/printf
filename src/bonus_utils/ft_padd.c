/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:43:26 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 23:43:45 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus_utils.h"

char	*ft_padd(const char *str, char c, int count, int right)
{
	if (right)
		return (ft_padd_right(str, c, count));
	return (ft_padd_left(str, c, count));
}
