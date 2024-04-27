#include "hash.hpp"
#include "array_list.hpp"

/*
https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/
*/
bool isSubset(int arr1[], int m, int arr2[] , int n ) {
    map<int,int> mapper;

    for(int i=0;i<m;i++) {
        mapper[arr1[i]]+=1;
    }

    for(int i=0;i<n;i++) {
        if (mapper.find(arr2[i]) == mapper.end())
            return false;
    }
    return true;
}

void array_subset_driver () {
    int arr1[] = {11 , 1 , 13 , 21 , 3 , 7};
    int arr2[] = {11 , 3 , 2 , 1};

    bool ret = isSubset(arr1,6,arr2,4);
    cout <<"Is subset " << ret << endl;

}

/*
https://www.geeksforgeeks.org/maximum-distance-two-occurrences-element-array/
*/

int max_distance (int arr[], int sz ) {
    unordered_map <int,int> mp;
    int max_distance = 0;
    for(int i =0; i < sz;i++) {
        if (mp.find(arr[i]) == mp.end()) {
            mp[arr[i]]=i;
        } else {
            if( max_distance < i-mp[arr[i]]) {
            max_distance =  i-mp[arr[i]];
            }
        }
    }
    return max_distance;
}


void array_max_distance_driver() {
    int arr [] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int sz = *(&arr+1) -arr;
    cout << "max Distance " <<max_distance(arr,sz) << endl;
}

/*
https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
*/

int longest_zero_sum(array_list al){
    int *arr= al.get_array();
    int sz = al.get_size();
    unordered_map<int,int> mp;
    int max_distance =0;
    int sum=0;
    for(int i=0;i<sz;i++) {
        sum+=arr[i];
        //cout << "Sum " <<sum << endl;
        if (mp.find(sum) == mp.end()) {
            mp[sum]=i;
        } else {
            if (i-mp[sum] > max_distance) {
                max_distance = i-mp[sum];
            }
        }
    }
    return max_distance;
}

void array_longest_zero_sum_driver() {
    int arr [] = {15, -2, 2, -8, 1, 7, 10, 23 };
    int sz = *(&arr+1) -arr;
    array_list al(arr,sz);
    
    cout << "max Distance " << longest_zero_sum(al) << endl;
}

/*
https://www.geeksforgeeks.org/check-if-two-arrays-are-equal-or-not/
*/

bool check_2_array_identical(array_list a1, array_list a2) {
    unordered_map<int,int> mp;

    for(int i=0;i<a1.get_size();i++){
        mp[a1.get_value_at_index(i)]+=1;
    }

    for(int i=0;i < a2.get_size();i++) {
        if (mp.find(a2.get_value_at_index(i)) == mp.end())
            return false;
        if (mp[a2.get_value_at_index(i)] ==0)
            return false;
        mp[a2.get_value_at_index(i)]-=1;
    }
    return true;
}

void check_2_array_identical_driver() {
    int arr1 [] = {1, 2, 5, 4, 0};
    int sz1 = *(&arr1+1) -arr1;
    int arr2 [] = {2, 4, 5, 0, 1};
    int sz2 = *(&arr2+1) -arr2;
    array_list a1(arr1,sz1);
    array_list a2(arr2,sz2);
    cout << "identical " << check_2_array_identical(a1,a2)<< endl;
}






void unique_element_in_sliding_window_driver() {
    int arr [] = {1, 2, 1, 3, 4, 2, 3};
    int window =4;
    int sz = *(&arr+1) -arr;
    array_list al(arr,sz);
    

}