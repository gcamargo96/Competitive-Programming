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

class Restrictions{
public:
	int lo[505], hi[505];

	vector <int> exist(int n, int m, vector <int> type, vector <int> l, vector <int> r, vector <int> val){
		for(int i = 0; i < n; i++){
			lo[i] = 1;
			hi[i] = 1000000;
		}

		for(int i = 0; i < m; i++){
			for(int j = l[i]; j <= r[i]; j++){
				if(type[i] == 1){
					lo[j] = max(lo[j], val[i]);
				}
				else{
					hi[j] = min(hi[j], val[i]);
				}
			}
		}

		vector<int> ans;
		for(int i = 0; i < n; i++){
			if(lo[i] > hi[i]){
				ans.pb(-1);
				return ans;
			}
		}

		for(int i = 0; i < n; i++){
			ans.pb(lo[i]);
		}

		return ans;
	}
};
