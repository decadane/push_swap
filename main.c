#include "operations.h"

int		main()
{
	int		stackA[] = {0, 0, 1, 2, 3, 4};
	int		stackB[] = {0, 0, 0, 0, 0, 0};

	ft_shift(stackA, 6, 1);
	ft_print_stack(stackA, stackB, 6);
	return (0);
}
