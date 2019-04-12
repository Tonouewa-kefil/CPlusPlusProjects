//
//  main.cpp
//  Code Jam
//
//  Created by Tonouewa King kefil on 4/5/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std;

 void checkNumberGenerator(int,int);
void SplitCheck(int);
int testNum=1;
int main()
{

    srand(unsigned(time(NULL)));
    
    int i_T;
    int i_testNum;
    cout <<"How many check would you like to write?: ";
    cin>>i_testNum;
    cout<<endl;
    while (i_testNum>=1 && i_testNum<=100)
    {
    while (i_testNum-- )
    {
    
    cout<<"what is the amount of the check you wish to write : ";
    cin>>i_T;
    if (i_T>0)
    {
       
        SplitCheck(i_T);
        
    }
        
    }
    }
    

    return 0;
}

void SplitCheck(int i_Limit)
{
    if (i_Limit>=1 && i_Limit<4)
    {
        cout<<"you do not need my service to write this check!"<<endl;
    }
    
    
    else if (i_Limit>=4 && i_Limit<100000)
    {
        checkNumberGenerator(i_Limit,testNum);
    testNum++;
        return;
    }
    
   
    else if (i_Limit>=100 && i_Limit<1000000000)
    {
        checkNumberGenerator(i_Limit,testNum);
        testNum++;
        return;

    }
    
}
 void checkNumberGenerator(int i_Limit, int i_testNum)
{
    int i_A;
    int i_B = 0;
    string s_checkAmount;
    
    i_A=rand()%i_Limit+1;
    s_checkAmount=to_string(i_A);
    if(s_checkAmount.find('4')!=-1)
    {
        checkNumberGenerator(i_Limit,i_testNum);
    }

    else
    {
        i_B=i_Limit-i_A;
    }
    s_checkAmount=to_string(i_B);
    if(s_checkAmount.find('4')!=-1)
    {
        checkNumberGenerator(i_Limit,i_testNum);
    }
    else{
        cout<<i_Limit<<" Case #"<<i_testNum<<" "<<i_A<<" "<<i_B;
        cout<<endl;
        }
   
    
}


