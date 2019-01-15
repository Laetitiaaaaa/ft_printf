/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:13:34 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/15 20:32:21 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_add_value(s_my *s_f)
{
	char		*result;
	char		*inner_buf;
	int			decalage;
	char		*format;


	format = &(s_f->format[s_f->j]);
	if (s_f->first == 1)
		decalage = 0;
	else
		decalage = 2;
	inner_buf = ft_strnew(s_f->i - (s_f->j + decalage));
	inner_buf = ft_strncpy(inner_buf, &format[decalage],(size_t)(s_f->i - (s_f->j + decalage)));
	result = s_f->liste_fonction[s_f->nom_fonction](s_f);
	inner_buf = ft_strjoin_free(inner_buf, result);
	s_f->buffer = ft_strjoin_free(s_f->buffer, inner_buf);
	s_f->j = s_f->i;
	s_f->first = 0;
	return (s_f->buffer);
}

char			*ft_end_of_format(s_my *s_f)
{
	char		*inner_buf;
	int			decalage;
	char		*format;

	format = &(s_f->format[s_f->j]);
	if (s_f->first == 1)
		decalage = 0;
	else
		decalage = 2;
	inner_buf = ft_strnew(s_f->i - (s_f->j + decalage));
	inner_buf = ft_strncpy(inner_buf, &format[decalage],
(size_t)(s_f->i - (s_f->j + decalage)));
	s_f->buffer = ft_strjoin_free(s_f->buffer, inner_buf);
	return (s_f->buffer);
}

char			*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	char	*swap_s1;
	char	*swap_s2;

	swap_s1 = s1;
	swap_s2 = s2;
	if (swap_s1 == 0 || swap_s2 == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (swap_s1[i] != '\0')
		i++;
	while (swap_s2[j] != '\0')
		j++;
	if (!(str = malloc(sizeof(char) * (i + j) + 1)))
		return (0);
	ft_strcpy(str, (char*)(swap_s1));
	ft_strcat(str, (char*)(swap_s2));
	free(swap_s1);
	free(swap_s2);
	return (str);
}

void	ft_init_struct(s_my *s_f)
{
	s_f->liste_fonction[POURCENT_D] = ft_pourcent_d;
	s_f->liste_fonction[POURCENT_F] = ft_pourcent_f;
	s_f->buffer = NULL;
	s_f->buffer = ft_strnew(0);
	s_f->first = 1;
}

char		*ft_pourcent_d(s_my *s_f)
{
	char *result;
	int		my_result;

	my_result = va_arg(s_f->ap, int);
	result = ft_itoa(my_result);
	return (result);
}

char		*ft_pourcent_f(s_my *s_f)
{
	char		*result;
	float		my_result;

	my_result = (float)va_arg(s_f->ap, double);
	my_result += 2;
	result = ft_strdup("-1");
	return (result);
}
