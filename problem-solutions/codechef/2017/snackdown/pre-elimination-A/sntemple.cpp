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

const int N = 100002;
int t, n;
ll h[N], lr[N], rl[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		memset(h, 0, sizeof h);
		memset(lr, 0, sizeof lr);
		memset(rl, 0, sizeof rl);
		scanf("%d", &n);

		ll total = 0;
		For(i,1,n+1){
			scanf("%lld", &h[i]);
			total += h[i];
		}
	

		For(i,1,n+1){
			lr[i] = min(lr[i-1]+1, h[i]);
		}

		for(int i = n; i >= 1; i--){
			rl[i] = min(rl[i+1]+1, h[i]);
		}

		ll maior = 0;
		for(int i = 1; i <= n; i++){
			maior = max(maior, min(lr[i], rl[i]));
		}

		//printf("maior = %lld\n", maior);
		ll res = total - maior*maior;
		printf("%lld\n", res);
	}

	return 0;
}

