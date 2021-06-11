#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    node* pLeft;
    node* pRight;
} NODE;
typedef NODE* TREE;
void initializeTree(TREE &tree)
{
    tree = NULL;
}
void deleteTree(TREE &tree)
{
    if (tree != NULL)
    {
        deleteTree(tree->pLeft);
        deleteTree(tree->pRight);
        delete tree;
    }
}
void addNode(TREE &tree, int x)
{
    if (tree == NULL)
    {
        NODE* p = new NODE;
        p->data = x;
        p->pLeft= NULL;
        p->pRight= NULL;
        tree = p;
    }
    else
    {
        if (tree->data > x)
            addNode(tree->pLeft,x);
        else if ( tree->data < x)
            addNode(tree->pRight,x);
    }
}
void outputNLR(TREE tree)
{
    if ( tree != NULL)
    {
        cout << tree->data << " ";
        outputNLR(tree->pLeft);
        outputNLR(tree->pRight);
    }
}
NODE *findNode(TREE tree, int x)
{
    if (tree != NULL)
    {
        if (tree->data == x)
            return tree;
        if ( x < tree->data)
            return findNode(tree->pLeft,x);
        return findNode(tree->pRight,x);
    }
    return NULL;
}
int main()
{   
    TREE tree;
    initializeTree(tree);
    addNode(tree,5);
    addNode(tree,1);
    addNode(tree,2);
    addNode(tree,-2);
    addNode(tree,6);
    addNode(tree,7);
    outputNLR(tree);
    if(findNode(tree,2) != NULL)
        cout << "\nTon Tai";
    else
    {
        cout << "\nNone";
    }
    return 0;
}