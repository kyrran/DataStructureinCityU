#include <iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <list>
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

int checkFirstInput();
int * checkSecondInput(int size);

int main(int argc, char * argv[])
{
    int size = checkFirstInput();
    //cin >> size;
    int * A = checkSecondInput(size);
    ListNode* *_pool = new ListNode* [size+2];
       
    //set head 0
    List *list = new List();
    list->set_Head();
    list->get_Head()->set_Data(0);
    ListNode *cur = list->get_Head();
    _pool[0] = list->get_Head();
    //add 1 2 3 4 5
    for (int i = 1; i <= size; i++ )
    {
        ListNode * node = new ListNode();
        
        node->set_Data(i);
        list->insertNode(cur, node);
        _pool[i] = node;
        cur = cur->get_Rnext();
        //cout << *i << " ";
    }
    //add 6 as tail
    ListNode * tail = new ListNode();
    tail->set_Data(size+1);
    list->insertNode(cur,tail);
    _pool[size+1] = list->get_Head();
    
    //to remove every input in reverse order
    //scan their left and right neighbor
    //print neighbour pairs you got in reverse order

    std::list <int> outlist;
    //array, the pointer, with original input order
    for(int i = size-1; i >= 0; i--)
    {
        int value = A[i];
        ListNode * temp = _pool[value];
        
        //get its neighbors
        int right = temp->get_Rnext()->get_Data();
        int left = temp->get_Lnext()->get_Data();
        list->removeNode(list->get_Head(),temp);
        outlist.push_front(right);
        outlist.push_front(left);
        //cout << left << " " << right << endl;
        //0 1 2 3 4 5 6
        //3 
    }

    //print out the vector in reverse order
    std::list<int>::iterator it;
    for (it = outlist.begin(); it != outlist.end(); ++it)
    {
        cout << *it << " ";
        cout << *++it;
        cout << endl;
    }
    list->clear(list->get_Head());
    delete [] A;
    delete [] _pool;
    return 0;
}

int checkFirstInput()
{
    string s;
    int n;

    //cout << "n: ";
    getline(cin, s);

    while(cin.fail() || cin.eof() || s.find_first_not_of("0123456789") != std::string::npos) 
    {
        if( s.find_first_not_of("0123456789") == std::string::npos) {
            std::cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return checkFirstInput();
    }

    size_t st; //size_t
    try
    {
        n = stoi(s,&st);
    }catch (std::out_of_range const &e)
    {
        //cout << "Integer are out_of_range" << endl;
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return checkFirstInput();
    }catch (std::invalid_argument const &e) {
        //cout << "invalid_argument" << endl;
        cin.clear();
        return checkFirstInput();
    }

    if(n < 1 || n > 100000)
    {
        //cout << "Error" << endl;
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return checkFirstInput();
    }

    cin.clear(); //clear bad input flag
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //cout << n << endl;
    return n;
}
int * checkSecondInput(int size)
{
    cin.clear(); //clear bad input flag
    //cout << "Permuation: "; 
    int *arr = new int [size];

    string S, T;  // declare string variables  
    getline(cin, S); // use getline() function to read a line of string and store into S variable.  
    stringstream X(S); // X is an object of stringstream that references the S string  
    int t = 0;
    // use while loop to check the getline() function condition  
    while (getline(X, T, ' ')) { 
        
        while(cin.fail() || cin.eof() || T.find_first_not_of("0123456789") != string::npos) 
        {
            if( T.find_first_not_of("0123456789") == string::npos) 
            {
                cin.clear();
                X.clear();
                delete []arr;
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return checkSecondInput(size);
        }

        size_t st; //size_t
        int digit;
        try
        {
            digit = stoi(T,&st);
        }
        catch (std::out_of_range const &e)
        {
            //cout << "Integer are out_of_range" << endl;
            cin.clear();
            X.clear();
            delete[] arr;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return checkSecondInput(size);
        }
        catch (std::invalid_argument const &e) 
        {
            //cout << "invalid_argument" << endl;
            cin.clear();
            X.clear();
            delete[] arr;
            return checkSecondInput(size);
        }

        if(digit < 1 || digit > size)
        {
            //cout << "Error" << endl;
            cin.clear();
            X.clear();
            delete[] arr;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return checkSecondInput(size);
        }

        arr[t] = digit;
        t++;
    }
    cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return arr;
}