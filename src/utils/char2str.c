/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char2str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:35:27 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 16:57:49 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

char	*ft_char2str(char c)
{
	char	*str;

	if (c == 0)
		return (ft_strdup(""));
	str = (char *)malloc(2 * sizeof(char));
	str[0] = c;
	str[1] = 0;
	return (str);
}
