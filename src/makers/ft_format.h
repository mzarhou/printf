/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:12:09 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/24 22:26:48 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

typedef struct flags
{
	int	minus;
	int	zero;
	int	plus;
	int	blank;
	int	hash;
}	t_flags;

typedef struct format
{
	struct flags	flags;
	int				min_width;
	int				max_width;
	int				precision;
}	t_format;

#endif
