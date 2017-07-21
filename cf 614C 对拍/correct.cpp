#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
struct Node{
    double x, y;
}node[100010];
double DISTANCE(int a, int b){
    return sqrt((node[a].x - node[b].x) * (node[a].x - node[b].x)
                + (node[a].y - node[b].y) * (node[a].y - node[b].y));
}
int main()
{
    int n;
    double up, down, s;
    scanf("%d%lf%lf", &n, &node[0].x, &node[0].y);
    up = 0; down = 1e20;
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf", &node[i].x, &node[i].y);
        up = max(DISTANCE(i, 0), up);
    }
    for(int i = 1; i < n; i++){
        double a = DISTANCE(0, i);
        double b = DISTANCE(0, i + 1);
        double c = DISTANCE(i, i + 1);
        if(a*a + c*c - b*b < 0 ||  b*b + c*c - a*a < 0){
            down = min(down, min(a, b));
        }
        else{
            double p = (a + b + c) / 2;
            down = min(down, 2 * sqrt(p * (p - a) * (p - b) * (p - c)) / c);
        }
    }
    {
        double a = DISTANCE(0, 1);
        double b = DISTANCE(0, n);
        double c = DISTANCE(1, n);
        if(a*a + c*c - b*b < 0 ||  b*b + c*c - a*a < 0){
            down = min(down, min(a, b));
        }
        else{
            double p = (a + b + c) / 2;
            down = min(down, 2 * sqrt(p * (p - a) * (p - b) * (p - c)) / c);
        }
    }
    s = ((up * up) - (down * down)) * PI;
    printf("%.16lf\n", s);
    return 0;
}
