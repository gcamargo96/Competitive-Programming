#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 1502*1502;
int k[3];
int x1, x2, x3;
bool vis[N];

bool check(){
	memset(vis, 0, sizeof vis);
	
	for(int i = 0; i < N; i += k[0]){
		vis[i] = 1;
	}

	for(int i = 1; i < N; i += k[1]){
		vis[i] = 1;
	}

	for(int i = 2; i < N; i += k[2]){
		vis[i] = 1;
	}

	for(int i = 2; i < N; i++){
		if(!vis[i])
			return 0;
	}

	return 1;
}

int main(void){
	for(int i = 0; i < 3; i++){
		scanf("%d", &k[i]);
	}

	sort(k, k+3);

	do{
		if(check()){
			printf("YES\n");
			return 0;
		}
	}while(next_permutation(k, k+3));

	printf("NO\n");

	return 0;
}