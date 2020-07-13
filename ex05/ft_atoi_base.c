/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:40:49 by tsignore          #+#    #+#             */
/*   Updated: 2020/07/13 15:15:49 by tsignore         ###   ########.fr       */
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

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_pwr(int nbr, int pwr)
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

int			ft_is_neg(char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while (str[i])
	{
		sign = str[i] == '-' ? sign * -1 : sign;
		i++;
	}
	return (sign);
}

int			ft_atoi_base(char *str, char *base)
{
	int bs_len;
	int i;
	int res;
	int j;
	int end;

	if (!check_base(base))
		return (0);
	end = 0;
	while (str[end] == '-' || str[end] == '+')
		end++;
	bs_len = ft_strlen(base);
	i = ft_strlen(str) - 1;
	res = 0;
	while (i > end + 1)
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == str[i])
				break ;
			j++;
		}
		res += j * ft_pwr(bs_len, (ft_strlen(str) - 1) - i);
		i--;
	}
	return (res * ft_is_neg(str));
}
