#include<iostream>
using namespace std;
void merge(int arr[], int lb, int mid, int ub) {
    int temp[100];
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while(i <= mid && j <= ub) {
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    for(int i=lb;i<=ub;i++){
        arr[i]=temp[i];
    }
}

void mergesort(int arr[], int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main(){
    int arr[100],lb,ub;
    cout<<"enter value of lower bound"<<endl;
    cin>>lb; 
    cout<<"enter value of upper bound"<<endl;
    cin>>ub;
    cout<<"enter elements"<<endl;
    for(int i=lb;i<ub;i++){
        cin>>arr[i];
    }
    cout<<"displaying array"<<endl;
    for(int i=lb;i<ub;i++){
        cout<<arr[i]<<" ";
    }
    mergesort(arr, lb, ub-1);
    cout<<"\n after sorting \n";
    for(int i=lb;i<ub;i++){
        cout<<arr[i]<<" ";
    }
}
