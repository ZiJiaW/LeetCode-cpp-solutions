#include "all.h"
using namespace std;

//117
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root)
        {
            TreeLinkNode *nextLevelHead = nullptr;
            TreeLinkNode *p = new TreeLinkNode(-1);
            while (root)// 连接一层
            {
                if (root->left)
                {
                    if (!nextLevelHead) nextLevelHead = root->left;
                    p->next = root->left;
                    p = p->next;
                }
                if (root->right)
                {
                    if (!nextLevelHead) nextLevelHead = root->right;
                    p->next = root->right;
                    p = p->next;
                }
                root = root->next;
            }
            root = nextLevelHead;// 到下一层
        }
    }
};
