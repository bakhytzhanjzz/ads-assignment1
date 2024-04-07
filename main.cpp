#include <iostream>
#include <string>
using namespace std;

int findMinEl(int arr[], int n) {
    if (n==1) { //base case: if there's only one element it returns it
        return arr[0];
    }
    //recursive case: find minimum of first n-1 elements and compare with the nth element
    int tempMin = findMinEl(arr, n-1);
    return min(tempMin, arr[n-1]);
}

double findAverage(int arr[], int n, int index=0, double sum=0) {
    if (index==n){
        return sum/n; //base case: returns average after all elements are processed;
    }
    //recursive case: calculates the sum of elements and recursively compute it
    sum += arr[index];
    return findAverage(arr, n, index+1, sum);
}

bool isPrime(int n, int divisor = 2) {
    //3 base cases validating if number is prime
    if (n<=1) return false;
    if (divisor * divisor > n) return true;
    if (n % divisor == 0) return false;
    //recursive case: check next divisor
    return isPrime(n, divisor + 1);
}

int findFactorial(int n) {
    if (n == 1) return 1; //base case: 1! = 1
    return n*findFactorial(n-1); //recursive case: n! = n * (n-1)!
}

int findFibonacci(int n){
    if (n==0){ //base case: F(0) = 0
        return 0;
    } else if (n == 1){ //base case: F(1) = 1
        return 1;
    } else { //recursive case: F(n) = F(n-1) + F(n-2)
        return findFibonacci(n-1) + findFibonacci(n-2);
    }
}

int powerFunc(int a, int n){
    if (n == 0) { //base case: a^0 = 1
        return 1;
    } else { //recursive case: a^n = a*a^(n-1)
        return a * powerFunc(a, n - 1);
    }
}

void permutationsFunc(string& str, int start, int end){
    if (start == end){ //base case: prints out the permuted line when start and end meet
        cout << str << endl;
        return;
    }
    for (int i = start; i <= end; ++i) {
        swap(str[start], str[i]);//swap characters to generate permutations
        permutationsFunc(str, start+1, end);//recursively generate permutations
        swap(str[start], str[i]);//swap back to restore the original string
    }
}

bool isAllDigits(const string& str, int index){
    if (index == str.length()){ //base case: all characters are digits
        return true;
    }
    if (str[index] >= '0' && str[index] <= '9') { //recursive case: check next character
        return isAllDigits(str, index + 1);
    } else { //base case: false if the character is not a digit
        return false;
    }
}

int binomialCoefficientFunc(int n, int k){
    if (k == 0 || k == n) {
        return 1;
    } else {
        return binomialCoefficientFunc(n-1, k-1) + binomialCoefficientFunc(n-1, k);
    }
}

int gcdFunc(int a, int b){
    if (b == 0){//base case: C(n, 0) = C(n, n) = 1;
        return a;
    } else {//recursive case: C(n, k) = C(n-1, k-1) + C(n-1, k)
        return gcdFunc(b, a%b);
    }
}


//inputting all the values for the functions and calling them for corresponding task
void task1() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int minEl = findMinEl(arr, n);
    cout << minEl << endl;
}
void task2() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    double average = findAverage(arr, n);
    cout << average << endl;
}
void task3() {
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << "Prime" << endl;
    } else {
        cout << "Composite" << endl;
    }
}
void task4() {
    int n;
    cin >> n;
    cout << findFactorial(n);
}
void task5() {
    int n;
    cin >> n;
    cout << findFibonacci(n);
}
void task6() {
    int a, n;
    cin >> a >> n;
    cout << powerFunc(a, n);
}
void task7() {
    string inputString;
    cin >> inputString;
    permutationsFunc(inputString, 0, inputString.length() - 1);
}
void task8() {
    string inputString;
    cin >> inputString;
    if (isAllDigits(inputString, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
void task9() {
    int n, k;
    cin >> n >> k;
    cout << binomialCoefficientFunc(n, k);
}
void task10() {
    int a, b;
    cin >> a >> b;
    cout << gcdFunc(a, b);
}

//calling each task function by order
int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    return 0;
}