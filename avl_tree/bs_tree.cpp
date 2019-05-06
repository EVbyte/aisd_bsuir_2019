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
    }
    if (key < node -> key){
        if(node -> left)
            InsertRec(node -> left, key);
        else{
            bs_node<T> *n = new bs_node<T>(key);
            node -> left = n;
            n -> parent = node;
        }
    }
}

//удаление
template<typename T>
void BS_tree<T>::Remove(T key){
    RemoveRec(Root, key);
}

template<typename T>
void BS_tree<T>::RemoveRec(bs_node<T>* node, T key){
    if (!node) return;
    if (key > node -> key)
        RemoveRec(node -> right, key);
    else if (key < node -> key)
        RemoveRec(node -> left, key);
    else if (node -> left && node -> right){
        node -> key = minNodeRec(node -> right) -> key;
        RemoveRec(node -> right, node -> key);
    }
    else if (node -> left || node -> right)
        RemoveNodeWithOneLeaf(node);
    else RemoveLeaf(node);
}

template<typename T>
void BS_tree<T>::RemoveNodeWithOneLeaf(bs_node<T>* node){
    bs_node<T>* del = node;
    if (node -> left){
        if (!node -> parent) {
            Root = node -> left;
            Root -> parent = nullptr;
            delete del;
            return;
        }
        if (node -> parent -> left == node){
            node -> parent -> left = node -> left;
            node -> parent -> left -> parent = node -> parent;
        }
        else{
            node -> parent -> right = node -> left;
            node -> parent -> right -> parent = node -> parent;
        }
        delete del;
    }
    else if (node -> right){
        if (!node -> parent) {
            Root = node -> right;
            Root -> parent = nullptr;
            delete del;
            return;
        }
        if (node -> parent -> left == node){
            node -> parent -> left = node -> right;
            node -> parent -> left -> parent = node -> parent;
        }
        else{
            node -> parent -> right = node -> right;
            node -> parent -> right -> parent = node -> parent;
        }
        delete del;
    }
}

template<typename T>
void BS_tree<T>::RemoveLeaf(bs_node<T>* node){
    bs_node<T>* del = node;
    if (!node -> parent){
        Root = nullptr;
        delete del;
        return;
    }
    if (node -> parent -> left == node)
        node -> parent -> left = nullptr;
    else
        node -> parent -> right = nullptr;
    delete del;
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
        return FindRec(node -> right, key);
    if (key < node -> key && node -> left)
        return FindRec(node -> left, key);
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
    return node -> left ? minNodeRec(node -> left) : node;
}

template<typename T>
bs_node<T>* BS_tree<T>::maxNode(){
    return maxNodeRec(Root);
}

template<typename T>
bs_node<T>* BS_tree<T>::maxNodeRec(bs_node<T>* node){
    return node -> right ? minNodeRec(node -> right) : node;
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

template <typename T>
void BS_tree<T>::printRec(bs_node<T>* p, int level){
    if(p)
    {
        printRec(p->left,level + 1);
        for(int i = 0;i< level;i++) std::cout<<"   ";
        std::cout << p->key << std::endl;
        printRec(p->right,level + 1);
    }
}

template <typename T>
void BS_tree<T>::Print(){
    printRec(Root, 0);
}
//
template class BS_tree<int>;
template class BS_tree<double>;
template class BS_tree<float>;
template class BS_tree<char>;
template class BS_tree<std::string>;
