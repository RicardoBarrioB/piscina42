
int ft_is_prime(int nb)
{
    int n;
    
    n = nb / 2;
    if(nb <= 1)
        return (0);
    while (n > 1)
    {
        if (nb % n == 0)
            return (0);
        n--;
    }
    return (1);
}
