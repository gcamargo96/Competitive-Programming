#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 102;
int n;
int v[N];
bool used[N];

bool cmp(int a, int b){
	return a > b;
}

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &v[i]);
	}

	sort(v, v+n, cmp);

	int res = 0, cnt = 0;
	while(cnt < n){
		For(i,0,n){
			if(!used[i]){
				res++;
				used[i] = 1;
				cnt++;
				int tam = 0, cap = v[i];
				//stack<int> p;
				for(int j = n-1; j > i and tam < cap and cap > 0; j--){
					if(!used[j] and v[j] >= tam){
						//p.push(v[j]);
						used[j] = 1;
						cnt++;
						tam++;
					}
				}
				/*p.push(v[i]);
				while(!p.empty()){
					printf("%d ", p.top());
					p.pop();
				}
				printf("\n");
				*/
			}
		}
	}

	printf("%d\n", res);

	return 0;
}

