#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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
#define fastcin ios_base::sync_with_stdio(false)

int v[3][7];
bool vis[3];
int n;
vector<int> digits;

bool solve(int p){
	if(p == digits.size()) return 1;

	bool ret = 0;
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		for(int j = 0; j < 6; j++){
			if(v[i][j] == digits[p]){
				vis[i] = 1;
				ret |= solve(p+1);
				vis[i] = 0;
			}
		}
	}

	return ret;
}

int main(void){
	// fastcin;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			scanf("%d", &v[i][j]);
		}
	}

	int ans = 0;
	for(int i = 1; i <= 999; i++){
		memset(vis, 0, sizeof vis);
		digits.clear();
		
		int aux = i;
		while(aux > 0){
			int d = aux%10;
			digits.pb(d);
			aux /= 10;
		}

		bool ok = solve(0);
		if(ok) ans = i;
		else break;
	}

	printf("%d\n", ans);

	return 0;
}