/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:15:42 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/17 17:13:06 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

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
			(format[s_f.i + 1] == 'i') ? s_f.nom_fonction = POURCENT_D : NOTHING;
			(format[s_f.i + 1] == 'o') ? s_f.nom_fonction = POURCENT_O : NOTHING;
			(format[s_f.i + 1] == 'f') ? s_f.nom_fonction = POURCENT_F : NOTHING;
			(format[s_f.i + 1] == 'x') ? s_f.nom_fonction = POURCENT_X : NOTHING;
			(format[s_f.i + 1] == 'c') ? s_f.nom_fonction = POURCENT_C : NOTHING;
			(format[s_f.i + 1] == 's') ? s_f.nom_fonction = POURCENT_S : NOTHING;
			(format[s_f.i + 1] == 'X') ? s_f.nom_fonction = POURCENT_XX : NOTHING;
			(format[s_f.i + 1] == 'u') ? s_f.nom_fonction = POURCENT_U : NOTHING;
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
	ft_printf("Il y a %i %o %x %X %cilet(s) %s(s) sur %u ronds-points.", 42, 42, 42, 42, 'g', "jaune", 4294967295);
	return (0);
}
