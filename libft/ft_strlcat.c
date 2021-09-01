/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:53:26 by ptroger           #+#    #+#             */
/*   Updated: 2019/12/24 11:42:28 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	k = 0;
	while (src[k] != '\0')
		k++;
	if (dstsize == 0)
		return (k);
	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	l = i;
	j = 0;
	if (i < dstsize)
	{
		while (i < dstsize - 1 && src[j] != '\0')
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (dstsize - 1 < l)
		return (dstsize + k);
	return (k + l);
}
