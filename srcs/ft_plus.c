/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:39:44 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/15 18:36:19 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

char	*ft_plus(int n)
{
	char	*str;
	char	*tab;
	int		i;
	int		j;

	if (n > 0)
	{
		str = ft_itoa(n);
		i = ft_strlen(str);
		if (!(tab = (char *)malloc(sizeof(char) * (i + 2))))
			return (NULL);
		i = 0;
		j = 0;
		tab[i] = '+';
		i++;
		while (str[j] != 0)
		{ 
			tab[i] = str[j];
			i++;
			j++;
		}
		tab[i] = 0;
	}
	else
	{
		tab = ft_itoa(n);
	}
	return (tab);
}
