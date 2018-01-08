#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("text.txt", "r", stdin);
    freopen("answer.txt", "w", stdout);
    string a;
    cin >> a;
    int c, d, e, f, r = a.length();
    int arr[30];
    int alph[30];
    for (int i=0; i<30; i++){
        arr[i]=0;
        alph[i]=i;
    }
    for (int i=0; i<r; i++){
        c=a[i]-'a';
        arr[c]++;
    }


    for (int i = 0; i < 30; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
                swap(alph[j-1], alph[j]);
            }
        }
    }

    int k=0;

    for (int i=0; i<30; i++){

        if (arr[i]!=0) k++;

    }

    for (int i=29;i>29-k;i--){
        arr[29-i]=arr[i];
    }

    for (int i=29; i>29-k; i--){
        alph[29-i]=alph[i];
    }
    for(int i=0; i<k;i++){
        cout <<arr[i]<<"    "<<alph[i]<<endl;
    }
    return 0;
}
