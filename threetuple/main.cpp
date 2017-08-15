#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){

    int n;
    int one = 0, two = 0;
    long long ret = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 3){
            ret += one * two;
        }
        else if(x == 1){
            one++;
        }
        else{
            two++;
        }
    }
    cout << ret << endl;


    return 0;
}