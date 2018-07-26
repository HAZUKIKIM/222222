/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:50:30 by kykim             #+#    #+#             */
/*   Updated: 2018/07/25 19:05:35 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_percent(int info[4])
{
	int buffsize;
	int i;

	i = 0;
	buffsize = 1;
	if (info[1] > 1)
		buffsize = info[1];
	if ((info[0] % 10000) / 1000 == 1)
	{
		if ((info[0] % 1000) / 100 == 1)
		{
			while(i++ < buffsize - 1)
				ft_putchar('0');
			ft_putchar('%'); 
		}
		else
		{
			ft_putchar('%');
			while(i++ < buffsize - 1)
				ft_putchar('0');
		}
	}
	else //if ((info[0] % 10 == 1) || ((info[0] % 10000) / 1000 == 0))
	{
		if ((info[0] % 1000) / 100 != 1)
		{
			while(i++ < buffsize - 1)
				ft_putchar(' ');
			ft_putchar('%'); 
		}
		else
		{
			ft_putchar('%');
			while(i++ < buffsize - 1)
				ft_putchar(' ');
		}
	}
	return (buffsize);
}