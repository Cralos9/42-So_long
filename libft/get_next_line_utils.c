/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:09:06 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/13 12:21:54 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strchr(char *s, int line_break)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '\0')
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)line_break)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
*/

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*new;
	char	*original;

	if (!str)
		return (NULL);
	if (len > (unsigned int)ft_strlen(str) - start)
		len = (ft_strlen(str) - start);
	if (start >= (unsigned int)ft_strlen(str))
	{
		new = (char *) malloc(sizeof(*new));
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	new = (char *) malloc(sizeof(*new) * (len + 1));
	if (!new)
		return (NULL);
	original = new;
	while (str[start] && len--)
		*new++ = str[start++];
	*new = '\0';
	return (original);
}

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *) malloc(sizeof(*new) * ft_strlen((char *)str) + 1);
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = (char)str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = (char *) malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (*(unsigned char *)str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}
