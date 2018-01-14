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

int t, n;

int main(void){
	cin >> t;

	while(t--){
		cin >> n;

		bool ans = 0;
		for(int a = 0; 3*a <= n; a++){
			int resto = n - 3*a;
			if(resto%7 == 0){
				ans = 1;
			}
		}

		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}