//
//  LargeInt.cpp
//  csc311Project1
//
//  Created by Mehmet Sahin on 9/14/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#include "LargeInt.hpp"

LargeInt:: LargeInt(const std::string& num)
{
    fillTheList(num);
}

LargeInt:: LargeInt(int num)
{
    fillTheList(num);
}

LargeInt:: LargeInt(const UDList<int> &l)
{
    list = l;
}
// could override what is inside
void LargeInt:: operator= (const LargeInt& other)
{
    UDList<int>::iterator head = list.begin();
    if (head){
        list.makeEmpty();
    }
    list = other.list;
}
// could override what is inside
void LargeInt:: operator= (const std::string& num)
{
    UDList<int>::iterator head = list.begin();
    if (head){
        list.makeEmpty();
    }
    fillTheList(num);
}

void LargeInt:: operator= (int num)
{
    UDList<int>::iterator head = list.begin();
    if (head){
        list.makeEmpty();
    }
    fillTheList(num);
}

// could override what is inside
void LargeInt:: fillTheList(const std::string& num)
{
    long size = num.size();
    if (size > 0){
        for (int i = 0; i < size; i++){
            if (!isdigit(num[i])){
                std::cout << string("Bad data type");
                return;
            }
            list.insertBack(num[i] - '0');
        }
    }
}

void LargeInt:: fillTheList(int num)
{
    if (num == 0)
        list.insertFront(num % 10);
    while (num) {
        list.insertFront(num % 10);
        num = num / 10;
    }
}

LargeInt LargeInt:: operator+ (const LargeInt& other)
{
    UDList<int> temp;
    bool carry = false;
    UDList<int>::iterator ithis = list.end();
    UDList<int>::iterator iother = other.list.end();
    
    while (ithis || iother)
    {
        int total = 0;
        if (carry) total += 1;
        if (ithis && iother){
            total += (ithis->info + iother->info);
            ithis = ithis->prev;
            iother = iother->prev;
        }else if (ithis){
            total += ithis->info;
            ithis = ithis->prev;
        }else{
            total += iother->info;
            iother = iother->prev;
        }
        
        if (total > 9){
            carry = true;
            temp.insertFront(total % 10);
        }else{
            carry = false;
            temp.insertFront(total);
        }
    }
    
    if (carry) temp.insertFront(1);
    return LargeInt(temp);
}

bool LargeInt:: operator== (const LargeInt& other)
{
    UDList<int>::iterator ithis = list.begin();
    UDList<int>::iterator iother = other.list.begin();
    
    if (list.getLength() != other.list.getLength())
        return false;
    
    while (ithis && iother) {
        if (ithis->info != iother->info)
            return false;
        ithis = ithis->next;
        iother = iother->next;
    }
    
    return true;
}

std::ostream& operator<< (std::ostream& out, const LargeInt& largeInt)
{
    UDList<int>::iterator it = largeInt.list.begin();
    
    while (it) {
        out << it->info;
        it = it->next;
    }
    return out;
}

// could override what is inside ???? check with professor
std::istream& operator>> (std::istream& in,LargeInt& largeInt)
{
    std::string num;
    in >> num;
    if (largeInt.list.getLength() == 0)
        largeInt = num;
    return in;
}



void LargeInt:: print() const
{
    list.printFromFront();
}





