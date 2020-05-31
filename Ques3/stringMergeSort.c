/*Program to sort the given integers using merge sort*/

#include<stdio.h>
#define MAX 100//Size of array

void mergeSort(int arr[],int low,int up); //Function to merge two sorted arrays
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2); //Recursive function of merge sort
void copy(int arr[],int temp[],int low,int up);//This function copy elements to the original array

int main()
{
    int arr[MAX],num;//Variables deceleration
    printf("Enter the number of elements:");
    scanf("%d",&num);
    //Take integers as inputs and store them in arr
    for(int i=0;i<num;i++)
    {
        printf("\nEnter the element:");
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,num-1);//Invoking merge sort
    //Displaying output
    printf("\nElements in sorted order are:");
    for(int i=0;i<num;i++)
        printf("%d ",arr[i]);
}
void mergeSort(int arr[],int low,int up)
{
    int mid,temp[MAX];
    if(low==up)
        return;
    mid=(low+up)/2;//Stores the index of mid element of the array
    mergeSort(arr,low,mid);//Invoking merge sort for the left sublist
    mergeSort(arr,mid+1,up);//Invoking merge sort for the right sublist
    merge(arr,temp,low,mid,mid+1,up);//Invoking merge function to merge sorted left and sorted right sublist
    copy(arr,temp,low,up);//copy temp to the original array
}
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
    int i=low1;//i is initialized to starting index of left sublist
    int j=low2;//j is initialized to starting index of right sublist
    int k=low1;//k is initialized to starting index of temp
    while(i<=up1 && j<=up2)
    {
        //Element which is smaller between left and right sublist is inserted into temp
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=up1)//Inserting remaining elements of left sublist into temp
        temp[k++]=arr[i++];
    while(j<=up2)//Inserting remaining elements of right sublist into temp
        temp[k++]=arr[j++];
}
void copy(int arr[],int temp[],int low,int up)
{
    //copying elements of temp to arr
    for(int i=low;i<=up;i++)
        arr[i]=temp[i];
}
