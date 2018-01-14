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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1002;
int t, x, n;
string s;
set<string> opt;

void get_opt(int i, string& t){
	if(i == n-1){
		t += '0';
		opt.insert(t);
		t.pop_back();
		return;
	}

	get_opt(i+1, t);

	t += s[i];
	get_opt(i+1, t);
	t.pop_back();

	// t += '1';
	// get_opt(i+1, t);
	// t.pop_back();
}

int main(void){
	fastcin;
	cin >> t;

	while(t--){
		cin >> x >> s;
		n = s.size();

		string aux;
		aux += '1';
		get_opt(1, aux);
		s.pop_back();
	
		for(string a : opt){
			cout << a << endl;
		}
	}

	return 0;
}