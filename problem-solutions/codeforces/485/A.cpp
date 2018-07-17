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

map<string, string> m;
int n;

int main(void){
	cin >> n;

	m["purple"] = "Power";
	m["green"] = "Time";
	m["blue"] = "Space";
	m["orange"] = "Soul";
	m["red"] = "Reality";
	m["yellow"] = "Mind";

	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		m.erase(s);
	}

	cout << m.size() << endl;
	for(auto it : m){
		cout << it.se << endl;
	}

	return 0;
}