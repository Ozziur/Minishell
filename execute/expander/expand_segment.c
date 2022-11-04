#include "expander.h"

char	*expand_segment(char *seg, char *end)
{
	if (*seg == '$')
		expand_dollar(seg, end);
	if (*seg == '*')
		expand_wildcard
