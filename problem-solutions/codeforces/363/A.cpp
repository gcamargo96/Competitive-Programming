#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 200002;
int n;
string s;
int v[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	cin >> s;

	For(i,0,n){
		cin >> v[i];
	}

	int t = 1000000002;
	For(i,0,n-1){
		if(s[i] == 'R' and s[i+1] == 'L'){
			int menor = abs(v[i]-v[i+1])/2;
			t = min(t, menor);
		}
	}

	if(t < 1000000002) cout << t << endl;
	else cout << "-1" << endl;

	return 0;
}
