#include <iostream>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    
    long long count = 0;
    long long factor = 1;
    
    while (n / factor != 0) {
        long long higher = n / (factor * 10);
        long long current = (n / factor) % 10;
        long long lower = n % factor;
        
        if (x == 0) {
            if (higher == 0) {
            } else {
                if (current > x) {
                    count += higher * factor;
                } else if (current == x) {
                    count += (higher - 1) * factor + lower + 1;
                } else { 
                    count += (higher - 1) * factor;
                }
            }
        } else {
            if (current > x) {
                count += (higher + 1) * factor;
            } else if (current == x) {
                count += higher * factor + lower + 1;
            } else { // current < x
                count += higher * factor;
            }
        }
        factor *= 10;
    }
    cout << count << endl;
    
    return 0;
}