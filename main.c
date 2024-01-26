/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:19:11 by mdor              #+#    #+#             */
/*   Updated: 2024/01/26 10:42:08 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	process_line(char *line, t_options *data)
{
	char	**tab;
	int		error;

	error = 0;
	tab = ft_split(line, ' ');
	if (ft_strcmp(tab[0], "A") == 0)
		error = manage_ambiant(tab, data);
	else if (ft_strcmp(tab[0], "C") == 0)
		error = manage_cam(tab, data);
	else if (ft_strcmp(tab[0], "L") == 0)
		error = manage_light(tab, data);
	else if (ft_strcmp(tab[0], "sp") == 0)
		error = manage_sphere(tab, data);
	else if (ft_strcmp(tab[0], "pl") == 0)
		error = manage_plan(tab, data);
	else if (ft_strcmp(tab[0], "cy") == 0)
		error = manage_cyl(tab, data);
	else
		return (free_tabl_ret1(tab));
	free_tabl(tab);
	return (error);
}


void	parse_rt(char *rt_file, t_options *data)
{
	int		fd;
	char	*line;
	int		error;

	error = 0;
	fd = open(rt_file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		error = process_line(line, data);
		free (line);
		if (error == 1)
			break ;
		line = get_next_line(fd);
	}
}

void	init_data(t_options *data)
{
	data->cyl = NULL;
	data->mlx = NULL;
	data->plan = NULL;
	data->sphere = NULL;
	data->wind = NULL;
}

int	main (int argc, char **argv)
{
	t_options	data;

	if (argc != 2)
		return (1);
	init_data(&data);
	parse_rt(argv[1], &data);
	print_args(&data);
}