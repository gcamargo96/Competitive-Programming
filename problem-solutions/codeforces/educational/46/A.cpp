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

map<string, int> cnt1, cnt2;
string s;
int n;

int main(void){
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> s;
		cnt1[s]++;
	}
	for(int i = 0; i < n; i++){
		cin >> s;
		cnt2[s]++;
	}

	int iguais = 0;
	for(auto cur : cnt1){
		if(cnt2.count(cur.fi)){
			iguais += min(cur.se, cnt2[cur.fi]);
		}
	}

	cout << n-iguais << endl;

	return 0;
}