/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padd_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:45:38 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 20:46:09 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus_utils.h"

char	*ft_padd_left(const char *s, char c, int count)
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
	i = 0;
	while (i < count)
		str[i++] = c;
	ft_memmove(str + i, s, len);
	str[len + count] = 0;
	return (str);
}
