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

const int N = 50005, S = 255;
vector<tuple<int,int,int,int> > qry[N];
int cnt[S][S];
int freq[N], v[N], ans[N];
int n, q;

int main(void){
	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	int l, r, x, m;
	for(int i = 1; i <= q; i++){
		scanf("%d%d%d%d", &l, &r, &x, &m);

		qry[l-1].eb(-1, i, x, m);
		qry[r].eb(1, i, x, m);
	}

	for(int i = 1; i <= n; i++){
		freq[v[i]]++;

		for(int mod = 1; mod < S; mod++){
			cnt[mod][v[i]%mod]++;
		}

		for(int j = 0; j < qry[i].size(); j++){
			int mul, id, x, m;
			tie(mul, id, x, m) = qry[i][j];

			if(m < S){
				ans[id] += mul * cnt[m][x];
			}
			else{
				for(int k = x; k < N; k += m){
					ans[id] += mul * freq[k];
				}
			}
		}
	}

	for(int i = 1; i <= q; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}