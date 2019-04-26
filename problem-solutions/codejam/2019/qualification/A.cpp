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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 105;
int t;
string n;
int a[N], b[N];

void print_num(int *a){
	bool flag = 0;
	for(int i = N-1; i >= 0; i--){
		if(a[i] > 0){
			flag = 1;
		}
		if(flag){
			printf("%d", a[i]);
		}
	}
}

int main(void){
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> n;
		reverse(n.begin(), n.end());

		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);

		for(int i = 0; i < n.size(); i++){
			a[i] = n[i]-'0';
		}

		for(int i = 0; i < n.size(); i++){
			if(a[i] > 0){
				a[i]--;
				b[i]++;
				break;
			}
		}

		for(int i = 0; i < N; i++){
			if(a[i] == 4){
				a[i]--;
				b[i]++;
			}
		}

		printf("Case #%d: ", caso);
		print_num(a);
		printf(" ");
		print_num(b);
		printf("\n");
	}

	return 0;
}