#ifndef LIST_H
#define LIST_H

#include <iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#include <cstdio>
#include <cmath>
using namespace std;

class ListNode
{
    public:
        ListNode()
        {
            data = -1; 
            Lnext = NULL;
            Rnext = NULL;
        }

        /* Get functions */   
        int  get_Data() {return data; }
        ListNode *get_Lnext() {return Lnext;}
        ListNode *get_Rnext() {return Rnext;}

        /* Set functions */ 
        void set_Data(int dataValue)        {data  = dataValue;}
        void set_Lnext(ListNode* LeftNode)  {Lnext = LeftNode; }
        void set_Rnext(ListNode* RightNode) {Rnext = RightNode;}

    private:
        int data;
        ListNode *Lnext;
        ListNode *Rnext;
};

class List
{
    public:
        List(string name)
        {
            name = name;
            head = NULL;
            listSize = 0;
        }

        List()
        {
            name = "";
            head = NULL;
            listSize = 0;
        }

        void insertNode(ListNode *p, ListNode *newNode);
        void removeNode(ListNode * head, ListNode* pos);
        void print();
        void clear(ListNode * head);
        int count();

        /* Get functions */   
        string get_Name() {return name; }
        ListNode *get_Head() {return head;}
        int get_Size(){return listSize;}


        /* Set functions */ 
        void set_Name(int name) {name  = name;}
        void set_Head()
        {
            head = new ListNode(); 
            head->set_Lnext(NULL); 
            head->set_Rnext(NULL);
            listSize = 1;
        }
    private:
        string name;
        ListNode *head;
        int listSize;
};

#endif // LIST_H