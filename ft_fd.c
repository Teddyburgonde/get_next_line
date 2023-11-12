#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int dividend;
    int diviser;

    dividend = 10;
    diviser = 0;
    if (diviser == 0)
    {
        write(1, "Erreur : Division par zéro.\n", 27);
        perror("details de l'erreur");
        return (EXIT_FAILURE);
    }
    int result = dividend / diviser;
    printf("%d", result);
    //return (EXIT_SUCCESS);

}