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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;

int main(void){
	cin >> s;

	ll ans = 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = i+1; j < s.size(); j++){
			if(s[i] == 'Q' and s[j] == 'Q'){
				for(int k = i+1; k <= j-1; k++){
					if(s[k] == 'A') ans++;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}