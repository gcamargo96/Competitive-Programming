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
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	int mini = 1000000002;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		mini = min(mini, v[i]);
	}

	vi pos;
	for(int i = 0; i < n; i++){
		if(v[i] == mini){
			pos.pb(i);
		}
	}

	int ans = 1000000002;
	for(int i = 1; i < pos.size(); i++){
		ans = min(ans, pos[i]-pos[i-1]);
	}

	printf("%d\n", ans);

	return 0;
}