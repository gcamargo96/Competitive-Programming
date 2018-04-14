#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

struct seq{
	int op, cl, id;

	seq() {
		op = cl = id = 0;
	}

	seq(int _id){
		op = cl = 0;
		id = _id;
	}

	bool operator<(const seq& b) const{
		if(cl == b.cl)
			return op > b.op;
		return cl < b.cl;
	}
};

const int N = 200002;
seq v[N];
int n;

seq calc(const string& s, int id){
	stack<char> p;

	seq ret(id); // (close, open)
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			p.push('(');
		}
		else if(p.empty()){
			ret.cl++;
		}
		else{
			p.pop();
		}
	}

	ret.op = p.size();
	return ret;
}

int main(void){
	fastcin;
	cin >> n;

	string s;
	for(int i = 0; i < n; i++){
		cin >> s;

		v[i] = calc(s, i+1);
	}

	sort(v, v+n);

	// for(int i = 0; i < n; i++){
	// 	cout << v[i].id << " ";
	// }
	// cout << endl;

	int op = 0;
	for(int i = 0; i < n; i++){
		if(v[i].cl > op){
			cout << "NO" << endl;
			return 0;
		}

		op -= v[i].cl;
		op += v[i].op;
	}

	if(op == 0){
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			cout << v[i].id << " ";
		}
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}