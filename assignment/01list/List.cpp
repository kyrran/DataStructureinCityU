#include "List.h"
void List::clear(ListNode * head)
{
    ListNode *temp = new ListNode();

    while(head != NULL)
    {
        temp = head;
        head = head->get_Rnext();
        delete temp;
    }
}

void List :: insertNode(ListNode *p, ListNode *newNode)
{   
    newNode->set_Lnext(p);
    newNode->set_Rnext(p->get_Rnext());
	if (p->get_Rnext()!=NULL) 
    {
        p->get_Rnext()->set_Lnext(newNode);
    }
	p->set_Rnext(newNode);
    listSize++;
}

void List::removeNode(ListNode * head, ListNode* pos)
{
    if(head == pos)
    {
        head = pos->get_Rnext();
    }
    if (pos->get_Lnext()!=NULL) 
    {
        pos->get_Lnext()->set_Rnext(pos->get_Rnext());
    }
    if (pos->get_Rnext()!=NULL)
    {
        pos->get_Rnext()->set_Lnext(pos->get_Lnext());
    } 
    delete pos;
    listSize--;
}


int List::count()
{
    listSize = 0;
    ListNode* p = head;
    while (p != NULL) 
    {
        listSize++;
        p = p->get_Rnext();
    }
    return listSize; 
}


void List :: print()
{
    ListNode *p = head;
     while (p!= NULL) 
    {
        cout << p->get_Data() << " ";
        p = p->get_Rnext();
    }
    cout << endl;
}