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

int t, n, k;

int main(void){
	scanf("%d", &t);

	while(t--){
		set<int> s;
		scanf("%d%d", &n, &k);

		int x;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			s.insert(x);
		}

		int cnt = 0;
		for(int i = 0; cnt < k and i < 200002; i++){
			if(!s.count(i)){
				// printf("inseriu %d\n", i);
				s.insert(i);
				cnt++;
			}
		}

		int ans = 0;
		for(int i = 0; i < 200002; i++){
			if(!s.count(i)){
				ans = i;
				break;
			}
		}
		
		printf("%d\n", ans);
	}


	return 0;
}