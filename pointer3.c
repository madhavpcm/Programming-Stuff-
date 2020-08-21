#include<stdio.h>
#include<stdlib.h>

struct customer{
    char* fname;
    char* mname;
    char* lname;

    char* accType;
    int accNo;

    float balance;

}x[50];
void xinput(struct customer x){
    scanf("%s %s %s %s %d %f",&x.fname , &x.mname , &x.lname , &x.accType ,&x.accNo , &x.balance);
}
char* xgetFname(struct customer x)  { return x.fname;   }
float xgetBalance(struct customer x){ return x.balance; }
void  xprint(struct customer x){ 
    printf("First Name : %s\n Last Name : %s\n Last Name : %s\n Account Type : %s\n Account No : %d\n Balance : %d\n",x.fname , x.mname , x.lname , x.accType ,x.accno , x.balance);
}

void main(){
    int n ;
    printf("Enter the no of customer details you wanna add::");
    scanf("%d", &n);

    struct customer* db;

    db = (struct customer*)malloc(sizeof(struct customer) * n);

    for(int i =0 ; i< n ;i++){
        
    }

}