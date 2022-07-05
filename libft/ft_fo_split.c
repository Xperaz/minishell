/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fo_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:26:37 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/05 02:27:19 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include	"libft.h"

// char	**ft_fo_split(char *string, char separat)
// {
// 	int		f_lenth;
// 	int		word;
// 	int		lenth;
// 	char	**split;

// 	word = 0;
// 	lenth = ft_strlen(string);
// 	f_lenth = lenth - ft_strlen(ft_strchr(string, separat));
// 	if (ft_strchr(string, separat))
// 	{
// 		word++;
// 		if (f_lenth > lenth)
// 			word++;
// 	}
// 	split = (char **)malloc (3 * sizeof(char *));
// 	split[0] = ft_strndup(string, f_lenth);
// 	if (ft_strlen (ft_strchr(string, separat)) == 1)
// 		split[1] = ft_strdup(ft_strchr(string, separat));
// 	else if (ft_strlen (ft_strchr(string, separat)) > 1)
// 	{
// 		split[1] = ft_strdup(ft_strchr(string, separat) + 1);
// 		split[1] = ft_strtrim(split[1], "\"");
// 	}
// 	else
// 		split[1] = "\0";
// 	split[2] = 0;
// 	return(split);
// }