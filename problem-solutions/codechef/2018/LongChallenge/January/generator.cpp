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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

vector<ii> v;

int main(void){
	for(int n = 2; n <= 50; n++){
		for(int x = 1; x <= n; x++){
			v.pb(ii(x,n));
		}
	}

	cout << v.size() << endl;

	for(int i = 0; i < v.size(); i++){
		cout << v[i].fi << " " << v[i].se << endl;
	}

	return 0;
}