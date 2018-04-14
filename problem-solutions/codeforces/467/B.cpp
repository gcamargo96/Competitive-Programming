#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int p, y;

int main(void){
	scanf("%d%d", &p, &y);

	for(int i = y; i > p; i--){
		int s = min(p, int(sqrt(i)));
		bool ok = 1;
		for(int j = 2; j <= s; j++){
			if(i%j == 0){
				ok = 0;
				break;
			}
		}
		if(ok){
			printf("%d\n", i);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}