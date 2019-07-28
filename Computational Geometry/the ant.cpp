#include<bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y;
};
struct stick
{
    Point a,b;
};

int root[1001];

int Find(int u) {
	if(u!=root[u]) root[u] = Find(root[u]);
	return root[u];
}
void link(int u, int v) {
	root[u] = root[v];
}

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool intersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int m,n;
        cin>>n>>m;
        stick s[n+5];
        for(int i=1;i<= n;i++)
        {
            root[i] = i;
            scanf("%d%d%d%d",&s[i].a.x,&s[i].a.y,&s[i].b.x,&s[i].b.y);
        }
        int u,v;
        for(int i = 1; i <= n; i++) {
			for(int j = 1; j < n; j++) {
				u = Find(i);
				v = Find(j);
				//cout<<"u "<<u<<" v "<<v<<endl;
				if(u != v && intersect(s[i].a, s[i].b, s[j].a, s[j].b)) link(u, v);
                //cout<<intersect(s[i].a, s[i].b, s[j].a, s[j].b)<<endl;
			}
		}
		int x,y;
        for(int i=0;i<m;i++) {
            scanf("%d %d",&x,&y);
            u = Find(x);
            v = Find(y);
            //cout<<"u "<<u<<" v "<<v<<endl;
            if(u == v) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
