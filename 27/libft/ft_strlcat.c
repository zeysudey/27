/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:08:38 by zyilmaz           #+#    #+#             */
/*   Updated: 2024/10/27 14:39:52 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	int		i;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (dstsize <= d)
		return (dstsize + s);
	while (src[i] != '\0' && d + i + 1 < dstsize)
	{
		dst[i + d] = src[i];
		i++;
	}
	dst[i + d] = '\0';
	return (d + s);
}
