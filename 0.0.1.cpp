#include<sstream>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int main()
{
    int err;
    string str;
    bool fail;
    cin >> n;
    cin.ignore(1, '\n');
    getline(cin, str);
    istringstream stream(str);
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        if (!(stream >> a[i]) || n<0) {
            fail=true;
        }
        if (stream>>err) fail=true;
    }
    if(!fail){
        for (int i = 0; i < n / 2; i++) {
            swap(a[i], a[n-1- i]);
        }
    }
    else{
        cout<<"An error has occured while reading input data.";
        cin.get();
        return 0;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cin.get();
    return 0;
}
