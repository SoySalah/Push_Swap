/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdesala <abdesala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:59:46 by abdesala          #+#    #+#             */
/*   Updated: 2026/01/25 15:18:25 by abdesala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *argv[])
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while ((argv[i][j] && argv[i][j] == ' ') || (argv[i][j] >= '\t'
					&& argv[i][j] <= '\r'))
				j++;
			if (argv[i][j])
			{
				count++;
				while (argv[i][j] && !(argv[i][j] == ' ' || (argv[i][j] >= '\t'
							&& argv[i][j] <= '\r')))
					j++;
			}
		}
		i++;
	}
	return (count);
}

static int	words_len(char *str, int j)
{
	int	count;

	count = 0;
	while (str[j] && !(str[j] == ' ' || (str[j] >= '\t' && str[j] <= '\r')))
	{
		count++;
		j++;
	}
	return (count);
}

static int	im_splitting(char **result, char *str, int j, int x)
{
	int	k;

	if (str[j])
	{
		result[x] = malloc(words_len(str, j) + 1);
		if (!result[x])
		{
			free_func(result);
			return (0);
		}
		k = 0;
		while (str[j] && str[j] != ' ' && (!(str[j] >= '\t' && str[j] <= '\r')))
			result[x][k++] = str[j++];
		result[x][k] = '\0';
	}
	return (j);
}

static int	string(char **result, char *str, int x)
{
	int	j;

	j = 0;
	while (str[j])
	{
		while ((str[j] && str[j] == ' ') || (str[j] >= '\t' && str[j] <= '\r'))
			j++;
		if (str[j])
		{
			j = im_splitting(result, str, j, x);
			if (!j)
				return (0);
			x++;
		}
	}
	return (x);
}

char	**ft_split(char *argv[])
{
	char	**result;
	int		i;
	int		x;

	result = malloc((count_words(argv) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 1;
	x = 0;
	while (argv[i])
	{
		x = string(result, argv[i], x);
		if (!x)
			return (0);
		i++;
	}
	result[x] = NULL;
	return (result);
}
