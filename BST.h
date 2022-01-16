//
// Created by euael on 1/16/2022.
//

#include <iostream>
#include <cstdlib>
#include "Node.h"

#ifndef BST_BST_H
#define BST_BST_H

template <class T>
class BST{
private:
    Node<T> * root;
public:
    BST(){
        root = nullptr;
        std::cout << "Tree created!" << std::endl;
    }
    ~BST(){
        deleteTree();
        std::cout << "Tree deleted!" << std::endl;
    }

    void destroySubTree(Node<T> * nodePtr){ // works
        if (nodePtr){
            if (nodePtr->getLeft()){
//                std::cout << "about to delete left" << std::endl;
                destroySubTree(nodePtr->getLeft());
//                std::cout << "returning form deleting left" << std::endl;
            }
            if (nodePtr->getRight()){
//                std::cout << "about to delete right" << std::endl;
                destroySubTree(nodePtr->getRight());
//                std::cout << "returning form deleting right" << std::endl;
            }

//            std::cout << "deleting " << nodePtr->getValue() << std::endl;
            if (nodePtr == root){
                root = nullptr;
            }
            free(nodePtr);
        }
    }
    void deleteTree(){ // works
        destroySubTree(root);
//        std::cout << "Tree cleaned" << std::endl;
    }

    void insert(T num){ // works
        auto *temp = new Node<T>(num);
        temp->setRight(nullptr);
        temp->setLeft(nullptr);

        insertNode(root, temp);
    }
    void insertNode(Node<T> * &nodePtr, Node<T> * &newNode){ // works
        if (nodePtr == nullptr){
//            std::cout << "placeing value " << newNode->getValue() << std::endl;
            nodePtr = newNode;
        } else if (newNode->getValue() < nodePtr->getValue()){
            insertNode(nodePtr->refLeft(), newNode);
        } else if (newNode->getValue() > nodePtr->getValue()){
            insertNode(nodePtr->refRight(), newNode);
        } else {
            std::cerr << "Duplicate " << nodePtr->getValue() << std::endl;
        }
    }

    // recursive printing
    void print() const{ // works
        if (!root){
            std::cout << "tree empty" << std::endl;
            return;
        }
        print(root);
        std::cout << std::endl;
    }
    void print(Node<T> * teRoot) const{ // works
        if (teRoot == nullptr){
            return;
        }
        print(teRoot->getLeft());
        std::cout << teRoot->getValue() << " ";
        print(teRoot->getRight());
    }

    // search using loop
    bool search(T num){ // works
        Node<T> * nodePtr = root;
        while(nodePtr){
            if (nodePtr->getValue() == num){
                return true;
            } else if (num < nodePtr->getValue()){
                nodePtr = nodePtr->getLeft();
            } else{
                nodePtr = nodePtr->getRight();
            }
        }
        return false;
    }

    // recursive search
    bool searchV2(T num){ // works
        return searchTree(root, num);
    }
    bool searchTree(Node<T> * nodePtr, T num){ // works
        if (nodePtr == nullptr){
            return false;
        } else if (num < nodePtr->getValue()){
            return searchTree(nodePtr->getLeft(), num);
        } else if (num > nodePtr->getValue()){
            return searchTree(nodePtr->getRight(), num);
        } else{
            return true;
        }
    }

};

#endif //BST_BST_H
