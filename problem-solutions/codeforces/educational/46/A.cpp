#include <bits/stdc++.h>
using namespace std;
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

int n;
vector<string> s, t;

bool cmp(string a, string b){
	return a.size() < b.size();
}

int calc_diff(string s, string t){
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	int dif = 0;
	for(int i = 0; i < min(s.size(), t.size()); i++){
		if(s[i] != t[i]) dif++;
	}
	dif += max(s.size(), t.size()) - min(s.size(), t.size());

	return dif;
}

int main(void){
	fastcin;
	cin >> n;

	string in;
	for(int i = 0; i < n; i++){
		cin >> in;
		s.pb(in);
	}

	for(int i = 0; i < n; i++){
		cin >> in;
		t.pb(in);
	}

	sort(s.begin(), s.end(), cmp);
	sort(t.begin(), t.end(), cmp);

	int ans = 0;
	for(int i = 0; i < n; i++){
		int mindif = 100, pos = 0;
		for(int j = 0; j < t.size(); j++){
			int dif = calc_diff(s[i], t[j]);
			if(dif < mindif){
				mindif = dif;
				pos = j;
			}
		}

		ans += mindif;
		t.erase(t.begin() + pos);
	}

	cout << ans << endl;

	return 0;
}