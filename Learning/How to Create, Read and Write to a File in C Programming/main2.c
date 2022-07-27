#include <stdio.h>

int	counter()
{
	static int	i = 3;
	// int	i = 3;
	i++;
	return i;
}

int	main(void)
{
	int	i;
	// i = 0
	printf("%d\n",counter());
	printf("%d\n",counter());
	printf("%d\n",counter());
	return 0;
}
