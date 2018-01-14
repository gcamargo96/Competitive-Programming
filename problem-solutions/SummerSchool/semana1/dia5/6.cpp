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

const int N = 1000002;
int n;
//string s;
char s[N];
map<char,int> cnt;
set<char> abre, fecha;

void init(){
	abre.insert('(');
	abre.insert('[');
	abre.insert('{');
	abre.insert('<');

	fecha.insert(')');
	fecha.insert(']');
	fecha.insert('}');
	fecha.insert('>');
}

int main(void){
	//init();
	//ios_base::sync_with_stdio(false);
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	//cin >> n;
	scanf("%d", &n);

	For(i,0,n){
		cnt.clear();
		//cin >> s;
		scanf("%s", s);
		stack<tuple<int,int,int,int> > p;
		bool res = 1;
		
		int j = 0, k = 0, size = strlen(s);
		while(j < size){
			for(k = j; k < size and (s[k] == '(' or s[k] == '[' or s[k] == '{' or s[k] == '<'); k++){
				cnt[s[k]]++;
			}
			if(k > j){
				p.push(tuple<int,int,int,int>(cnt['('], cnt['['], cnt['{'], cnt['<']));
				cnt.clear();
			}
			j = k;

			for(k = j; k < size and (s[k] == ')' or s[k] == ']' or s[k] == '}' or s[k] == '>'); k++){
				cnt[s[k]]++;
			}

			if(k > j){	
				if(p.empty()){
					res = 0;
					break;
				}
				tuple<int,int,int,int> antes = tuple<int,int,int,int>(-1,-1,-1,-1);
				
				while(p.top() != antes){
					antes = p.top();
					tuple<int,int,int,int>& topo = p.top();
		
					int c0 = min(cnt[')'], get<0>(topo));
					int c1 = min(cnt[']'], get<1>(topo));
					int c2 = min(cnt['}'], get<2>(topo));
					int c3 = min(cnt['>'], get<3>(topo));
				
					get<0>(topo) -= c0;
					get<1>(topo) -= c1;
					get<2>(topo) -= c2;
					get<3>(topo) -= c3;

					cnt[')'] -= c0;
					cnt[']'] -= c1;
					cnt['}'] -= c2;
					cnt['>'] -= c3;
					
					//cout << get<0>(topo) << " " << get<1>(topo) << " " << get<2>(topo) << " " << get<3>(topo) << endl;	

					if(get<0>(topo) == 0 and get<1>(topo) == 0 and get<2>(topo) == 0 and get<3>(topo) == 0){
						//cout << "popou" << endl;
						p.pop();
						antes = tuple<int,int,int,int>(-1,-1,-1,-1);
					}
					if(p.empty()){
						if(cnt[')'] or cnt[']'] or cnt['}'] or cnt['>']) res = 0;
						break;
					}
				}
			}
			j = k;

			if(res == 0) break;
		}

		if(!p.empty()){
			res = 0;
			//tuple<int,int,int,int>& topo = p.top();
			//cout << get<0>(topo) << " " << get<1>(topo) << " " << get<2>(topo) << " " << get<3>(topo) << endl;	
		}

		if(res) printf("T\n");
		else printf("NIL\n");
	}

	return 0;
}

