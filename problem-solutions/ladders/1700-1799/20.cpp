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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int v[N], cnt[N], rev[N];
int n;

int main(void){
	scanf("%d", &n);

	v[0] = -1e9+10, v[n+1] = 1e9+10; 
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	cnt[1] = 1;
	for(int i = 2; i <= n; i++){
		cnt[i] = 1;
		if(v[i] > v[i-1]){
			cnt[i] = cnt[i-1]+1;
		}
	}

	rev[n] = 1;
	for(int i = n-1; i >= 1; i--){
		rev[i] = 1;
		if(v[i] < v[i+1]){
			rev[i] = rev[i+1]+1;
		}
	}

	int ans = 1;
	for(int i = 1; i <= n; i++){
		ans = max(ans, min(n, cnt[i]+1));
		if(v[i-1]+1 < v[i+1]){
			ans = max(ans, cnt[i-1] + 1 + rev[i+1]);
		}
	}

	printf("%d\n", ans);

	return 0;
}