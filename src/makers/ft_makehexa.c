/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makehexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:05 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/24 18:14:19 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

static char	*padd_it(char *str, const t_format *format, int is_zero)
{
	int	padd_length;

	padd_length = format->min_width - ft_strlen(str);
	if (!is_zero && format->flags.hash)
		padd_length -= 2;
	if (format->min_width > ft_strlen(str))
	{
		if (format->max_width > -1 || !format->flags.zero)
			return (ft_padd(str, ' ', padd_length, format->flags.minus));
		else
			return (ft_padd(str, '0', padd_length, format->flags.minus));
	}
	return (ft_strdup(str));
}

static int	ft_zeros(const char *str)
{
	while (str && *str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

static char	*ft_move_0x(const char *str)
{
	char	*temp1;
	char	*temp2;
	char	*ret;

	if ((ft_strlen(str) < 2) || str[0] != '0' || str[1] != 'x')
		return (ft_strdup(str));
	temp1 = ft_strdup(str);
	temp2 = temp1 + 1;
	ret = temp1;
	while (temp1 && temp2 && *temp1 && *temp2 && *(temp2 + 1) == ' ')
	{
		*(temp2 + 1) = *temp2;
		*temp2 = *temp1;
		*temp1 = ' ';
		temp1++;
		temp2++;
	}
	return (ret);
}

static char	*make_it(char *str, const t_format *format)
{
	int	is_zero;

	is_zero = 1;
	if (format->max_width > -1 && format->max_width > ft_strlen(str))
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
		padd_it(str, format, is_zero)
	);
	if (!is_zero && format->flags.hash && !ft_zeros(str))
		str = (ft_strjoin_free(ft_strdup("0x"), str));
	return (ft_assign_free(str, ft_move_0x(str)));
}

t_list	*ft_makehexa(va_list args, t_format *format, int uppercase)
{
	return (ft_lstnew(ft_uint2hexa8(va_arg(args, int), uppercase)));
}
