/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:12:33 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/17 19:02:38 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

static int		ft_size(unsigned int a)
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
	str[0] = a + 48;;
	return (str);
}
/*#include <stdio.h>
char			*ft_ftoa(double f)
{
	double	d;
	char	*str;
	char	*tmp;

	str = ft_itoa((int)f);
	tmp = ft_strjoin(str, ".");
	while ((f - (int)f) != 0)
	{
		printf("f = %f & (int)f = %d\n", f, (int)f);
		d = f - (int)f;
		printf("d = %f\n", d);
		d = d * 10;
		printf("D = %f\n", d);
		tmp = ft_strjoin(tmp, ft_itoa((int)d));
		f = d;
	}
	return (tmp);
}

int		main()
{
	double f = 42.35875;
	printf("%s\n", ft_ftoa(f));
	return (0);
}*/
