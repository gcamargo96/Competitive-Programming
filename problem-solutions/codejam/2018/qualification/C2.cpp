#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

int t, a;

int main(void){
	scanf("%d", &t);

	for(int c = 1; c <= t; c++){
		scanf("%d", &a);

		int ok = 0;
		int x, y;
		for(int i = 0; i < 200; i++){
			printf("2 2\n");
			fflush(stdout);
			scanf("%d%d", &x, &y);
			if(x == 0 and y == 0){
				ok = 1;
				break;
			}
			if(x == -1 and y == -1){
				return 0;
			}
		}

		if(ok == 1){
			continue;
		}

		for(int i = 0; i < 200; i++){
			printf("5 2\n");
			fflush(stdout);
			scanf("%d%d", &x, &y);
			if(x == 0 and y == 0){
				ok = 1;
				break;
			}
			if(x == -1 and y == -1){
				return 0;
			}
		}

		if(ok == 1){
			continue;
		}

		for(int i = 0; i < 200; i++){
			printf("8 2\n");
			fflush(stdout);
			scanf("%d%d", &x, &y);
			if(x == 0 and y == 0){
				ok = 1;
				break;
			}
			if(x == -1 and y == -1){
				return 0;
			}
		}
	}

	return 0;
}