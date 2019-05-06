//
//  bs_tree.hpp
//  avl_tree
//
//  Created by Eduard Adasko on 5/5/19.
//  Copyright © 2019 Eduard Adasko. All rights reserved.
//

#ifndef bs_tree_hpp
#define bs_tree_hpp
#include <stdio.h>
#include <vector>
template <typename T>
struct bs_node {
    T key;
    bs_node<T>* parent;
    bs_node<T>* left;
    bs_node<T>* right;
    bs_node<T>(T k) {
        key = k;
        parent = left = right = nullptr;
    }
};

template <typename T>
class BS_tree{
private:
    bs_node<T>* Root;
    void InsertRec(bs_node<T>* node, T key);
    void RemoveRec(bs_node<T>* node, T key);
    void inOrderRec(bs_node<T>* node);
    bool FindRec(bs_node<T>* node, T key);
    bs_node<T>* minNodeRec(bs_node<T>* node);
    bs_node<T>* maxNodeRec(bs_node<T>* node);
    void RemoveLeaf(bs_node<T>* node);
    void RemoveNodeWithOneLeaf(bs_node<T>* node);
    void printRec(bs_node<T>* node, int level);
public:
    BS_tree<T>();
    BS_tree<T>(std::vector<T> keys);
    void Insert(T key);
    void Insert(std::vector<T> keys);
    void Remove(T key);
    void inOrder();
    bool Find(T key);
    void Print();
    bs_node<T>* minNode();
    bs_node<T>* maxNode();
    bs_node<T>* successor(bs_node<T>* node);
    bs_node<T>* predecessor(bs_node<T>* node);
};
#endif /* bs_tree_hpp */
