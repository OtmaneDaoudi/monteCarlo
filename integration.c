#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(int x)
{
    return log(x);
}

double monteCarloIntegraation(double a, double b, double c, int dataPoints)
{
    double squareArea = (b - a) * c;
    double proportion = 0;

    // random data points
    for (int i = 0; i < dataPoints; i++)
    {
        double x = a + ((double)rand() / RAND_MAX) * (b - a);
        double y = ((double)rand() / RAND_MAX) * c;

        if (y <= f(x))
            proportion++;
    }

    return proportion / dataPoints * squareArea;
}

int main(int argc, char **argv)
{
    double a = atof(argv[1]), b = atof(argv[2]), c = atof(argv[3]);
    int dataPoints = atoi(argv[4]);
    printf("%d data points generated\n", dataPoints);
    double res = monteCarloIntegraation(a, b, c, dataPoints);
    printf("approx integral value over a = %lf and b = %lf with max bound c = %lf is : %lf\n", a, b, c, res);
}