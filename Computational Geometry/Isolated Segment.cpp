#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int x;
	int y;
};

struct seg
{
    Point p1,p2;
};

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

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
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
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        seg s[n];

        for(int i=0; i<n; i++)
        {
            cin>>s[i].p1.x>>s[i].p1.y;
            cin>>s[i].p2.x>>s[i].p2.y;
        }
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            bool check = true;
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                if(doIntersect(s[i].p1,s[i].p2,s[j].p1,s[j].p2)){
                    check = false;
                    break;
                }
            }
            if(check) cnt++;
        }
        cout<<cnt<<endl;
    }
	return 0;
}
