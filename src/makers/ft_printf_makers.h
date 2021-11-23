/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_makers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:00:27 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 17:54:27 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MAKERS_H
# define FT_PRINTF_MAKERS_H
# include "../../libft/libft.h"
# include "../ft_printf.h"
# include "../utils/ft_printf_utils.h"

t_list	*ft_makeint(va_list args);
t_list	*ft_makestr(va_list args);
t_list	*ft_makeaddr(va_list args);
t_list	*ft_makehexa(va_list args, int uppercase);
t_list	*ft_makeuint(va_list args);
#endif
