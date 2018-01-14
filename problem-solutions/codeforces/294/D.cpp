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

const int N = 100002;
int letras[26];
string s;
vi v[26];
ll sum[N];
map<ll,vi> same_sum;

int main(void){
	ios_base::sync_with_stdio(false);

	For(i,0,26){
		cin >> letras[i];
	}

	s += "#";
	string aux;
	cin >> aux;
	s += aux;

	if(s.size() == 1){
		cout << 0 << endl;
		return 0;
	}

	for(int i = 1; i < s.size(); i++){
		sum[i] = sum[i-1] + letras[s[i]-'a'];
	}

	for(int i = 1; i <= s.size(); i++){
		same_sum[sum[i]].pb(i);
	}

	for(auto it = same_sum.begin(); it != same_sum.end(); it++){
		if((it->se).size() >= 2){
			map<ll,ll>
		}
	}

	cout << res << endl;

	return 0;
}

