/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:24:13 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/07 10:37:17 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_checkset(char c, char set)
{
	if (c == set)
		return (1);
	else
		return (0);
}

static char	*ft_copy_buffer(const char *s, const char *buff)
{
	int		size;
	char	*dup;
	int		i;

	size = ft_strlen(buff) - ft_strlen(s);
	dup = malloc((size + 1) * sizeof(*dup));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (buff != s)
	{	
		dup[i] = *buff;
		i++;
		buff++;
	}
	dup[i] = 0;
	return (dup);
}

static int	ft_count_words(const char *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	if (ft_checkset(s[i], c) && s[i])
		i++;
	while (s[i])
	{
		while (!ft_checkset(s[i], c) && s[i])
			i++;
		word++;
		while (ft_checkset(s[i], c) && s[i])
			i++;
	}
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char		**split;
	int			index;
	const char	*buff;

	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	index = 0;
	while (ft_checkset(*s, c) && *s)
		s++;
	while (*s)
	{
		buff = s;
		while (!ft_checkset(*s, c) && *s)
			s++;
		split[index] = ft_copy_buffer(s, buff);
		index++;
		while (ft_checkset(*s, c) && *s)
			s++;
	}
	split[index] = 0;
	return (split);
}
