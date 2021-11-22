/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:07:08 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/22 22:53:05 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkfor(char c, const char *format, int index)
{
	if (format[index] == '%' && format[index + 1] == c)
		return (1);
	return (0);
}

char	*ft_getstr(const char *str)
{
	if (str)
		return (ft_strdup(str));
	return (ft_strdup("(null)"));
}

char	*ft_getaddr(void *ptr)
{
	uintptr_t	uptr;

	uptr = (uintptr_t)ptr;
	return (ft_strjoin_free(ft_strdup("0x"), ft_uint2hexa(uptr, 0)));
}

int	ft_getCcount(const char *format)
{
	int	count;

	count = 0;
	while (format && *format)
	{
		if (*format == '%' && *(format + 1) == 'c')
			count++;
		format++;
	}
	return (count);
}

int	ft_print_str(const char *format, va_list args)
{
	int		i;
	int		count;
	t_list *list;
	int		c;

	i = 0;
	count = 0;
	list = 0;
	while (format[i])
	{
		if (ft_checkfor('c', format, i))
		{
			c = va_arg(args, int);
			if (c == 0)
				ft_lstadd_back(&list, ft_lstnew(0));
			else
				ft_lstadd_back(&list, ft_lstnew(ft_char2str(c)));
		}
		else if (ft_checkfor('s', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_getstr(va_arg(args, char *))));
		else if (ft_checkfor('p', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_getaddr(va_arg(args, void *))));
		else if (ft_checkfor('d', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_itoa(va_arg(args, int))));
		else if (ft_checkfor('i', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_itoa(va_arg(args, int))));
		else if (ft_checkfor('u', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_utoa(va_arg(args, unsigned int))));
		else if (ft_checkfor('x', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_uint2hexa8(va_arg(args, int), 0)));
		else if (ft_checkfor('X', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_uint2hexa8(va_arg(args, int), 1)));
		else if (ft_checkfor('%', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_char2str('%')));
		else
			ft_lstadd_back(&list, ft_lstnew(ft_char2str(format[i--])));
		i += 2;
	}
	while (list)
	{
		if (!list->content)
		{
			count += 1;
			ft_putchar_fd(0, 1);
		}
		else
		{
			count += ft_strlen(list->content);
			ft_putstr_fd(list->content, 1);
		}
		list = list->next;
	}
	ft_lstclear(&list, free);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		nb_chars;

	if (!format)
		return (0);
	va_start(args, format);
	nb_chars = ft_print_str(format, args);
	va_end(args);
	return (nb_chars);
}

// int main()
// {
// 	int a = -4;
// 	// ft_printf("%x %d %s\n", -16, 16, "here we go");
// 	//    printf("%x %d %s\n", -16, 16, "here we go");
// 	uint8_t p = (uint8_t)257;
// 	printf("%d\n", p);
// }
