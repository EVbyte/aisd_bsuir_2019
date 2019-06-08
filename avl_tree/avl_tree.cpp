//
//  avl_tree.cpp
//  avl_tree
//
//  Created by Eduard Adasko on 5/6/19.
//  Copyright © 2019 Eduard Adasko. All rights reserved.
//

#include "avl_tree.hpp"
#include <iostream>

template<typename T>
AVL_tree<T>::AVL_tree(){
    root = nullptr;
}

template<typename T>
AVL_tree<T>::AVL_tree(std::vector<T> keys){
    root = nullptr;
    for (int i = 0; i < keys.size(); i++)
        insert(keys[i]);
}

template<typename T>
void AVL_tree<T>::insert(std::vector<T> keys){
    for (int i = 0; i < keys.size(); i++)
        insert(keys[i]);
}

template<typename T>
void AVL_tree<T>::insert(T key){
    if (!root){
        avl_node<T> *n = new avl_node<T>(key);
        root = n;
        return;
    }
    if (find(key)) return;
    insertRec(root, key);
}

template<typename T>
void AVL_tree<T>::insertRec(avl_node<T>* node, T key){
    if (key > node -> key){
        if(node -> right)
            insertRec(node -> right, key);
        else{
            avl_node<T> *n = new avl_node<T>(key);
            node -> right = n;
            n -> parent = node;
        }
    }
    if (key < node -> key){
        if(node -> left)
            insertRec(node -> left, key);
        else{
            avl_node<T> *n = new avl_node<T>(key);
            node -> left = n;
            n -> parent = node;
        }
    }
    changeNodeToBalanced(node);
    return;
}

template<typename T>
void AVL_tree<T>::remove(T key){
    removeRec(root, key);
}

template<typename T>
void AVL_tree<T>::removeRec(avl_node<T>* node, T key){
    if (!node) return;
    if (key > node -> key)
        removeRec(node -> right, key);
    else if (key < node -> key)
        removeRec(node -> left, key);
    else if (node -> left && node -> right){
        node -> key = successor(node) -> key;
        removeRec(node -> right, node -> key);
    }
    else if (node -> left || node -> right)
        removeNodeWithOneLeaf(node);
    else removeLeaf(node);
    changeNodeToBalanced(node);
}

template<typename T>
void AVL_tree<T>::removeNodeWithOneLeaf(avl_node<T>*& node){
    avl_node<T>* del = node;
    if (node -> left){
        if (!node -> parent) {
            root = node -> left;
            root -> parent = nullptr;
            delete del;
            node = root;
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
    else{
        if (!node -> parent) {
            root = node -> right;
            root -> parent = nullptr;
            delete del;
            node = root;
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
void AVL_tree<T>::removeLeaf(avl_node<T>*& node){
    avl_node<T>* del = node;
    if (!node -> parent){
        root = nullptr;
        delete del;
        node = nullptr;
        return;
    }
    if (node -> parent -> left == node)
        node -> parent -> left = nullptr;
    else
        node -> parent -> right = nullptr;
    delete del;
}

template<typename T>
bool AVL_tree<T>::find(T key){
    return findRec(root, key);
}
template<typename T>
bool AVL_tree<T>::findRec(avl_node<T>* node, T key){
    if (node -> key == key)
        return true;
    if (key > node -> key && node -> right)
        return findRec(node -> right, key);
    if (key < node -> key && node -> left)
        return findRec(node -> left, key);
    return false;
}

template<typename T>
void AVL_tree<T>::inOrder(){
    inOrderRec(root);
}

template<typename T>
void AVL_tree<T>::inOrderRec(avl_node<T>* node){
    if (node){
        inOrderRec(node -> left);
        std::cout << node -> key << " ";
        inOrderRec(node -> right);
    }
}

template<typename T>
long long AVL_tree<T>::size(){
    return sizeRec(root);
}

template<typename T>
long long AVL_tree<T>::sizeRec(avl_node<T>* node){
    if (!node)
        return 0;
    return sizeRec(node -> left) + sizeRec(node -> right) + 1;
}

template<typename T>
avl_node<T>* AVL_tree<T>::minNode(){
    if (root)
        return minNodeRec(root);
    return nullptr;
}

template<typename T>
avl_node<T>* AVL_tree<T>::minNodeRec(avl_node<T>* node){
    return node -> left ? minNodeRec(node -> left) : node;
}

template<typename T>
avl_node<T>* AVL_tree<T>::maxNode(){
    if (root)
        return maxNodeRec(root);
    return nullptr;
}

template<typename T>
avl_node<T>* AVL_tree<T>::maxNodeRec(avl_node<T>* node){
    return node -> right ? maxNodeRec(node -> right) : node;
}

template<typename T>
T AVL_tree<T>::min(){
    return minRec(root);
}

template<typename T>
T AVL_tree<T>::minRec(avl_node<T>* node){
    return node -> left ? minRec(node -> left) : node -> key;
}

template<typename T>
T AVL_tree<T>::max(){
    return maxRec(root);
}
template<typename T>
T AVL_tree<T>::maxRec(avl_node<T>* node){
    return node -> right ? maxRec(node -> right) : node -> key;
}

template<typename T>
avl_node<T>* AVL_tree<T>::successor(avl_node<T>* node){
    if (node -> right)
        return minNodeRec(node -> right);
    avl_node<T>* p = node->parent;
    while (p && node == p -> right){
        node = p;
        p = p -> parent;
    }
    return p;
}

template<typename T>
avl_node<T>* AVL_tree<T>::predecessor(avl_node<T>* node){
    if (node -> left)
        return maxNodeRec(node -> left);
    avl_node<T>* p = node->parent;
    while (p && node == p -> left){
        node = p;
        p = p -> parent;
    }
    return p;
}

template<typename T>
avl_node<T>* AVL_tree<T>::makeBalanced(avl_node<T>* node){
    setHeight(node);
    if (balanceFactor(node) == 2){
        if (balanceFactor(node -> right) < 0)
            node -> right = rotateR(node -> right);
        return rotateL(node);
    }
    
    if (balanceFactor(node) == -2){
        if (balanceFactor(node -> left) > 0)
            node -> left = rotateL(node -> left);
        return rotateR(node);
    }
    return node;
}

template<typename T>
void AVL_tree<T>::changeNodeToBalanced(avl_node<T>* node){
    if (!root) return;
    avl_node<T>* parent = node -> parent;
    avl_node<T>* newNode = makeBalanced(node);
    if (parent && parent -> right == node){
        parent -> right = newNode;
        return;
    }
    if (parent && parent -> left == node){
        parent -> left = newNode;
        return;
    }
    root = newNode;
    return;
}

template<typename T>
avl_node<T>* AVL_tree<T>::rotateR(avl_node<T>* node){
    avl_node<T>* parent = node -> parent;
    avl_node<T>* q = node -> left;
    if (q && q -> right)
        q -> right -> parent = node;
    node -> left = q -> right;
    node -> parent = q;
    q -> right = node;
    q -> parent = parent;
    setHeight(node);
    setHeight(q);
    return q;
}

template<typename T>
avl_node<T>* AVL_tree<T>::rotateL(avl_node<T>* node){
    avl_node<T>* parent = node -> parent;
    avl_node<T>* q = node -> right;
    if (q && q -> left)
        q -> left -> parent = node;
    node -> right = q -> left;
    node -> parent = q;
    q -> left = node;
    q -> parent = parent;
    setHeight(node);
    setHeight(q);
    return q;
}

template<typename T>
unsigned char AVL_tree<T>::height(avl_node<T>* node){
    return node ? node -> height : 0;
}
    
template<typename T>
int AVL_tree<T>::getHeight(){
    return height(root);
}

template<typename T>
int AVL_tree<T>::balanceFactor(avl_node<T>* node){
    return height(node -> right) - height(node -> left);
}

template<typename T>
void AVL_tree<T>::setHeight(avl_node<T>* node){
    unsigned char hl = height(node->left);
    unsigned char hr = height(node->right);
    node -> height = (hl > hr ? hl : hr) + 1;
}

template<typename T>
bool AVL_tree<T>::isBalanced(avl_node<T>* node){
    return abs(balanceFactor(node)) <= 1;
}

template <typename T>
void AVL_tree<T>::Print(){
    std::cout << "Height: " << getHeight() << std::endl;
    printRec(root, 0);
}

template <typename T>
void AVL_tree<T>::printRec(avl_node<T>* p, int level){
    if(p){
        printRec(p->left,level + 1);
        for(int i = 0; i < level; i++) std::cout<<"   ";
        std::cout << p->key << std::endl;
        printRec(p->right,level + 1);
    }
}

template <typename T>
T AVL_tree<T>::rootElement(){
    return root -> key;
}

template class AVL_tree<int>;
template class AVL_tree<double>;
template class AVL_tree<float>;
template class AVL_tree<char>;
template class AVL_tree<std::string>;
