/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_makers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:00:27 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 21:58:20 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MAKERS_H
# define FT_PRINTF_MAKERS_H
# include "../../libft/libft.h"
# include "../ft_printf.h"
# include "../utils/ft_printf_utils.h"
#include "../bonus_utils/ft_printf_bonus_utils.h"

typedef struct flags
{
	int	minus;
	int	zero;
	int	plus;
	int	blank;
	int	hash;
}	t_flags;

typedef struct format
{
	t_flags			flags;
	int	min_width;
	int	max_width;
	int	precision;
}	t_format;

t_list	*ft_makeint(va_list args, t_format format);
t_list	*ft_makestr(va_list args, t_format format);
t_list	*ft_makeaddr(va_list args, t_format format);
t_list	*ft_makechar(va_list args, t_format format);
t_list	*ft_makehexa(va_list args, t_format format, int uppercase);
t_list	*ft_makeuint(va_list args, t_format format);
#endif
