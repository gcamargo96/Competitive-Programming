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

const int N = 200002;
int n;
int v[N], cnt[N];
set<int> s;

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);

		auto it = s.upper_bound(v[i]);

		if(it == s.end()){
			cnt[v[i]]--;
		}
		else{		
			auto it2 = s.end();
			it2--;
			if(*it == *it2){
				cnt[*it]++;
			}
		}

		s.insert(v[i]);
	}

	int mx = -INF, ans = 1;
	for(int i = 1; i <= n; i++){
		// printf("%d ", cnt[i]);
		if(cnt[i] > mx){
			mx = cnt[i];
			ans = i;
		}
	}
	// printf("\n");

	printf("%d\n", ans);

	return 0;
}