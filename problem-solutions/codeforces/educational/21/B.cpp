#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 200002;
int n, k;
double v[N], mul[N];

int main(void){
	scanf("%d%d", &n, &k);

	For(i,1,n+1){
		scanf("%lf", &v[i]);
	}

	double res = 0;
	if(k <= n-k+1){
		for(int i = 1; i < k; i++){
			res += ((double)i)*(v[i]);
		}
		for(int i = k; i <= n-k+1; i++){
			res += ((double)k)*v[i];
		}
		for(int i = n-k+2; i <= n; i++){
			res += ((double)(n-i+1))*v[i];
		}
	}
	else{
		for(int i = 1; i <= n-k; i++){
			res += ((double)i)*(v[i]);
		}
		for(int i = n-k+1; i <= n-(n-k); i++){
			res += ((double)(n-k+1))*v[i];
		}
		for(int i = n-(n-k)+1; i <= n; i++){
			res += ((double)(n-i+1))*v[i];
		}
	}

	res /= (n-k+1);

	printf("%lf\n", res);

	return 0;
}

