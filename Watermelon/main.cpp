#include <cstdio>
#include <cstring>

using namespace std;

bool isPrime(int);

int main()
{
    // insert code here...
    int W_Weight = 0;//Watermelon weight

    //Ask for the weight of the watermelon
    scanf("%d",&W_Weight);
    
    //Check if it is an even number (yes)
    if((W_Weight % 2) == 0)
    {
        //check if it is two because two is the only even number that does not satify the conditions (No)
        if(W_Weight == 2)
        {
            printf("No \n");
            fflush(stdout);
        }
        //If the weight is even and not two then (Yes)
        else
        {
            printf("Yes\n");
            fflush(stdout);
        }
    }
    //Check if the weight is 1 or a prime number or divisible by three of by 9 (No)
    else if (W_Weight == 1 || isPrime(W_Weight) || (W_Weight % 3) == 0 || (W_Weight % 9) == 0)
    {
        printf("No \n");
        fflush(stdout);
    }
    //Every other weight does not satisfy the sitution (No)
    else
    {
        printf("No \n");
        fflush(stdout);
        
    }
    
    return 0;
}


//Function to check for prime number.
bool isPrime(int num)
{
    bool primeCheck = true;
    for (int i = 2; i<=num/2; ++i) {
        if((num%i) == 0)
        {
            primeCheck = false;
            
        }
    }
    
    return primeCheck;
}

