/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruncorn <lruncorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:06:45 by lruncorn          #+#    #+#             */
/*   Updated: 2021/06/30 17:12:59 by lruncorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char *)malloc(len + 1);
		if (!(new))
			return (NULL);
		while (*s1 != '\0')
		{
			*new = *s1;
			new++;
			s1++;
		}
		while (*s2 != '\0')
			*new++ = *s2++;
		*new = '\0';
		new -= len;
	}
	return (new);
}
