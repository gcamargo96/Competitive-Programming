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

const int N = 20002;

int t, a, b, x;
int vis[N];
vector<int> ans;

void sieve(int a, int b){
	if(a == 1){
		if(x == 1){
			ans.pb(1);
			return;
		}
		else{
			a++;
		}
	}
	
	for(int i = b; i >= a; i--){
		bool ok = 1;
		for(int j = i; j <= b; j += i){
			if(vis[j]){
				ok = 0;
				break;
			}
		}
		vis[i] = 1;
		if(ok) ans.pb(i);
		if(ans.size() == x) return;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		cin >> a >> b >> x;
		
		memset(vis, 0, sizeof vis);
		ans.clear();
		sieve(a, b);

		// for(int i = 0; i < x; i++){
		// 		cout << ans[i] << " ";
		// 	}
		// cout << endl;

		if(ans.size() == x){
			for(int i = 0; i < x; i++){
				cout << ans[i] << " ";
			}
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}
	}

	return 0;
}