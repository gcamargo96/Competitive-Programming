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

const int N = 5002;
int n;
int v[N], vis[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	sort(v, v+n);

	int ans = n;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(v[j] > v[i] and !vis[j]){
				vis[j] = 1;
				ans--;
				break;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}