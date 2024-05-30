
void aux(int prohi[10], int colocadas[10], int *cont)
{
    int index;
    int posi;
    int index2;

    posi = 0;
    index = 0;
    index2 = 0;
    while (prohi[index])
    {
        if(index % 2 != 0)
            prohi[index]++;
        index++;
    }
    while (posi < 10)
    {
        index = 0;
        while(prohi[index] && posi != prohi[index])
            index++;
        if(prohi[index])
            while(colocadas[index2])
                index2++;
            colocadas[index2] = posi + '0';
            prohi[index++] = posi;
            prohi[index] = posi; 
            aux(prohi, colocadas, cont);
        posi++;
    }
    write(1, colocadas, 9);
    (*cont)++;
}

int ft_ten_queens_puzzle(void)
{
    int cont;
    int prohi [10];
    int colocadas [10]

    cont = 0;
    aux(prohi, colocadas, &cont);
   
   return (cont);
}