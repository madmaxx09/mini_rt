#include "minirt.h"

int manage_cyl(char **tab, t_options *data)
{
	char	**xyz;
	int		i;
	t_cyl	*new_cyl;
	t_cyl	*temp;

	i = 0;
	new_cyl = malloc(sizeof(t_cyl));
	xyz = ft_split(tab[1], ',');
	//malloc prot
	while (xyz[i])
		i++;
	if (i != 3)
		exit(EXIT_FAILURE);
	new_cyl->x_cent = ft_atof(xyz[0]);
	new_cyl->y_cent = ft_atof(xyz[1]);
	new_cyl->z_cent = ft_atof(xyz[2]);
	free_tabl(xyz);
	xyz = ft_split(tab[2], ',');
	//malloc prot
	i = 0;
	while (xyz[i])
		i++;
	if (i != 3)
		exit(EXIT_FAILURE);
	new_cyl->vec_x = ft_atof(xyz[0]);
	new_cyl->vec_y = ft_atof(xyz[1]);
	new_cyl->vec_z = ft_atof(xyz[2]);
	free_tabl(xyz);
	//check value must be between -1 and 1
	printf("dia : %s\n", tab[3]);
	new_cyl->diameter = ft_atof(tab[3]);
	new_cyl->height = ft_atof(tab[4]);
	xyz = ft_split(tab[5], ',');
	//malloc prot
	i = 0;
	while (xyz[i])
		i++;
	new_cyl->r = ft_atoi(xyz[0]);
	new_cyl->g = ft_atoi(xyz[1]);
	new_cyl->b = ft_atoi(xyz[2]);
	new_cyl->next = NULL;
	free_tabl(xyz);
	//check value between 0 et 255
	if (data->cyl == NULL)
		data->cyl = new_cyl;
	else
	{
		temp = data->cyl;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_cyl;		
	}
	return (0);
}