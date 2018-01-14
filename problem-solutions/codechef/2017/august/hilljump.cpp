#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 1002;
int n, q;
ll v[N];

int main(void){
	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
	}

	int type, p, k, l, r;
	ll x;
	while(q--){
		scanf("%d", &type);
		
		if(type == 1){
			scanf("%d%d", &p, &k);
			int cur = p, jumps = 0, last = 0;
			while(cur <= n and jumps < k){
				for(int i = 1; i <= 100 and cur+i <= n; i++){
					if(v[cur] < v[cur+i]){
						cur += i;
						jumps++;
						break;
					}
				}
				if(jumps == last) break;
				last = jumps;
			}
			printf("%d\n", cur);
		}
		else{
			scanf("%d%d%lld", &l, &r, &x);
			for(int i = l; i <= r; i++){
				v[i] += x;
			}
		}
	}

	return 0;
}