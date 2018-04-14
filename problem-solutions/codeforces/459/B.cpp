#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 1002;
int n, m;
map<string, string> ip_name;

int main(void){
	fastcin;
	cin >> n >> m;

	string name, ip;
	for(int i = 0; i < n; i++){
		cin >> name >> ip;
		ip_name[ip] = name;
	}

	string com;
	for(int i = 0; i < m; i++){
		cin >> com >> ip;
		ip.pop_back();

		cout << com << " " << ip << "; #" << ip_name[ip] << endl;
	}

	return 0;
}