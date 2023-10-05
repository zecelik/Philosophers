/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelik <@42kocaeli.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:19:56 by fcelik            #+#    #+#             */
/*   Updated: 2023/08/07 18:19:59 by fcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	valid_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (err_msg("Number of arguments must be 4 or 5.\n"));
	if (unsigned_atoi(av[1]) <= 0)
		return (err_msg("Number of philos must be bigger than 0.\n"));
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (err_msg("Arguments must be digit.\n"));
		i++;
	}
	if (unsigned_atoi(av[1]) > 200)
		return (err_msg("Error!\n"));
	if ((unsigned_atoi(av[2]) < 60 || unsigned_atoi(av[3]) < 60)
		|| unsigned_atoi(av[4]) < 60)
		return (err_msg("Error!\n"));
	return (1);
}

t_table	*parse(int ac, char **av)
{
	t_table	*table;

	if (!valid_check(ac, av))
		return (NULL);
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->number_of_philos = unsigned_atoi(av[1]);
	table->time_to_die = unsigned_atoi(av[2]);
	table->time_to_eat = unsigned_atoi(av[3]);
	table->time_to_sleep = unsigned_atoi(av[4]);
	table->number_of_must_eat = -1;
	if (ac == 6)
		table->number_of_must_eat = unsigned_atoi(av[5]);
	table->philos = malloc(sizeof(t_philo) * table->number_of_philos);
	table->time = current_time();
	table->stop = 0;
	return (table);
}
