#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > 1000) {
            cerr << A[i] << " > 1000";
            return 0;
        }
    }
}
