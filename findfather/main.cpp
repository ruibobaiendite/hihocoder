#include <iostream>
#include <vector>
using namespace std;

struct node{
    int par;
    vector<int> neig;
    node(){
        par = -1;
        neig = {};
    }
};

vector<node> S;

void traverse(int cur, int par){

    for(int i = 0; i < S[cur].neig.size(); i++){
        if(S[cur].neig[i] == par)
            continue;
        S[S[cur].neig[i]].par = cur;
        traverse(S[cur].neig[i], cur);
    }
}

int main() {
    int N;
    int k;
    cin>>N>>k;
    int n1, n2;
    S.resize(N+1);
    for(int i = 0; i < N - 1; i++){
        cin>>n1>>n2;
        S[n1].neig.push_back(n2);
        S[n2].neig.push_back(n1);
    }
    S[k].par = 0;
    traverse(k, 0);
    cout<<S[1].par;
    for (int i = 2; i <= N; i++){
        cout << " " << S[i].par;
    }
    cout << endl;
    return 0;
}