#include<stdio>
#include<stdlib>
int strLen(char *p)
{
   int c = 0;
    while( *(p+c) != '\0' )
      c++;
    return c;
}
void revone(char *string)
{
   int length, c;
   char *begin, *end, temp;
 
   length = strLen(string);
 
   begin = string;
   end = string;
 
   for ( c = 0 ; c < ( length - 1 ) ; c++ )
      end++;
 
   for ( c = 0 ; c < length/2 ; c++ ) 
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}
void revAll(char** x)
{
    for (int i =0 ; i < n ; i++){
        revone(A[i]);
    }
}
int usrCalc(char** names, int n , int ch) 
{ 

    int i, j; 
    if(ch == 1){
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (strcmp(names[j], names[j + 1]) > 0) { 
                char* temp; 
                temp = (char*)calloc(30, sizeof(char)); 
                strcpy(temp, names[j]); 
                strcpy(names[j], names[j + 1]); 
                strcpy(names[j + 1], temp); 
            } 
    return 0;
    }else if(ch ==2){
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (strcmp(names[j], names[j + 1]) < 0) { 
                char* temp; 
                temp = (char*)calloc(30, sizeof(char)); 
                strcpy(temp, names[j]); 
                strcpy(names[j], names[j + 1]); 
                strcpy(names[j + 1], temp); 
            } 
    return 0;
    }else{printf("invalid option try again");return 1;}   
} 
  
void main(){
    int n;

    printf("Enter how many strings you need :: ");
    scanf("%d", &n);
    char** A;
    A = (char**)calloc(n, sizeof(char*)); 

    printf("Enter N strings :\n");

    for(int i = 0 ; i < n ; i++){
        printf("string %d\n", i +1);
        A[i] = (char*)calloc(sizeof(char));
        scanf("%s" , A[i]);
    }
    int ch =0 ;
    printf("Do you want it sorted in ascending or descending ? :: 
    \n 1. Ascending \n 2. Descending");
    scanf("%d",&ch);

    revAllstrings(A , n);
    while(usrCalc(A ,n,ch) == 1)
    {
        printf("\nRe enter option ::");
        scanf("%d", &ch);
        usrCalc(A ,n,ch);
    }
    
    ///Destroy    
    for(int i =0 ; i< n ; i++){
        free(A[i]);
    }
    free(A);
}