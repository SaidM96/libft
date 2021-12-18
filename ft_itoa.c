/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:44:16 by smia              #+#    #+#             */
/*   Updated: 2021/11/25 19:06:48 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		count++;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static char	*ft_putnb(char *str, long long nb, int signe, int count)
{
	if (nb == 0)
		str[count] = '0';
	str[count] = '\0';
	while (count)
	{
		count--;
		str[count] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (signe == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			signe;
	int			len;
	long long	nbr;

	signe = 0;
	nbr = n;
	len = ft_count_digits(nbr);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		nbr = nbr * (-1);
		signe = 1;
	}
	return (ft_putnb(s, nbr, signe, len));
}
