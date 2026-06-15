/*
link: https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&count=25&page=1&search=&sort_entity=order&sort_order=ASC

Allocate Books
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1.

we can run a loop for value of max_allocation_to_a_student from max_element(arr) to sumOfAllElements(arr)
in which for first instance where all the books are allocated to m students, we get our ans
we can optimize the for loop by using binary search
*/


bool isPossible(vector<int>& arr, int n, int m, int max_value){
    int pages = 0;
    int noOfStudent = 1;
    for(int i=0;i<n;i++){
        if((pages + arr[i])<= max_value){
            pages+=arr[i];
        }
        else{
            noOfStudent++;
            pages = arr[i];
        }
    }
    if(noOfStudent<=m)  return true;
    return false;
}

int findPages(vector<int>& arr, int n, int m) {
    if(n<m) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = 0;
    for(int i=0;i<n;i++) high += arr[i];
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(arr,n, m, mid)){
            high = mid-1;
            ans = min(ans, mid);
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}