/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:25:10 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/24 21:28:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus_utils.h"

void	ft_init_format(t_format *format)
{
	format->flags.blank = 0;
	format->flags.hash = 0;
	format->flags.minus = 0;
	format->flags.plus = 0;
	format->flags.zero = 0;
	format->max_width = -1;
	format->min_width = -1;
}
