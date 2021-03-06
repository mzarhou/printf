/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:07:08 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/25 16:58:40 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
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

int	ft_fill_list(t_list **list_ptr, va_list args, char c, t_format *format)
{
	if (c == 'c')
		ft_lstadd_back(list_ptr, ft_makechar(list_ptr, args, format));
	else if (c == 's')
		ft_lstadd_back(list_ptr, ft_makestr(args, format));
	else if (c == 'p')
		ft_lstadd_back(list_ptr, ft_makeaddr(args, format));
	else if (c == 'd')
		ft_lstadd_back(list_ptr, ft_makeint(args, format));
	else if (c == 'i')
		ft_lstadd_back(list_ptr, ft_makeint(args, format));
	else if (c == 'u')
		ft_lstadd_back(list_ptr, ft_makeuint(args, format));
	else if (c == 'x')
		ft_lstadd_back(list_ptr, ft_makehexa(args, format, 0));
	else if (c == 'X')
		ft_lstadd_back(list_ptr, ft_makehexa(args, format, 1));
	else if (c == '%')
		ft_lstadd_back(list_ptr, ft_lstnew(ft_char2str('%')));
	else
		return (0);
	return (1);
}

int	ft_print_str(const char *str, va_list args)
{
	int			i;
	int			count;
	t_list		*list;
	t_format	format;

	i = 0;
	list = 0;
	ft_init_format(&format);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += ft_get_format(str, i, &format);
			ft_fill_list(&list, args, str[i], &format);
		}
		else
			ft_lstadd_back(&list, ft_lstnew(ft_char2str(str[i])));
		i++;
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
