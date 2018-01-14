#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 102;
int n, w;

struct node{
	int vol, id, ans;
};

bool cmp_vol(node a, node b){
	return a.vol < b.vol;
}

bool cmp_id(node a, node b){
	return a.id < b.id;
}

node a[N];

int main(void){
	scanf("%d%d", &n, &w);

	For(i,0,n){
		scanf("%d", &a[i].vol);
		a[i].id = i;
	}

	sort(a, a+n, cmp_vol);

	int last = 0;
	For(i,0,n){
		int add = max(last, (a[i].vol+1)/2);
		if(w < add){
			printf("-1\n");
			return 0;
		}

		a[i].ans = add;
		w -= add;
	}
	
	int i = n-1;
	while(i >= 0 and w > 0){
		int add = min(a[i].vol-a[i].ans, w);
		a[i].ans += add;
		w -= add;
		i--;
	}

	sort(a, a+n, cmp_id);

	For(i,0,n){
		printf("%d ", a[i].ans);
	}
	printf("\n");

	return 0;
}

