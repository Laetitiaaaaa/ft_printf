/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:37:14 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/16 17:11:42 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_champs(char *s, int n, char *c)
{
	size_t	i;
	int		j;
	char	*str;
	char	*tab;

	str = NULL;
	i = ft_strlen(s);
	j = n - i;
	if (n > (int)i)
	{
		if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
			return (NULL);
		i = 0;
		while ((int)i < j)
		{
			if (c[0] != '-')
				str[i++] = c[0];
			else
				str[i++] = c[1];
		}
		str[i] = 0;
		if (c[0] != '-')
			tab = ft_strjoin(str, s);
		else
			tab = ft_strjoin(s, str);
	}
	else
		return (s);
	return (tab);
}
