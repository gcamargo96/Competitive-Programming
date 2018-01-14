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
 
const int N = 52;
int t, x, n;
int dp[N][N*N], op[N][N*N];
int total;
string path;
 
bool solve(int i, int sum){
	if(i > n){
		if(sum == total/2)
			return 1;
		return 0;
	}
 
	if(i == x){
		return dp[i][sum] = solve(i+1, sum);
	}
 
	if(dp[i][sum] != -1)
		return dp[i][sum];
 
	bool A = solve(i+1, sum + i);
	bool B = solve(i+1, sum);
 
	if(A)
		op[i][sum] = 0;
	else
		op[i][sum] = 1;
 
	return dp[i][sum] = A or B;
}
 
void get_path(int i, int sum){
	if(i > n){
		return;
	}
 
	if(i == x){
		path += '2';
		get_path(i+1, sum);
		return;
	}
 
	if(op[i][sum] == 0){
		path += '0';
		get_path(i+1, sum + i);
	}
	else{
		path += '1';
		get_path(i+1, sum);
	}
}
 
int main(void){
	scanf("%d", &t);
 
	while(t--){
		scanf("%d%d", &x, &n);
 
		total = ((1+n)*n)/2 - x;
		
		if(total%2 == 1){
			printf("impossible\n");
			continue;
		}
 
		memset(dp, -1, sizeof dp);
		bool ans = solve(1, 0);
 
		if(!ans){
			printf("impossible\n");
			continue;
		}
 
		path.clear();
		get_path(1, 0);
 
		cout << path << endl;
	}
 
	return 0;
}