#include "minirt.h"

//dont forget to procect every read from a tabl

int manage_ambiant(char **tab, t_options *data)
{
    char    **rgb;
    int     i;

    i = 0;
    if (data->amli.init == 1)
        return (1); //error ambiant light already init
    data->amli.ratio = ft_atof(tab[1]);
    if (data->amli.ratio < 0.0 || data->amli.ratio > 1.0)
        exit(EXIT_FAILURE);
    rgb = ft_split(tab[2], ',');
    while (rgb[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    data->amli.r = ft_atoi(rgb[0]);
    data->amli.g = ft_atoi(rgb[1]);
    data->amli.b = ft_atoi(rgb[2]);
    //rajouter un check entre 0 et 255;
    free_tabl(rgb);
    data->amli.init = 1;
    // printf("oh : %f\n", data->amli.ratio);
    // printf("RGB : %d,%d,%d\n", data->amli.r, data->amli.g, data->amli.b);
    return (0);
}

int manage_cam(char **tab, t_options *data)
{
    char    **xyz;
    int     i;

    i = 0;
    if (data->cam.init == 1)
        return (1); //error cam already init
    xyz = ft_split(tab[1], ',');
    //protect malloc
    while (xyz[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    data->cam.x_ax = ft_atof(xyz[0]);
    data->cam.y_ax = ft_atof(xyz[1]);
    data->cam.z_ax = ft_atof(xyz[2]);
    //check for range here 
    free_tabl(xyz);
    xyz = ft_split(tab[2], ',');
    //protect malloc
    i = 0;
    while(xyz[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    data->cam.vec_x = ft_atof(xyz[0]);
    data->cam.vec_y = ft_atof(xyz[1]);
    data->cam.vec_z = ft_atof(xyz[2]);
    //check range
    data->cam.fov = ft_atoi(tab[3]);
    //check range
    data->cam.init = 1;
    return (0);
}

int manage_light(char **tab, t_options *data)
{
    char    **rgb;
    int     i;

    i = 0;
    if (data->light.init == 1)
        return (1); //error light aleardy init
    rgb = ft_split(tab[1], ',');
    //protect malloc
    while (rgb[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    data->light.x_ax = ft_atof(rgb[0]);
    data->light.y_ax = ft_atof(rgb[1]);
    data->light.z_ax = ft_atof(rgb[2]);
    free_tabl(rgb);
    data->light.lighting = ft_atof(tab[2]);
    data->light.init = 1;
    return (0);
}

int manage_sphere(char **tab, t_options *data)
{
    char    **xyz;
    int     i;
    t_sphere    *new_sphere;
    t_sphere    *temp;

    i = 0;
    new_sphere = malloc(sizeof(t_sphere));
    xyz = ft_split(tab[1], ',');
    //malloc prot
    while (xyz[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    new_sphere->x_ax = ft_atof(xyz[0]);   
    new_sphere->y_ax = ft_atof(xyz[1]);
    new_sphere->z_ax = ft_atof(xyz[2]);
    free_tabl(xyz);
    new_sphere->diameter = ft_atof(tab[2]);
    //check value
    xyz = ft_split(tab[3], ',');
    // prot malloc 
    i = 0;
    while (xyz[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    new_sphere->r = ft_atoi (xyz[0]);
    new_sphere->g = ft_atoi (xyz[1]);
    new_sphere->b = ft_atoi (xyz[2]);
    new_sphere->next = NULL;
    free_tabl(xyz);
    if (data->sphere == NULL)
        data->sphere = new_sphere;
    else
    {
        temp = data->sphere;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_sphere;
    }
    return (0);
}

int manage_plan(char **tab, t_options *data)
{  
    char    **xyz;
    int     i;
    t_plan    *new_plan;
    t_plan    *temp;

    i = 0;
    new_plan = malloc(sizeof(t_sphere));
    xyz = ft_split(tab[1], ',');
    //malloc prot
    while (xyz[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    new_plan->x_ax = ft_atof(xyz[0]);   
    new_plan->y_ax = ft_atof(xyz[1]);
    new_plan->z_ax = ft_atof(xyz[2]);
    free_tabl(xyz);
    //check value
    xyz = ft_split(tab[2], ',');
    i = 0;
    while (xyz[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    new_plan->vec_x = ft_atoi (xyz[0]);
    new_plan->vec_y = ft_atoi (xyz[1]);
    new_plan->vec_z = ft_atoi (xyz[2]);
    free_tabl(xyz);
    xyz = ft_split(tab[3], ',');
    // prot malloc 
    i = 0;
    while (xyz[i])
        i++;
    if (i != 3)
        exit(EXIT_FAILURE);
    new_plan->r = ft_atoi (xyz[0]);
    new_plan->g = ft_atoi (xyz[1]);
    new_plan->b = ft_atoi (xyz[2]);
    new_plan->next = NULL;
    free_tabl(xyz);
    if (data->plan == NULL)
        data->plan = new_plan;
    else
    {
        temp = data->plan;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_plan;
    }
    return (0);    
}