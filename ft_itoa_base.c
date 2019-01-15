/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:25:56 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/15 15:02:24 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa_10tox(int n, int a)
{
	int		i;
	int		c;
	char	*tab;
	char	*str;

	i = n;
	c = 1;
	str = "0123456789abcdef";
	while (i >= a)
	{
		i = i / a;
		c++;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	tab[c] = 0;
	c--;
	while (n >= a)
	{
		tab[c] = str[n % a];
		n = n / a;
		c--;
	}
	tab[c] = str[n];
	return (tab);
}

int		main(int ac, char **av)
{
	ac = 3;
	printf("%s\n", ft_itoa_10tox(atoi(av[1]), atoi(av[2])));
	return (0);
}
