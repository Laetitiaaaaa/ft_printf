/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:37:14 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/16 15:25:36 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_champs(char *s, int n, char *c)
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
				tab[n--] = s[i--];
			tab[n] = c[0];
			n--;
		}
	}
	else
		return (s);
	return (tab);
}
