
#include <stdio.h>
#include <math.h>

#define SQR(X) ((X) * (X))

const double EPSILON = 1.0e-16;

double calc_new_phi(double phi)
{

    return 1.0 + 1.0 / phi;
}

double calc_phi_non_recusively()
{
    double phi = 1.0;
    double new_phi;
    double error = 10.0;
    int depth = 0;

    while (error > EPSILON)
    {
        depth++;
        new_phi = calc_new_phi(phi);
        error = fabs(new_phi - phi);
        phi = new_phi;
        printf("%0.16lf, depth = %i\n", phi, depth);
    }
    return phi;
}

double calc_phi_recursively(int depth)
{
    if (depth > 40)
    {
        return 1;
    }
    else
    {
        double new_phi = 1.0 + 1.0 / (calc_phi_recursively(depth + 1));
        printf("newphi = %0.16lf, depth = %i\n", new_phi, depth);
        return (new_phi);
    }
}

int main()
{
    double phi1 = calc_phi_non_recusively();
    printf("\npow((2 * phi1 - 1),2) = %0.16lf\n\n", SQR(2.0 * phi1 - 1.0));

    double phi2 = calc_phi_recursively(0);
    printf("\npow((2 * phi2 - 1),2) = %0.16lf\n", SQR(2.0 * phi2 - 1.0));
}
