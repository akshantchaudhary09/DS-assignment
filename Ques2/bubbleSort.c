/*This program sort the given integers using bubble sort*/

#include<stdio.h>
int main()
{
    //Deceleration of variables
    int arr[100],temp,num;
    printf("Enter the number of elements:");
    scanf("%d",&num);
    //Takes integers as inputs and stores them in arr
    for(int i=0;i<num;i++)    {
        printf("\nEnter the element:");
        scanf("%d",&arr[i]);
    }
    //Bubble sort
    for(int i=num-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                //Swap arr[j] and arr[j+1] using temp
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    //Display the output
    printf("\nElements in sorted order are:");
    for(int i=0;i<num;i++)
        printf("%d ",arr[i]);
}

