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

ll n, m, a, b;

int main(void){
	cin >> n >> m >> a >> b;

	ll ans = min((n%m)*b, (m-(n%m))*a);

	cout << ans << endl;

	return 0;
}