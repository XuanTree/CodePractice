#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int space = n - i;
        int star = 2 * i - 1;
        int j = 0;
        while(j < space){
            cout << " ";
            j++;
        }
        int k = 0;
        while(k < star){
            cout << "*";
            k++;
        }
        cout << endl;
    }
    return 0;
}