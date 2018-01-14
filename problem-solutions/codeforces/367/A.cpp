#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int n;
int a, b;

struct taxi{
  int x, y, v;  

};

taxi t[1002];

int main(void){
   	scanf("%d%d", &a, &b);

    scanf("%d", &n);
    
    For(i,0,n){
        cin >> t[i].x >> t[i].y >> t[i].v;
    }
    
    double res = DBL_MAX;
    For(i,0,n){
        double dist = sqrt((a-t[i].x)*(a-t[i].x)+(b-t[i].y)*(b-t[i].y));
        double temp = dist/(double)t[i].v;
        //cout << "temp = " << temp << endl;
        res = min(res, temp);
    }
    
   	printf("%lf\n", res);

    return 0;
}
