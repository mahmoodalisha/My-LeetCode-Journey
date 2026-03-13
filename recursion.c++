int factorial(n){
    if(n<=1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

//fibonacci series
int fibonacci(n){
    if(n<=1){
        return 1;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

//Recursive Linear Search
int search(vector<int> arr; int n; int i; int target){
    if(i == n){
        return -1;
    }
    if(arr[i] == target){
        return i;
    }
}


int binarysearch(vector<int> arr, int left, int right, int target){
    while(left<right){
        int mid = (left+right)/2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid]<target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1
}

void bubblesort(vector<int> arr, int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }
}