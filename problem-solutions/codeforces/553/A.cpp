#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

int n;
string s;

int dist(char a, char b){
	if(a > b) swap(a, b);
	int d = min(b-a, 'Z'-b + a-'A' + 1);
	return d;
}

int main(void){
	fastcin;
	cin >> n >> s;

	string pat = "ACTG";

	int ans = INF;
	for(int i = 0; i <= n-4; i++){

		int aux = 0;
		for(int j = 0; j < 4; j++){
			aux += dist(s[i+j], pat[j]);
		}

		ans = min(ans, aux);
	}

	cout << ans << endl;

	return 0;
}