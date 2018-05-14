#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 105;
int n, m;
string s;
int l, r;
char c1, c2;

int main(void){
	cin >> n >> m >> s;

	while(m--){
		cin >> l >> r >> c1 >> c2;
		l--, r--;
		for(int i = l; i <= r; i++){
			if(s[i] == c1){
				s[i] = c2;
			}
		}
	}

	cout << s << endl;

	return 0;
}