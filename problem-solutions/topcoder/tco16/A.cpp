#include <iostream>
#include <string>
using namespace std;

class EllysTimeMachine{
public:
    string getTime(string time){
    	string hour, minute;
        /*hour += time[0];
        hour += time[1];
        minute += time[3];
        minute += time[4];*/
        
        int h = (time[0]-'0')*10+time[1]-'0'; //stoi(hour, nullptr, 10);
        int m = (time[3]-'0')*10+time[4]-'0';
        h *= 5;
        m /= 5;
        
		if(m == 0) m = 12;

        int auxh = m/10, auxm = h/10;
        string res;
        res += auxh+'0';
        res += m%10+'0';
        res += ':';
        res += auxm+'0';
        res += h%10+'0';
        
        //cout << res << endl;
        
        return res;
    }

};


int main(void){
	EllysTimeMachine m;
	string ent; cin >> ent;
	string s = m.getTime(ent);
	cout << s << endl;
}
