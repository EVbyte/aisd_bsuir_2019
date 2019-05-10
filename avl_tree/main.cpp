//
//  main.cpp
//  avl_tree
//
//  Created by Eduard Adasko on 5/5/19.
//  Copyright © 2019 Eduard Adasko. All rights reserved.
//
#include <iostream>
#include "avl_tree.hpp"
#include "vector"
#include <time.h>


int main(int argc, const char * argv[]) {
    AVL_tree<int> avl_tree;
    for (int i = 0; i < 100; i++ )
        avl_tree.Insert(i);
    
    avl_tree.Print();
    
    for (int i = 0; i < 100; i++)
        avl_tree.Remove(rand() % 100);
    
    avl_tree.Print();

    for (avl_node<int>* n = avl_tree.minNode(); n; n = avl_tree.successor(n))
        std::cout << n -> key << std::endl;
    
    avl_tree.Print();
    
    long long n = avl_tree.size();
    
    for (int i = 0; i < n; i++){
        avl_tree.Remove(avl_tree.rootElement());
        avl_tree.Print();
    }
    
    avl_tree.Insert({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    
    avl_tree.Print();
    
    for (avl_node<int>* n = avl_tree.maxNode(); n; n = avl_tree.predecessor(n))
        std::cout << n -> key << std::endl;
    
    return 0;
}

