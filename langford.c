#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Ceiling function that rounds up given numerator and denominator
int ceiling (int numerator, int denom){
    if (denom == 0){
        fprintf(stderr, "Error: Division by zero\n");
        return -1; 
    }
    return (numerator + denom - 1) / denom;
}
// Helper function for populating an array with even numbers between two indexes
void* fill_with_evens(int* array, int start, int end){
    int index = 0;
    for (int i = start; i <= end; i+= 2){
        array[index] = i;
        index +=1;
    }
    return array;
}

//help function that populates an array with odds numbers between two indexes
void* fill_with_odds(int* array, int start, int end){
    int index = 0;
    for (int i = start; i <= end; i +=2){
        array[index] = i;
        index += 1;
    }
    return array;
}

// reverses the inputted array and returns a new array
int* reverse_array(int* array, int size){
    int* reverse_array = malloc(size*sizeof(int));
    if(!reverse_array){
        fprintf(stderr, "Memory allocation for reversed array failed");
        exit(1);
    }
    for (int i = 0; i < size; i++){
        reverse_array[i] = array[size - 1 - i];
    }
    return reverse_array;
}

// Helper function that prints out the contents of inputted array in a list
// e.g print_list([1,2,3], 3)
// [1, 2, 3]
void print_list(int* array, int size){
    // printf("Your Sequence: [");
    printf("[");
    for (int j = 0; j< size; j++){
        printf("%d", array[j]);
        if (j < size - 1) {
            printf(", "); // Print a comma and space if this is not the last element
        }
    }
    printf("]\n");
}
// checkmode; checks whether integer array is a valid langford pairing
bool is_langford_pairing(int size, const int int_array[] ){
    if (size <= 2){
        return false;
    }
    bool visited[size];
    for (int j=0; j < size; j++){
        visited[j] = false;
    }

    for (int i=0; i<size; i++){
        int n = int_array[i];
        if (visited[n]) {
            continue;
        }
        // check to make sure n is valid; it cannot be smaller than 1, and 
        // the max distance between two numbers cannot exceed size/2 to fit in array
        if (n < 1 || n > size / 2){
            return false;
        }
        // check whether the current index is within bounds of the array,
        // and its paired value at the i+n+1 index matches n, the current value  
        int paired_index = i + n + 1;
        if (paired_index >= size || int_array[paired_index] != n){
            return false;
        }
        visited[n] = true;    
    }
    // Check if all numbers at all indexes were visited once; if not, index
    // was not reached is not valid
    for (int i = 1; i <= size / 2; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

// // creates a langford pairing given the input n 
bool create_langford_pairing(int n){
    // Checks whether size is valid; must have remainder 0 or 1 when divided by 4 to be valid
    if (n % 4 != 0 && n % 4 != 3){
        printf("No Results found.\n");
        return false;
    }
    // initiate parameters; algorithm based off of supplemental video
        int x =  ceiling(n, 4); int a = 2*x-1; int b = 4*x-2; int c = 4*x-1; int d = 4*x;
        // a is odd, there are a-1/2 odd numbers
        int p_size = (a - 1) / 2; // Number of odds from 1 to a-1
        // int q_size = (a - 2) / 2; // Number of evens from 2 to a-1
        int q_size = ceiling((a-2), 2);
        int r_size = ceiling((b-1)-(a+2)+1, 2);
        // int r_size = ((b - 1) - (a + 2) + 1) / 2; // Number of odds from a+2 to b-1
        int s_size = ceiling((b-1)-(a+1)+1, 2);
        // int s_size = ((b - 1) - (a + 1) + 1) / 2; // Number of evens from a+1 to b-1
        //initialize arrays for each variable
        int*p_array = malloc(p_size*sizeof(int));
        if (!p_array) {
            perror("Memory allocation failed at p_array");
            exit(EXIT_FAILURE);
        }
        int*q_array = malloc(q_size*sizeof(int));
        if (!q_array) {
            perror("Memory allocation failed_q_array");
            exit(EXIT_FAILURE);
        }
        int*r_array = malloc(r_size*sizeof(int));
        if (!r_array) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        int*s_array = malloc(s_size*sizeof(int));
        if (!s_array) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        //populate the arrays;
        // p array
        fill_with_odds(p_array, 1, a-1);
        // r array
        fill_with_odds(r_array, a+2, b-1);
        // q array
        fill_with_evens(q_array, 2, a-1);
        // s array
        fill_with_evens(s_array, a+1, b-1);
        // Reverese S array
        int*reveresed_s = reverse_array(s_array, s_size);
        int *reveresed_p = reverse_array(p_array, p_size);
        int *reveresed_q = reverse_array(q_array, q_size);
        int *reveresed_r = reverse_array(r_array, r_size);
    int lang_array[n*2]; //generate array of length 2n
    if (n % 4 == 0){
        // populate langford array: reveresed_s + reveresed_p + b + p + c + s + d + R[r] + R[q] + c + r + a +d
        int i = 0;
        for (int j = 0; j < s_size; j++){ // populate with Reverse S array
            lang_array[i] = reveresed_s[j];
            i++;
        }
        for (int p = 0; p < p_size; p++){ //populate with reverse p array
            lang_array[i] = reveresed_p[p];
            i++;
        }
        lang_array[i] = b;
        i++;
        for (int p =0; p < p_size; p ++){ // populate with p array
            lang_array[i] = p_array[p];
            i++;
        }
        lang_array[i] = c;
        i++;
        for (int s = 0; s< s_size; s++){
            lang_array[i] = s_array[s];
            i++;
        }
        lang_array[i] = d;
        i++;
        for (int r = 0; r < r_size; r++){
            lang_array[i] = reveresed_r[r];
            i++;
        }       
        for(int q  = 0; q < q_size; q++){
            lang_array[i] = reveresed_q[q];
            i++;
        }
        lang_array[i] = b;
        i++;
        lang_array[i] = a;
        i++;
        for(int q  = 0; q < q_size; q++){
            lang_array[i] = q_array[q];
            i++;
        }    
        lang_array[i] = c;
        i++;
        for(int r = 0; r < r_size; r++){
            lang_array[i] = r_array[r];
            i++;
        }           
        lang_array[i] = a;
        i++;
        lang_array[i] = d;
        free(reveresed_s); 
        free(reveresed_p); 
        free(reveresed_r); 
        free(reveresed_q);
        free(p_array); 
        free(s_array); 
        free(q_array); 
        free(r_array);
        print_list(lang_array, n*2);
        return true;
        }
    else if(n % 4 == 3){
        int i = 0;
        for (int j = 0; j < s_size; j++){ // populate with Reverse S array
            lang_array[i] = reveresed_s[j];
            i++;
        }
        for (int p = 0; p < p_size; p++){ //populate with reverse p array
            lang_array[i] = reveresed_p[p];
            i++;
        }
        lang_array[i] = b;
        i++;
        for (int p =0; p < p_size; p ++){ // populate with p array
            lang_array[i] = p_array[p];
            i++;
        }
        lang_array[i] = c;
        i++;
        for (int s = 0; s< s_size; s++){
            lang_array[i] = s_array[s];
            i++;
        }
        lang_array[i] = a;
        i++;
        for (int r = 0; r < r_size; r++){
            lang_array[i] = reveresed_r[r];
            i++;
        }  
        for(int q  = 0; q < q_size; q++){
            lang_array[i] = reveresed_q[q];
            i++;
        }
        lang_array[i] = b;
        i++;
        lang_array[i] = a;
        i++;
        for(int q  = 0; q < q_size; q++){
            lang_array[i] = q_array[q];
            i++;
        } 
        lang_array[i] = c;
        i++;
        for(int r = 0; r < r_size; r++){
            lang_array[i] = r_array[r];
            i++;
        } 
        free(reveresed_s); 
        free(reveresed_p); 
        free(reveresed_r); 
        free(reveresed_q);
        free(p_array); 
        free(s_array); 
        free(q_array); 
        free(r_array);
        print_list(lang_array, n*2);
        return true;
    }
    return false;
}

// Create a parser to get rid of the directory and only keep the ./ or ././?
int main(int argc, char **argv) {
    // checks whether the first input is "-h", or if no arguments were supplied 
    if (argc == 1 || (argc> 1 && strcmp(argv[1], "-h") == 0 )){
        // "usage: ./langford [-h] -c n | num..."
        fprintf(stderr, "usage: %s [-h] -c n | num...\n", argv[0]);
        exit(0);
    }
    // input after executable is "-c"
    if (argc >= 2 && strcmp(argv[1], "-c") == 0){
        // no arguments after -c
        if (argc == 2) {
            fprintf(stderr, "%s: -c option requires an argument.\n", argv[0]);
            exit(1);
        }
        // Too many arguments after -c; additional argument after argv[2]
        if (argc > 3){
            fprintf(stderr, "%s: -c option received too many arguments.\n", argv[0]);
            exit(1);
        }
        // argument after -c is not an integer after being converted
        char *end_ptr;
        long value = strtol(argv[2], &end_ptr, 10);
        // no conversion took place; is not an integer as the string is the same as the original argument input
        if (*end_ptr != '\0') {
            fprintf(stderr, "error: %s is not an integer\n", argv[2]);
            exit(1);
        }
        // conversion was successful; is a valid integer
        else {
            printf("Creating a langford pairing with n=%ld\n", value);
            return create_langford_pairing(value);
        }
    }
    // neither -h and -c are the first argument; check each argument is an integer
    int *int_array = malloc((argc -1 )*sizeof(int));  //declare dynamic array not containing the first argument(./langford); making sure allocation is successful
    if (int_array == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    // checks that all arguments are valid; all integers
    for (int i=1; i< argc; i++){
        char *end_ptr;
        long value = strtol(argv[i], &end_ptr, 10);

        if (*end_ptr != '\0'){ //e.g ./langford 1 2x 3, error: 2x is not an integer
            fprintf(stderr, "error: %s is not an integer", argv[i]);
            exit(1);
        }
        int_array[i-1] = (int)value;
    }
    // storage of arguments were successful; print out the sequence
    printf("Your sequence: ");
    print_list(int_array, argc-1);
    // checks whether inputted array is a valid langford pairing
    if(is_langford_pairing(argc-1, int_array)){
        printf("It is a langford pairing!\n");
        free(int_array);
        exit(0);
    }
    printf("It is NOT a langford pairing.\n");
    free(int_array);
    exit(0);
}

