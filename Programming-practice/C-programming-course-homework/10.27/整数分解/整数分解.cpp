#include <iostream>
#include <cmath>  
using namespace std;
int main() {
    int n;
    cin >> n;
    int result;
    if (n == 2) {
        result = 1;  
    } else if (n == 3) {
        result = 2;  
    } else {
        switch (n % 3) {
            case 0:
                result = pow(3, n / 3);
                break;
            case 1:
                result = 4 * pow(3, (n - 4) / 3);
                break;
            case 2:
                result = 2 * pow(3, n / 3);
                break;
        }
    }
    cout << result << endl;
    return 0;
}
