# include	<stdarg.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<time.h>
# include	<fcntl.h>
# include	"../libft/libft.h"

int main(int argc, char **argv)
{
    int len;
    int *mas;
    int i = 0;
    int j1;
    int j2;
    int buf;

    if (argc != 2)
        return (0);
    len = ft_atoi(argv[1]);
    mas = (int *)malloc(sizeof(int) * len + 1);
	while (i < len)
	{
		mas[i] = i;
		i++;
	}
	mas[i] = -1;
	i = 0;
	srand(time(NULL));
	while (i < len * 10)
	{
	    j1 = rand() % len;
	    j2 = rand() % len;
	    buf = mas[j1];
	    mas[j1] = mas[j2];
	    mas[j2] = buf;
	    i++;
	}
    i = 0;
	int fd = open(".rand_num/res.txt", O_TRUNC);
	close(fd);
	fd = open(".rand_num/res.txt", O_WRONLY);
	if (fd == -1)
	{
		printf("fd error\n");
		exit(0);
	}
    while (mas[i + 1] != -1)
    {
		ft_putnbr_fd(mas[i], fd);
		write(fd, " ", 1);
        printf("%i ", mas[i]);
        i++;
    }
	ft_putnbr_fd(mas[i], fd);
	write(fd, "\n", 1);
    printf("%i\n", mas[i]);
	close (fd);
    //exit(0);
	return (0);
}
