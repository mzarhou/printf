/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padd_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:42:32 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 20:44:00 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus_utils.h"

char	*ft_padd_right(const char *s, char c, int count)
{
	int		len;
	char	*str;
	int		i;

	if (count < 0)
		return (ft_strdup(s));
	if (!s)
		s = ft_strdup("");
	len = ft_strlen(s);
	str = (char *)malloc(len + count + 1);
	ft_memmove(str, s, len);
	i = len;
	while (i < (len + count))
		str[i++] = c;
	str[len + count] = 0;
	return (str);
}
