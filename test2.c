#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void*	routine1(void* x)
{
	int	*value = (int*)x;
	x++;
	sleep(2);
	printf("value of x in routine1 = %d\n", *value);
	return (NULL);
}

void*	routine2(void *x)
{
	int	*value = (int*)x;
	printf("value of x in routine2 = %d\n", *value);
	return (NULL);
}
int	main(int c, char **v)
{
	int	x = 1;
	pthread_t t1;
	pthread_t t2;

	if (pthread_create(&t1, NULL, &routine1, &x))
		return (1);
	if (pthread_create(&t2, NULL, &routine2, &x))
		return (2);
	if (pthread_join(t1, NULL))
		return (3);
	if (pthread_join(t2, NULL))
		return (4);

	printf("value of x in main function = %d\n", x);
	return (0);
}
