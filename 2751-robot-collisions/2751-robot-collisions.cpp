class Solution {
public:
    vector<int> survivedRobotsHealths(
        vector<int>& positions,
        vector<int>& healths,
        string directions
    ) {
        int n = positions.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(),
             [&](int a, int b){ return positions[a] < positions[b]; });

        vector<bool> alive(n, true);
        vector<int>  stack;  // indices of R-movers

        for (int idx : order) {
            if (directions[idx] == 'R') {
                stack.push_back(idx);
            } else {
                while (!stack.empty()) {
                    int top = stack.back();
                    if (healths[top] < healths[idx]) {
                        alive[top] = false;
                        stack.pop_back();
                        healths[idx]--;
                    } else if (healths[top] > healths[idx]) {
                        alive[idx] = false;
                        healths[top]--;
                        break;
                    } else {
                        alive[top] = false;
                        alive[idx] = false;
                        stack.pop_back();
                        break;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (alive[i]) result.push_back(healths[i]);
        return result;
    }
};