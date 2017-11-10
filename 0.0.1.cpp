#include <iostream>
#include <sstream>
using namespace std;
bool vvod(int & n, int * a)
{
    string str;
    getline(cin, str);
    istringstream stream(str);
    int element = -1;
    bool fail = true;
    for (int i = 0; i < n; ++i) {
        if (!(stream >> a[i])) {
            fail = false;
            break;
        }
    }
    if (stream >> element) fail = false;
    return fail;
}
int main() {
    int n;
    string str;
    getline(cin, str);
    istringstream stream(str);
    if (stream >> n) {
        int k = abs(n);
        int * a = new int[k];
        if (vvod(n, a) && n > 0) {
            for (int i = 0,j=n-1; i < n / 2 ; j--,i++) {
                swap(a[i], a[j]);
            }
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
        }
        else {
            cout << "An error has occured while reading input data.";
        }
    delete[] a;
    }
    cin.get();
    return 0;
}
