/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:12:33 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/19 14:30:38 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_size(unsigned int a)
{
	int		c;

	c = 1;
	while (a >= 10)
	{
		a = a / 10;
		c++;
	}
	return (c);
}

char			*ft_utoa(unsigned int	a)
{
	int		i;
	char	*str;

	i = ft_size(a);
	str = (char *)malloc(sizeof(char) * i);
	str[i] = 0;
	i--;
	while (a >= 10)
	{
		str[i] = a % 10 + 48;
		a = a / 10;
		i--;
	}
	str[0] = a + 48;
	return (str);
}

char			*ft_ftoa(double f)
{
	double	d;
	char	*str;
	char	*tmp;

	str = ft_itoa((int)f);
	tmp = ft_strjoin(str, ".");
	free(str);
	while ((int)f != 0)
	{
//		printf("f = %f\n", f);
//		printf("(int)f = %d\n", (int)f);
		d = f - (int)f;
		d = d * 10;
//		printf("d = %f\n", d);
		tmp = ft_strjoin_free(tmp, ft_itoa(d));
//	printf("tmp = %s\n", tmp);
		f = d;
	}
	return (tmp);
}

char			*ft_pointeur(void	*p)
{
	char		*x;
	char		*tab;
	char		*res;

	if (!(tab = (char *)malloc(sizeof(char) * 6)))
		return (NULL);
	tab = "0xfff";
	x = ft_itoa_base((int)p, 16);
	res = ft_strjoin(tab, x);
	return (res);
}
