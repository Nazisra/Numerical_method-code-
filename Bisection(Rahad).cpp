#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int x;

double equation(double x);

void bisectionMethod(double a, double b, double decimalplace) {
    double fa = equation(a);
    double fb = equation(b);

    if (fa * fb >= 0) {
        cout << "error..............put correct value of a and b" << endl;
        return;
    }

    double c = a;
    double prev_c = 0;
    cout << setw(5) << "Iter" << setw(15) << "a" << setw(15) << "b"
         << setw(15) << "equation(a)" << setw(15) << "equation(b)"
         << setw(15) << "c" << setw(15) << "equation(c)" << endl;

    int it = 0;

    while (true) {
        fa = equation(a);
        fb = equation(b);
        
        c = (a + b) / 2.0;
        double fc = equation(c);

        cout << setw(5) << it + 1 << setw(15) << a << setw(15) << b
             << setw(15) << fixed << setprecision(5) << fa << setw(15) << fixed << setprecision(5) << fb
             << setw(15) << fixed << setprecision(x + 1) << c << setw(15) << fixed << setprecision(x + 1) << fc << endl;

        if (fabs(fc) <= decimalplace || fabs(c - prev_c) <= decimalplace) {
            cout << "The root is approximately near to : " << fixed << setprecision(4) << c << endl;
            return;
        }

        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }

        prev_c = c;
        it++;
    }
}

double equation(double x) {
    
    return x*exp(x)-1;
}

int main() {
    cout << "Please put the range of a and b: ";
    double a, b;
    cin >> a >> b;
    cout << "put the decimal place: ";
    cin >> x;

    double decimalplace;

    if (equation(b) >= 0 && equation(a) < 0) {
        swap(a, b);
    }
    if (x == 3) {
        decimalplace = 0.001;
    } else if (x == 4) {
        decimalplace = 0.0001;
    } else if (x == 5) {
        decimalplace = 0.00001;
    }

    bisectionMethod(a, b, decimalplace);

    return 0;
}
