#include <stdio.h>
#include <pthread.h>

int	i = 0;

void*	routine()
{
	int	f = 0;
	while (f++ < 100000)
		i++;
	return (NULL);
}

int	main(int c, char **v)
{
	pthread_t t1;
	pthread_t t2;

	if (pthread_create(&t1, NULL, routine, NULL))
		return (1);
	if (pthread_create(&t2, NULL, routine, NULL))
		return (2);
	if (pthread_join(t1, NULL))
		return (3);
	printf("the value of i = %d\n", i);
	if (pthread_join(t2, NULL))
		return (4);
	//printf("the value of i = %d\n", i);
}
