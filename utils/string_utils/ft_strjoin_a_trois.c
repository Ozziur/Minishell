#include "../utils.h"

char	*ft_strjoin_a_trois(char *s1, char *s2, char *s3,
				t_bool free1, t_bool free2, t_bool free3)
{
	return (ft_strjoin(
				s1,
				ft_strjoin(
						s2,
						s3,
						free2,
						free3
					),
				free1, e_true)
		);
}
