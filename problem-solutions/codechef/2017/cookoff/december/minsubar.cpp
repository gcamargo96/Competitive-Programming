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

const int N = 100002;
int t, n, d;
int v[N], sum[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &d);
		
		sum[0] = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
			sum[i] = sum[i-1] + v[i];
		}

		set<ii> s;
		s.insert(ii(d,0));
		int ans = INF;
		for(int i = 1; i <= n; i++){
			if(v[i] >= d){
				ans = 1;
				break;
			}

			auto it = s.upper_bound(ii(sum[i], INF));

			if(it != s.begin()){
				it--;
				vector<ii> to_delete;
				while(it != s.begin()){
					ans = min(ans, i-it->se);
					to_delete.pb(*it);
					it--;
				}
				ans = min(ans, i-it->se);
				to_delete.pb(*it);

				for(int j = 0; j < to_delete.size(); j++){
					s.erase(to_delete[j]);
				}
			}

			s.insert(ii(sum[i]+d, i));
		}

		if(ans == INF){
			printf("-1\n");
		}
		else{
			printf("%d\n", ans);
		}
	}

	return 0;
}