#include "tree.h"

void	sub_redir(t_node_content *content, t_token_id in_out, char *file_name)
{
	t_redirection *redir;

	if (in_out == e_HERE_DOC || in_out == e_IN_FILE_TRUNC)
		direction = &content->in_redir;
	else
		direction = &content->out_redir;
	ft_free(redir->file_name);
	redir->file_name = ft_strdup(file_name);
	if (in_out == e_IN_OUT_FILE_APPEND)
		redir->append_mode = e_true;
	else
		redir->append_mode = e_false;
}
