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

const int N = 300002;
int bit[N];
int n, k;
map<int,int> ida, volta;
set<int> all;
ii v[N];

void update(int id, int x){
	while(id < N){
		bit[id] += x;
		id += (id & -id);
	}
}

int query(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= (id & -id);
	}
	return sum;
}

int main(void){
	scanf("%d%d", &n, &k);

	int l, r;
	For(i,0,n){
		scanf("%d%d", &l, &r);
		update(l, 1);
		update(r+1, -1);
	}

	for(int i = 1; i <= 10; i++){
		printf("%d ", query(i)-query(i-1));
	}
	printf("\n");

	/*int l, r;
	For(i,0,n){
		scanf("%d%d", &v[i].fi, &v[i].se);
		all.insert(v[i].fi);
		all.insert(v[i].se);
	}

	int cnt = 1;
	for(auto it = all.begin(); it != all.end(); it++){
		if(!ida.count(*it)){
			ida[*it] = cnt;
			volta[cnt] = *it;
			cnt++;
		}
	}

	for(auto it = ida.begin(); it != ida.end(); it++){
		printf("%d -> %d\n", it->fi, it->se);
	}

	For(i,0,n){
		l = v[i].fi, r = v[i].se;
		printf("update de %d a %d\n", ida[l], ida[r]);
		update(ida[l], 1);
		update(ida[r]+1, -1);
	}

	for(int i = 1; i <= cnt; i++){
		printf("%d ", query(i)-query(i-1));
	}
	printf("\n\n");

	int cnt2 = 0, maior = -1;
	l = r = -1;
	int ll = -1;
	for(int i = 1; i <= cnt; i++){
		if(query(i)-query(i-1) >= k){
			if(cnt == 0) ll = i;
			cnt2++;
		}
		else{
			if(cnt2 > maior){
				l = ll;
				r = i;
				maior = cnt2;
			}
			cnt2 = 0;
		}	
	}

	int res = volta[r]-volta[r]+1;

	printf("%d\n", res);
	*/
	return 0;
}

