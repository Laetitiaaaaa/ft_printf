/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:33:54 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/16 15:13:20 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main()
{
	char c = 'a';
	char *str = "banana";
	int pos = 0xff2a5;
	int	neg = -42;
	double f = 42.45678521586;

	printf("c = %c\n", c);
	printf("-8.5s = %-8.5s|\n", str);
	printf("8.5s = %8.5s|\n", str);
	printf("p = %p\n", &c);
	printf("d = %d\n", pos);
	printf("d = %d\n", neg);
	printf("i = %i\n", pos);
	printf("i = %i\n", neg);
	printf("o = %o\n", pos);
	printf("o = %o\n", neg);
	printf("u = %u\n", pos);
	printf("u = %u\n", neg);
	printf("x = %x\n", pos);
	printf("x = %x\n", neg);
	printf("X = %X\n", pos);
	printf("X = %X\n", neg);
	printf("f = %f\n", f);
	printf("\n");
	printf("#o = %#o\n", pos);
	printf("#x = %#x\n", pos);
	printf("#X = %#X\n", pos);
	printf("\n");
	printf("6/dneg = %6d\n", neg);
	printf("esp/x = %x\n", pos);
//	printf("+/esp/o = %+ o\n", pos);
	printf("esp/u = %u\n", pos);
	printf("esp/ineg = % i\n", neg);
	printf("\n");
	printf("+dpos = %d\n", pos);
	printf("+dneg = %d\n", neg);
	printf("\n");
	printf("020d = %020d\n", pos);
//	printf("-020d = %-020d\n", pos);
	printf("\n");
	printf("5d = %5d\n", pos);
	printf("-+20d = %-+20d\n", pos);
	printf("\n");
	printf("-20.5d = %-20.5d\n", pos);
	printf(".5f = %.5f\n", f);
	printf("20.5f = %20.5f\n", f);
	return (0);
}
