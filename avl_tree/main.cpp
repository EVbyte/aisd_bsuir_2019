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
using namespace std;


int main(int argc, const char * argv[]) {
    AVL_tree<double> avl_tree;
    avl_tree.Insert({1, 2, 3, 4, 5});
    avl_tree.Print();
    
    avl_tree.Remove(2);
    avl_tree.Print();
    
    for (avl_node<double>* n = avl_tree.minNode(); n; n = avl_tree.successor(n))
        cout << n -> key << " ";
    
    return 0;
}

