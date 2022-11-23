#include "../utils.h"

size_t	ft_word_len(char *word)
{
	size_t	i;

	i = 0;
	while (word[i])
	{
		if (char_is_alpha(word[i]) == 0)
			return (i);
		++i;
	}
	return (i);
}
