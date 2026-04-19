#include "codexion.h"

int	is_valid_number(const char *str)
{
	long long	value;
	int			i;

	if (!str || *str == '\0')
		return (FAILURE);
	i = 0;
	value = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FAILURE);
		value = value * 10 + (str[i] - '0');
		if (value > 2147483647LL)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}


int	parse_arguments(int argc, char **argv, t_config *config)
{
	if (argc != 9)
	{
		printf("\033[31mError: Invalid number of arguments\033[0m\n");
		printf("Usage: ./codexion <number_of_coders> <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor> <number_of_compiles_required> <dongle_cooldown> <scheduler>\n");
		return (FAILURE);
	}
	if (is_valid_number(argv[1]) == FAILURE
		|| is_valid_number(argv[2]) == FAILURE
		|| is_valid_number(argv[3]) == FAILURE
		|| is_valid_number(argv[4]) == FAILURE
		|| is_valid_number(argv[5]) == FAILURE
		|| is_valid_number(argv[6]) == FAILURE
		|| is_valid_number(argv[7]) == FAILURE)
	{
		printf("\033[31mError: Invalid numeric argument\033[0m\n");
		return (FAILURE);
	}
	if (strcmp(argv[8], "fifo") != 0 && strcmp(argv[8], "edf") != 0)
	{
		printf("\033[31mError: Scheduler must be 'fifo' or 'edf'\033[0m\n");
		return (FAILURE);
	}
	config->number_of_coders = atoi(argv[1]);
	config->time_to_burnout = atoi(argv[2]);
	config->time_to_compile = atoi(argv[3]);
	config->time_to_debug = atoi(argv[4]);
	config->time_to_refactor = atoi(argv[5]);
	config->number_of_compiles_required = atoi(argv[6]);
	config->dongle_cooldown = atoi(argv[7]);
	if (strcmp(argv[8], "fifo") == 0)
		config->scheduler = FIFO;
	else
		config->scheduler = EDF;
	return (SUCCESS);
}
