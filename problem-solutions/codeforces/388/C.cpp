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

int n;
queue<int> d, r;

int main(void){
	scanf("%d", &n);

	char c;
	For(i,0,n){
		scanf(" %c", &c);
		if(c == 'D') d.push(i);
		else r.push(i);
	}

	while(!d.empty() and !r.empty()){
		int df = d.front();
		int rf = r.front();

		if(df < rf){
			d.push(df+n);
		}
		else{
			r.push(rf+n);
		}

		d.pop();
		r.pop();
	}

	if(!d.empty()) printf("D\n");
	else printf("R\n");

	return 0;
}

