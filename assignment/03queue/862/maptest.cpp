// C++ program to demonstrate use of map of vector
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node{
    public:
        int val;
        Node *next;
        Node *prev;
      
        Node(int x)
        {
            val = x;
            next = NULL;
            prev = NULL;
        }
};

class Queue{
    private:
        Node *front;
        Node *end;
        int size;
    public:
        Queue()
        {
            front = NULL;
            end = NULL;
            size = 0;
        }
        void PushBack(int x);
        void vectorFront(Node * node);
      
        Node* getEnd();
        void PopFront();
        
        bool IsEmpty();
        Node* getFront();

        //int searchNodeIndex(int x);
        //pair<Node*, Node*> searchNode(int x);
        //bool isNodeExisted(int x);
};
void Queue::vectorFront(Node * node){
    front = node;
}
void Queue::PopFront(){

    if (IsEmpty()) {
        //cout << "1empty" << endl;
        return;
    }

    Node *node = front;
    //new front
    front = front->next;
    if(front == NULL)
    {
       end = NULL; 
    }
    else
    {
        front->prev = NULL;
    }
    
    delete node;
    size--;
}

void Queue::PushBack(int x){

    Node * newNode = new Node(x);
    if (IsEmpty()) {
        front = newNode;
        //end = front = newnode
        end = front;
        size++;
        return;
    }

    newNode->prev = end;
    end->next = newNode;
    //newnode is new end
    end = newNode; 
    size++;
}
Node* Queue::getEnd()
{
    if (IsEmpty()) 
    {
        //cout << "2empty" << endl;
        return NULL;
    }

    return end;
}
bool Queue::IsEmpty()
{
    //both null -> true?
    return (front == NULL && end == NULL);
}
void show(unordered_map<int, vector<Node*> >& mapOfvector)
{
	// Using iterator to access
	// key, value pairs present
	// inside the mapOfvector
	for (unordered_map<int, vector<Node*> > ::iterator it = mapOfvector.begin();
		it != mapOfvector.end();
		it++) {

		// Key is integer
		cout << it->first << " => ";

		// Value is a vector of string
		vector<Node*> st = it->second;

		// Strings will be printed
		// in sorted order as vector
		// maintains the order
		for (vector<Node*> ::iterator it = st.begin();
			it != st.end(); it++) {
			cout << (*it)->val << ' ';
		}
		cout << '\n';
	}
}

bool isNodeExisted(int x, unordered_map<int, vector<Node*> > mapOfvector)
{
    if(mapOfvector.find(x) == mapOfvector.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

Node* Queue::getFront(){

    if (IsEmpty()) {
        //cout << "3empty" << endl;;
        return NULL;
    }

    return front;
}

// Driver code
int main()
{
	// Declaring a map whose key
	// is of integer type and
	// value is a vector of string

    Queue *q = new Queue();

    
	unordered_map<int, vector<Node*> > mapOfvector;



    q->PushBack(3);
	// Inserting values in the
	// vector mapped with key 1
    Node * p = q->getEnd();
	mapOfvector[p->val].push_back(p);

    q->PushBack(3);
    mapOfvector[q->getEnd()->val].push_back(q->getEnd());

    q->PushBack(2);
    mapOfvector[q->getEnd()->val].push_back(q->getEnd());

    q->PushBack(3);
    mapOfvector[q->getEnd()->val].push_back(q->getEnd());

    q->PushBack(4);
    mapOfvector[q->getEnd()->val].push_back(q->getEnd());

    q->PopFront();

    

	show(mapOfvector);

    cout << "........." << endl;

    cout << mapOfvector[3].size()<<endl;
	return 0;
}
