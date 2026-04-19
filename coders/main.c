#include "codexion.h"


int	main(int argc, char **argv)
{
	t_config	config;

	if (parse_arguments(argc, argv, &config) == FAILURE)
		return (FAILURE);

	return (SUCCESS);
}
