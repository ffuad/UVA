#include <iostream>

using namespace std;

#define x first
#define y second

int main()
{
    pair<double,double> c1,c2,c3,c4,ans;
    while(cin>>c1.x>>c1.y>>c2.x>>c2.y>>c3.x>>c3.y>>c4.x>>c4.y)
    {
        if(c2 == c3){
            ans.x = (c4.x+c1.x) - c2.x;
            ans.y = (c4.y+c1.y) - c2.y;
        }
        else if(c3 == c1){
            ans.x = (c2.x+c4.x) - c1.x;
            ans.y = (c2.y+c4.y) - c1.y;
        }
        else if(c4 == c1){
            ans.x = (c2.x+c3.x) - c1.x;
            ans.y = (c2.y+c3.y) - c1.y;
        }
        else{
            ans.x = (c1.x+c3.x) - c2.x;
            ans.y = (c1.y+c3.y) - c2.y;
        }
        printf("%.3f %.3f\n",ans.x,ans.y);
    }
    return 0;
}
