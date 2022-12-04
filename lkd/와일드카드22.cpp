#include iostream
#include cstring
#include set
using namespace std;

int cache[100][100];
string W, S;
int N;


bool match(int w, int s)
{
    if(w==W.length()) return (s == S.length());
    int& ret = cache[w][s];
    if(ret != -1) return ret;

    if(W[w] == ''  W[w] == S[s]) return ret = match(w+1, s+1);

    if(W[w] == '')
        return ret = (match(w+1,s)  (sS.length() && match(w, s+1)));

    return ret = 0;
}

int main()
{
    int C;
    cin  C;
    while(C--)
    {
        cin  W  N;
        setstring ans;

        while(N--)
        {
            memset(cache, -1, sizeof(cache));
            cin  S;
            if(match(0, 0)) ans.insert(S);
        }

        for(auto& a ans) cout  a  endl;
        ans.clear();
    }
}