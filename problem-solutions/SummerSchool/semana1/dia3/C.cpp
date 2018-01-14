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

int n;
int p[15];

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &p[i]);
	}

	for(int i = 1; i <= 100; i++){
		bool ok = 1;
		For(j,0,n){
			bool ok2 = 0;
			for(int k = 0; k <= i; k++){
				int prob = round((100.0*k)/(double)i);
				if(prob == p[j]){
					ok2 = 1;
					break;
				}
			}
			if(!ok2){
				ok = 0;
				break;
			}
		}
		if(ok){
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}

