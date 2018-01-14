#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

double s, v1, v2, t1, t2;

int main(void){
	scanf("%lf%lf%lf%lf%lf", &s, &v1, &v2, &t1, &t2);

	double ans1 = s*v1 + t1;
	double ans2 = s*v2 + t2;

	printf("%lf %lf\n", ans1, ans2);

	if(ans1 > ans2){
		printf("First\n");
	}
	else if(ans1 < ans2){
		printf("Second\n");
	}
	else{
		printf("Friendship\n");
	}

	return 0;
}