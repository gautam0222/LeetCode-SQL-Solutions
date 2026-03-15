/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next== NULL) return head;

        ListNode* temp= head;
        vector<int>v;
        while(temp!=NULL){ // step 1: convert linked list in vector(array).
            v.push_back(temp->val);
            temp= temp->next;
            
        }
        map<int,int>mp;
        
        for(auto it: v){ //step 2: count frequency of each element
            mp[it]++;
        }

        vector<int>ans;
        for(auto it: mp){ //step 3: if unique number(element) then push it in ans
            if(it.second==1)ans.push_back(it.first);
        }

        temp= head;
        
        if(ans.size()==0) return NULL;
        for(int i=0; i<ans.size(); i++){
            temp->val= ans[i]; //step 4.1: fill in linked list again from ans(vector)

            if(i== ans.size()-1){
                temp->next=NULL; //step 4.2: important linked list start from 1
                                 //while array from 0 , so i==n-1 linkedlist will at n.
                break;
            }
            temp= temp->next;
        }
        temp->next= NULL;
        temp= head;
        
        return temp;
        
    }
};