class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current = "";
        backtrack(res, current, n, 0, 0);
        return res;
    }

    void backtrack(vector<string>& res, string& current, int n, int open, int close) {
        if (current.length() == 2 * n) {
            res.push_back(current);
            return;
        }
        if (open < n) {
            current += '(';
            backtrack(res, current, n, open + 1, close);
            current.pop_back();
        }
        if (close < open) {
            current += ')';
            backtrack(res, current, n, open, close + 1);
            current.pop_back();
        }
    }
};