//
// Created by euael on 1/16/2022.
//

#include <iostream>

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

    void remove(T num){
        deleteNode(root, num);
    }
    void deleteNode(Node<T> *& nodePtr, T num){
        if (nodePtr == nullptr){
            std::cerr << "Node Does NOT Exist!" << std::endl;
            return;
        }
        if (num < nodePtr->getValue()){
            deleteNode(nodePtr->refLeft(), num);
        } else if (num > nodePtr->getValue()){
            deleteNode(nodePtr->refRight(), num);
        } else {
            makeDeletion(nodePtr);
//            destroySubTree(nodePtr);
            return;
        }

    }
    void makeDeletion(Node<T> *& nodePtr){
        Node<T> * nodeToDelete = nodePtr;
        Node<T> * attachPoint;

        if (!nodePtr->getRight() && !nodePtr->getLeft()){
            nodePtr = nullptr;
        } else if (!nodePtr->getRight() && nodePtr->getLeft()){
            nodePtr = nodePtr->refLeft();
        } else if (nodePtr->getRight() && !nodePtr->getLeft()){
            nodePtr = nodePtr->refRight();
        } else{
            attachPoint = nodePtr->getRight();
            while(attachPoint->getLeft()){
                attachPoint = attachPoint->getLeft();
            }
            attachPoint->setLeft(nodePtr->getLeft());
            nodePtr = nodePtr->refRight();
        }
        delete nodeToDelete;
   }

    // recursive deleting SUB-Tree
    void destroySubTree(Node<T> *& nodePtr){ // works
        if (nodePtr){
            if (nodePtr->getLeft()){
                destroySubTree(nodePtr->refLeft());
            }
            if (nodePtr->getRight()){
                destroySubTree(nodePtr->refRight());
            }
            Node<T> * temp = nodePtr;
            nodePtr = nullptr;
            delete temp;
        }
    }
    void deleteTree(){ // works
        destroySubTree(root);
    }

    // recursive insersion
    void insert(T num){ // works
        auto *temp = new Node<T>(num);
        temp->setRight(nullptr);
        temp->setLeft(nullptr);

        insertNode(root, temp);
    }
    void insertNode(Node<T> * &nodePtr, Node<T> * newNode){ // works
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

    // inOrder printing
    void print() const{ // works
        if (!root){
            std::cout << "tree empty" << std::endl;
            return;
        }
        print(root);
        std::cout << std::endl;
    }
    void print(Node<T> * teRoot) const{ // works
        if (teRoot){
            print(teRoot->getLeft());
            std::cout << teRoot->getValue() << " ";
            print(teRoot->getRight());
        }

    }

    // postOrder printing
    void PostOrderPrint() const{ // works
        if (!root){
            std::cout << "tree empty" << std::endl;
            return;
        }
        PostOrderPrint(root);
        std::cout << std::endl;
    }
    void PostOrderPrint(Node<T> * teRoot) const{ // works
        if (teRoot){
            PostOrderPrint(teRoot->getLeft());
            PostOrderPrint(teRoot->getRight());
            std::cout << teRoot->getValue() << " ";
        }
    }

    // preOrder printing
    void PreOrderPrint() const{ // works
        if (!root){
            std::cout << "tree empty" << std::endl;
            return;
        }
        PreOrderPrint(root);
        std::cout << std::endl;
    }
    void PreOrderPrint(Node<T> * teRoot) const{ // works
        if (teRoot){
            std::cout << teRoot->getValue() << " ";
            PreOrderPrint(teRoot->getLeft());
            PreOrderPrint(teRoot->getRight());
        }
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
