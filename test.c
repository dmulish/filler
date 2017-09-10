#include "filler.h"

int		main(void)
{
	int x = 2;
	int y = 10;
	char	*res;

	res = (char*)malloc((sizeof(char) * (ft_strlen(ft_itoa(x))
		+ ft_strlen(ft_itoa(y)) + 2)) + 1);
	res = ft_strdup(ft_itoa(x));
	printf("\"%s\"\n", res);
	res = ft_strcat(ft_strcat(ft_strcat(res, " "), ft_itoa(y)), "\n");
	printf("\"%s\"\n", res);
	return (0);
}
