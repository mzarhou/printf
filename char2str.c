/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char2str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:35:27 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/22 15:00:12 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_char2str(char c)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	str[0] = c;
	str[1] = 0;
	return (str);
}
