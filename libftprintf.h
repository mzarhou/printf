/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:05:17 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/22 18:26:15 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);

char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_char2str(char c);
char	*ft_uint2hexa(uintptr_t a, int uppercase);
char	*ft_uint2hexa8(uint32_t a, int uppercase);
#endif
