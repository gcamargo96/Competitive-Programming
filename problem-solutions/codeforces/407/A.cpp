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

const int N = 100002;
int n, k;
int v[N];

int main(void){
	scanf("%d%d", &n, &k);

	For(i,0,n){
		scanf("%d", &v[i]);
	}

	ll res = 0;
	For(i,0,n){
		/*while(v[i] > 0){
			v[i] -= min(v[i], k);
			res++;
		}*/
		if(v[i]%k != 0)res++;
		res += v[i]/k;
	}

	ll ans = 0;
	if(res%2 == 1) ans++;
	ans += res/2;

	printf("%lld\n", ans);

	return 0;
}

