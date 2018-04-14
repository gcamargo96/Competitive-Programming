#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n, u;
ll v[N];

int main(void){
	scanf("%d%d", &n, &u);

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
	}
	v[n] = 1000000000000LL;

	int j = 0;
	bool ok = 0;
	double ans = -1;
	for(int i = 0; i < n; i++){
		while(v[j+1]-v[i] <= u){
			j++;
		}

		if(j-i+1 >= 3){
			ok = 1;
			ans = max(ans, double(v[j]-v[i+1])/double(v[j]-v[i]));
		}
	}

	if(ok){
		printf("%.10lf\n", ans);
	}
	else{
		printf("-1\n");
	}

	return 0;
}