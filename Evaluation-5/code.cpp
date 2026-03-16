#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    while (m--) {
        string q;
        cin >> q;

        bool found = false;

        for (string &s : words) {
            if (s.size() != q.size()) continue;

            int diff = 0;

            for (int i = 0; i < s.size(); i++) {
                if (s[i] != q[i]) diff++;
                if (diff > 1) break;
            }

            if (diff == 1) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}