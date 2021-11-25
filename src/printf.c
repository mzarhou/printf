/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:07:08 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/25 02:39:15 by mzarhou          ###   ########.fr       */
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

int	ft_fill_list(t_list **list_ptr, va_list args, const char *str, int *index)
{
	t_format	format;

	ft_init_format(&format);
	if (ft_checkfor('c', str, index, &format))
		ft_lstadd_back(list_ptr, ft_makechar(list_ptr, args, &format));
	else if (ft_checkfor('d', str, index, &format))
		ft_lstadd_back(list_ptr, ft_makeint(args, &format));
	else if (ft_checkfor('i', str, index, &format))
		ft_lstadd_back(list_ptr, ft_makeint(args, &format));
	else if (ft_checkfor('u', str, index, &format))
		ft_lstadd_back(list_ptr, ft_makeuint(args, &format));
	else if (ft_checkfor('x', str, index, &format))
		ft_lstadd_back(list_ptr, ft_makehexa(args, &format, 0));
	else if (ft_checkfor('X', str, index, &format))
		ft_lstadd_back(list_ptr, ft_makehexa(args, &format, 1));
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
		if (ft_fill_list(&list, args, str, &i))
			;
		else if (ft_checkfor('p', str, &i, &format))
			ft_lstadd_back(&list, ft_makeaddr(args, &format));
		else if (str[i] == '%' && str[i + 1] == '%' && ++i)
			ft_lstadd_back(&list, ft_lstnew(ft_char2str('%')));
		else if (ft_checkfor('s', str, &i, &format))
			ft_lstadd_back(&list, ft_makestr(args, &format));
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
