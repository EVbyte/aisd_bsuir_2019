//
//  main.cpp
//  avl_tree
//
//  Created by Eduard Adasko on 5/5/19.
//  Copyright © 2019 Eduard Adasko. All rights reserved.
//
#include <iostream>
#include "bs_tree.hpp"
#include "vector"
int main(int argc, const char * argv[]) {
    BS_tree<int> tree({-345, 2, 2234, 9, 5});
    tree.Insert({123,-432432, -43543543, 2340});
    tree.inOrder();
    std ::cout << std::endl;
    
    for(bs_node<int>* node = tree.minNode(); node; node = tree.successor(node))
        std ::cout << node -> key << " ";
    
    std ::cout << std::endl;
    
    for(bs_node<int>* node = tree.maxNode(); node; node = tree.predecessor(node))
        std ::cout << node -> key << " ";
    
    return 0;
}
