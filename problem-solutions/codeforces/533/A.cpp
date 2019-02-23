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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1005;
int n;
int a[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int ans = 1000000005, tt = 1;
	for(int t = 1; t <= 100; t++){
		int sum = 0;

		for(int j = 0; j < n; j++){
			int x = abs(t-a[j]);

			if(x > 1){
				sum += x-1;
			}
		}

		if(sum < ans){
			ans = sum;
			tt = t;
		}
	}

	printf("%d %d\n", tt, ans);

	return 0;
}