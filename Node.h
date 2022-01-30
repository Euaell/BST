//
// Created by euael on 1/16/2022.
//
#include <cstdlib>
#ifndef BST_NODE_H
#define BST_NODE_H

template <class T>
class Node{
private:
    T value;
    Node<T> * left;
    Node<T> * right;

public:
    Node(){
        this->right = nullptr;
        this->left = nullptr;
//        std::cout << "Empty node created" << std::endl;
    }
    explicit Node(T value){
        this->right = nullptr;
        this->left = nullptr;
        this->value = value;
//        std::cout << "node created with value " << this->value << std::endl;
    }
//    ~Node(){
////        delete this;
////        std::cout << "node Deleted" << std::endl;
//    }

//    Getters
    T getValue(){
        return value;
    }
    Node<T> * getLeft(){
        return left;
    }
    Node<T> *getRight(){
        return right;
    }
//    reference getter
    Node<T> *& refRight(){
        return right;
    }
    Node<T> *& refLeft(){
        return left;
    }
    T & refValue(){
        return value;
    }

//    Setters
    void setValue(T v){
        this-> value = v;
    }
    void setLeft(Node<T> * le){
        this->left = le;
    }
    void setRight(Node<T> * ri){
        this->right = ri;
    }
};

#endif //BST_NODE_H
