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

int n, k;
string s;
int op[26], cl[26];
bool op2[26];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> s;

	For(i,0,s.size()){
		if(!op[s[i]-'A']){
			op[s[i]-'A'] = i+1;
		}
	}

	for(int i = int(s.size())-1; i >= 0; i--){
		if(!cl[s[i]-'A']){
			cl[s[i]-'A'] = i+1;
		}
	}


	int cnt = 0;
	bool ans = 1;
	For(i,0,s.size()){
		if(i+1 == op[s[i]-'A']){
			cnt++;
		}
		if(cnt > k){
			ans = 0;
		}
		if(i+1 == cl[s[i]-'A']){
			cnt--;
		}
	}

	if(ans) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}