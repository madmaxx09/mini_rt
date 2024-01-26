/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:14:58 by mdor              #+#    #+#             */
/*   Updated: 2024/01/26 10:50:44 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "./LIBFT/libft.h"
//# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 666
# endif


typedef struct s_cyl
{
	float	x_cent;
	float	y_cent;
	float	z_cent;
	float	vec_x;
	float	vec_y;
	float	vec_z;
	float	diameter;
	float	height;
	int		r;
	int		g;
	int		b;
	struct s_cyl	*next;
}   t_cyl;

typedef struct s_plan
{
	float	x_ax;
	float	y_ax;
	float	z_ax;
	float	vec_x;
	float	vec_y;
	float	vec_z;
	int		r;
	int		g;
	int		b;
	struct s_plan	*next;
}   t_plan;

typedef struct s_sphere
{
	float	x_ax;
	float	y_ax;
	float	z_ax;
	float	diameter;
	int		r;
	int		g;
	int		b;
	struct	s_sphere	*next;
}   t_sphere;

typedef struct s_light
{
	float	x_ax;
	float	y_ax;
	float	z_ax;
	float	lighting;
	int		init;
	//optionnal rgb
}   t_light;

typedef struct s_cam
{
	float	x_ax;
	float	y_ax;
	float	z_ax;
	float	vec_x;
	float	vec_y;
	float	vec_z;
	int		fov;
	int		init;
}   t_cam;

typedef struct s_amli
{
	float	ratio;
	int		r;
	int		g;
	int		b;
	int		init;
}   t_amli;


typedef struct s_options
{
    t_amli		amli;
    t_cam		cam;
    t_light		light;
    t_sphere	*sphere;
    t_plan		*plan;
    t_cyl		*cyl;
	void		*mlx;
	void		*wind;
}   t_options;


/*Parse data*/

void	parse_rt(char *rt_file, t_options *data);
int	process_line(char *line, t_options *data);
int manage_ambiant(char **tab, t_options *data);

int manage_cam(char **tab, t_options *data);
int manage_light(char **tab, t_options *data);
int manage_sphere(char **tab, t_options *data);
int manage_plan(char **tab, t_options *data);
int manage_cyl(char **tab, t_options *data);



/*Error and other utils*/

int		free_tabl_ret1(char **tabl);
void	free_tabl(char **tabl);
float	ft_atof(char *str);
void	print_args(t_options *data);



#endif
