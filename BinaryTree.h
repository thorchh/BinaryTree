//
// Created by Thor Christoffersen Hochman on 12/16/22.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#include <string>


struct BinaryTreeNode {
    std::string value_;
    BinaryTreeNode* leftNode_;
    BinaryTreeNode* rightNode_;
};

class BinaryTree {
    public:
        BinaryTree();
        BinaryTree(const std::string& value);
        BinaryTree(const BinaryTreeNode* treeNode);
        virtual ~BinaryTree();
        void addTreeNode(const std::string& value);
        void printTree(const BinaryTree& tree) const;
        bool empty() const;
        int countNodes(const BinaryTreeNode *node);
        void print2D(BinaryTreeNode* root);

    BinaryTreeNode *getRootNode() const;

private:
        BinaryTreeNode* rootNode_;
        size_t size_;
};


#endif //BINARYTREE_BINARYTREE_H
