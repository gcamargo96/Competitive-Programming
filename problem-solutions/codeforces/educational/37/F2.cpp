#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 300002, M = 1000002;
int n, m;
int v[N], d[M];
ll bit[N];
set<int> s;

void sieve(){
	for(int i = 1; i < M; i++){
		for(int j = i; j < M; j += i){
			d[j]++;
		}
	}
}

void update(int id, ll x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

ll query(int id){
	ll sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

int main(void){
	scanf("%d%d", &n, &m);
	sieve();

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		if(v[i] > 2)
			s.insert(i);
		update(i, v[i]);
	}

	int t, l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &t, &l, &r);

		if(t == 1){
			for(auto it = s.lower_bound(l); it != s.end(); ){
				int j = *it;
				if(j > r)
					break;

				update(j, -v[j]);
				v[j] = d[v[j]];
				update(j, v[j]);

				if(v[j] <= 2)
					it = s.erase(it);
				else
					it++;
			}
		}
		else{
			printf("%lld\n", query(r) - query(l-1));
		}
	}

	return 0;
}