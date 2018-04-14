#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define ii pair<int,int>
#define fi first
#define se second
#define INF 2147483648
#define endl "\n"

using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int n;
ordered_set s;
map<string,int> m, r; // code -> id, code -> reliability
map<int,string> c; // id -> code
int id = 0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	string op, code;
	for(int i = 0; i < n; i++){
		cin >> op;
		if(op == "ISSUE"){
			cin >> code;
			if(m.count(code)){
				cout << "EXISTS " << m[code] << " " << r[code] << endl;
			}
			else{
				cout << "CREATED " << id << " 0" << endl;
				s.insert(ii(0, id));
				r[code] = 0;
				c[id] = code;
				m[code] = id++;
			}
		}
		if(op == "DELETE"){
			cin >> code;
			if(m.count(code)){
				auto it = s.find(ii(-r[code], m[code]));
				cout << "OK " << m[code] << " " << r[code] << endl;
				m.erase(code);
				r.erase(code);
				c.erase(it->se);
				s.erase(it);
			}
			else{
				cout << "BAD REQUEST" << endl;
			}
		}
		if(op == "RELIABILITY"){
			cin >> code;
			int k; cin >> k;

			if(m.count(code)){
				auto it = s.find(ii(-r[code], m[code]));
				r[code] += k;
				ii novo = ii(-r[code], m[code]);
				// cout << "ID = " << it->se << "RELIABILITY = " << it->fi << endl;
				s.erase(it);
				s.insert(novo);
				cout << "OK " << m[code] << " " << r[code] << endl;
			}
			else{
				cout << "BAD REQUEST" << endl;
			}
		}
		if(op == "FIND"){
			int k; cin >> k;

			if(s.empty()){
				cout << "EMPTY" << endl;
			}
			else if(k+1 >= s.size()){
				auto it = s.end();
				it--;
				cout << "OK " << c[it->se] << " " << it->se << " " << -it->fi << endl;
			}
			else{
				auto it = s.find_by_order(k);
				cout << "OK " << c[it->se] << " " << it->se << " " << -it->fi << endl;
			}
		}
	}

	return 0;
}