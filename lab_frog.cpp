#include <iostream>
using namespace std;
int main()
{
    int n,or1=3,or2=4;
    cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > 1000) {
            cerr << i << " > 1000";
            return 0;
        }
    }
    if (n == 2) {
        cout << "-1";
        return 0;
    }
    if (n == 1) {
        cout << A[0];
        cout << "1";
        return 0;
    }

    int k = n;
    int* B = new int[k];
    int j = 1;
    B[0] = 0;

    // Основной цикл
    for (int i = 2; i < n; i++) {
        if (i > 4) {
            if ((A[i] + A[i - 3]) < (A[i] + A[i - 2])) {
                A[i] = A[i] + A[i - 2];
                B[j] = i - 1;
               /* B[l] = or2;
                l++;*/
                
            }
            else {
                A[i] = A[i] + A[i - 3];
                B[j] = i - 2;
               /* B[l] = or1;
                l++;*/
            }
        }
        else {
            if (i == 2 || i == 3) {
                A[i] = A[i] + A[0];
                
                
            }
            if (i == 4) {
                A[4] = A[4] + A[2];
               
            }
        }
        j++;

    }
    
    cout << A[n-1]<<endl;
    /*B[0] = n;
    for (int i = n-1; i >= 0; i--) {
        int k = i;
        if (A[i - 2] < A[i - 3]) {
            k = k - 3;
            B[j] = i - 2;
        }
        if (A[i - 2] > A[i - 3]) {
            k = k - 2;
            B[j] = i - 1;
        }
        if (A[i - 2] == A[i - 3]) {
            k = k - 2;
            B[j] = i - 1;
        }
        j++;
        i = k;
    }
    B[j] = 1;*/
    for (int i = 0; i <= j; i++) {
        cout << B[i] << " ";
    }
    

}
