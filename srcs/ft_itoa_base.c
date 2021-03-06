/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:25:56 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/21 13:56:09 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

char	*ft_itoa_base(int n, unsigned int a)
{
	unsigned int	i;
	int				c;
	char			*tab;
	char			*str;

	c = 1;
	str = "0123456789abcdef";
	i = (unsigned int)n;
	while (i >= a)
	{
		i = i / a;
		c++;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	tab[c--] = 0;
	while ((unsigned int)n >= a)
	{
		tab[c] = str[(unsigned int)n % a];
		n = (unsigned int)n / a;
		c--;
	}
	tab[c] = str[n];
	return (tab);
}

char	*ft_char(char c)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(1);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*ft_string(char *s)
{
	char	*str;
	str = ft_strdup(s);
	return (str);
}

char	*ft_xtoX(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(s);
	while (str[i] != 0)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
