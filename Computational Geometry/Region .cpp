#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second


int main()
{
    int n;
    cin>>n;
    while(n--){
        double r1,r2,r3;
        cin >> r1 >> r2 >> r3;

        double a1,a2,a3;

        a1 = r1*r1*acos(1-(2*r2*r3)/((r1+r2)*(r1+r3)));
        a2 = r2*r2*acos(1-(2*r1*r3)/((r1+r2)*(r2+r3)));
        a3 = r3*r3*acos(1-(2*r1*r2)/((r3+r1)*(r3+r2)));

        double t = sqrtl(r1*r2*r3*(r1+r2+r3));
        double ans = t-.5*(a1+a2+a3);

        printf("%.6f\n",ans);
    }
    return 0;
}
