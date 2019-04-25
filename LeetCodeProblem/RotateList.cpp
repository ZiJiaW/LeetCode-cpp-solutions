#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode *p = head, *pp;
        int length = 1;
        for (; head->next; head = head->next) length++;
        if (k % length == 0) return p;
        head->next = p;
        int step = k < length ? length - k : (k / length + 1) * length - k;
        for (int i = 0; i < step; ++i)
        {
            pp = p;
            p = p->next;
        }
        pp->next = NULL;
        return p;
    }
};