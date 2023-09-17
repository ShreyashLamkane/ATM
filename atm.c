#include<stdio.h>
#include<stdlib.h>

int pinCheck();
void takeAmount();

int pin=1;
int balance=200;
int amount=0;

int main(){
    printf("Set the 4 digit pin: ");
    scanf("%d",&pin);
    int choice;
    int check=1;
    int chance=0;
    while(1){
        printf("\nSelect from one of the Choice:\n1.Check balance\n2.Withdraw Money\n3.Deposit Money\n4.Change pin\n5.Exit\n");
        printf("\nEnter one of the Choice: ");
        scanf("%d",&choice);
        if(choice==1){
            process1:
                check=pinCheck();
                if(check==1){
                    printf("\nAvailable balance is: %d",balance);
                }
                else{
                    chance++;
                    if (chance==3){
                        exit(0);
                    }
                    else{
                        printf("\nPlease Enter the Correct Pin.You have %d chances left.",(3-chance));
                        goto process1;
                    }
                }
        }

        else if(choice==2){
            process2:
                check=pinCheck();
                if(check==1){
                    takeAmount();
                    
                    if ((balance-amount)>200){
                        balance-=amount;
                        printf("\nBalance updated!\n");
                        

                    }
                    else{
                        printf("\nPlease Enter the Minimum Balance of 200.");
                    }
                }
                else{
                    chance++;
                    if (chance==3){
                        exit(0);
                    }
                    else{
                        printf("\nPlease Enter the Correct Pin.You have %d chances left.",(3-chance));
                        goto process2;
                    }
                }
        }

        else if(choice==3){
            
            process3:
                check=pinCheck();
                if(check==1){
                    takeAmount();
                    balance+=amount;
                    printf("\nBalance updated!\n");
                }
                else{
                    chance++;
                    if (chance==3){
                        exit(0);
                    }
                    else{
                        printf("\nPlease Enter the Correct Pin.You have %d chances left.",(3-chance));
                        goto process3;
                    }
                }
            
        }

        else if(choice==4){
            
            process4:
                check=pinCheck();
                if(check==1){
                    printf("Enter the new pin: ");
                    int newPin=1;
                    scanf("%d",&newPin);
                    printf("\nConfirm the Pin: ");
                    int confirmPin=1;
                    scanf("%d",&confirmPin);
                    if(newPin==confirmPin){
                        pin=newPin;
                        printf("\nNew Pin is set Successfully!");
                    }
                }
                else{
                    chance++;
                    if (chance==3){
                        exit(0);
                    }
                    else{
                        printf("\nPlease Enter the Correct Pin.You have %d chances left.",(3-chance));
                        goto process4;
                    }
                }
            
        }
        

        else{
            exit(0);
        }
    }

    return 0;
}
int pinCheck(){
    int temp=1;
    printf("\nEnter the Pin: ");
    scanf("%d",&temp);
    if(temp==pin)
        return 1;
    else{
        return 0;
    
    }
}
void takeAmount(){
    printf("\nEnter the amount for the transaction: ");
    scanf("%d",&amount);
}