#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Ford(i, s, t) for(int i = (s); i >= (t); i--)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define Repd(i, t) for(int i = ((t)-1); i >= (0); i--)
#define rep(i, s, t) for(int i = (s); i < (t); i++)


class SBTNode {
public:
    int val;
    SBTNode *left, *right;
    int size;

    SBTNode(int val, int size) : val(val), size(size), left(nullptr), right(nullptr) {}
};

class SizeBalancedTree {
private:
    SBTNode *root;

    SBTNode* L_Rotate(SBTNode *node) {
        SBTNode *right = node->right;
        node->right = right->left;
        right->left = node;

        right->size = node->size;
        node->size = (node->left != nullptr ? node->left->size : 0) +
                     (node->right != nullptr ? node->right->size : 0) + 1;
        return right;
    }

    SBTNode* R_Rotate(SBTNode *node) {
        SBTNode *left = node->left;
        node->left = left->right;
        left->right = node;

        left->size = node->size;
        node->size = (node->left != nullptr ? node->left->size : 0) +
                     (node->right != nullptr ? node->right->size : 0) + 1;
        return left;
    }

    SBTNode* maintain(SBTNode *cur) {
        if (cur == nullptr) {
            return nullptr;
        }

        int leftSize = cur->left != nullptr ? cur->left->size : 0;
        int rightSize = cur->right != nullptr ? cur->right->size : 0;
        int leftLeftSize = cur->left != nullptr && cur->left->left != nullptr ? cur->left->left->size : 0;
        int leftRightSize = cur->left != nullptr && cur->left->right != nullptr ? cur->left->right->size : 0;
        int rightLeftSize = cur->right != nullptr && cur->right->left != nullptr ? cur->right->left->size : 0;
        int rightRightSize = cur->right != nullptr && cur->right->right != nullptr ? cur->right->right->size : 0;

        if (leftLeftSize > rightSize) {
            cur = R_Rotate(cur);
            cur->right = maintain(cur->right);
            cur = maintain(cur);
        } else if (leftRightSize > rightSize) {
            cur->left = L_Rotate(cur->left);
            cur = R_Rotate(cur);
            cur->left = maintain(cur->left);
            cur->right = maintain(cur->right);
            cur = maintain(cur);
        } else if (rightLeftSize > leftSize) {
            cur->right = R_Rotate(cur->right);
            cur = L_Rotate(cur);
            cur->left = maintain(cur->left);
            cur->right = maintain(cur->right);
            cur = maintain(cur);
        } else if (rightRightSize > leftSize) {
            cur = L_Rotate(cur);
            cur->left = maintain(cur->left);
            cur = maintain(cur);
        }
        return cur;
    }

    SBTNode* add(SBTNode *cur, int val) {
        if (cur == nullptr) {
            return new SBTNode(val, 1);
        } else if (cur->val > val) {
            cur->size++;
            cur->left = add(cur->left, val);
        } else {
            cur->size++;
            cur->right = add(cur->right, val);
        }
        return maintain(cur);
    }


    SBTNode* deleteNode(SBTNode *cur, int val) {
        cur->size--;
        if (cur->val > val) {
            cur->left = deleteNode(cur->left, val);
        } else if (cur->val < val) {
            cur->right = deleteNode(cur->right, val);
        } else {
            if (cur->left == nullptr && cur->right == nullptr) {
                delete cur;
                cur = nullptr;
            } else if (cur->left == nullptr) {
                SBTNode *temp = cur;
                cur = cur->right;
                delete temp;
            } else if (cur->right == nullptr) {
                SBTNode *temp = cur;
                cur = cur->left;
                delete temp;
            } else {
                SBTNode *pre = nullptr;
                SBTNode *des = cur->right;
                des->size--;
                while (des->left != nullptr) {
                    pre = des;
                    des = des->left;
                    des->size--;
                }
                if (pre != nullptr) {
                    pre->left = des->right;
                    des->right = cur->right;
                }
                des->left = cur->left;
                des->size = des->left->size + (des->right != nullptr ? des->right->size : 0) + 1;
                delete cur;
                cur = des;
            }
        }
        return cur;
    }
    SBTNode* findKth(SBTNode *cur, int k) {
        int leftSize = cur->left != nullptr ? cur->left->size : 0;
        if (k <= leftSize) {
            return findKth(cur->left, k);
        } else if (k > leftSize + 1) {
            return findKth(cur->right, k - leftSize - 1);
        } else {
            return cur;
        }
    }

public:
    SizeBalancedTree() : root(nullptr) {}

    void add(int val) {
        if (root == nullptr) {
            root = new SBTNode(val, 1);
        } else {
            root = add(root, val);
        }
    }

    void deleteNode(int val) {
        root = deleteNode(root, val);
    }
    int findKth(int k) {
        SBTNode *node = findKth(root, k);
        return node != nullptr ? node->val : -1;
    }

    int size() {
        return root == nullptr ? 0 : root->size;
    }
};

int main() {
    SizeBalancedTree sbt;
    int N, K;
    scanf("%d%d", &N,&K);
    For(i, 1, N) sbt.add(i);
    int cur=1;
    while (sbt.size() > 0) {
        cur = (cur + K - 1) % sbt.size();
        if (cur == 0) cur = sbt.size();
        int val = sbt.findKth(cur);

        cout << val << " ";
        sbt.deleteNode(val);
    }

    return 0;
}
