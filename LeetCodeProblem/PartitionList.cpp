#include <iostream>
#include <vector>
using namespace std;
//86
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* insertPos = dummy, *p, *pp;
        while (insertPos->next && insertPos->next->val < x)
            insertPos = insertPos->next;
        for (p = insertPos->next, pp = insertPos; p;)
        {
            if (p->val < x)
            {
                pp->next = p->next;
                p->next = insertPos->next;
                insertPos->next = p;
                p = pp->next;
                insertPos = insertPos->next;
            }
            else
            {
                pp = pp->next;
                p = p->next;
            }
        }
        return dummy->next;
    }
};
