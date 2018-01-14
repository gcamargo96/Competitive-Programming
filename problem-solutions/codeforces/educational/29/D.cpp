#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 2000002;
ll qnt[N], suml[N], sumr[N];
int v[N];
int n;
map<int, int> m;

void update(ll *bit, int id, ll x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

long double query(ll *bit, int id){
	long double sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

main(void){
	scanf("%d", &n);

	vector<ll> aux;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		aux.pb(v[i]);
	}

	sort(aux.begin(), aux.end());
	aux.resize(unique(aux.begin(), aux.end()) - aux.begin());

	for(int i = 0; i < aux.size(); i++){
		m[aux[i]] = i+1;
	}

	long double ans = 0;
	for(int i = 0; i < n; i++){
		auto id = upper_bound(aux.begin(), aux.end(), v[i]-2);

		if(id != aux.begin()){
			id--;

			long double cnt = query(qnt, id-aux.begin()+1);
			long double sum = query(suml, id-aux.begin()+1);

			ans += v[i]*cnt - sum;
		
		}
				
		update(qnt, m[v[i]], 1);
		update(suml, m[v[i]], v[i]);

		// for(int j = 1; j <= n; j++){
		// 	printf("%lld ", query(qnt, j) - query(qnt, j-1));
		// }
		// printf("\n");
	}

	memset(qnt, 0, sizeof qnt);

	for(int i = n-1; i >= 0; i--){
		auto id = upper_bound(aux.begin(), aux.end(), v[i]-2);
	
		if(id != aux.begin()){
			id--;

			long double cnt = query(qnt, id-aux.begin()+1);
			long double sum = query(sumr, id-aux.begin()+1);
			ans -= v[i]*cnt - sum;
		}
	
		update(qnt, m[v[i]], 1);
		update(sumr, m[v[i]], v[i]);
	}

	cout << fixed << setprecision(0) << ans << endl;

	return 0;
}