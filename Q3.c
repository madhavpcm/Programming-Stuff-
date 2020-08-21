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

void  fdPrint(struct customer x){ 
    printf("First Name : %s\n Last Name : %s\n Last Name : %s\nAccount No : %d\n Balance : %d\n",
                    x.fname , x.mname , x.lname , x.accNo , x.balance);
}
void dataSort(struct customer *db ,int n){
    int i, j; 

    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (strcmp(db[j].fname, db[j + 1].fname) > 0) { 
                char* temp; 
                temp = (char*)calloc(30, sizeof(char)); 
                strcpy(temp, db[j]); 
                strcpy(db[j], db[j + 1]); 
                strcpy(db[j + 1], temp); 
            } 
}
void dataFD(struct customer *db , int n){
    for(int i = 0 ; i< n ; i++){
        if(strcmp(db[i].accType,"FD")==0){
            fdPrint(db[i]);
        }
    }
}
void main(){
    int n ;
    printf("Enter the no of customer details you wanna add::");
    scanf("%d", &n);

    struct customer* db;

    db = (struct customer*)malloc(sizeof(struct customer) * n);

    for(int i =0 ; i< n ;i++){
        xinput(db[i]);
    }
    int x ;
    printf("Enter accNo to be searched ::");
    scanf("%d", &x);
    for(int i =0 ; i< n ; i++){
        if(db[i].accNo == x)
            printf("Found !! your balance is :: %f", db[i].balance);
    }   
    dataSort(db , n);
    dataFD(db , n);

    free(db);
}