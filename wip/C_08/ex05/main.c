#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

int main(void)
{
	char *av[] = {"Hello", "world", "42", "Piscine"};
	struct s_stock_str *tab;
	int	i;

	tab = ft_strs_to_tab(4, av);
	if (tab != NULL)
	{
		ft_show_tab(tab);
		i = 0;
		while (i < 4)
		{
			free(tab[i].copy);
			i++;
		}
		free(tab);
	}
	return (0);
}
