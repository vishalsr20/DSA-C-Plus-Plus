#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int>&nums, int start, int end){
    int pivotIndex=start;
    int pivotElement=nums[start];

    int count=0;
    for(int i=start+1; i<=end; i++){
        if(nums[i] <= pivotElement){
            count++;
        }
    }

    cout<<"Count : "<<count<<endl;;
    int middleIndex=start+count;
    swap(nums[pivotIndex],nums[middleIndex]);

    pivotIndex = middleIndex;

    int i=start;
    int j =end;
    while(i < pivotIndex && j > pivotIndex){
        while(nums[i] <= pivotElement){
            i++;
        }

        while(nums[j] > pivotElement){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(nums[i],nums[j]);
        }
    }
    cout<<"End : "<<pivotIndex<<endl;;
    return pivotIndex;
}
void quickSort(vector<int>&nums, int start, int end){
    if(start >= end){
        return;
    }

    int pivotIndex = Partition(nums,start,end);

    cout<<"Pivot : "<<pivotIndex<<endl;
     quickSort(nums,start,pivotIndex-1);
     quickSort(nums,pivotIndex+1,end);

}

int main(){
    vector<int>arr{8,2,6,4,88,20,30};
    quickSort(arr,0,arr.size());

    for(int i=0; i<arr.size() ; i++){
        cout<<arr[i]<< " ";
    }
}