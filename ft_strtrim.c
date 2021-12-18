/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:19:14 by smia              #+#    #+#             */
/*   Updated: 2021/11/27 11:49:22 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check_start(char *s1, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (&s1[i]);
}

static char	ft_check_last(char *s1, char *set)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(s1);
	while (i > 0 && set[j])
	{
		if (s1[i - 1] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	int		last;

	if (!s1 || !set)
		return (0);
	start = ft_check_start((char *)s1, (char *) set);
	last = ft_check_last(start, (char *)set);
	str = (char *)malloc(sizeof(char) * (last + 1));
	if (!str)
		return (0);
	ft_memcpy(str, start, last);
	str[last] = '\0';
	return (str);
}
