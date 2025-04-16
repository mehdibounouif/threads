#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data
{
	pthread_mutex_t	lock;
	int	start;
	int	end;
}	t_data;

void	*routine(void *args)
{
	t_data	*data;
	int	i;

	data = (t_data*)args;
	i = data->start;
	pthread_mutex_lock(&data->lock);
	while (i < data->end)
		i++;
	pthread_mutex_unlock(&data->lock);
	return ((void*)(long)i);
}

int	main(int c, char **v)
{
	t_data	*data;
	pthread_t threads[3];
	int	i;
	void	*result;

	if (c <= 1)
	{
		fprintf(stderr, "Invalid input!\n");
		return (1);
	}
	if (!(data = malloc(sizeof(t_data))))
		return (1);
	i = 0;
	data->start = atoi(v[1]);
	data->end = atoi(v[2]);
	pthread_mutex_init(&data->lock, NULL);
	while (i < 3)
	{
		if (pthread_create(&threads[i], NULL, routine, data))
		{
			fprintf(stderr, "pthread_create failed\n");
			return (2);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (pthread_join(threads[i], &result))
		{
			fprintf(stderr, "pthread_join failed\n");
			return (3);
		}
		printf("result = %ld\n", (long)result);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	return (0);
}
