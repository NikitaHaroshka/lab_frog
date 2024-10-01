#include <iostream>

using namespace std;
int main()
{
    int n, or1 = 3, or2 = 4, j = 0;
    cin >> n;
    int* A = new int[n];
    int* B = new int[n];
    int* pr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > 1000) {
            cerr << i << " > 1000";
            delete[] A;
            delete[] B;
            delete[] pr;
            return 0;
        }
    }
    if (n == 3) {
        cout << A[2] + A[0] << endl;
        cout << "1 3";
        delete[] A;
        delete[] B;
        delete[] pr;
        return 0;
    }
    if (n == 2) {
        cout << "-1";
        delete[] A;
        delete[] B;
        delete[] pr;
        return 0;
    }
    if (n == 1) {
        cout << A[0] << endl;
        cout << "1";
        delete[] A;
        delete[] B;
        delete[] pr;
        return 0;
    }
    pr[0] = -1;
    pr[1] = -1;
    pr[2] = 1;
    pr[3] = 1;
    pr[4] = 3;
    A[1] = -1;
    A[2] = A[2] + A[0];
    
    for (int i = 3; i < n; i++) {
            if ((A[i] + A[i - 3]) < (A[i] + A[i - 2])) {
                A[i] = A[i] + A[i - 2];
                pr[i] = i - 1;
                j++;
            }
            else {
                A[i] = A[i] + A[i - 3];
                pr[i] = i - 2;
                j++;
            }
    }

    cout << A[n - 1] << endl;
    pr[n] = n;
    

    B[0] = n;
    int k = 1;
    for (int i = n - 1; i > 0; i--) {
        while (pr[i] != -1) {
            B[k] = pr[i];
            i = pr[i] - 1;
            k++;

        }
    }

    for (int i = k - 1; i >= 0; i--) {
        cout << B[i] << " ";
    }
    delete[] A;
    delete[] B;
    delete[] pr;
    return 0;
}
