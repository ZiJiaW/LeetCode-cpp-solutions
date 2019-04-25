//143
#include "all.h"
using namespace std;
// 找到中间节点，reverse后merge一下
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *p = head, *fastp = head;
        while (fastp->next&&fastp->next->next) {
            p = p->next;
            fastp = fastp->next->next;
        }
        auto l2 = p->next;
        p->next = nullptr;
        l2 = reverse(l2);
        merge(head, l2);
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode *q = head->next, *p = head;
        while (q) {
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
            q = p->next;
        }
        return pre->next;
    }
    void merge(ListNode* p, ListNode* q) {
        ListNode *tmp = nullptr;
        bool order = true;
        while (p || q) {
            if (order) {
                tmp = p->next;
                p->next = q;
                p = tmp;
            }
            else {
                tmp = q->next;
                q->next = p;
                q = tmp;
            }
            order = !order;
        }
    }
};

//int main()
//{
//    ListNode head(1), a(2), b(3), c(4), d(5);
//    head.next = &a; a.next = &b; b.next = &c;//, c.next = &d;
//    auto p = &head;
//    Solution().reorderList(p);
//    while (p) {
//        cout << p->val << ' ';
//        p = p->next;
//    }
//    return 0;
//}