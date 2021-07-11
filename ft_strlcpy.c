/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruncorn <lruncorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:19:39 by lruncorn          #+#    #+#             */
/*   Updated: 2021/06/30 16:52:30 by lruncorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	m;

	if (!dst || !src)
		return (0);
	m = ft_strlen(src);
	n = size;
	if (size)
		size -= 1;
	while (size && *src)
	{
		*(dst++) = *(src++);
		size--;
	}
	if (n)
		*dst = '\0';
	return (m);
}
