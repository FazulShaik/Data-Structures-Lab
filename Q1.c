#include<stdio.h>
int binarySearch(int arr[],int size,int n);
int main(){
    int n;
    printf("Enter size of the array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements into the array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int size;
    printf("Enter element to be search");
    scanf("%d",&size);
    int b=binarySearch(arr,size,n);
    if(b==-1){
        printf("%d is not found",size);
    }
    else{
        printf("%d is found at %d index",size,b);
    }
    return 0;
}
int binarySearch(int arr[],int size,int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==size){
            return mid;
        }
        else if(arr[mid]>size){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}