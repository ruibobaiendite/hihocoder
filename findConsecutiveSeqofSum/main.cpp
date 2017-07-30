#include <iostream>
#include "vector"
#include "deque"
using namespace std;


int getseq(int x){
    if(x > 100000){
        int y
        while()
    }
    int h = 1;
    int t = 1;
    int sum = 1;
    deque<int> ret = {1};
    while(h <= x){
        while(t<=x && sum < x){
            t++;
            sum += t;
            ret.push_back(t);
            if(sum == x){
                return ret.size();
            }
        }
        sum -= h;
        h++;

        ret.pop_front();
        if(sum == x)
            return ret.size();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> ret;
    for(int i = 0; i < n; i++){
        int curn;
        cin >> curn;
        ret.push_back(getseq(curn));
    }
    for(int i = 0; i < n; i++){
        cout << ret[i]<< endl;
    }

    return 0;
}