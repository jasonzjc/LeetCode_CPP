//
//  main.cpp
//  Q2
//
//  Created by Jeff Zhao on 10/18/17.
//  Copyright © 2017 Jeff Zhao. All rights reserved.
//

//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* temp3 = l3;
        ListNode* last = temp3;
        int carry = 0;
        while(temp1 || temp2 || carry){
            temp3->next = new ListNode(0);
            if(temp1 && temp2){
                temp3->val = (temp1->val + temp2->val + carry)%10;
                carry = (temp1->val + temp2->val + carry)/10;
                last = temp3;
                temp3 = temp3->next;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if(!temp1 && temp2){
                temp3->val = (temp2->val + carry)%10;
                carry = (temp2->val + carry)/10;
                last = temp3;
                temp3 = temp3->next;
                temp2 = temp2->next;
            }
            else if(temp1 && !temp2){
                temp3->val = (temp1->val + carry)%10;
                carry = (temp1->val + carry)/10;
                last = temp3;
                temp3 = temp3->next;
                temp1 = temp1->next;
            }
            else{
                temp3->val = carry;
                carry = 0;
                temp3->next = nullptr;
                last = temp3;
            }
        }
        last->next = nullptr;
        return l3;
    }
};

class ListNodeBuid{
private:
    int x;
public:
    ListNode* ListNodeBuid1(int x){
        int n = x;
        ListNode* l = new ListNode(0);
        ListNode* temp = l;
        while (n/10 != 0) {
            temp->val = n%10;
            temp->next = new ListNode(0);
            temp = temp->next;
            n = n/10;
        }
        temp->val = n%10;
        temp->next = nullptr;
        return l;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    ListNodeBuid build;
    ListNode* l1 = build.ListNodeBuid1(1);
    ListNode* l2 = build.ListNodeBuid1(99);
    Solution solve;
    
    ListNode* l3;
    l3 = solve.addTwoNumbers(l1,l2);
    return 0;
}
