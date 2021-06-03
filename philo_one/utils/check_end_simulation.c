#include "../philo_one.h"

int     check_end_simulation(t_struct *data)
{
    if (data->info.time_stop_simulation && data->info.time_stop_simulation == data->verif.nb_death)
        return (1);
    else if (!data->info.time_stop_simulation && data->verif.nb_death)
        return (1);
    return (0);
}