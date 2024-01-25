#include "minirt.h"

void print_args(t_options *data)
{
    // Print ambient light details
    printf("Ambient Light:\n");
    printf("\tRatio: %f\n", data->amli.ratio);
    printf("\tColor: R: %d, G: %d, B: %d\n", data->amli.r, data->amli.g, data->amli.b);

    // Print camera details
    printf("Camera:\n");
    printf("\tPosition: X: %f, Y: %f, Z: %f\n", data->cam.x_ax, data->cam.y_ax, data->cam.z_ax);
    printf("\tVector: X: %f, Y: %f, Z: %f\n", data->cam.vec_x, data->cam.vec_y, data->cam.vec_z);
    printf("\tFOV: %d\n", data->cam.fov);

    // Print light details
    printf("Light:\n");
    printf("\tPosition: X: %f, Y: %f, Z: %f\n", data->light.x_ax, data->light.y_ax, data->light.z_ax);
    printf("\tLighting: %f\n", data->light.lighting);

    // Print spheres
    printf("Spheres:\n");
    while (data->sphere != NULL) {
        printf("\tPosition: X: %f, Y: %f, Z: %f\n", data->sphere->x_ax, data->sphere->y_ax, data->sphere->z_ax);
        printf("\tDiameter: %f\n", data->sphere->diameter);
        printf("\tColor: R: %d, G: %d, B: %d\n", data->sphere->r, data->sphere->g, data->sphere->b);
        data->sphere = data->sphere->next;
    }

    // Print plans
    printf("Plans:\n");
    t_plan *current_plan = data->plan;
    while (current_plan != NULL) {
        printf("\tPosition: X: %f, Y: %f, Z: %f\n", current_plan->x_ax, current_plan->y_ax, current_plan->z_ax);
        printf("\tVector: X: %f, Y: %f, Z: %f\n", current_plan->vec_x, current_plan->vec_y, current_plan->vec_z);
        printf("\tColor: R: %d, G: %d, B: %d\n", current_plan->r, current_plan->g, current_plan->b);
        current_plan = current_plan->next;
    }

    // // Print cylinders
    // printf("Cylinders:\n");
    // t_cyl *current_cyl = data->cyl;
    // while (current_cyl != NULL) {
    //     printf("\tCenter: X: %f, Y: %f, Z: %f\n", current_cyl->x_cent, current_cyl->y_cent, current_cyl->z_cent);
    //     printf("\tVector: X: %f, Y: %f, Z: %f\n", current_cyl->vec_x, current_cyl->vec_y, current_cyl->vec_z);
    //     printf("\tDiameter: %d\n", current_cyl->diameter);
    //     printf("\tHeight: %d\n", current_cyl->height);
    //     printf("\tColor: R: %d, G: %d, B: %d\n", current_cyl->r, current_cyl->g, current_cyl->b);
    //     current_cyl = current_cyl->next;
    // }
}

// Define your structs and main function if necessary for testing
