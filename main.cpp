/**
 CSC-331 Project 1, Doubly Linked List and LargeInt
 Purpose: Create two classes to implement LargeInt idea.
 
 @author Copyright © 2018 Mehmet Sahin. All rights reserved.
 @version 1.1 Created by Mehmet Sahin on 9/8/18.
 */


#include <iostream>
#include "LargeInt.cpp" // cannot incldue hpp because of linking issue
using namespace std;

// test LargeInt with string values function prototypes 
LargeInt storeStringTest();
// test LargeInt with int values function prototypes
LargeInt storeIntTest();
// test LargeInt with negative values function prototypes
LargeInt negativeValueTest();

int main(int argc, const char * argv[]) {
    
    cout << storeStringTest() << endl;
    cout << storeIntTest() << endl;

    cout << negativeValueTest() << endl;
    
    return 0;
}

LargeInt negativeValueTest()
{
    LargeInt l(-1000);
    return l;
}

LargeInt storeIntTest()
{
    LargeInt l2("100");
    l2 = "200";

    return l2;
}

LargeInt storeStringTest()
{
    LargeInt l(0);
    l = 100;

    return l;
}
