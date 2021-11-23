/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:07:08 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/23 17:09:24 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils/ft_printf_utils.h"
#include "makers/ft_printf_makers.h"

int	ft_get_res_len(t_list *list)
{
	int	count;

	count = 0;
	while (list)
	{
		if (!list->content)
			count += 1;
		else
			count += ft_strlen((char *)list->content);
		list = list->next;
	}
	return (count);
}

void	ft_print_result(void *str)
{
	if (!str)
		ft_putchar_fd(0, 1);
	else
		ft_putstr_fd((char *)str, 1);
}

int	ft_fill_list(t_list **list_ptr, va_list args, const char *format, int index)
{
	char	c;

	if (ft_checkfor('c', format, index))
	{
		c = va_arg(args, int);
		if (c == 0)
			ft_lstadd_back(list_ptr, ft_lstnew(0));
		else
			ft_lstadd_back(list_ptr, ft_lstnew(ft_char2str(c)));
	}
	else if (ft_checkfor('d', format, index))
		ft_lstadd_back(list_ptr, ft_makeint(args));
	else if (ft_checkfor('i', format, index))
		ft_lstadd_back(list_ptr, ft_makeint(args));
	else if (ft_checkfor('u', format, index))
		ft_lstadd_back(list_ptr, ft_makeuint(args));
	else if (ft_checkfor('x', format, index))
		ft_lstadd_back(list_ptr, ft_makehexa(args, 0));
	else if (ft_checkfor('X', format, index))
		ft_lstadd_back(list_ptr, ft_makehexa(args, 1));
	else
		return (0);
	return (1);
}

int	ft_print_str(const char *format, va_list args)
{
	int		i;
	int		count;
	t_list	*list;

	i = 0;
	list = 0;
	while (format[i])
	{
		if (ft_fill_list(&list, args, format, i))
			;
		else if (ft_checkfor('p', format, i))
			ft_lstadd_back(&list, ft_makeaddr(args));
		else if (ft_checkfor('%', format, i))
			ft_lstadd_back(&list, ft_lstnew(ft_char2str('%')));
		else if (ft_checkfor('s', format, i))
			ft_lstadd_back(&list, ft_makestr(args));
		else
			ft_lstadd_back(&list, ft_lstnew(ft_char2str(format[i--])));
		i += 2;
	}
	ft_lstiter(list, ft_print_result);
	count = ft_get_res_len(list);
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
