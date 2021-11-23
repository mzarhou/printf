/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:39 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 23:45:17 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

char	*make_it(char *str, t_format format)
{
	int	padd_length;

	if (format.max_width > -1)
		str = ft_assign_free(
			str,
			ft_padd_left(str, '0', format.max_width - ft_strlen(str))
		);
	padd_length = format.min_width - ft_strlen(str);
	if (format.flags.blank)
		padd_length--;
	if (format.min_width > ft_strlen(str))
		str = ft_assign_free(
			str,
			ft_padd(str, ' ', padd_length, format.flags.minus)
		);
	if (format.flags.blank)
		return (ft_strjoin_free(ft_strdup(" "), str));
	return (str);
}

t_list	*ft_makeint(va_list args, t_format format)
{
	char	*str;

	str = ft_itoa(va_arg(args, int));
	return (ft_lstnew(make_it(str, format)));
}
