#include <iostream>
#include <fstream>
#include <cstdio>
#include<stdio.h>
using namespace std;

int t[1000000+10] = {};
int main() {
    freopen("test.txt", "r", stdin);
    int M, N, T, K1, K2;
    int cc = 0;
    int curm = 0;
    cin >> N >> M >> T >> K1 >> K2;

    if(K1>M || K2>M)
        return -1;
    if(K1 > M/2+1 && K2 > M/2+1)
        return T;

    for(int i = 0; i < N; i++){
        int b, e;
        cin >> b >> e;
        t[b] = K1;
        t[e+1] = K2;
    }
    if(t[1] == 0) t[1] = K2;
    int curk = t[1];
    for(int i = 1; i <= T; i++){
        if(t[i] && curk != t[i])
            curk = t[i];
        if(curm < curk) {
            cc++;
            curm = M;
        }
        curm -= curk;
    }

    std::cout << cc << std::endl;
    return 0;
}