#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--){
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int a1 = y1 - y2;
        int b1 = x2 - x1;
        int c1 = x1*a1 + y1*b1;
        int a2 = y3 - y4;
        int b2 = x4 - x3;
        int c2 = x3*a2 + y3*b2;
        int A = a1*b2 - a2*b1;
        int B = c1*b2 - c2*b1;
        int C = a1*c2 - a2*c1;

        if(!A and (B or C)) printf("NONE\n");
        else if(!A and !B and !C) printf("LINE\n");
        else{
            printf("POINT %.2f %.2f\n",(double)B/A,(double)C/A);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
