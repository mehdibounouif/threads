#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct	s_list
{
	int	value;
	pthread_mutex_t	mutex;
}	t_list;

void	*routine(void *args)
{
	t_list	*list;
	int	i;

	list = (t_list *)args;
	i = 0;
	pthread_mutex_lock(&(list->mutex));
	while (i++ < 100000)
		list->value++;
	pthread_mutex_unlock(&(list->mutex));
}

int	main()
{
	int	i;
	t_list	*list;
	pthread_t	th[4];

	i = 0;
	if (!(list = malloc(sizeof(t_list))))
		return (1);
	pthread_mutex_init(&(list->mutex), NULL);
	while (i < 4)
	{
		if (pthread_create(&th[i], NULL, routine, list))
		{
			printf("thread create failed!\n");
			return (2);
		}
		if (pthread_join(th[i], NULL))
		{
			printf("thread failed execution!\n");
			return (3);
		}
		i++;
	}
	pthread_mutex_destroy(&(list->mutex));
	printf("Value = %d\n", list->value);
	return (0);

}
