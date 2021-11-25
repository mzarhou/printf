/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:44:17 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/25 00:38:35 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_checkfor(char c, const char *str, int *index, t_format *format)
{
	const char	*start;
	const char	*end;
	char		*temp;
	int			length;

	if (str[*index] == '%')
	{
		start = str + *index;
		end = ft_strchr(start, c);
		if (!end || end <= start)
			return (0);
		length = end - start + 1;
		temp = ft_substr(start, 0, length);
		ft_parse_format(temp, format);
		free(temp);
		*index += length - 1;
		return (1);
	}
	return (0);
}
