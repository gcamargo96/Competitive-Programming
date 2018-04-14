#include <bits/stdc++.h>
using namespace std;
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

const int N = 1000002;
bool vis[N];
int n;

int main(void){
	scanf("%d", &n);

	int p;
	for(int i = 0; i < n; i++){
		scanf("%d", &p);
		vis[p] = 1;
	}

	int cnt = 0, temp = 0;
	for(int i = 1, j = 1000000; i <= j and cnt < n; i++, j--){
		if(vis[i]){
			cnt++;
		}
		if(vis[j]){
			cnt++;
		}
		if(cnt >= n){
			break;
		}
		temp++;
	}

	printf("%d\n", temp);

	return 0;
}