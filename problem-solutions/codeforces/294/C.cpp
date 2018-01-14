#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	if(n == 0 or m == 0){
		cout << 0 << endl;
		return 0;
	}

	int res = 0;
	while(n > 0 and m > 0 and n+m >= 3){
		if(n > m){
			n -= 2;
			m -= 1;
		}
		else{
			n -= 1;
			m -= 2;
		}
		res++;
	}

	cout << res << endl;

	return 0;
}

