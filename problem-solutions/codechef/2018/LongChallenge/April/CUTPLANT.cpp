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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int t, n;
int ini[N], fin[N];
int bit[N];

int seg[4*N];
int a, b;

void update_bit(int id, int x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

int query_bit(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

int query(int r, int i, int j){
	if(b < i || a > j) return INF;
	if(a <= i && j <= b){
		return seg[r];
	}

	int mid = (i+j)/2;
	ll L = query(2*r, i, mid);
	ll R = query(2*r+1, mid+1, j);
	return min(L,R);
}

void update(int r, int x, int i, int j){
	if(b < i || a > j) return;
	if(a <= i && j <= b){
		seg[r] = x;
		return;
	}
	int mid = (i+j)/2;
	update(r*2, x, i, mid);
	update(r*2+1, x, mid+1, j);
	seg[r] = min(seg[2*r], seg[2*r+1]);
}

bool cmp(ii a, ii b){
	if(a.fi == b.fi){
		return a.se < b.se;
	}
	return a.fi > b.fi;
}

int main(void){
	scanf("%d", &t);

	while(t--){
		memset(seg, 0, sizeof seg);
		memset(bit, 0, sizeof bit);
		scanf("%d", &n);

		for(int i = 1; i <= n; i++){
			scanf("%d", &ini[i]);
		}

		for(int i = 1; i <= n; i++){
			scanf("%d", &fin[i]);
		}

		bool ok = 1;
		for(int i = 1; i <= n; i++){
			if(ini[i] < fin[i]){
				ok = 0;
				break;				
			}
		}

		if(!ok){
			printf("-1\n");
			continue;
		}

		for(int i = 1; i <= n; i++){
			a = b = i;
			update(1, ini[i], 1, n);
		}

		vector<ii> v;
		for(int i = 1; i <= n; i++){
			v.pb(ii(fin[i],i));
		}

		sort(v.begin(), v.end(), cmp);

		// for(int i = 1; i <= n; i++){
		// 	a = b = i;
		// 	printf("%d ", query(1, 1, n));
		// }
		// printf("\n");

		int l = 0, ans = 0;
		bool flag = (ini[v[0].se] > fin[v[0].se] ? 1 : 0);
		for(int r = 1; r < n; r++){
			a = v[l].se, b = v[r].se;
			int qry_seg = query(1, 1, n);
			int qry_bit = query_bit(b) - query_bit(a-1);
			// printf("qry_seg = %d, qry_bit = %d\n", qry_seg, qry_bit);
			if(v[r].fi < v[r-1].fi or qry_seg < v[r].fi or qry_bit > 0){ // cortar ate o anterior
				// printf("cortou em %d - %d\n", v[l].se, v[r-1].se);
				if(flag){
					ans++;
					// printf("aumentou a resposta\n");
				}

				flag = (ini[v[r].se] > fin[v[r].se] ? 1 : 0);
				
				for(int i = l; i < r; i++){
					update_bit(v[i].se, 1);
				}
				
				l = r;
			}
			else if(ini[v[r].se] > fin[v[r].se]){
				flag = 1;
			}
		}
		if(flag == 1){
			// printf("cortou no fim\n");
			ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}