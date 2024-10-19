#include <iostream>
#include <vector>

using namespace std;

// 求两个多项式的和
vector<int> addPolynomials(const vector<int>& poly1, const vector<int>& poly2) {
    int maxDegree = max(poly1.size(), poly2.size());
    vector<int> sum(maxDegree, 0);

    for (int i = 0; i < poly1.size(); ++i) {
        sum[i] += poly1[i];
    }
    for (int i = 0; i < poly2.size(); ++i) {
        sum[i] += poly2[i];
    }

    return sum;
}

// 求两个多项式的乘积
vector<int> multiplyPolynomials(const vector<int>& poly1, const vector<int>& poly2) {
    int degree1 = poly1.size();
    int degree2 = poly2.size();
    vector<int> product(degree1 + degree2 - 1, 0);

    for (int i = 0; i < degree1; ++i) {
        for (int j = 0; j < degree2; ++j) {
            product[i + j] += poly1[i] * poly2[j];
        }
    }

    return product;
}

int main() {
    vector<int> poly1 = {3, 5, -10, 0, 7, 0, 6}; // 3 + 5x + (-10)x^2 + 0x^3 + 7x^4 + 0x^5 + 6x^6
    vector<int> poly2 = {1, 0, 2, 0, 0, 4};      // 1 + 0x + 2x^2 + 0x^3 + 0x^4 + 4x^5

    vector<int> result = addPolynomials(poly1, poly2);
    cout << "Sum of polynomials: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << "x^" << i;
        if (i < result.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    vector<int> result2 = multiplyPolynomials(poly1, poly2);
    cout << "Product of polynomials: ";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << "x^" << i;
        if (i < result2.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    // 暂停
    cin.get();

    return 0;
}
