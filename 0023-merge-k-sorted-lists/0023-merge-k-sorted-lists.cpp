class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int minVal = INT_MAX, maxVal = INT_MIN;
        bool hasNodes = false;

        for (auto node : lists) {
            while (node) {
                minVal = min(minVal, node->val);
                maxVal = max(maxVal, node->val);
                node = node->next;
                hasNodes = true;
            }
        }

        if (!hasNodes) return nullptr;

        long long range = (long long)maxVal - minVal + 1;
        vector<int> freq(range, 0);

        for (auto node : lists) {
            while (node) {
                freq[node->val - minVal]++;
                node = node->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        for (int i = 0; i < range; i++) {
            while (freq[i]--) {
                curr->next = new ListNode(i + minVal);
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};