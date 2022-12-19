//
// Created by Thor Christoffersen Hochman on 12/16/22.
//

#include "BinaryTree.h"
#include "iostream"
using namespace std;

BinaryTree::BinaryTree() {
    rootNode_ = nullptr;
    size_ = 0;
}

BinaryTree::BinaryTree(const string& value) {
    rootNode_ = new BinaryTreeNode;
    rootNode_->value_ = value;
    rootNode_->leftNode_ = nullptr;
    rootNode_->rightNode_ = nullptr;
    size_ = 1;
}

BinaryTree::BinaryTree(const BinaryTreeNode* treeNode){
    rootNode_ = new BinaryTreeNode;
    *rootNode_ = *treeNode;
    //calculate size
    size_ = countNodes(rootNode_);
}

BinaryTree::~BinaryTree() {
    //have to loop through binary tree to delete all pointer
    delete rootNode_;
}

int BinaryTree::countNodes(const BinaryTreeNode* node){
    if(node == nullptr) return 0;
    return 1 + countNodes(node->leftNode_) + countNodes(node->rightNode_);
}

void BinaryTree::addTreeNode(const string& value) {
    cout << "running addTreeNode now " << endl;
    cout << "Value =  " << value << endl;
    if(rootNode_ == nullptr){
//        cout << "rootNode_ == nullptr " << endl;
        rootNode_ = new BinaryTreeNode;
        rootNode_->value_ = value;
        rootNode_->leftNode_ = nullptr;
        rootNode_->rightNode_ = nullptr;
    }
    else{
//        cout << "else " << endl;
        BinaryTreeNode* tempNode = rootNode_;
//        cout << "(value > tempNode->value_): " << value << " > "<< tempNode->value_ << ": "<< (value > tempNode->value_) << endl;
//        cout << "(tempNode->rightNode_!=nullptr): " << (tempNode->rightNode_!=nullptr) << endl;
//
//        cout << "(value < tempNode->value_): " << value << " < "<< tempNode->value_ << ": "<< (value < tempNode->value_) << endl;
//        cout << "(tempNode->leftNode_!=nullptr): " << (tempNode->leftNode_!=nullptr) << endl;
//
//        cout << "(value > tempNode->value_)&&(tempNode->rightNode_!=nullptr): " << ((value > tempNode->value_)&&(tempNode->rightNode_!=nullptr)) << endl;
//        cout << "(value < tempNode->value_)&&(tempNode->leftNode_!=nullptr): " << ((value < tempNode->value_)&&(tempNode->leftNode_!=nullptr)) << endl;
        while(((value > tempNode->value_)&&(tempNode->rightNode_!=nullptr))
        or ((value < tempNode->value_)&&(tempNode->leftNode_!=nullptr))){
//            cout << "entering the while loop now " << endl;
            if(tempNode->value_ < value){
//                cout << "tempNode->value_ > value" << endl;
                tempNode = tempNode->rightNode_;
            }
            else if(tempNode->value_ > value){
//                cout << "tempNode->value_ < value" << endl;
                tempNode = tempNode->leftNode_;
            }
            else{
                cout << "break" << endl;
                break;
            }
        }
//        cout << "finished with the while loop" << endl;
        if(tempNode->value_ != value) {
            BinaryTreeNode* tempNodeNotPtr = new BinaryTreeNode;
            cout << "new BinaryTreeNode created" << endl;
            tempNodeNotPtr->value_ = value;
//            cout << "tempNode->value_: " << tempNode->value_ << endl;
            tempNodeNotPtr->leftNode_ = nullptr;
            tempNodeNotPtr->rightNode_ = nullptr;
            if(tempNode->value_ < value){
                tempNode->rightNode_ = tempNodeNotPtr;
            }
            else if(tempNode->value_ > value){
                tempNode->leftNode_ = tempNodeNotPtr;
            }
        }
    }
    size_ ++;
}

bool BinaryTree::empty() const{
    return size_ == 0;
}

BinaryTreeNode *BinaryTree::getRootNode() const {
    return rootNode_;
}
