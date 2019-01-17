/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:19:29 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/17 16:31:54 by llejeune         ###   ########.fr       */
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
# define POURCENT_X 3
# define POURCENT_C 4
# define POURCENT_S 5
# define POURCENT_O 6
# define POURCENT_XX 7
# define POURCENT_U 8
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
char			*ft_pourcent_x(s_my *s_f);
char			*ft_pourcent_c(s_my *s_f);
char			*ft_pourcent_s(s_my *s_f);
char			*ft_pourcent_o(s_my *s_f);
char			*ft_pourcent_X(s_my *s_f);
char			*ft_pourcent_u(s_my *s_f);
char			*ft_itoa_base(int n, int a);
char			*ft_char(char c);
char			*ft_string(char *s);
char			*ft_xtoX(char *s);
char			*ft_utoa(unsigned int a);

#endif
