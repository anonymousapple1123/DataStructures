//#include <iostream>
#include <vector>

//various sorting alogorith comparison based
void swap(double& num1, double& num2){
    double temp = num1;
    num1 = num2;
    num2 = temp;
}
void selection_sort (std::vector<double> &arr){
    int n = arr.size();

    for(int i = 0; i<=n; ++i){
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

// int main(){
//     std::vector<double> arr{31,43,4,2,5,6,3,9,9,876,7,4,2,433,456,33,56};
//     selection_sort(arr);
//     for(auto i : arr){
//         std::cout<<"> "<<i<<std::endl;
//     }
//     return 0;
// }
