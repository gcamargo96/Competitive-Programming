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

ll n;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	if(n == 1){
		cout << -1 << endl;
	}
	else{
		cout << n << " " << n+1 << " " << n*(n+1) << endl;
	}

	return 0;
}

