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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200002;
int a[N], h[N];
int n, s, f;
ll acum[N];

int at_first_timezone(int i){
	int ans = s + (n+1 - i);
	if(ans > n)
		ans -= n;
	return ans;
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	scanf("%d%d", &s, &f);

	for(int i = n+1; i <= 2*n; i++){
		a[i] = a[i-n];
	}

	for(int i = 1; i <= 2*n; i++){
		acum[i] = acum[i-1] + a[i];
	}

	int d = f-s;
	ll best = 0;
	int pos = 0, time_first = N;
	for(int i = 1; i <= n; i++){
		ll cur = acum[i+d-1] - acum[i-1];
		int new_time_first = at_first_timezone(i);
		// printf("%d\n", new_time_first);
		if(cur > best or (cur == best and new_time_first < time_first)){
			best = cur;
			pos = i;
			time_first = new_time_first;
		}
	}

	// printf("best = %lld\n", best);

	printf("%d\n", time_first);

	return 0;
}