#include <bits/stdc++.h>
using namespace std;
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

int n;
string s;

int main(void){
	fastcin;
	cin >> n >> s;

	int ans = n;
	for(int i = 0; i < n-1; i++){
		if(s[i] != s[i+1]){
			ans--;
			i++;
		}
	}

	cout << ans << endl;

	return 0;
}