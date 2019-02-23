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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define A 0
#define B 1

const int N = 100005;
int n;
priority_queue<int> a, b;
ll suma = 0, sumb = 0;

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		a.push(x);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		b.push(x);
	}

	bool turn = A;
	while(!a.empty() or !b.empty()){
		if(turn == A){
			if(!a.empty() and !b.empty()){
				if(a.top() > b.top()){
					suma += a.top();
					a.pop();
				}
				else{
					// printf("tirou %d de b\n", b.top());
					b.pop();
				}
			}
			else if(!a.empty()){
				suma += a.top();
				a.pop();
			}
			else if(!b.empty()){
				b.pop();
			}
		}
		else{ // turn == B
			if(!a.empty() and !b.empty()){
				if(b.top() > a.top()){
					sumb += b.top();
					b.pop();
				}
				else{
					a.pop();
				}
			}
			else if(!b.empty()){
				sumb += b.top();
				b.pop();
			}
			else if(!a.empty()){
				a.pop();
			}
		}

		turn = !turn;
	}

	printf("%lld\n", suma-sumb);

	return 0;
}