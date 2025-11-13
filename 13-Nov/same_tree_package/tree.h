#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <cstddef>
class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }
    bool isSameBinaryTree(Tree& t) {
        // Insert your code here
        return loop_check(mRoot, t.mRoot);
    }
    // You can also put your code here
    bool loop_check(Node *(&T1), Node *(&T2)){
        if (T1 == NULL && T2 == NULL) {
            return true;
        }
        else if (T1 == NULL ^ T2 == NULL) {
            return false;
        }
        else {
            return (
                T1->data == T2->data
                and
                loop_check(T1->left,T2->left)
                and
                loop_check(T1->right,T2->right)
            );
        }
    }
    

protected:
    void insertAt(Node*& r, int x) {
        if (!r) {
           r = new Node(x, NULL, NULL);
           mSize++;
           return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDED
