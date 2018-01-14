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

const int N = 100002;
int first[N], last[N];
int n;

int main(void){
	memset(first, -1, sizeof first);
	memset(last, -1, sizeof last);

	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(first[x] == -1){
			first[x] = i;
		}
		last[x] = i;
	}

	int ans = 1;
	for(int i = 1; i <= 100000; i++){
		// cout << first[i] << " " << last[i] << endl;
		ans = max(ans, last[i]-first[i]+1);
	}

	printf("%d\n", ans);

	return 0;
}