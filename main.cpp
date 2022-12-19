#include <iostream>
#include "BinaryTree.h"

using namespace std;

void print2DUtil(BinaryTreeNode* root, int inbetweenSpace)
{
    if (root == nullptr)
        return;

    inbetweenSpace += 5;

    // right child
    print2DUtil(root->rightNode_, inbetweenSpace);

    // current node
    cout << endl;
    for (int i = 5; i < inbetweenSpace; i++)
        cout << " ";
    cout << root->value_ << "\n";

    // left child
    print2DUtil(root->leftNode_, inbetweenSpace);
}

void print2D(BinaryTreeNode* root)
{
    print2DUtil(root, 0);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    BinaryTree temp = BinaryTree("3");
    temp.addTreeNode("4");
    temp.addTreeNode("2");
    temp.addTreeNode("1");
    temp.addTreeNode("2.5");
    temp.addTreeNode("5");
    print2D(temp.getRootNode());
    return 0;
}
