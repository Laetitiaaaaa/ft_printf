/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:15:42 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/14 15:47:34 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"


int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	enum type	type;
	int			i;
	//char		*buffer;

    va_start(ap, format); //initialise le parcours des parametres optionnels
	//attend deux arguments
	// une variable de type va_list
	// et le nom du dernier parametre obligatoire de la fonction courante
	// la fonction doit etre appeller avant toute operation sur les parametres optionels
    //    va_arg(ap, type);
		//la macro fonction va_arg retourne le parametre optionel suivant 
		//en considerant  celui-ci comme de type "type"
		//attend deux arguments
		//une variable de type va_list prcedement initialise par va_start
		//et le type du parametre optionel suivant

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] == 'd')
			type = TYPE_INT;
		if (format[i] == '%' && format[i + 1] == 'f')
			type = TYPE_FLOAT;
	}

		if( type == TYPE_INT)
			printf("un entier =%d\n", va_arg(ap, int));
		if (type == TYPE_FLOAT)
			printf("Un flottant =%f", (float)va_arg(ap, double));
    va_end(ap);
	//met fin au parcours des arguments optionnels
	return (1);
}

int		main(void)
{
	ft_printf("Il y a %f gilet jaunes\n", 3.4);
	return (0);
}
