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

const int N = 4002;
int n, a, b, c;

int main(void){
	scanf("%d%d%d%d", &n, &a, &b, &c);

	int res = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			int x = a*i + b*j;
			if(n-x == 0){
				res = max(res, i+j);
			}
			if(n-x > 0 and (n-x)%c == 0){
				res = max(res, i+j+(n-x)/c);
			}
		}
	}

	printf("%d\n", res);

	return 0;
}

