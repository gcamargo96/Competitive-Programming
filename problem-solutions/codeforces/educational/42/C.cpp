#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
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
typedef complex<double> base;

string s;
int n, ans = INF;
set<int> square;
bool flag[12];

bool valid(){
	string t;

	for(int i = 0; i < n; i++){
		if(flag[i])
			t += s[i];
	}

	if(t.size() == 0)
		return 0;
	if(t[0] == '0')
		return 0;

	int num = stoi(t);
	if(square.count(num))
		return 1;

	return 0;
}

void solve(int i, int ops){
	if(i == n){
		if(valid())
			ans = min(ans, ops);
		return;
	}


	flag[i] = 1;
	solve(i+1, ops);
	flag[i] = 0;
	solve(i+1, ops+1);
}

int main(void){
	fastcin;
	cin >> s;
	n = s.size();

	for(ll i = 1; i*i <= 2000000000LL; i++){
		square.insert(i*i);
	}

	solve(0, 0);

	if(ans == INF){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}

	return 0;
}