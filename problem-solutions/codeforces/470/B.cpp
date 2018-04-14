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

const int N = 1000002;
int x2;
vi v[2*N];
int ans[2*N];

void sieve(){
	for(int i = 2; i < N; i++){
		if(v[i].size() == 0){
			for(int j = i; j < N; j += i){
				v[j].pb(i);
			}
		}
	}
}

int main(void){
	sieve();
	scanf("%d", &x2);

	queue<int> q;
	q.push(4);
	
	for(int i = 3; i < N; i++){
		if(v[i][0] == i){
			q.push(i);
		}

		while(!q.empty()){
			if(ans[q.front()] == 0){
				ans[q.front()] = i;
			}
			q.pop();
		}

		for(int x : v[i]){
			q.push(i+x);
		}
	}

	// for(int i = 3; i <= x2; i++){
	// 	printf("%d ", ans[i]);
	// }
	// printf("\n");

	int x0 = N;
	for(int x1 = x2; x1 >= ans[x2]; x1--){
		x0 = min(x0, ans[x1]);
	}

	printf("%d\n", x0);

	return 0;
}