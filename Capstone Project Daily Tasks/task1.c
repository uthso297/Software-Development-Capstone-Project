/*
Problem: 
Write a program in C to read 12 numbers from the keyboard and find whether
the number is Negative or Positive and Find total Multiplication of all the
Negative and Positive numbers separately and check whether the outputs
are EVEN or ODD. If EVEN then print “Go back to the Left Side.”, otherwise
it will print “Go forward directly.”


*/

#include<stdio.h>

int input_numbers(){
    int a;
    printf("Enter your number: ");
    scanf("%d",&a);
    return a;
}

void check_sign(int a){
    if(a>=0){
        printf("The number is positive \n");
    }
    else{
        printf("The number is negative \n");
    }
}

int main(){
    int product_positive=1;
    int product_negative=1;

    for(int i=0;i<12;i++){
    int number = input_numbers();
    check_sign(number);
    if (number>=0){
        product_positive *=number;
    }
    if(number<0){
        product_negative*=number;
    }
    }
   printf("Multiplication of all the positive numbers %d \n", product_positive);
   if(product_positive%2==0){
       printf("Go back to the Left Side. \n");
   }
   else{
       printf("Go forward directly. \n");
   }
   printf("Multiplication of all the negative numbers %d \n", product_negative);
   if(product_negative%2==0){
       printf("Go back to the Left Side. \n");
   }
   else{
       printf("Go forward directly. \n");
   }

    return 0;
}
