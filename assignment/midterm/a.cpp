#include <iostream>
using namespace std;

int main()
{
    int miraHP,dragonHP,miraAttack, dragonAttack, DragonRestore;


    while(scanf("%d%d%d%d%d", &miraHP,&dragonHP,&miraAttack, &dragonAttack, &DragonRestore)!=EOF)
    {
        //cout << miraHP << dragonHP << miraAttack << dragonAttack<< DragonRestore<<endl;
        while(dragonHP > 0 && miraHP > 0)
        {
            //mira attack -> draginhp - mira attack
            dragonHP -= miraAttack;
            //dragon attacks
            miraHP -= dragonAttack;
            //dragon restores
            dragonHP += DragonRestore;
            //cout << "DHP: "<<dragonHP << endl;
            //cout << "MHP: "<<miraHP << endl;

        }

        if(dragonHP <= 0)
        {
            cout << "Yes" << endl;
        }
        else if(miraHP <= 0)
        {
            cout << "No" <<endl;
        }

    }

}