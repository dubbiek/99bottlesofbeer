#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
using namespace std;
template <typename NT>
class AVLTREE
{
    public:

        AVLTREE()
        {
            root = nullptr;
        }
        void insertNode (const NT &);
        void emptyTree();
        void printTree();
        ~AVLTREE()
        {
            emptyTree();
        }
    private:
        struct AvlNode
        {
            NT thing;
            AvlNode *left;
            AvlNode *right;
            int nheight;
             AvlNode( const NT & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : thing{ ele }, left{ lt }, right{ rt }, nheight{ h } { }

        AvlNode( NT && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : thing{ std::move( ele ) }, left{ lt }, right{ rt }, nheight{ h } { }
        };
         //struct
        AvlNode *root;
        int height(AvlNode *ptr) const;
        void insertHelper(const NT &, AvlNode *&);
        void balance(AvlNode *&);
        void leftChildRotation(AvlNode *&);
        void rightChildRotation(AvlNode *&);
        void doubleLeftRotation(AvlNode *&);
        void doubleRightRotation(AvlNode *&);
        void EmptyTreeHelper(AvlNode *&);
        void printTreeHelper(AvlNode *);

}; //end AVLTREE
template <typename NT>
int AVLTREE<NT>::height(AvlNode *ptr) const
{
        if (ptr == nullptr)
        {
            return -1;
        }
        else
            return ptr->nheight;

}
template <typename NT>
void AVLTREE<NT>::insertNode(const NT &d)
{
    insertHelper(d, root);
}//insert
template <typename NT>
void AVLTREE<NT>::insertHelper(const NT &data, AvlNode *& ptr)
{
    //if null, create new node and plant data
    //if not empty, sort based on value
    //then balance from end to root
    if (ptr == nullptr)
        ptr = new AvlNode(data, nullptr, nullptr);
    else if (data < ptr->thing)
        insertHelper(data, ptr->left);
    else if (data > ptr->thing)
        insertHelper(data, ptr->right);
    balance(ptr);
}//insertHelper
static const int TOTAL_DIFF = 1;
template <typename NT>
void AVLTREE<NT>::balance(AvlNode *&nptr)
{
    //if null, pass back
    //if unbalanced, check case to rotate
    //update height of nodes as passed back up
    if (nptr == nullptr)
        return;
    if (height(nptr->left) - height(nptr->right) > TOTAL_DIFF) {
        if (height(nptr->left->left) >= height(nptr->left->right))
            leftChildRotation(nptr);
        else
            doubleLeftRotation(nptr);
    }
    else
    if (height(nptr->right) - height(nptr->left) > TOTAL_DIFF){
        if (height(nptr->right->right) >= height(nptr->right->left))
            rightChildRotation(nptr);
        else
            doubleRightRotation(nptr);
    }
    nptr->nheight = max(height(nptr->left), height(nptr->right)) + 1;
}//balance
template <typename NT>
void AVLTREE<NT>::leftChildRotation(AvlNode *&top)
{
    //hold the child. pass right pointer to old top.
    //set child right to top. set top to child.
    AvlNode *child = top->left;
    top->left = child->right;
    child->right = top;
    top->nheight = max(height(top->left), height(top->right)) + 1;
    child->nheight = max(height(child->left), height(child->right)) + 1;
    top = child;
} //rotateLeft
template <typename NT>
void AVLTREE<NT>::rightChildRotation(AvlNode *&top)
{
    //make a child node and pass it top right.
    //set empty top right to child left and child left to top.
    AvlNode *child = top->right;
    top->right = child->left;
    child->left= top;
    top->nheight = max(height(top->left), height(top->right)) + 1;
    child->nheight = max(height(child->left), height(child->right)) + 1;
    top = child;
} //rotateRight
template <typename NT>
void AVLTREE<NT>::doubleLeftRotation(AvlNode *&gc)
{
    rightChildRotation(gc->left);
    leftChildRotation(gc);
} //doubleLeft
template <typename NT>
void AVLTREE<NT>::doubleRightRotation(AvlNode *&gc)
{
    leftChildRotation(gc->right);
    rightChildRotation(gc);
}//doubleRight
template <typename NT>
void AVLTREE<NT>::emptyTree()
{
    EmptyTreeHelper(root);
}
template <typename NT>
 void AVLTREE<NT>::EmptyTreeHelper(AvlNode *&ptr)
 { //if not null, go left then right and delete data/set ptr to null
     if( ptr != nullptr )
        {
            EmptyTreeHelper( ptr->left );
            EmptyTreeHelper( ptr->right );
            delete ptr;
        }
        ptr = nullptr;
 }//delete the tree
 template <typename NT>
 void AVLTREE<NT>::printTree()
 {
     printTreeHelper(root);
 }
template <typename NT>
 void AVLTREE<NT>::printTreeHelper(AvlNode *ptr)
 {
     //traverse and print in order
 if (ptr !=nullptr) {
        printTreeHelper( ptr->left );
        cout << ptr->thing << endl;
        printTreeHelper( ptr->right );
    }
 }
#endif
