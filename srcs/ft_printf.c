/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:15:42 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/16 17:21:19 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	s_my		s_f;

	ft_init_struct(&s_f);
	s_f.format = (char*)format;
	va_start(s_f.ap, format);
	s_f.j = 0;
	s_f.i = 0;
	while (format[s_f.i])
	{
		s_f.nom_fonction = NOTHING;
		if (format[s_f.i] == '%')
		{
			(format[s_f.i + 1] == 'd') ? s_f.nom_fonction = POURCENT_D : NOTHING;
			(format[s_f.i + 1] == 'f') ? s_f.nom_fonction = POURCENT_F : NOTHING;
		}
		if (s_f.nom_fonction != NOTHING)
			s_f.buffer = ft_add_value(&s_f);
		(s_f.i)++;
	}
	s_f.buffer = ft_end_of_format(&s_f);
	va_end(s_f.ap);
	ft_putstr(s_f.buffer);
	free(s_f.buffer);
	return (1);
}

int		main(void)
{
	ft_printf("Il y a %f gilet jaunes sur %d rond point\n", 10.4, 3);
	return (0);
}
