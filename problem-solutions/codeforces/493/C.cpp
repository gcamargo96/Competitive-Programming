#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 300005;
int n;
ll rev, flip;
string s;

int main(void){
	fastcin;
	cin >> n >> rev >> flip;
	cin >> s;

	ll ans1 = flip;
	for(int i = 0; i < n;){
		bool flag = (s[i] == '0');
		while(i < n and s[i] == '0') i++;
		if(i == n) flag = 0;
		while(i < n and s[i] == '1') i++;
		
		if(flag and i < n) ans1 += rev;
	}

	ll ans2 = flip;
	for(int i = n-1; i >= 0;){
		bool flag = (s[i] == '0');
		while(i >= 0 and s[i] == '0') i--;
		if(i < 0) flag = 0;
		while(i >= 0 and s[i] == '1') i--;

		if(flag and i >= 0) ans2 += rev;
	}

	ll ans3 = 0;
	for(int i = 0; i < n;){
		bool flag = (s[i] == '0');
		while(i < n and s[i] == '0') i++;
		while(i < n and s[i] == '1') i++;

		if(flag) ans3 += flip;
	}

	ll ans = min(min(ans1, ans2), ans3);
	cout << ans << endl;

	return 0;
}