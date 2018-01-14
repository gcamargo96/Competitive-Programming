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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, m;
int X1, Y1, x2, y2;

int main(void){
	cin >> n >> m >> X1 >> Y1 >> x2 >> y2;

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(abs(X1-i) + abs(Y1-j) == abs(x2-i) + abs(y2-j)){
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}