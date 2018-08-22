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

string a, b, c;
int n;
vi dif;
string ans;
set<string> all_ans;

void solve(int i, int fa, int fb, int fc){
	if(i == dif.size()){
		all_ans.insert(ans);
		return;
	}

	int p = dif[i];
	set<char> s;
	s.insert(a[p]);
	s.insert(b[p]);
	s.insert(c[p]);
	s.insert('#');

	int cnt = 0;
	for(char x : s){
		if(a[p] != x and fa) continue;
		if(b[p] != x and fb) continue;
		if(c[p] != x and fc) continue;

		ans[p] = x;
		solve(i+1, fa | (a[p] != x), fb | (b[p] != x), fc | (c[p] != x));
	}
}

int main(void){
	cin >> a >> b >> c;
	n = a.size();

	for(int i = 0; i < n; i++){
		if(a[i] != b[i] or a[i] != c[i] or b[i] != c[i]){
			dif.pb(i);
		}
	}

	if(dif.size() > 3){
		cout << "Impossible" << endl;
		return 0;
	}
	if(dif.size() <= 1){
		cout << "Ambiguous" << endl;
		return 0;
	}

	ans = a;
	solve(0, 0, 0, 0);

	if(all_ans.size() == 0){
		cout << "Impossible" << endl;
	}
	else if(all_ans.size() == 1){
		cout << *all_ans.begin() << endl;
	}
	else{
		cout << "Ambiguous" << endl;
	}

	return 0;
}