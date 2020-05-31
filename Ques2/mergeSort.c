/*This program sort the given string using merge sort*/

#include<stdio.h>
#include<string.h>
#define MAX 100//Size of array

void mergeSort(char str[],int low,int up); //This function merge two sorted arrays
void merge(char str[],char temp[],int low1,int up1,int low2,int up2); //This is a recursive function of merge sort
void copy(char str[],char temp[],int low,int up);//This function Copy elements to the original string

int main()
{
    char str[MAX],len;//Deceleration of variables
    //Taking string as input using gets function
    printf("Enter the string:");
    gets(str);
    len=strlen(str);//Length of input string
    mergeSort(str,0,len-1);//invoking merge sort
    //Displaying output
    printf("\nString in sorted order is:");
    for(int i=0;i<len;i++)
        printf("%c",str[i]);
}

void mergeSort(char str[],int low,int up)
{
    int mid;
    char temp[MAX];
    if(low==up)
        return;
    mid=(low+up)/2;//stores the index of mid element of the string
    mergeSort(str,low,mid);//Invoking merge sort for left sublist
    mergeSort(str,mid+1,up);//Invoking merge sort for right sublist
    merge(str,temp,low,mid,mid+1,up);//Invoking merge function to merge left and right sublist
    copy(str,temp,low,up);//Copy temp to original string
}
void merge(char str[],char temp[],int low1,int up1,int low2,int up2)
{
    int i=low1;//i is initialized to starting index of left sublist
    int j=low2;//j is initialized to starting index of right sublist
    int k=low1;//k is initialized to starting index of temp
    while(i<=up1 && j<=up2)
    {
        //Element which is smaller between left and right sublist is inserted into temp
        if(str[i]<=str[j])
            temp[k++]=str[i++];
        else
            temp[k++]=str[j++];
    }
    while(i<=up1)//Inserting remaining elements of left sublist into temp
        temp[k++]=str[i++];
    while(j<=up2)//Inserting remaining elements of right sublist into temp
        temp[k++]=str[j++];
}
void copy(char str[],char temp[],int low,int up)
{
    //copying elements of temp to str
    for(int i=low;i<=up;i++)
        str[i]=temp[i];
}

