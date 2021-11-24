/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:43:03 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/24 21:28:12 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_UTILS_H
# define FT_PRINTF_BONUS_UTILS_H
# include "../../libft/libft.h"
# include "../ft_printf.h"
# include "../makers/ft_printf_makers.h"

char	*ft_padd_left(const char *s, char c, int count);
char	*ft_padd_right(const char *s, char c, int count);
char	*ft_padd(const char *str, char c, int count, int right);
int		ft_parse_format(const char *str, t_format *format);
void	ft_init_format(t_format *format);
#endif
