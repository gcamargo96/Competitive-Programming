#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define MOD 1000000007
const int N = 500002;
int n, m, g;
vi v[N];

int main(void){
	scanf("%d%d", &n, &m);

	int x;
	For(i,0,n){
		scanf("%d", &g);
		For(j,0,g){
			scanf("%d", &x);
			v[x].pb(i);
		}
	}

	sort(v+1, v+m+1);

	ll res = 1, t = 1;
	for(int i = 2; i <= m; i++){
		if(v[i] == v[i-1]){
			t++;
			res = (res * t)%MOD;
		}
		else{
			t = 1;
		}
	}

	cout << res << endl;

	return 0;
}

