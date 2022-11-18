/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:43:48 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/18 16:43:48 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

size_t	here_docs_count(char *cmd)
{
	size_t	here_docs;
	size_t	i;

	here_docs = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] == '<')
		{
			if (cmd[i + 2] == '<')
				return (0);
			here_docs++;
		}
		i++;
	}
	return (here_docs);
}

static char	*take_next_delimiter(char *cmd, size_t offset)
{
	char	*deli;
	size_t	deli_len;

	offset = skip_consecutive_chars(cmd, offset, ' ', +1);
	deli_len = hdoc_read_file_name(cmd, offset);
	deli = ft_strcpy(NULL, cmd + offset, deli_len);
	return (deli);
}

char	**here_doc_take_delimiters(char *cmd)
{
	size_t	i;
	size_t	j;
	size_t	here_docs;
	char	**here_docs_delimiters;

	here_docs = here_docs_count(cmd);
	if (here_docs == 0)
		return (NULL);
	here_docs_delimiters = (char **) malloc((here_docs + 1) * sizeof(char *));
	here_docs_delimiters[here_docs] = NULL;
	j = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] == '<'
			&& cmd[i + 2] != '<')
		{
			i = skip_consecutive_chars(cmd, (i + 2), ' ', +1);
			here_docs_delimiters[j] = take_next_delimiter(cmd, i);
			j++;
		}
		else
			i++;
	}
	return (here_docs_delimiters);
}