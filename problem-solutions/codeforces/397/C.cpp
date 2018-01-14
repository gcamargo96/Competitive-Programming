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

int k, a, b;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> k >> a >> b;

	if(a < k and b < k){
		cout << -1 << endl;
		return 0;
	}
	/*if(a == 0 and b == 0){
		cout << 0 << endl;
		return 0;
	}*/

	int res = a/k + b/k;

	if(a%k <= (k-1)*(b/k) and b%k <= (k-1)*(a/k)){
		cout << res << endl;
	}
	else{
		cout << -1 << endl;
	}

	return 0;
}

