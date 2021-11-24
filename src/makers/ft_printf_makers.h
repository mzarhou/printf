/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_makers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:00:27 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/24 22:13:27 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MAKERS_H
# define FT_PRINTF_MAKERS_H
# include "../utils.h"
# include "../../libft/libft.h"
# include "../utils/ft_printf_utils.h"
# include "../bonus_utils/ft_printf_bonus_utils.h"
# include "ft_format.h"

t_list	*ft_makeint(va_list args, const t_format *format);
t_list	*ft_makestr(va_list args, const t_format *format);
t_list	*ft_makeaddr(va_list args, const t_format *format);
t_list	*ft_makechar(t_list **list_ptr, va_list args, const t_format *format);
t_list	*ft_makehexa(va_list args, const t_format *format, int uppercase);
t_list	*ft_makeuint(va_list args, const t_format *format);
#endif
