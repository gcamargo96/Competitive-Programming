#include <bits/stdc++.h>
using namespace std;
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

const int N = 100005;
int n;
int w[N], h[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &w[i], &h[i]);
	}

	int last = 1000000005;
	for(int i = 0; i < n; i++){
		if(w[i] < h[i]) swap(w[i], h[i]);
		
		if(w[i] <= last){
			last = w[i];
		}
		else if(h[i] <= last){
			last = h[i];
		}
		else{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	return 0;
}