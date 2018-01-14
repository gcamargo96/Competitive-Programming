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

const int N = 1000002;
int t, n, k;
string s;

int check(){
	int i = 0, maior = 0;
	while(i < n){
		int j;
		for(j = i; s[j] == s[j+1]; j++){}

		maior = max(maior, j-i+1);
		if(i == j) j++;
		i = j;
	}
	return maior;
}

int go(int i, int cnt){
	if(i == n){
		if(cnt <= k) return check();
		else return INF;
	}

	if(s[i] == '0') s[i] = '1';
	else s[i] = '0';
	int ret = go(i+1, cnt++);
	if(s[i] == '0') s[i] = '1';
	else s[i] = '0';

	ret = min(ret, go(i+1, cnt));
	
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		cin >> n >> k >> s;
		s += '#';

		int res = go(0, 0);

		cout << res << endl;
	}
	
	return 0;
}

