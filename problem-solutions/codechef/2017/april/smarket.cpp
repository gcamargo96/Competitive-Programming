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
int t, n, q;
int a[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &q);

		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		
		int l, r, k;
		For(i,0,q){
			scanf("%d%d%d", &l, &r, &k);
			
			int tam = 1, res = 0;
			for(int i = l+1; i <= r; i++){
				if(a[i] == a[i-1]){
					tam++;
				}
				else{
					if(tam >= k) res++;
					tam = 1;
				}
			}
			if(tam >= k) res++;

			printf("%d\n", res);
		}
	}

	return 0;
}

