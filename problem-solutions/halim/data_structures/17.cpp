#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 102;
queue<int> v[N];
stack<int> car;
int t, n, s, q;

bool finished(){
	if(!car.empty()) return 0;
	
	For(i,0,n){
		if(!v[i].empty()) return 0;
	}
	
	return 1;
}

int main(void){
	scanf("%d", &t);

	For(i,0,t){
		scanf("%d%d%d", &n, &s, &q);
		
		For(j,0,n){
			int qi;
			scanf("%d", &qi);

			int to;
			For(k,0, qi){
				scanf("%d", &to);
				v[j].push(to);
			}
		}

		int j = 0, res = 0;
		bool fi = 1;
		while(!finished()){
			if(fi){
				fi = 0;
			}
			else{
				res += 2;
			}

			while(!car.empty() and (car.top() == j+1 or v[j].size() < q)){
				if(car.top() != j+1){
					v[j].push(car.top());
				}
				car.pop();
				res++;
			}

			while(!v[j].empty() and car.size() < s){
				car.push(v[j].front());
				v[j].pop();
				res++;
			}

			j = (j+1)%n;
		}

		printf("%d\n", res);
	}

	return 0;
}
