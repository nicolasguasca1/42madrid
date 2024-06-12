#include <stdlib.h>
#include <stdio.h>

// Prototipo de ft_split
char	**ft_split(char *str, char *charset);

// Función auxiliar para imprimir la tabla de cadenas resultante
void	print_split_result(char **split_result)
{
	while (*split_result)
	{
		printf("%s\n", *split_result);
		split_result++;
	}
}

int	main(void)
{
	// Cadena de entrada y caracteres separadores
	char str[] = "Hola,mundo!Este,es,un,ejemplo";
	char charset[] = ",!";

	// Llamada a la función ft_split
	char **result = ft_split(str, charset);

	// Imprimir el resultado
	if (result)
	{
		print_split_result(result);
	}
	else
	{
		printf("Error al dividir la cadena.\n");
	}

	// Liberar la memoria asignada
	char **temp = result;
	while (*temp)
		free(*temp++);
	free(result);

	return (0);
}
