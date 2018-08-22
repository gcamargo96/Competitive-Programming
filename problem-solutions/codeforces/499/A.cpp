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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;
int n, k;

int main(void){
	cin >> n >> k;
	cin >> s;

	sort(s.begin(), s.end());

	int last = -100, cnt = 0, ans = 0;
	for(int i = 0; i < s.size() and cnt < k; i++){
		int x = s[i]-'a'+1;
		if(x >= last+2){
			last = x;
			cnt++;
			ans += x;
		}
	}

	if(cnt == k){
		cout << ans << endl;
	}
	else{
		cout << -1 << endl;
	}

	return 0;
}