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
};

const int N = 200002;
int n;
vector<seq> cre, decr;

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

bool cmp_cre(seq a, seq b){
	return a.cl < b.cl;
}

bool cmp_decr(seq a, seq b){
	return a.op > b.op;
}

int main(void){
	fastcin;
	cin >> n;

	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		seq cur = calc(s, i+1);
		if(cur.op >= cur.cl){
			cre.pb(cur);
		}
		else{
			decr.pb(cur);
		}
	}

	sort(cre.begin(), cre.end(), cmp_cre);
	sort(decr.begin(), decr.end(), cmp_decr);

	// for(int i = 0; i < cre.size(); i++){
	// 	cout << cre[i].op << " " << cre[i].cl << endl;
	// }
	// for(int i = 0; i < decr.size(); i++){
	// 	cout << decr[i].op << " " << decr[i].cl << endl;
	// }
	// cout << endl;

	int tot = 0;
	for(int i = 0; i < cre.size(); i++){
		tot -= cre[i].cl;
		if(tot < 0){
			cout << "NO" << endl;
			return 0;
		}
		tot += cre[i].op;
	}

	for(int i = 0; i < decr.size(); i++){
		tot -= decr[i].cl;
		if(tot < 0){
			cout << "NO" << endl;
			return 0;
		}
		tot += decr[i].op;		
	}

	if(tot == 0){
		cout << "YES" << endl;
		for(int i = 0; i < cre.size(); i++){
			cout << cre[i].id << " ";
		}
		for(int i = 0; i < decr.size(); i++){
			cout << decr[i].id << " ";
		}
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}