#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
int n, m;
int v[N];
vector<int> asc, desc;

int main(void){
	scanf("%d%d", &n, &m);

	For(i,0,n){
		scanf("%d", &v[i]);
	}
	For(i,0,n-1){
		if(v[i] > v[i+1]) desc.pb(i+1);
		if(v[i] < v[i+1]) asc.pb(i+1);
	}

	int l, r;
	For(i,0,m){
		scanf("%d%d", &l, &r);
		
		if(r-l+1 <= 2){
			printf("Yes\n");
			continue;
		}

		l, r--;
		
		auto d = lower_bound(desc.begin(), desc.end(), l);
		auto a = upper_bound(asc.begin(), asc.end(), r);

		if(a != asc.begin()){
			a--;
			if(d != desc.end() and *d >= l and *d <= r and *a >= l and *a <= r){
				if(*d < *a){
					printf("No\n");
				}
				else{
					printf("Yes\n");
				}
			}
			else{
				printf("Yes\n");
			}
		}
		else{
			printf("Yes\n");
		}
	}
	
	return 0;
}

