#include <iostream>
#include <string>
#include <cstdio>
#include <regex>
#include <cstring>
#include <sstream>
using namespace std;
#include <stack>

bool isDigit(char symbol)
{
    if(symbol >= '0' && symbol <= '9')
    {
        return true;
    }
    return false;
}
int calc(char ope, int x, int y)
{
    switch(ope)
    {
        case '+':
            return (x+y);
        case '-':
            return (y-x);
        case '*':
            return (x*y);
    }
    return -100;
}

void checkInput(stack<int>stack)
{
    char * arr = new char[1005];
    int i = 0;
    int c = 0;

    do
    {
        c = getchar();

        if(c == 32)
        {
            continue;
        }
    
        arr[i] = (char)c;

        if (arr[i] == '\n')
        {
            char e;
            int result;
            //do not read the final bit '\n'
            for(int j = 0; j < i; j++)
            {
                e = arr[j];
                //cout << e << endl;

                
                // use while loop to check the getline() function condition  

                if(isDigit(e))
                {
                    stack.push(e-'0');
                }
                else
                {
                    int x = stack.top();
                    stack.pop();
                    int y = stack.top();
                    stack.pop();
                    result = calc(e,x,y);

                    stack.push(result);
                }
            }
            i = 0;
            stack.pop();
            //after pop the result, if there are still items in stack
            cout << result << endl;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            std::stack<int>nothing; 
            stack.swap(nothing);
        }
        else
        {
            i++;
        }
       

    } while(c!=EOF);

    
}


int main()
{
    stack<int>stack;
    checkInput(stack);
    return 0;
}
