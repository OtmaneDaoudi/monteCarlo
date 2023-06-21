#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// pi approximation using monte carlo integration
double pi(int dataPoints)
{
    // area of circle = pi * r²
    // use unit circle to get get area = pi
    // area of enclosing square = 2 * 2 = 4

    double proportion = 0;
    for (int i = 0; i < dataPoints; i++)
    {
        // generate random data points within the square
        double x = -1.0 + (2.0 * rand()) / (RAND_MAX + 1);
        double y = -1.0 + (2.0 * rand()) / (RAND_MAX + 1);

        // check if the point is inside the circle
        if (sqrt(x * x + y * y) <= 1)
            proportion++;
    }

    return proportion / dataPoints * 4;
}

int main(int atgc, char **argv)
{
    printf("data points : %d\n", atoi(argv[1]));
    printf("pi = %lf\n", pi(atoi(argv[1])));
}