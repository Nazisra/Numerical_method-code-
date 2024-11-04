#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int x;

double equation(double x);
double derivative(double x);

void newtonRaphsonMethod(double initialGuess, double decimalplace) {
    double x0 = initialGuess;
    double x1;
    int it = 0;

    cout << setw(9) << "Iteration" << setw(12) << "x0" 
         << setw(15) << "f(x0)" << setw(16) << "f'(x0)" 
         << setw(12) << "x1" << setw(16) << "|x1-x0|" << endl;

    while (true) {
        double fx0 = equation(x0);
        double dfx0 = derivative(x0);

        if (dfx0 == 0) {
            cout << "Derivative is zero. No solution found." << endl;
            return;
        }

        x1 = x0 - (fx0 / dfx0);
        
        cout << setw(9) << it + 1 << setw(14) << x0 
             << setw(14) << fixed << setprecision(x+1) << fx0 
             << setw(14) << fixed << setprecision(x+1) << dfx0 
             << setw(14) << fixed << setprecision(x + 1) << x1 
             << setw(14) << fixed << setprecision(x + 1) << fabs(x1 - x0) << endl;

        if (fabs(x1 - x0) <= decimalplace) {
            cout << "The root is approximately near to : " << fixed << setprecision(4) << x1 << endl;
            return;
        }

        x0 = x1;
        it++;
    }
}

double equation(double x) {
    return 3*x-cos(x)-1; 
}

double derivative(double x) {
    return 3+sin(x); 
}

int main() {
    
    cout << "Please put the initial guess: ";
    double initialGuess;
    cin >> initialGuess;
    cout << "put the decimal place: ";
    cin >> x;

    double decimalplace;

    if (x == 3) {
        decimalplace = 0.001;
    } else if (x == 4) {
        decimalplace = 0.0001;
    } else if (x == 5) {
        decimalplace = 0.00001;
    }

    newtonRaphsonMethod(initialGuess, decimalplace);

    return 0;
}
