#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

double h, w;

int main(void){
	freopen("alex.in", "r", stdin);
	freopen("alex.out", "w", stdout);

	scanf("%lf%lf", &h, &w);

	double ans = min(h, w)/2.0;

	if(h/3.0  <= w){
		ans = max(ans, h/3.0);
	}

	if(w/3.0 <= h){
		ans = max(ans, w/3.0);
	}

	if(3.0*w <= h){
		ans = max(ans, w);
	}

	if(3*h <= w){
		ans = max(ans, h);
	}

	printf("%.10lf\n", ans);

	return 0;
}