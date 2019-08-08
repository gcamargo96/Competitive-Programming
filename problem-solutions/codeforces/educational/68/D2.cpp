#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int t, n, k;

int main(void){
	fastcin;
	cin >> t;

	while(t--){
		cin >> n >> k;

		if(k%3 != 0){
			cout << (n%3 == 0 ? "Bob" : "Alice") << endl;
		}
		else{
			int r = n%(k+1);

			if(r == k){
				cout << "Alice" << endl;
			}
			else{
				cout << (r%3 == 0 ? "Bob" : "Alice") << endl;
			}
		}
	}

	return 0;
}