/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:13:03 by tsignore          #+#    #+#             */
/*   Updated: 2020/07/14 10:50:29 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n'
			|| c == '\v' || c == '\f'
				|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if (c > '9' || c < '0')
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i])
	{
		sign = str[i] == '-' ? sign * -1 : sign;
		if (ft_isnum(str[i]))
			break ;
		i++;
	}
	if (str[i] == '0')
		return (0);
	while (str[i] && ft_isnum(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
