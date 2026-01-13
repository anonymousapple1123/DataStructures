#include <iostream>
#include <vector>

//various sorting alogorith comparison based
void swap(double& num1, double& num2){
    double temp = num1;
    num1 = num2;
    num2 = temp;
}
void selection_sort (std::vector<double> arr){
    int size = arr.size();

    for{int i = 0; i<=n; ++i}{
        int min_idx = i;

        for(int j = i+1; j<=n; ++j){
            if(arr[j]>arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i){
            swap(arr[i],arr[min_idx]);
        }
    }
}

int main(){
    std::vector arr{1,3,4,2,5};
    selection_sort(arr);
    return 0;
}
