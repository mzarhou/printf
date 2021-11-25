/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:39 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/25 05:37:33 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

static char	*padd_it(char *str, const t_format *format, int is_positive)
{
	int	padd_length;

	padd_length = format->min_width - ft_strlen(str);
	if (format->flags.blank)
		padd_length--;
	if (format->flags.plus || !is_positive)
		padd_length--;
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

static char	*make_it(const char *s, const t_format *format, int is_positive)
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
	str = ft_assign_free(str, padd_it(str, format, is_positive));
	if (is_positive && format->flags.plus)
		str = (ft_strjoin_free(ft_strdup("+"), str));
	else if (is_positive && format->flags.blank)
		str = (ft_strjoin_free(ft_strdup(" "), str));
	return (str);
}

t_list	*ft_makeint(va_list args, const t_format *format)
{
	char	*str;
	int		nb;
	int		is_positive;

	is_positive = 1;
	nb = va_arg(args, int);
	if (nb < 0)
		is_positive = 0;
	str = ft_itoa(nb);
	if (!is_positive)
		str = ft_assign_free(str, ft_strdup(str + 1));
	str = ft_assign_free(str, make_it(str, format, is_positive));
	if (!is_positive)
	{
		str = ft_strjoin_free(ft_strdup("-"), str);
		str = (ft_assign_free(str, ft_move_sign(str, '-')));
	}
	else
		str = (ft_assign_free(str, ft_move_sign(str, '+')));
	return (ft_lstnew(str));
}
