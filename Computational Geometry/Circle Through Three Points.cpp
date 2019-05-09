#include <bits/stdc++.h>

using namespace std;

void print(double d){
    char ch = d < 0 ? '-' : '+';
    printf("%c %.3f", ch, abs(d));

}

int main()
{
    double x1,x2,x3,y1,y2,y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        double A = powl(x1, 2) - powl(x3, 2);

        double B = powl(y1, 2) - powl(y3, 2);

        double C = powl(x2, 2) - powl(x1, 2);
        double D = powl(y2, 2) - powl(y1, 2);

        double f = ((A) * (x1 - x2) + (B) * (x1 - x2) + (C) * (x1 - x3) + (D) * (x1 - x3)) / (2 * ((y3 - y1) * (x1 - x2) - (y2 - y1) * (x1 - x3)));
        double g = ((A) * (y1 - y2) + (B) * (y1 - y2) + (C) * (y1 - y3) + (D) * (y1 - y3)) / (2 * ((x3 - x1) * (y1 - y2) - (x2 - x1) * (y1 - y3)));

        double c = -powl(x1, 2) - powl(y1, 2) - 2 * g * x1 - 2 * f * y1;

        //cout<<"f "<<f<<"g "<<g<<"c "<<c;

        double h = -f, k = -g, r = sqrtl(h * h + k * k - c);

        printf("(x ");
        print(-k);
        printf(")^2 + (y ");
        print(-h);
        printf(")^2 = %.3f^2\n",r);

        printf("x^2 + y^2 ");
        print(2*g);
        printf("x ");
        print(2*f);
        printf("y ");
        print(c);
        printf(" = 0\n\n");
    }
    return 0;
}
