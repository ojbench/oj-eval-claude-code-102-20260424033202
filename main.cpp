#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Convert char to its integer value in base B
int charToInt(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (islower(c)) {
        return c - 'a' + 10;
    } else if (isupper(c)) {
        return c - 'A' + 10;
    }
    return 0;
}

// Convert integer value to its char representation in base B
char intToChar(int val) {
    if (val < 10) {
        return '0' + val;
    } else {
        return 'A' + (val - 10);
    }
}

int main() {
    int m, n, B;
    if (!(cin >> m >> n >> B)) return 0;

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = m - 1;
    int len2 = n - 1;
    int maxLen = max(len1, len2);

    string result = "";
    int carry = 0;

    for (int i = 0; i < maxLen; ++i) {
        int v1 = 0;
        if (i < len1) {
            v1 = charToInt(str1[len1 - 1 - i]);
        }

        int v2 = 0;
        if (i < len2) {
            v2 = charToInt(str2[len2 - 1 - i]);
        }

        int sum = v1 + v2 + carry;
        result += intToChar(sum % B);
        carry = sum / B;
    }

    // Reverse the result because we added digits from least significant
    reverse(result.begin(), result.end());

    cout << result << endl;

    return 0;
}
