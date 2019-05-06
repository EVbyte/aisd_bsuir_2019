//
//  avl_tree.hpp
//  avl_tree
//
//  Created by Eduard Adasko on 5/6/19.
//  Copyright © 2019 Eduard Adasko. All rights reserved.
//

#ifndef avl_tree_hpp
#define avl_tree_hpp

#include <stdio.h>
#include <vector>
template <typename T>
struct avl_node {
    T key;
    unsigned char height;
    avl_node<T>* parent;
    avl_node<T>* left;
    avl_node<T>* right;
    avl_node<T>(T k) {
        key = k;
        parent = left = right = nullptr;
        height = 1;
    }
};

template <typename T>
class AVL_tree{
private:
    avl_node<T>* Root;
    void InsertRec(avl_node<T>* node, T key);
    void RemoveRec(avl_node<T>* node, T key);
    void RemoveLeaf(avl_node<T>* node);
    void RemoveNodeWithOneLeaf(avl_node<T>* node);
    void inOrderRec(avl_node<T>* node);
    bool FindRec(avl_node<T>* node, T key);
    avl_node<T>* minNodeRec(avl_node<T>* node);
    avl_node<T>* maxNodeRec(avl_node<T>* node);
    avl_node<T>* makeBalanced(avl_node<T>* node);
    avl_node<T>* rotateL(avl_node<T>* node);
    avl_node<T>* rotateR(avl_node<T>* node);
    avl_node<T>* rotateLR(avl_node<T>* node);
    avl_node<T>* rotateRL(avl_node<T>* node);
    unsigned char height (avl_node<T>* node);
    int balanceFactor (avl_node<T>* node);
    void setHeight (avl_node<T>* node);
    bool isBalanced (avl_node<T>* node);
    void changeNodeToBalanced(avl_node<T>* node);
    void printRec(avl_node<T>* node, int level);
public:
    AVL_tree<T>();
    AVL_tree<T>(std::vector<T> keys);
    void Insert(T key);
    void Insert(std::vector<T> keys);
    void Remove(T key);
    void inOrder();
    bool Find(T key);
    void Print();
    avl_node<T>* minNode();
    avl_node<T>* maxNode();
    avl_node<T>* successor(avl_node<T>* node);
    avl_node<T>* predecessor(avl_node<T>* node);
    
};

#endif /* avl_tree_hpp */
