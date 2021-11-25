/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeuint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:18 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/25 05:46:57 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

static char	*padd_it(char *str, const t_format *format)
{
	int	padd_length;

	padd_length = format->min_width - ft_strlen(str);
	if (format->min_width > (int)ft_strlen(str))
	{
		if (format->max_width > -1 || !format->flags.zero)
			return (ft_padd(str, ' ', padd_length, format->flags.minus));
		else
			return (ft_padd(str, '0', padd_length, format->flags.minus));
	}
	return (ft_strdup(str));
}

static char	*ft_move_sign(const char *str, char sign)
{
	char	*temp;
	char	*ret;

	if ((ft_strlen(str) < 1) || str[0] != sign)
		return (ft_strdup(str));
	temp = ft_strdup(str);
	ret = temp;
	while (temp && *temp && *(temp + 1) == ' ')
	{
		*(temp + 1) = sign;
		*temp = ' ';
		temp++;
	}
	return (ret);
}

static char	*make_it(const char *s, const t_format *format)
{
	int		is_zero;
	char	*str;

	is_zero = 1;
	str = ft_strdup(s);
	if (format->max_width > -1)
		str = ft_assign_free(
				str,
				ft_padd_left(str, '0', format->max_width - ft_strlen(str))
				);
	is_zero = (format->max_width == 0 && ft_strlen(str) == 1 && str[0] == '0');
	if (is_zero)
		str = (ft_assign_free(str, ft_strdup("")));
	return (ft_assign_free(str, padd_it(str, format)));
}

t_list	*ft_makeuint(va_list args, const t_format *format)
{
	char	*str;

	str = ft_utoa(va_arg(args, unsigned int));
	str = ft_assign_free(str, make_it(str, format));
	return (ft_lstnew(str));
}
