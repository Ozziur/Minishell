/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:18:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/18 16:18:38 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

static t_status	here_doc_read_current(char **delimiter, char *hdoc_file_name)
{
	t_status	outcome;
	pid_t		hdoc_prompt_pid;
	int			hdoc_prompt_exit_status;
	char		delimiter_enclosing_quote;

	hdoc_prompt_pid = fork();
	if (!hdoc_prompt_pid)
	{
		expand_delimiter_take_quote(delimiter, &delimiter_enclosing_quote);//da creare
		here_doc_prompt(CONTINUE, delimiter_enclosing_quote,// da creare
			*delimiter, hdoc_file_name);
	}
	waitpid(hdoc_prompt_pid, &hdoc_prompt_exit_status, 0);
	if (!WIFEXITED(hdoc_prompt_exit_status)
		|| WEXITSTATUS(hdoc_prompt_exit_status))
		outcome = ERROR;
	else
		outcome = OK;
	free(hdoc_file_name);
	return (outcome);
}

t_status	here_doc_read(char *cmd)
{
    t_status    outcome;
    char        **here_doc_delim;
    size_t      hdoc_count;
    int         cur_hdoc_rev_id;

    hdoc_count = here_doc_count(cmd);
    if (hdoc_count == 0)
        return (OK);
    outcome = OK;
    signal(SIGINT, sig_ign);
    cur_hdoc_rev_id = hdocs_count - 1;
	here_doc_delims = here_doc_take_delimiters(cmd);
    	while (cur_hdoc_rev_id > -1)
	{
		outcome = here_doc_read_current(
				&here_doc_delims[cur_hdoc_index(hdoc_count, cur_hdoc_rev_id)],// da creare
				hdoc_next_file_name()// da creare
				);
		cur_hdoc_rev_id--;
		if (outcome == ERROR)
			break ;
	}
	ft_splitclear(here_doc_delims);
	return (outcome);
}