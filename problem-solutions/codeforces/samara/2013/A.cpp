#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 200002;
int n;
vi v[N];
set<int> a, b, c;

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int x;
		for(int j = 0; j < 3; j++){
			scanf("%d", &x);
			v[i].pb(x);
		}
		sort(v[i].begin(), v[i].end());
		a.insert(v[i][0]);
		b.insert(v[i][1]);
		c.insert(v[i][2]);
	}

	if(n == 1){
		printf("1\n");
		printf("1\n");
		return 0;
	}

	vi ans;
	for(int i = 0; i < n; i++){
		a.erase(v[i][0]);
		b.erase(v[i][1]);

		auto ita = --(a.end()); // maior a		
		auto itb = --(b.end()); // maior b
		if(v[i][1] > *ita and v[i][2] > *itb){
			ans.pb(i+1);
		}

		a.insert(v[i][0]);
		b.insert(v[i][1]);
	}

	printf("%d\n", int(ans.size()));
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}