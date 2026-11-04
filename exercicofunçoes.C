#include <stdio.h>
#include <math.h>

//Questao 2

int calcula_raizes(float a, float b, float c, float *x1, float *x2)
{
    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        return 0;
    }
    else if (delta == 0) {
        *x1 = -b / (2 * a);
        *x2 = *x1;
        return 1;
    }
    else {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
        return 2;
    }
}

int main()
{
    float a, b, c, x1, x2;
    int n;

    printf("Digite a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    n = calcula_raizes(a, b, c, &x1, &x2);

    if (n == 0)
        printf("A equacao nao possui raizes reais.\n");
    else if (n == 1)
        printf("A equacao possui 1 raiz real: x = %.2f\n", x1);
    else
        printf("A equacao possui 2 raizes reais: x1 = %.2f e x2 = %.2f\n", x1, x2);

    return 0;
}

//Obs: não consegui concluir a questao 3 e 4 a tempo.
