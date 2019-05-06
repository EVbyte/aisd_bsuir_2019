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
    for (int i = 0; i < 1000; i++ )
        avl_tree.Insert(rand() % 1000);
    
    avl_tree.Print();
    std::cout << std::endl << std::endl << std::endl;
    std::cout << avl_tree.GetHeight();
    
    for (int i = 0; i < 1000; i++)
        avl_tree.Remove(rand() % 1000);
    
    avl_tree.Print();
    std::cout << std::endl << std::endl << std::endl;
    std::cout << avl_tree.GetHeight();

    for (avl_node<int>* n = avl_tree.minNode(); n; n = avl_tree.successor(n))
        std::cout << n -> key << std::endl;
    return 0;
}

