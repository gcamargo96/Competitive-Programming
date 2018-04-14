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

const int N = 200002;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	int x;
	ll tot = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		tot += v[i];
	}
	
	ll sum = 0, target = (tot+1)/2;
	for(int i = 0; i < n; i++){
		sum += v[i];
		if(sum >= target){
			printf("%d\n",i+1);
			return 0;
		}
	}

	return 0;
}