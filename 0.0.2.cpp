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
int *vswap(int * a, int k)
{
    for (int i = 0,j = k - 1; i < k / 2;j--, i++) {
        swap(a[i], a[j]);
    }
    return a;
}
int main() {
    int n;
    string str;
    getline(cin, str);
    istringstream stream(str);
    
    if (stream >> n) {
        int g = abs(n);
        int * a = new int[g];
        int k;
        if (vvod(n, a) && n > 0 ) {
            string str;
            getline(cin, str);
            istringstream stream(str);
            if (stream >> k) {
                int * b = new int[k];
                for (int i = 0; i < k; i++) {
                    b[i] = a[i];
                }
                int * c = new int[n - k];
                for (int i = 0,j = k; i < n - k; j++,i++) {
                    c[i] = a[j];
                }
                b = vswap(b, k);
                c = vswap(c, n - k);
                
                for (int i = 0; i < k; i++) {
                    a[i] = b[i];
                }
                for (int i = k,j = 0; i < n; i++,j++) {
                    a[i] = c[j];
                }
                a = vswap(a, n);
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " ";
                }
                
                delete[] a;
                delete[] b;
                delete[] c;
            }
            else {
                cout << "An error has occured while reading input data.";
            }
        }
        else {
            cout << "An error has occured while reading input data.";
        }
    }
    cin.get();
    return 0;
}
