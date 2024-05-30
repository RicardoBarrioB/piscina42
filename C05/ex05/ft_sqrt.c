
int ft_sqrt(int nb)
{
    int n;

    n = 1;
    while (n <= nb)
    {
        if(n * n == nb)
            return (n);
    }

    return (0);
}