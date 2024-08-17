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