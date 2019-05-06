//
//  main.cpp
//  avl_tree
//
//  Created by Eduard Adasko on 5/5/19.
//  Copyright © 2019 Eduard Adasko. All rights reserved.
//
#include <iostream>
#include "bs_tree.hpp"
#include "avl_tree.hpp"
#include "vector"


int main(int argc, const char * argv[]) {
    AVL_tree<int> avl_tree ({1,2,3,4});
    avl_tree.Print();
    avl_tree.Remove(1);
    avl_tree.Print();
    return 0;
}

