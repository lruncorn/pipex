/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruncorn <lruncorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:55:39 by lruncorn          #+#    #+#             */
/*   Updated: 2021/06/30 16:50:56 by lruncorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = NULL;
	if (!s)
		return (0);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	if (start < ft_strlen(s))
	{
		s = s + start;
		while (*s && i < len)
		{
			sub[i] = *s;
			s++;
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
