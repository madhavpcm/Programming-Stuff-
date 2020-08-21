#include<stdio.h>
#include<stdlib.h>

void inpMat(int * mat, int x ,int y){
    for(int i = 0 ; i < x ; i++)
        for(int j = 0 ; j < y ; j++){
            scanf("%d" , (mat + i*y +j));
        }    
}
void matDisp(int *mat , int x ,int y){
    for(int i = 0 ; i < x ; i++){
        for(int j = 0 ; j < y ; j++){
            printf("%d " , *(mat + i*y +j));
        }       
        printf("\n");
    }
}
void transpose(int *mat , int x ,int y){
    printf("transpose\n");
    for(int j = 0 ; j < y ; j++){
        for(int i = 0 ; i < x ; i++){
            printf("%d " , *(mat + j*y +i));
        }       
        printf("\n");
    }  
}
void matmult(int *mat1 , int *mat2 , int m , int n , int x ,int y){
    
    if(n!=x || m==0 || n==0 || x==0 || y==0){
        printf(
            "Matrices are not multiplyable"
        );
        return;
    }
    printf("Product\n");
    int *mat3;
    mat3 = (int*)malloc(m * y * sizeof(int));

    for (int i =0 ; i< m ; i++){
        printf("\n");
        for(int j=0 ; j< y ; j++){
            int sum =0;
            for(int k =0 ; k< n ;k++)
                sum += (*(mat1 + i*n + k)) * (*(mat2 + k*y +j)) ;
            printf("%d ", sum);
        }
    }

    free(mat3);
}
void add(int *mat1 , int* mat2 ,int m , int n ,int x ,int y){
    
    if(m != x || n != y){
        printf(
            "Matrices are not addable"
        );
    }
    printf("Sum Of A and B\n");
    for(int i = 0 ; i< m ; i++)
    {
        for(int j =0 ; j< n; j++)
            printf("%d ",*(mat1 + i*n +j) + *(mat2 + i*n + j));
        printf("\n");
    }
}
void upp_Triangle(int *mat , int x ,int y){
    if(x != y){
        printf("Not a Square Matrix");
        return;
    }
    printf("Upper Triangle of B\n");
    int Z = x*x;
    for(int i = 0 ; i < x ; i++ ){
        for (int j =0 ; j<= x -i -1 ; j++){
            printf("%*d " , x ,*(mat + j*y +i));
        }
        printf("\n");
    }
}
void diag(int *mat , int x ,int y){
    if(x != y){
        printf("Not a Square Matrix");
        return;
    }
    printf("\nDiagonal of A");
    for(int i = 0 ; i < x ; i++ ){
        printf("\n");
        for (int j =0 ; j<= i ; j++){
            if(i==j)
                printf("%2d" , *(mat + i*y +j));
            else
                printf("  ");
        }
    }   
}

void main (){

    int m=0,n=0,x=0,y=0;
    printf("Enter matrix dimensions for A and B");
    scanf("%d %d %d %d", &m , &n , &x ,&y);

    if(m<=0||n<=0||x<=0||y<=0){
        printf(
            "Invalid arguments for matrix dimensions"
        );
        return;
    }
    
    int* mat1;
    int* mat2;
    
    mat1 = (int*)malloc(m * n * sizeof(int));
    mat2 = (int*)malloc(x * y * sizeof(int));

    printf("\nInput first Matrix::\n");
    inpMat(mat1 , m , n);
    printf("\nInput second Matrix::\n");
    inpMat(mat2 , x , y);
    
    add(mat1 , mat2, m ,n , x ,y) ;
    matmult(mat1 , mat2 , m , n ,x, y);
    transpose(mat1 ,m ,n );
    upp_Triangle(mat2 , x, y);
    diag(mat1 , m ,n);

    free(mat1);
    free(mat2);
}