/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:39 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/24 18:21:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"


static char	*padd_it(char *str, const t_format *format)
{
	int	padd_length;

	padd_length = format->min_width - ft_strlen(str);
	if (format->flags.blank)
		padd_length--;
	if (format->min_width > ft_strlen(str))
	{
		if (format->max_width > -1 || !format->flags.zero)
			return (ft_padd(str, ' ', padd_length, format->flags.minus));
		else
			return (ft_padd(str, '0', padd_length, format->flags.minus));
	}
	return (ft_strdup(str));
}

static char	*make_it(char *str, const t_format *format)
{
	int	is_zero;

	is_zero = 1;
	if (format->max_width > -1)
		str = ft_assign_free(
				str,
				ft_padd_left(str, '0', format->max_width - ft_strlen(str))
				);
	is_zero = format->max_width == 0 && ft_strlen(str) == 1 && str[0] == '0';
	if (is_zero)
		str = (ft_assign_free(
			str,
			ft_strdup("")
		));
	str = ft_assign_free(
		str,
		padd_it(str, format)
	);
	if (format->flags.blank)
		return (ft_strjoin_free(ft_strdup(" "), str));
	return (str);
}

t_list	*ft_makeint(va_list args, const t_format *format)
{
	char	*str;

	str = ft_itoa(va_arg(args, int));
	return (ft_lstnew(make_it(str, format)));
}
