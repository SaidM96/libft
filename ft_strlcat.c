/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:05:33 by smia              #+#    #+#             */
/*   Updated: 2021/11/27 12:11:53 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;

	i = 0;
	j = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	if (!src)
		return (0);
	if (j >= dstsize || dstsize == 0)
		return (srclen + dstsize);
	while (i < srclen && i < (dstsize - j - 1))
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + srclen);
}
