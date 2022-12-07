#include "stdio.h"
#include "math.h"

int main()
{
    double x = 0.5, y = 8.1, z = 1.2;

    // printf("Iveskite tris realius skaicius: ");
    // while ((scanf("%lf%lf%lf", &x, &y, &z) != 3) && (getchar() != '\n'))
    // {
    //     scanf("%*[^\n]");
    //     printf("Iveskite tris realius skaicius: ");
    // }

    double firstSum = x + 4 * y + z * z * z;
    double secondSum = (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3);

    printf("%f\n%f", firstSum, secondSum);
    return 0;
}