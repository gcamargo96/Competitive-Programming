#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

int cnt[105];

class TreeAndVertex{
public:
	int get(vector<int> tree){
		if(tree.size() == 1){
			return 0;
		}
		int maior = 0;//, repet = 0;
		for(int i = 0; i < tree.size(); i++){
			cnt[tree[i]]++;
			cnt[i+1]++;
		}
		for(int i = 0; i < 105; i++){
			if(cnt[i] > maior){
				maior = cnt[i];
				//repet = i;
			}
		}
		//if(repet == 0){
			return maior;
		//}
		/*else{
			return maior+1;
		}*/
	}
};

int main(void){
	ios_base::sync_with_stdio(false);

	TreeAndVertex t;
	vector<int> v;
	int n, x; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.pb(x);
	}
	int res = t.get(v);
	cout << res << endl;

	return 0;
}
