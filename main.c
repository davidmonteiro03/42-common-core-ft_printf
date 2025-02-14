/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:59:40 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/14 10:52:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int				i;
	int				ret[2];
	int				in;
	unsigned int	uin;

	i = 0;
	while (++i < argc)
	{
		in = atoi(argv[i]);
		uin = (unsigned int)in;
		printf("ft_printf: '");
		fflush(stdout);
		ret[0] = ft_printf("%c %s %p %d %i %u %x %X %%", in, argv[i], &argv[i],
				in, in, uin, uin, uin);
		printf("'\n");
		printf("  printf : '");
		ret[1] = printf("%c %s %p %d %i %u %x %X %%", in, argv[i], &argv[i], in,
				in, uin, uin, uin);
		printf("'");
		printf("\n----------------\n");
		printf("my_ret: %d\n", ret[0]);
		printf("cc_ret: %d\n", ret[1]);
	}
	return (0);
}
