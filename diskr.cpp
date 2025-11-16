#include<iostream>
#include<iomanip>
#include<cmath>

#define VERSION_MAJOR 3
#define VERSION_MINOR 0

void start(double *mass);
int print(double *mass);
double calculate_discriminant(const double *mass);
void print_X12(double *mass, double discriminant);
void printX(double *mass, double discriminant);

int main()
{
    std::cout.precision(3); 
        std::cout << std::fixed; 

    // parametrs
    double mass[3]{0,0,0} ;
        double discriminant;

    start(mass);
       
    if (print(mass) == 0)
    {
        system("pause");
        return 0;
    }

        discriminant = calculate_discriminant(mass);
            if (discriminant == 0)
            {
                printX(mass,discriminant);
                    system("pause");
                        return 0;
            }
                
    print_X12(mass,discriminant);
        system("pause");

    return 0;
}

void start(double *mass)
{
    std::cout << "enter num A" << std::endl;
        std::cin >>  mass[0];

    std::cout << "enter num B" << std::endl;
        std::cin >> mass[1];

    std::cout << "enter num C" << std::endl;
        std::cin >> mass[2];

     system("cls");

    std::cout << "parametr numbers" << std::endl;
        for (size_t i = 0; i < 3; i++)
        {
            std::cout << char(65 + i) << ' ' <<mass[i] << '\t' ; }
                std::cout << std::endl;
}

int print(double *mass)
{
    std::cout << "formula" << std::endl;
        std::cout << "D = (b*b) -(4*a*c)"; 

    double discriminant_B = (mass[1] * mass[1]) - (4 * mass[0] * mass[2]) ;
        std::cout << " | D = " << discriminant_B << "\n" ; 

    if (discriminant_B >= 0) {
        std::cout << "Roots exist.\n";
            return 1;}

    else { std::cout << "No real roots.\n";
        return 0;}
}

double calculate_discriminant(const double *mass) {
    return (mass[1] * mass[1]) - 4 * mass[0] * mass[2];
}

void print_X12(double *mass, double discriminant)
{
    double X_1, X_2;

    std::cout << "formula" << std::endl;
        std::cout << " (-b +- (root D) / 2* a)\n" ;

        std::cout << -mass[1] << " + " << sqrt(discriminant) << " / 2 * " << mass[0] << std::endl;  
            std::cout << -mass[1] << " - " << sqrt(discriminant) << " / 2 * " << mass[0] << std::endl;

    X_1 = (-mass[1] + sqrt(discriminant)) / (2 * mass[0]);
        X_2 = (-mass[1] - sqrt(discriminant)) / (2 * mass[0]);

    std::cout << "X1 = | " << X_1 << " |\n" ;
        std::cout << "X2 = | " << X_2 << " |\n" ;
}

void printX(double *mass, double discriminant)
{
    std::cout << "formula" << std::endl;
        std::cout << "x = -b / 2a" << " |  | " << "x = " << -mass[1] << "/ 2*" << mass[0] << '\n';

    std::cout << "X = |" << (-mass[1] / (2*mass[0])) << " | \n" ;
}