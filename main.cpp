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
// test LargeInt with addition of two negative values function prototypes
LargeInt additionOfTwoNegativeValueTest();
// test LargeInt with bigger smaller operators function prototypes
void biggerSmallerTest(int num1, int num2);
// test LargeInt with equal operator function prototypes
void equalTest(int num1, int num2);
// test LargeInt with minus operator function prototypes
void minusTest(int num1, int num2);
// test LargeInt with minus operator function prototypes
void differentSignAddTest(int num1, int num2);
// test equality operator
void equalityTest(int num1, int num2);

int main(int argc, const char * argv[]) {
    
    // cout << storeStringTest() << endl;
    // cout << storeIntTest() << endl;

    // cout << negativeValueTest() << endl;

    // cout << additionOfTwoNegativeValueTest() << endl;

    // biggerSmallerTest(-100, -50);

    // equalTest(-10, 10);

     minusTest(2, 2);
    // minusTest(-2,-100);

    // differentSignAddTest(1, -10);

     equalityTest(2,2);

    return 0;
}

void equalityTest(int num1, int num2) 
{
    LargeInt l(num1);
    LargeInt l2(num2);

    cout << (l == l2) << endl;
}

void differentSignAddTest(int num1, int num2)
{
    LargeInt l(num1);
    LargeInt l2(num2);

    LargeInt l3;
    l3 = l + l2;

    cout << l3 << endl;
}

void minusTest(int num1, int num2)
{
    LargeInt l(num1);
    LargeInt l2(num2);

    LargeInt l3;
    l3 = l - l2;

    cout << l3 << endl;
}

void equalTest(int num1, int num2)
{
    LargeInt l(num1);
    LargeInt l2(num2);

    cout << l << " is equal to " << l2 << ": " << (l == l2) << endl;

}

void biggerSmallerTest(int num1, int num2)
{
    LargeInt l(num1);
    LargeInt l2(num2);

    cout << l << " is bigger than " << l2 << ": " << (l > l2) << endl;
    cout << l << " is smaller than " << l2 << ": " << (l < l2) << endl;
}

LargeInt additionOfTwoNegativeValueTest()
{
    LargeInt l(-1000);
    LargeInt l2(-1000);

    LargeInt l3;
    l3 = l + l2;

    return l3;
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
