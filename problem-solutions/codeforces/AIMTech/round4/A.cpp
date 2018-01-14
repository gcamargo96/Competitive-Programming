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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int k;
string s;
int cnt[30];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;
	cin >> k;

	if(k > s.size()){
		cout << "impossible\n";
		return 0;
	}

	int cntdif = 0;
	for(int i = 0; i < s.size(); i++){
		if(cnt[s[i]-'a'] == 0){
			cntdif++;
		}
		cnt[s[i]-'a']++;
	}

	int ans = k-min(k, cntdif);

	cout << ans << endl;

	return 0;
}