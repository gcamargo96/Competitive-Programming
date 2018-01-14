#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200002;
set<int> numbers;
int n, k;
int v[N];

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; i++){
		numbers.insert(i);
	}

	vi ans;
	for(int i = 0; i < k; i++){
		scanf("%d", &v[i]);
		ans.pb(v[i]);
		numbers.erase(v[i]);
	}

	int nxt = 1;
	stack<int> s;
	for(int i = 0; i < k; i++){
		if(s.empty() or s.top() > v[i]){
			s.push(v[i]);
		}
		else{
			printf("-1\n");
			return 0;
		}

		while(!s.empty() and s.top() == nxt){
			// v.pb(s.top());
			s.pop();
			nxt++;
		}		
	}

	while(!s.empty() or !numbers.empty()){
		while(!s.empty() and s.top() == nxt){
			// v.pb(s.top());
			s.pop();
			nxt++;
		}

		while(numbers.count(nxt)){
			vi to_erase;
			if(s.empty()){
				auto it = numbers.end();
				it--;
				while(it != numbers.begin()){
					s.push(*it);
					ans.pb(*it);
					to_erase.pb(*it);
					it--;
				}
				ans.pb(*it);
				s.push(*it);
				to_erase.pb(*it);
			}
			else{
				auto it = numbers.lower_bound(s.top());
				it--;
				while(it != numbers.begin()){
					s.push(*it);
					ans.pb(*it);
					to_erase.pb(*it);
					it--;
				}
				ans.pb(*it);
				s.push(*it);
				to_erase.pb(*it);
			}

			for(int i = 0; i < to_erase.size(); i++){
				numbers.erase(to_erase[i]);
			}
		}
	}

	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}