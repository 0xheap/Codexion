#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define SUCCESS 0
# define FAILURE 1

/* ==================== STRUCTURES ==================== */

typedef enum e_scheduler
{
	FIFO = 0,
	EDF = 1
}	t_scheduler;

typedef struct s_config
{
	int				number_of_coders;
	int				time_to_burnout;
	int				time_to_compile;
	int				time_to_debug;
	int				time_to_refactor;
	int				number_of_compiles_required;
	int				dongle_cooldown;
	t_scheduler		scheduler;
}	t_config;

/* ==================== PROTOTYPES ==================== */

int		is_valid_number(const char *str);
int		parse_arguments(int argc, char **argv, t_config *config);

#endif
