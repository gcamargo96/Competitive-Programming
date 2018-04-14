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

const int N = 100005;
int t;
int n;

int main(void){
	scanf("%d", &t);

	for(int c = 1; c <= t; c++){
		scanf("%d", &n);

		int x;
		priority_queue<int, vector<int>, greater<int> > q0, q1;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			if(i%2 == 0){
				q0.push(x);
			}
			else{
				q1.push(x);
			}
		}

		vi v;
		for(int i = 0; i < n; i++){
			if(i%2 == 0){
				v.pb(q0.top());
				q0.pop();
			}
			else{
				v.pb(q1.top());
				q1.pop();
			}
		}

		// for(int i = 0; i < n; i++){
		// 	printf("%d ", v[i]);
		// }
		// printf("\n");

		int ans = -1;
		for(int i = 0; i < n-1; i++){
			if(v[i] > v[i+1]){
				ans = i;
				break;
			}
		}


		if(ans == -1){
			printf("Case #%d: OK\n", c);
		}
		else{
			printf("Case #%d: %d\n", c, ans);
		}
	}

	return 0;
}