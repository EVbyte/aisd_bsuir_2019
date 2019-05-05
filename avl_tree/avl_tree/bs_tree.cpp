//
//  bs_tree.cpp
//  avl_tree
//
//  Created by Eduard Adasko on 5/5/19.
//  Copyright © 2019 Eduard Adasko. All rights reserved.
//

#include "bs_tree.hpp"
#include <iostream>

//конструкторы
template<typename T>
BS_tree<T>::BS_tree(){
    Root = nullptr;
}

template<typename T>
BS_tree<T>::BS_tree(std::vector<T> keys){
    Root = nullptr;
    for (int i = 0; i < keys.size(); i++)
        Insert(keys[i]);
}

//вставка
template<typename T>
void BS_tree<T>::Insert(T key){
    if (!Root){
        bs_node<T> *n = new bs_node<T>(key);
        Root = n;
        return;
    }
    if (Find(key)) return;
    InsertRec(Root, key);
}

template<typename T>
void BS_tree<T>::Insert(std::vector<T> keys){
    for (int i = 0; i < keys.size(); i++)
        Insert(keys[i]);
}

template<typename T>
void BS_tree<T>::InsertRec(bs_node<T>* node, T key){
    if (key > node -> key){
        if(node -> right)
            InsertRec(node -> right, key);
        else{
            bs_node<T> *n = new bs_node<T>(key);
            node -> right = n;
            n -> parent = node;
        }
        return;
    }
    if (key < node -> key){
        if(node -> left)
            InsertRec(node -> left, key);
        else{
            bs_node<T> *n = new bs_node<T>(key);
            node -> left = n;
            n -> parent = node;
        }
        return;
    }
}

//поиск
template<typename T>
bool BS_tree<T>::Find(T key){
    return FindRec(Root, key);
}
template<typename T>
bool BS_tree<T>::FindRec(bs_node<T>* node, T key){
    if (node -> key == key)
        return true;
    if (key > node -> key && node -> right)
        FindRec(node -> right, key);
    if (key < node -> key && node -> left)
        FindRec(node -> left, key);
    return false;
}

//обходы
template<typename T>
void BS_tree<T>::inOrder(){
    inOrderRec(Root);
}

template<typename T>
void BS_tree<T>::inOrderRec(bs_node<T>* node){
    if (node){
        inOrderRec(node -> left);
        std::cout << node -> key << " ";
        inOrderRec(node -> right);
    }
}

template<typename T>
bs_node<T>* BS_tree<T>::minNode(){
    return minNodeRec(Root);
}

template<typename T>
bs_node<T>* BS_tree<T>::minNodeRec(bs_node<T>* node){
    if (!node -> left)
        return node;
    return minNodeRec(node -> left);
}

template<typename T>
bs_node<T>* BS_tree<T>::maxNode(){
    return maxNodeRec(Root);
}

template<typename T>
bs_node<T>* BS_tree<T>::maxNodeRec(bs_node<T>* node){
    if (!node -> right)
        return node;
    return maxNodeRec(node -> right);
}

template<typename T>
bs_node<T>* BS_tree<T>::successor(bs_node<T>* node){
    if (node -> right)
        return minNodeRec(node -> right);
    bs_node<T>* p = node->parent;
    while (p && node == p -> right){
        node = p;
        p = p -> parent;
    }
    return p;
}

template<typename T>
bs_node<T>* BS_tree<T>::predecessor(bs_node<T>* node){
    if (node -> left)
        return maxNodeRec(node -> left);
    bs_node<T>* p = node->parent;
    while (p && node == p -> left){
        node = p;
        p = p -> parent;
    }
    return p;
}
//
template class BS_tree<int>;
template class BS_tree<double>;
template class BS_tree<float>;
template class BS_tree<char>;
template class BS_tree<std::string>;
