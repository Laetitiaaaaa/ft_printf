/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diese.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:38:29 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/16 10:32:26 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_diese(char c, char *s)
{
	char	*str;

	if (c == 'o')
		str = ft_strjoin("0", s);
	else if (c == 'x')
		str = ft_strjoin("0x", s);
	else if (c == 'X')
		str = ft_strjoin("0X", s);
	else
		str = s;
	return (str);
}
