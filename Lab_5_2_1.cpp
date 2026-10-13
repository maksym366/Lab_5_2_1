// 1-й спосіб: void-функції
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s;
    int n;

    cout << "Enter xp = ";
    cin >> xp;
    cout << "Enter xk = ";
    cin >> xk;
    cout << "Enter dx = ";
    cin >> dx;
    cout << "Enter eps = ";
    cin >> eps;

    cout << fixed;
    cout << "---------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |"
        << setw(14) << "ln(1-x)" << " |"
        << setw(14) << "Sum" << " |"
        << setw(8) << "n" << " |" << endl;
    cout << "---------------------------------------------------" << endl;

    x = xp;

    while (x <= xk)
    {
        if (x > -1 && x < 1)
        {
            S(x, eps, n, s);

            cout << "|" << setw(8) << setprecision(3) << x << " |"
                << setw(14) << setprecision(6) << log(1 - x) << " |"
                << setw(14) << setprecision(6) << s << " |"
                << setw(8) << n << " |" << endl;
        }
        else
        {
            cout << "|" << setw(8) << setprecision(3) << x
                << " | x out of range (-1, 1)                  |" << endl;
        }

        x += dx;
    }

    cout << "---------------------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = 0;
    s = 0;

    do
    {
        n++;
        A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    if (n == 1)
        a = -x;
    else
        a *= x * (n - 1.0) / n;
}