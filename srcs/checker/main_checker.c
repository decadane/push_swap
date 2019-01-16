#include "operations.h"

int		main()
{
	int		a_stack[] = {0, 0, 1, 2, 3, 4};
	int		b_stack[] = {0, 0, 0, 0, 0, 0};

	ft_call_function(a_stack, b_stack, "rra", 6);
	ft_print_stack(a_stack, b_stack, 6);
	return (0);
}
