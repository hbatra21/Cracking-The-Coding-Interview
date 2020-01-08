class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        if (N == 0) return 1;
        vector<int> A(N+1, 0);
        A[N] = 1;
        A[N-1] = (s[N-1] == '0' ? 0 : 1);
        for (int i(N-2); i >= 0; --i) {
            if (s[i] == '0') {
                A[i] = 0;
            }
            else if (s[i] == '1' or (s[i] == '2' and s[i+1] <= '6')) {
                A[i] = A[i+1] + A[i+2];
            }
            else {
                A[i] = A[i+1];
            }
        }
        return A[0];
    }
};
