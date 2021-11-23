/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:13 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 21:41:31 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

static char	*make_it(char *str, t_format format)
{
	char	*temp;

	if (format.max_width > -1)
		str = ft_substr(str, 0, format.max_width);
	else
		str = ft_strdup(str);
	temp = str;
	if (format.flags.minus > 0 && format.min_width > -1)
		str = ft_padd_right(str, ' ', format.min_width - ft_strlen(str));
	else if (format.min_width > -1)
		str = ft_padd_left(str, ' ', format.min_width - ft_strlen(str));
	else
		str = ft_strdup(str);
	free(temp);
	return (str);
}

t_list	*ft_makestr(va_list args, t_format format)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_lstnew(ft_strdup("(null)")));
	return (ft_lstnew(make_it(str, format)));
}
