/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:19:29 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/15 20:32:25 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

# define POURCENT_F 0
# define POURCENT_D 1
# define NOTHING 2

typedef struct	t_my
{
	int			i;
	int			j;
	char		*buffer;
	int			first;
	va_list		ap;
	char		*format;
	int			nom_fonction;
	int			add;
	char*		(*liste_fonction[10]) (struct t_my *s_f);
}				s_my;

char			*ft_end_of_format(s_my *s_f);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_add_value(s_my *s_f);
void			ft_init_struct(s_my *s_f);
char			*ft_pourcent_d(s_my *s_f);
char			*ft_pourcent_f(s_my *s_f);
#endif
