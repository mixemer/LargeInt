//
//  LargeInt.cpp
//  csc311Project1
//
//  Created by Mehmet Sahin on 9/14/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#include "LargeInt.hpp"
#include <string>

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
    this->negative = other.negative;
}

void LargeInt:: operator= (const UDList<int>& otherlist)
{
    list = otherlist;
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
    int i = 0;
    if (num[0] == '-'){
        negative = true;
        i = 1;
    }else {
        negative = false;
    }
    long size = num.size();
    if (size > 0){
        while (i < size) {
            if (!isdigit(num[i])){
                std::cout << string("Bad data type");
                return;
            }
            list.insertBack(num[i] - '0');
            i++;
        }
    }
}

void LargeInt:: fillTheList(int num)
{
    if (num == 0)
        list.insertFront(num);
    else if (num < 0){
        negative = true;
        num = num * -1;
    }else{
        negative = false;
    }
    while (num) {
        list.insertFront(num % 10);
        num = num / 10;
    }
}

LargeInt LargeInt:: abs(const LargeInt& other) 
{
    LargeInt temp = other;
    if (temp.negative) temp.negative = false;
    return temp;
}

UDList<int> LargeInt:: add(const LargeInt& other)
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
    return temp;
}

LargeInt LargeInt:: operator+ (const LargeInt& other)
{
    LargeInt temp;
    if ( (this->negative && other.negative) ) {
        temp = add(other);
        temp.negative = true;
    } else if ( (!this->negative && !other.negative) ){
        temp = add(other);
        temp.negative = false;
    } else {
        LargeInt absThis = abs(*this);
        LargeInt absOther = abs(other);
        UDList<int>::iterator first = nullptr;
        UDList<int>::iterator second = nullptr;

        if (absThis == absOther) {
            temp.list.insertFront(0);
            temp.negative = false;
        }else if (this->negative) {
            if (absThis > absOther){
                first = list.end();
                second = other.list.end();
                temp.negative = true;
            }else{
                first = other.list.end();
                second = list.end();
                temp.negative = false;
            }
        }else {
            if (absThis > absOther){
                first = list.end();
                second = other.list.end();
                temp.negative = false;
            }else{
                first = other.list.end();
                second = list.end();
                temp.negative = true;
            }
        }
        temp = subs(first, second);
    }
    return temp;
}

UDList<int> LargeInt:: subs(UDList<int>::iterator first, UDList<int>::iterator second)
{
    UDList<int> temp;
    UDList<int>::iterator p;

    while (first || second)
    {
        int num = 0;
        if (first && second ) {
            if (first->info < second->info) {
                p = first->prev;
                while (p->info == 0)
                    p = p->prev;
                p->info -= 1;
                p = p->next;
                while (p != first) {
                    p->info += 10;
                    p->info -= 1;
                    p = p->next;
                }
                p->info += 10;
            }
            num = first->info - second->info;
            temp.insertFront(num);
            second = second->prev;
        }else {
            if (first->info != 0) 
                temp.insertFront(first->info);
        }
        first = first->prev;
    }

    return temp;
}

LargeInt LargeInt:: operator- (const LargeInt& other)
{
    LargeInt temp;
    UDList<int>::iterator first = nullptr;
    UDList<int>::iterator second = nullptr;
    bool bothPositive = (!this->negative && !other.negative);
    bool bothNegative = (this->negative && other.negative);
    if (bothNegative || bothPositive){
        if ((*this) == other) {
            temp.list.insertFront(0);
            temp.negative = false;
        }else {
            if ( bothNegative ) {
                if ((*this) > other){
                    first = other.list.end();
                    second = list.end();
                    temp.negative = false;
                }else{
                    first = list.end();
                    second = other.list.end();
                    temp.negative = true;
                }
            } else if ( bothPositive ){
                if ((*this) > other){
                    first = list.end();
                    second = other.list.end();
                    temp.negative = false;
                }else{
                    first = other.list.end();
                    second = list.end();
                    temp.negative = true;
                }
            }
            temp = subs(first, second);
        }
    }else {
        if (this->negative) {
            temp.negative = true;
        }else{
            temp.negative = false;
        }
        temp = add(other);
    }
    return temp;
}

bool LargeInt:: operator== (const LargeInt& other)
{
    UDList<int>::iterator ithis = list.begin();
    UDList<int>::iterator iother = other.list.begin();
    bool sameLength = (this->list.getLength() == other.list.getLength());
    bool bothPositive = (!this->negative && !other.negative);
    bool bothNegative = (this->negative && other.negative);
    bool same = true;
    
    if (sameLength && (bothPositive || bothNegative)) {
        while (ithis && iother) {
            if (ithis->info != iother->info){
                same = false;
                break;
            }
            ithis = ithis->next;
            iother = iother->next;
        }
    }else {
        same = false;
    }
    
    return same;
}

bool LargeInt:: operator< (const LargeInt& other)
{
    UDList<int>::iterator ithis = list.begin();
    UDList<int>::iterator iother = other.list.begin();
    bool smaller = (this->list.getLength() < other.list.getLength());
    bool sameLength = (this->list.getLength() == other.list.getLength());
    bool same = false;

    if (this->negative && !other.negative) {
        smaller = true;
    }else if (!this->negative && other.negative){
        smaller = false;
    }else if (sameLength && (!this->negative && !other.negative)) {
        while (ithis && iother) {
            if (ithis->info < iother->info) {
                smaller = true;
                same = false;
                break;
            }else if (ithis->info > iother->info) {
                smaller = false;
                break;
            }else {
                same = true;
            }
            ithis = ithis->next;
            iother = iother->next;
        }
    }else if (this->negative && other.negative){
        if (sameLength){
            while (ithis && iother) {
                if (ithis->info > iother->info) {
                    smaller = true;
                    same = false;
                    break;
                }else if (ithis->info < iother->info) {
                    smaller = false;
                    break;
                }else {
                    same = true;
                }
                ithis = ithis->next;
                iother = iother->next;
            }
        }else{
            smaller = (this->list.getLength() > other.list.getLength());
        }
    }
    if (same) smaller = false;
    return smaller;
}

bool LargeInt:: operator> (const LargeInt& other) 
{
    UDList<int>::iterator ithis = list.begin();
    UDList<int>::iterator iother = other.list.begin();
    bool bigger = (this->list.getLength() > other.list.getLength());
    bool sameLength = (this->list.getLength() == other.list.getLength());
    bool same = false;

    if (this->negative && !other.negative) {
        bigger = false;
    }else if (!this->negative && other.negative){
        bigger = true;
    }else if (sameLength && (!this->negative && !other.negative)) {
        while (ithis && iother) {
            if (ithis->info > iother->info) {
                bigger = true;
                same = false;
                break;
            }else if (ithis->info < iother->info) {
                bigger = false;
                break;
            }else {
                same = true;
            }
            ithis = ithis->next;
            iother = iother->next;
        }
    }else if (this->negative && other.negative){
        if (sameLength){
            while (ithis && iother) {
                if (ithis->info < iother->info) {
                    bigger = true;
                    same = false;
                    break;
                }else if (ithis->info > iother->info) {
                    bigger = false;
                    break;
                }else {
                    same = true;
                }
                ithis = ithis->next;
                iother = iother->next;
            }
        }else{
            bigger = (this->list.getLength() < other.list.getLength());
        }
    }
    if (same) bigger = false;
    return bigger;
}


std::ostream& operator<< (std::ostream& out, const LargeInt& largeInt)
{
    UDList<int>::iterator it = largeInt.list.begin();
    if (largeInt.negative) {
        out << '-';
    }
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
    if (this->negative) {
        std::cout << '-';
    }
    list.printFromFront();
}





