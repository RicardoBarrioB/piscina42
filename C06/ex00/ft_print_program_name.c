
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int index;

    index = 0;
    while(argv[0][index])
    {
        ft_putchar(argv[0][index]);
        index++;
    }

    return (0);
}