#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 1005;
int n, t;
ll a, b, c;
int v[N];

int main(void){
	scanf("%d%lld%lld%lld%d", &n, &a, &b, &c, &t);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	ll ans1 = a*n;
	ll ans2 = 0, cnt = 0;

	sort(v+1, v+1+n);

	int j = 1;
	for(int i = 1; i <= t; i++){
		ans2 += c*cnt;
		printf("ans += %lld*%lld=%lld\n", c, cnt, c*cnt);
		while(j <= n and v[j] == i){
			cnt++;
			j++;
		}
	}

	printf("%lld\n", max(ans1, ans2));

	return 0;
}