/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:37:14 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/16 14:58:18 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft/libft.h"

char	*ft_champs(char *s, int n, char c)
{
	size_t	i;
	int		j;
	char	*tab;

	i = ft_strlen(s);
	j = n - i;
	if (n > (int)i)
	{
		if (!(tab = (char *)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		tab[n + 1] = 0;
		while (n >= 0)
		{
			while (n >= j)
			{
				tab[n] = s[i];
				i--;
				n--;
			}
			tab[n] = c;
			n--;
		}
	}
	else
	{
		tab = ft_strnew(i);
		ft_memcpy(tab, s, i);
	}
	return (tab);
}
