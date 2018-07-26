/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c_cc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:24:18 by kykim             #+#    #+#             */
/*   Updated: 2018/07/25 17:03:47 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_left(char *buff, int buffsize, wint_t c, int i)
{
	buff[i++] = c;
	while (i < buffsize)
		buff[i++] = ' ';
}

void	print_right(char *buff, int buffsize, wint_t c, int i)
{
	while (i < buffsize - 1)
		buff[i++] = ' ';
	buff[buffsize - 1] = c;
}

int		convert_c(int info[4], va_list ap)
{
	char	*buff;
	int		buffsize;
	wint_t	c;
	int		i;

	i = 0;
	buffsize = 1;
	if (info[1] > 1)
		buffsize = info[1];
	buff = (char *)malloc(sizeof(char) * (buffsize + 1));
	buff[buffsize] = '\0';
	if (info[3] == 3)
		c = va_arg(ap, wint_t);
	else
		c = (unsigned char)va_arg(ap, wint_t);
	if ((info[0] % 1000) / 100 == 1)
		print_left(buff, buffsize, c, i);
	else
		print_right(buff, buffsize, c, i);
	ft_putstr(buff);
	free(buff);
	return (buffsize);
}

int		convert_cc(int info[4], va_list ap)
{
	char	*buff;
	int		buffsize;
	wint_t	c;
	int		i;

	i = 0;
	buffsize = 1;
	if (info[1] > 1)
		buffsize = info[1];
	buff = (char *)malloc(sizeof(char) * (buffsize + 1));
	buff[buffsize] = '\0';
	c = va_arg(ap, wint_t);
	if ((info[0] % 1000) / 100 == 1)
		print_left(buff, buffsize, c, i);
	else
		print_right(buff, buffsize, c, i);
	ft_putstr(buff);
	free(buff);
	return (buffsize);
}
