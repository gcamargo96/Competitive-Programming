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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000002;
int bit[N];
int n, p;

void update(int id, int x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

int query(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

int bit_lower_bound(int x){
	int l = 1, r = n, ans = 1;
	while(l <= r){
		int mid = (l+r)/2;

		if(query(mid) >= x){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	return ans;
}

void print_bit(){
	for(int i = 1; i <= n; i++){
		printf("%d ", 	query(i) - query(i-1));
	}
	printf("\n");
}

int main(void){
	scanf("%d%d", &n, &p);

	for(int i = 1; i <= n; i++){
		update(i, 1);
	}

	int pos = 1;
	for(int i = 0; i < n-1; i++){
		// printf("pos = %d\n", pos);
		// print_bit();
		int tras = pos;
		int frente = query(n) - pos;

		int new_pos;
		if(frente >= p-1){
			new_pos = tras + p-1;
		}
		else{
			new_pos = (p-1 - frente)%(n-i);
			if(new_pos == 0)
				new_pos = n-i;
		}

		// printf("new_pos = %d\n", new_pos);
		int idx = bit_lower_bound(new_pos);
		update(idx, -1);
		
		if(new_pos == n){
			pos = 1;
		}
		else{
			pos = new_pos;
		}
	}
	// print_bit();

	int ans = bit_lower_bound(1);

	printf("%d\n", ans);

	return 0;
}