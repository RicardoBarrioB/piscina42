
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

int ft_find_next_prime(int nb)
{
    while (1)
    {
         if(ft_find_next_prime(nb) == 1)
            return (nb);
        nb++;
    }
}
