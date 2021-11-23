/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:05:17 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 01:47:23 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);

char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_char2str(char c);
char	*ft_uint2hexa(uintptr_t a);
char	*ft_uint2hexa8(uint32_t a, int uppercase);
char	*ft_utoa(unsigned int nb);
int		ft_checkfor(char c, const char *format, int index);
#endif
