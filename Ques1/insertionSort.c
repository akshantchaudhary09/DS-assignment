/*This program sort the given integers using insertion sort*/

#include<stdio.h>
int main()
{
    //Deceleration of variables
    int arr[100],temp,num,j;
    printf("Enter the number of elements:");
    scanf("%d",&num);
    //Takes integers as inputs and stores them in arr
    for(int i=0;i<num;i++)
    {
        printf("\nEnter the element:");
        scanf("%d",&arr[i]);
    }
    //Insertion sort
    for(int i=1;i<num;i++)
    {
        temp=arr[i];
        for(j=i-1;j>=0 && arr[j]>temp;j--)
            arr[j+1]=arr[j];//Shift elements
        arr[j+1]=temp;
    }
    //Display output
    printf("\nElements in sorted order are:");
    for(int i=0;i<num;i++)
        printf("%d ",arr[i]);
}


