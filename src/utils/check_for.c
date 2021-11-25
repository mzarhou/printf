/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:44:17 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/25 16:46:07 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_get_format(const char *str, int index, t_format *format)
{
	const char	*start;
	const char	*end;
	char		*temp;

	start = str + index;
	end = start + 1;
	while (end && *end)
	{
		if (ft_strrchr("cspdiuxX%", *end))
			break ;
		end++;
	}
	if (end - start < 2)
		return (end - start);
	temp = ft_substr(start, 0, end - start + 1);
	ft_parse_format(temp, format);
	if (temp)
		free(temp);
	return (end - start);
}
