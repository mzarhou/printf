/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:34:17 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/25 16:47:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include "../utils.h"
# include "../../libft/libft.h"
# include "../makers/ft_printf_makers.h"
# include "../makers/ft_format.h"

int		ft_printf(const char *format, ...);

char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_char2str(char c);
char	*ft_uint2hexa(uintptr_t a);
char	*ft_uint2hexa8(uint32_t a, int uppercase);
char	*ft_utoa(unsigned int nb);
int		ft_get_format(const char *str, int index, t_format *format);
char	*ft_assign_free(char *str, char *value);

#endif
