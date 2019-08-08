#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

class PartitionArray{
public:
	const int N = 505;
	int dp[505];
	int n;
	vector<int> ans;

	int solve(vector<int>& a, int i){
		if(i == n) return 1;
		if(dp[i] != -1) return dp[i];

		int sum = 0, ret = 0;
		for(int j = i; j < n; j++){
			sum += a[j];

			if(sum > 0){
				ret |= solve(a, j+1);
			}
		}

		return dp[i] = ret;
	}

	void build(vector<int>& a, int i){
		if(i == n) return;

		int sum = 0;
		for(int j = i; j < n; j++){
			sum += a[j];

			if(sum > 0 and dp[j+1] == 1){
				ans.push_back(j-i+1);
				build(a, j+1);
				break;
			}
		}
	}

	vector <int> positiveSum(vector <int> a){
		n = a.size();

		memset(dp, -1, sizeof dp);
		dp[n] = 1;
		int ok = solve(a, 0);
		// printf("%d\n", ok);
		
		if(ok){
			build(a, 0);
		}else{
			ans.push_back(-1);
		}

		return ans;
	}

};

int main(void){
	PartitionArray p;

	int n; scanf("%d", &n);

	vector<int> a;
	for(int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		a.push_back(x);
	}

	vector<int> ans = p.positiveSum(a);

	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}