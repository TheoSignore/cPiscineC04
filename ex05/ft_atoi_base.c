/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:40:49 by tsignore          #+#    #+#             */
/*   Updated: 2020/07/14 11:48:15 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check_base(char *base)
{
	int i;
	int j;
	int res;

	res = base[0] == '\0' || base[1] == '\0' ? 0 : 1;
	i = 0;
	while (base[i])
	{
		res = base[i] == 43 || base[i] == 45 || base[i] == 32 ? 0 : res;
		res = base[i] >= 9 && base[i] <= 13 ? 0 : res;
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			res = j != i && base[j] == base[i] ? 0 : res;
			j++;
		}
		i++;
	}
	return (res);
}

int			ft_pw(int nbr, int pwr)
{
	int i;
	int res;

	if (pwr == 1)
		return (nbr);
	if (pwr == 0)
		return (1);
	i = 1;
	res = 1;
	while (i <= pwr)
	{
		res *= nbr;
		i++;
	}
	return (res);
}

int			ft_is_neg(char *str, int begin)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while (i < begin)
	{
		sign = str[i] == '-' ? sign * -1 : sign;
		i++;
	}
	return (sign);
}

int			ft_nd(char *str, char *base, int begin)
{
	int i;
	int j;
	int pos;

	i = begin;
	while (str[i])
	{
		pos = 0;
		j = 0;
		while (base[j])
		{
			if (base[j] == str[i])
				pos = 1;
			j++;
		}
		if (pos == 0)
			return (i);
		i++;
	}
	return (i);
}

int			ft_atoi_base(char *str, char *base)
{
	int i;
	int res;
	int j;
	int bn;

	if (!check_base(base))
		return (0);
	bn = 0;
	while (str[bn] == 45 || str[bn] == 43 ||
			str[bn] == 32 || (str[bn] >= 9 && str[bn] <= 13))
		bn++;
	i = ft_nd(str, base, bn);
	res = 0;
	while (i-- > bn)
	{
		j = -1;
		while (base[++j])
		{
			if (base[j] == str[i])
				break ;
		}
		res += j * ft_pw(ft_nd(base, base, 0), (ft_nd(str, base, bn) - 1) - i);
	}
	return (res * ft_is_neg(str, bn));
}
