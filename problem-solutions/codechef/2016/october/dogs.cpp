#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int t;
double s, v;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%lf%lf", &s, &v);

		double R = (s*sqrt(3.0))/3.0;
		double res = R/(v*cos(acos(-1)/6.0));
		printf("%lf\n", res);
	}

	return 0;
}

