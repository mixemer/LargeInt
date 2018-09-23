/**
 CSC-331 Project 1, Doubly Linked List and LargeInt
 Purpose: Create two classes to implement LargeInt idea.
 
 @author Copyright © 2018 Mehmet Sahin. All rights reserved.
 @version 1.1 Created by Mehmet Sahin on 9/8/18.
 */


#include <iostream>
#include "LargeInt.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    LargeInt l("200");
    LargeInt l2("300");
    
    LargeInt l3;
    
    l3 = l + l2;
    l3 = "0";
    
    cout << l3 << endl;
    
    return 0;
}
