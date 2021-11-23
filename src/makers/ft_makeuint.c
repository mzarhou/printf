/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeuint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:18 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 16:52:24 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_makers.h"

t_list	*ft_makeuint(va_list args)
{
	return (ft_lstnew(
			ft_utoa(va_arg(args, unsigned int))
		));
}
