// Stack based Challenges
// * Create an Array that can hold complex numbers
// 	* Write function to push a complex number to stack
// 	* Write function to pop a complex number from stack

#include<stdio.h>
#include<stdlib.h>

struct complex_num{
    int real;
    int img;
};
typedef struct complex_num complex_num;

void show_choices()
{
    printf("Choose the below choices!\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. terminate\n");
}

int check_choice(int c)
{
    if(c>=1 && c<=3)
        return 1;
    printf("\nPlease enter correct choices\n");
    return 0;
}

int isEmpty(int n, int top)
{
    if(top==-1)
        return 1;
    return 0;
}

int isFull(int n, int top)
{
    if(top==n-1)
        return 1;
    return 0;
}

void push(complex_num *stack, int n, int *top)
{
    if(!isFull(n, *top))
    {
        *top+=1;
        printf("Enter the real number : ");
        scanf("%d",&(stack+(*top))->real);
        printf("Enter the imaginary number : ");
        scanf("%d",&(stack+(*top))->img);
    }  
    else
    {
        printf("Stack is overflow\n");
    }
}

void pop(complex_num *stack, int n, int *top)
{
    if(!isEmpty(n, *top))
    {
        (stack+(*top))->real = 0;
        (stack+(*top))->img = 0;
        *top-=1;
    }
    else{
        printf("Stack is underflow\n");
    }
}

int main()
{
    int n;
    printf("Enter size of the stack : ");
    scanf("%d",&n);
    complex_num stack[n];
    int top = -1;
    while(1)
    {
        int choice;
        show_choices();
        scanf("%d",&choice);
        if(!check_choice(choice))
            continue;
        else{
            switch(choice)
            {
                case 1: push(stack, n, &top);
                    break;
                case 2: pop(stack, n, &top);
                    break;
                default: goto terminate;
            }
        }
        terminate : if(choice == 3) break;
    }
    // printf("real: %d\nimaginary: %d",stack[top].real,stack[top].img);
    return 0;
}