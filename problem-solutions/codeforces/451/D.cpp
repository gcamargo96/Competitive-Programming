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

const int N = 1000002;
int n, m, k;
int bit[N], v[N];

void update(int id, int x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

int query(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		update(v[i], 1);
	}

	sort(v, v+n);

	int ans = 0;
	for(int i = m; i <= 1000000; i++){
		int sum = query(i) - query(i-m);
		// cout << "sum = " << sum << endl;

		if(sum >= k){
			ans += sum-k+1;

			auto it = upper_bound(v, v+n, i);
			// cout << "i = " << i << " it = " << *it << endl;
			it--;


			for(int j = 0; j < sum-k+1; j++){
				update(*it, -1);
				it--;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}