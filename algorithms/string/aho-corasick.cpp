const int MAXS = 315; //Sum of the lenght of all keywords
const int MAXC = 2; //Max chars in alphabet

int out[MAXS]; 

int f[MAXS];
int g[MAXS][MAXC];

int buildMatchingMachine(const vector<string> &words,
                         char lowestChar = '0',
                         char highestChar = '1') {
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    
    int states = 1;
        
    for (int i = 0; i < words.size(); ++i) {
        const string &keyword = words[i];
        int currentState = 0;
        for (int j = 0; j < keyword.size(); ++j) {
            int c = keyword[j] - lowestChar;
            if (g[currentState][c] == -1) {
                g[currentState][c] = states++;
            }
            currentState = g[currentState][c];
        }
        out[currentState] |= (1 << i);
    }
    
    for (int c = 0; c < MAXC; ++c) {
        if (g[0][c] == -1) {
            g[0][c] = 0;
        }
    }

    queue<int> q;
    for (int c = 0; c <= highestChar - lowestChar; ++c) {
        if (g[0][c] != -1 and g[0][c] != 0) {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size()) {
        int state = q.front();
        q.pop();
        for (int c = 0; c <= highestChar - lowestChar; ++c) {
            if (g[state][c] != -1) {
                int failure = f[state];
                while (g[failure][c] == -1) {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;

                out[g[state][c]] |= out[failure]; 
                q.push(g[state][c]);
            }
        }
    }

    return states;
}

int findNextState(int currentState, char nextInput,
                                    char lowestChar = '0') {
    int answer = currentState;
    int c = nextInput - lowestChar;
    while (g[answer][c] == -1) answer = f[answer];
    return g[answer][c];
}