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

const int N = 200002;
int n, m;
string s[N];
int point[N], loves[N];

int main(void){
	fastcin;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> s[i];
		point[i] = i;
	}

	cin >> m;

	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		point[u] = point[v];
		loves[u] = loves[v]+1;
	}

	for(int i = 0; i < loves[1]; i++){
		cout << "I_love_";
	}
	cout << s[point[1]] << endl;

	return 0;
}