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
int a[N], bit_beg[N], bit_end[N], L[N], R[N];
vector<ii> blocks[N];

struct query{
	int l, r, k, id;
};

query qry[N];

void init(){
	For(i,0,N)
		blocks[i].clear();
	memset(bit_beg, 0, sizeof bit_beg);
	memset(bit_end, 0, sizeof bit_end);
	memset(L, 0, sizeof L);
	memset(R, 0, sizeof R);
}

bool cmp(query a, query b){
	return a.k < b.k;
}

void update_beg(int id, int x){
	while(id < N){
		bit_beg[id] += x;
		id += id & -id;
	}
}

int query_beg(int id){
	int sum = 0;
	while(id > 0){
		sum += bit_beg[id];
		id -= id & -id;
	}
	return sum;
}

void update_end(int id, int x){
	while(id < N){
		bit_end[id] += x;
		id += id & -id;
	}
}

int query_end(int id){
	int sum = 0;
	while(id > 0){
		sum += bit_end[id];
		id -= id & -id;
	}
	return sum;
}

int main(void){
	scanf("%d", &t);

	while(t--){
		init();
		scanf("%d%d", &n, &q);

		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}

		int cnt = 1;
		for(int i = 1; i <= n; i++){
			L[i] = cnt;
			if(a[i+1] != a[i]){
				blocks[cnt].pb(ii(i-cnt+1,i));
				cnt = 1;
			}
			else{
				cnt++;
			}
		}

		cnt = 1;
		for(int i = n; i >= 1; i--){
			R[i] = cnt;
			if(a[i] != a[i-1]){
				cnt = 1;
			}
			else{
				cnt++;
			}
		}
		
		For(i,0,q){
			scanf("%d%d%d", &qry[i].l, &qry[i].r, &qry[i].k);
			qry[i].id = i;
		}

		sort(qry, qry+q, cmp);

		int j = N;
		vector<ii> res;
		for(int i = q-1; i >= 0; i--){
			while(j >= qry[i].k){
				For(x,0,blocks[j].size()){
					//begs.insert(blocks[j][x]);
					update_beg(blocks[j][x].fi, 1);
					update_end(blocks[j][x].se, 1);
				}
				j--;
			}

			//printf("query: %d %d %d\n", qry[i].l, qry[i].r, qry[i].k);

			int tem, tem2, ans = 0;
			int ini = query_beg(qry[i].r-1);
			int fim = query_end(qry[i].r-1);
			
			//printf("ini1 = %d, fim1 = %d\n", ini, fim);

			if(ini == fim){
				tem = ini;
			}
			else{
				tem = ini-1;
			}
			if(L[qry[i].r] >= qry[i].k) ans++;
			
			ini = query_beg(qry[i].l);
			fim = query_end(qry[i].l);
			
			//printf("ini2 = %d, fim2 = %d\n", ini, fim);
			
			if(ini == fim){
				tem2 = ini;
			}
			else{
				tem2 = ini;
			}
			if(R[qry[i].l] >= qry[i].k) ans++;
			if(R[qry[i].l] >= qry[i].r-qry[i].l+1) ans--;

			//printf("tem = %d, tem2 = %d\n", tem, tem2);

			if(tem-tem2 > 0) ans += tem-tem2;
			
			//printf("ans[%d] = %d\n", qry[i].id, ans);
			res.pb(ii(qry[i].id, ans));
		}

		sort(res.begin(), res.end());
		For(i,0,res.size()){
			printf("%d\n", res[i].se);
		}
	}

	return 0;
}

