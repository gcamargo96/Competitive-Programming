#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mk make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

struct Rune{
	int r1, r2, r3;
};

const int N = 102;
int t, n, rings, runes;
int r1, r2, r3, aux;
bool null_ring, invalid_ring, repeated_ring;
Rune v[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;
	
	while(t--){
		null_ring = invalid_ring = repeated_ring = 0;
		cin >> rings >> runes;
		
		for(int i = 0; i < runes; i++){
			cin >> r1 >> r2 >> r3 >> aux;
			if(!r1 or !r2 or !r3) null_ring = 1;
			if(r1 < -rings or r1 > rings  or r2 < -rings or r2 > rings or r3 < -rings or r3 > rings) invalid_ring = 1;
			if(abs(r1) == abs(r2) or abs(r2) == abs(r3) or abs(r1) == abs(r3)) repeated_ring = 1;
			v[i].r1 = r1, v[i].r2 = r2, v[i].r3 = r3;
		}
		
		if(null_ring){
			cout << "INVALID: NULL RING" << endl;
		}
		else if(invalid_ring){
			cout << "INVALID: RING MISSING" << endl;
		}
		else if(repeated_ring){
			cout << "INVALID: RUNE CONTAINS A REPEATED RING" << endl;
		}
		else{
			int bitmask, res = 0;
			for(bitmask = 0; bitmask <= (1 << 22); bitmask++){
				bool finished = 1;
				bool foi = 0;
				for(int j = 0; j < runes; j++){
					foi = 0;
					if(v[j].r1 > 0 and (bitmask & (1 << v[j].r1)) >= 1){
						foi = 1;
						continue;
					}
					if(v[j].r2 > 0 and (bitmask & (1 << v[j].r2)) >= 1){
						foi = 1;
						continue;
					}
					if(v[j].r3 > 0 and (bitmask & (1 << v[j].r3)) >= 1){
						foi = 1;
						continue;
					}
					
					if(v[j].r1 < 0 and (bitmask & (1 << -v[j].r1)) == 0){
						foi = 1;
						continue;
					}
					if(v[j].r2 < 0 and (bitmask & (1 << -v[j].r2)) == 0){
						foi = 1;
						continue;
					}
					if(v[j].r3 < 0 and (bitmask & (1 << -v[j].r3)) == 0){
						foi = 1;
						continue;
					}
					
					if(!foi){
						finished = 0;
						break;
					}
				}
				
				if(finished){
					res = 1;
					break;
				}
			}
			
			if(res){
				cout << "RUNES SATISFIED!" << endl;
			}
			else{
				cout << "RUNES UNSATISFIABLE! TRY ANOTHER GATE!" << endl;
			}
		}
	}
	
	return 0;
}
