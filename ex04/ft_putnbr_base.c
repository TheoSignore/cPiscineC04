/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:04:57 by tsignore          #+#    #+#             */
/*   Updated: 2020/07/13 21:34:55 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_iscorrect(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (j != i && base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			bs_len;
	long int	n;

	n = nbr;
	if (base_iscorrect(base))
	{
		bs_len = ft_strlen(base);
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= bs_len)
		{
			ft_putnbr_base((n / bs_len), base);
			ft_putchar(base[n % bs_len]);
		}
		else if (n < bs_len)
			ft_putchar(base[n]);
	}
}
