#include <bits/stdc++.h>
using namespace std;
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

int t;
int v[3];
vi d1, d2, d3;
set<vector<int> > s;

int solve(int i, int j, int k){
	if(i == d1.size() or j == d2.size() or k == d3.size()){
		return 0;
	}

	vi v;
	v.pb(d1[i]);
	v.pb(d2[j]);
	v.pb(d3[k]);

	if(s.count(v)) return 0;
	s.insert(v);

	int ret = 0;
	for(int c = k+1; c < d3.size(); c++){
		if(d3[c] >= d2[j]){
			ret += solve(i,j,c);
			break;
		}
	}
	for(int b = j+1; b < d2.size(); b++){
		if(d2[b] >= d1[i] and d2[b] <= d3[k]){
			ret += solve(i,b,k);
			break;
		}
	}
	for(int a = i+1; a < d1.size(); a++){
		if(d1[a] <= d2[j]){
			ret += solve(a,j,k);
			break;
		}
	}

	// if(j+1 < d2.size() and d2[j+1] <= d3[k]){
	// 	ret += solve(i,j+1,k);
	// }
	// if(i+1 < d1.size() and d1[i+1] <= d2[j]){
	// 	ret += solve(i+1,j,k);
	// }

	return ret+1;
}

int main(void){
	scanf("%d", &t);

	while(t--){
		s.clear();
		d1.clear(), d2.clear(), d3.clear();

		for(int i = 0; i < 3; i++){
			scanf("%d", &v[i]);			
		}

		sort(v, v+3);

		for(int x = 1; x*x <= v[0]; x++){
			if(v[0]%x == 0){
				d1.pb(x);
				d1.pb(v[0]/x);
			}
		}
		for(int x = 1; x*x <= v[1]; x++){
			if(v[1]%x == 0){
				d2.pb(x);
				d2.pb(v[1]/x);
			}
		}
		for(int x = 1; x*x <= v[2]; x++){
			if(v[2]%x == 0){
				d3.pb(x);
				d3.pb(v[2]/x);
			}
		}

		sort(d1.begin(), d1.end());
		sort(d2.begin(), d2.end());
		sort(d3.begin(), d3.end());
	
		d1.resize(unique(d1.begin(), d1.end()) - d1.begin());
		d2.resize(unique(d2.begin(), d2.end()) - d2.begin());
		d3.resize(unique(d3.begin(), d3.end()) - d3.begin());

		// for(int i = 0; i < d1.size(); i++){
		// 	printf("%d ", d1[i]);
		// }
		// printf("\n");
		// for(int i = 0; i < d2.size(); i++){
		// 	printf("%d ", d2[i]);
		// }
		// printf("\n");
		// for(int i = 0; i < d3.size(); i++){
		// 	printf("%d ", d3[i]);
		// }
		// printf("\n");

		int ans = solve(0,0,0);

		printf("%d\n", ans);
	}

	return 0;
}