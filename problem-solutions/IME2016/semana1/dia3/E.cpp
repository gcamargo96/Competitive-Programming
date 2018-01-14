#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int n, m, d, l, res;
vector<int> gophers;
set<int> cds;

bool interfere(int gopher, int cd){
	if(cd-l <= gopher and gopher <= cd+l) return 1;
	return 0;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> d >> l;

	int x;
	gophers.pb(0);
	for(int i = 1; i < n; i++){
		cin >> x;
		gophers.pb(x);
	}

	for(int i = 0; i < m; i++){
		cin >> x;
		cds.insert(x);
	}

	set<int>::iterator it;
	res = n;
	for(int i = 0; i < n; i++){
		it = cds.lower_bound(gophers[i]);
		if(it != cds.begin()){
			it--;
			if(interfere(gophers[i], *it)) continue;
		}
		it = cds.lower_bound(gophers[i]);
		if(it != cds.end()){
			if(interfere(gophers[i], *it)) continue;
		}
		res--;
	}

	cout << res << endl;

	int p, r;
	for(int i = 0; i < d; i++){
		cin >> p >> r;
	
		cds.erase(p);
		int left, right;
		it = cds.lower_bound(p);
		if(it == cds.begin()){
			left = p-l;
		}
		else{
			it--;
			left = max(*it+l+1, p-l);
		}
		it = cds.lower_bound(p);
		if(it == cds.end()){
			right = p+l;
		}
		else{
			right = min(*it-l-1, p+l);
		}

		if(left <= right){
			int x = lower_bound(gophers.begin(), gophers.end(), left) - gophers.begin();
			int y = upper_bound(gophers.begin(), gophers.end(), right) - gophers.begin();
			res -= y-x;
		}

		it = cds.lower_bound(r);
		if(it == cds.begin()){
			left = r-l;
		}
		else{
			it--;
			left = max(*it+l+1, r-l);
		}
		it = cds.lower_bound(r);
		if(it == cds.end()){
			right = r+l;
		}
		else{
			right = min(*it-l-1, r+l);
		}

		if(left <= right){
			int x = lower_bound(gophers.begin(), gophers.end(), left) - gophers.begin();
			int y = upper_bound(gophers.begin(), gophers.end(), right) - gophers.begin();
			res += y-x;
		}
		
		cds.insert(r);
		
		cout << res << endl;
	}


	return 0;
}
