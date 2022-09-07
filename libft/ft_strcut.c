/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:38:20 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/07 10:42:48 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Cut string at character and return it.

char	*ft_strcut(char	*str, char c)
{
	char	*cut;
	int		i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	cut = malloc(i * sizeof(cut));
	i = 0;
	while (str[i] != c && str[i])
	{
		cut[i] = str[i];
		i++;
	}
	cut[i] = 0;
	return (cut);
}
