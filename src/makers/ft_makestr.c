/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:13 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 16:31:36 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

t_list	*ft_makestr(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str)
		return (ft_lstnew(ft_strdup(str)));
	return (ft_lstnew(ft_strdup("(null)")));
}
