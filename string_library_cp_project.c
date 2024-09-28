#include<stdio.h>

// Function declaration
void compare(char str1[], int n, char str2[], int m);
void reverse(char str1[], int n);
void count(char str1[], int n);
int length(char a[], int n);
void subset(char str1[], int n, char str2[], int m);
void interchange(char str1[], int n, char str2[], int m);
void copy(char str1[], int n, char str[], int m);
void ncopy(char str1[], int n, char str2[], int m);
void concat(char str1[], int n, char str2[], int m);
void nconcat(char str1[], int n, char str2[], int m);
void foccurance(char str1[], int n);
void loccurance(char str1[], int n);
void uppercase(char str1[]);
void lowercase(char str1[]);
void nuppercase(char str1[], int n);
void nlowercase(char str1[], int n);

int main() {
    int n = 100, m = 100, op = 1;
    char str1[n], str2[m];
    while (n) {
        // Display menu for the user to choose an operation
        printf("Enter the operation to perform \n\t'1' = compare (to compare two strings)\n\t'2' = reverse (to reverse characters of a given string)\n\t'3' = count (to count occurance of a given character)\n\t'4' = length (to get length of a given string)\n\t'5' = subset (to check whether a given string is subset of previous string)\n\t'6' = interchange (to interchange each characters of two strings one by one)\n\t'7' = copy (to copy a given string to a new string)\n\t'8' = ncopy (to coop a given range of a string to a new string)\n\t'9' = concat (to attach two string)\n\t'10' = nconcat (to attach a given range of second string to first string) \n\t'11' = foccurance (to find the first occurance of a given character)\n\t'12' = loccurance (to find the last occurance of a given character)\n\t'13' = convert whole string to upper case\n\t'14' = convert whole string to lower case\n\t'15' = convert a range of string to upper case\n\t'16' = convert a range string of to lower case\n\t'0' = Exit\n");

        printf("Please enter the operation: ");
        scanf("%d", &op);

        // Input the first string

        // For operations other than reverse, count, length, first occurrence, and last occurrence,
        // input the second string as well
        if (op > 0 && op < 17)
        {
            printf("Please enter first string : ");
            getchar();
            fgets(str1, 100, stdin);
        }
        if (op == 1 || op == 5 || op == 6 || op == 9 || op == 10) {
            printf("Please enter second string : ");
            fgets(str2, 100, stdin);
        }
        switch (op) {
        case 1: compare(str1, n, str2, m);
            break;
        case 2: reverse(str1, n);
            break;
        case 3: count(str1, n);
            break;
        case 4: printf("Length is %d", length(str1, n));
            break;
        case 5: subset(str1, n, str2, m);
            break;
        case 6: interchange(str1, n, str2, m);
            break;
        case 7: copy(str1, n, str2, m);
            break;
        case 8: ncopy(str1, n, str2, m);
            break;
        case 9: concat(str1, n, str2, m);
            break;
        case 10: nconcat(str1, n, str2, m);
            break;
        case 11: foccurance(str1, n);
            break;
        case 12: loccurance(str1, n);
            break;
        case 13: uppercase(str1);
            break;
        case 14: lowercase(str1);
            break;
        case 15: nuppercase(str1, n);
            break;
        case 16: nlowercase(str1, n);
            break;
        case 0: {
            printf("THANK YOU");
            return 0;
        }
        default: printf("\nThe operation isn't available\n");
        }
        printf("\n");
    }

}

// Function to compare two strings
void compare(char str1[], int n, char str2[], int m) {
    int i;
    //loop to check both the string character at a particular index
    for (i = 0;str1[i] != '\n'; i++) {
        if (str1[i] != str2[i]) {
            break;
        }
    }
    //if-else statements are to print the result by comparing length of string 2 with i 
    if (length(str1, n) == length(str2, n) && length(str2, n) == i) {
        printf("\nBoth strings are equal\n");
    }
    else {
        printf("\nBoth strings are unequal\n");
    }
}

// Function to reverse a string
void reverse(char str1[], int n) {
    //loop for swaping each character of the string of 'n'th index to '(length of string - n -1)'th index
    for (int i = 0; i < length(str1, n) / 2; i++) {
        int c = str1[i];
        str1[i] = str1[length(str1, n) - i - 1];
        str1[length(str1, n) - i - 1] = c;
    }
    printf("\nReverse is: %s\n", str1);
}

// Function to count occurrences of a character in a string
void count(char str1[], int n) {
    printf("Enter 1 if you want to count spaces else input any character: ");
    char c, a;
    scanf(" %c", &a);
    //initialize 'c' to 'space' if input is '1'
    if (a == '1')
        c = ' ';
    //initialize 'c' to input character other than space
    else
        c = a;
    int count = 0;
    //loop to compare each character of string with 'c' and increment count (count is total number of occurance of input character)
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == c) {
            count++;
        }
    }
    //print result
    if (a == '1')
        printf("\nThere are %d occurrences of spaces\n", count);
    else
        printf("\nThere are %d occurrences of %c\n", count, a);
}

// Function to calculate the length of a string
int length(char a[], int n) {
    int count = 0;
    //loop to increse count until rhe string ends
    for (int i = 0; a[i] != '\n'; i++) {
        count++;
    }
    return count;
}

// Function to check if one string is a subset of another
void subset(char str1[], int n, char str2[], int m) {
    int counts = 0, a = 0, ans = 0;
    //if length of string 2 is greater than length of string 1, than string 2 is not a subset of string 1
    if (length(str2, m) > length(str1, n)) {
        printf("\nSecond string is not a subset of the first string\n");
        return;
    }
    //if length of string 2 is less than or equal to length of string 1
    else {
        //loop to compare each character one by one of string 1
        for (int i = 0;i < length(str1, n);i++)
        {
            //if character of index i of string 1 is equal to first character of string 2 
            if (str1[i] == str2[0]) {
                /*
                loop to compare each character of string 2 one by one with string 1 (from index i+1 one by one),
                if character of index i of string 1 is equal to first character of string 2
                */
                for (int j = 1;j < length(str2, m);j++) {
                    if (str1[i + j] == str2[ans + 1]) {
                        ans++;
                    }
                    else
                        break;
                }
            }
        }
        //print result
        if (ans == length(str2, m) - 1)
            printf("\nSecond string is a subset of the first string\n");

        else if (ans != length(str2, m) - 1)
            printf("\nSecond string is not a subset of the first string\n");
    }
}

// Function to interchange characters of two strings
void interchange(char str1[], int n, char str2[], int m) {
    int a;
    //initialize a with length of larger string
    if (length(str1, n) >= length(str2, m)) {
        a = length(str1, n);
    }
    else {
        a = length(str2, m);
    }
    //loop to swap each character of string 1 with string 2 one by one
    for (int i = 0; i < a; i++) {
        //initialize variable temp with 'i'th index of string 1 one by one
        char temp = str1[i];
        //initialize 'i'th index of string 1 with 'i'th index of string 2 one by one
        str1[i] = str2[i];
        //initialize 'i'th index of string 2 with variable temp one by one
        str2[i] = temp;
    }
    //print result
    printf("\nNew first string : %s\n", str1);
    printf("\nNew second string : %s\n", str2);
}

// Function to copy characters from one string to another
void copy(char str1[], int n, char str[], int m) {
    int i;
    //loop to copy each character of input string to another string one by one
    for (i = 0; i <= m - 1; i++) {
        str[i] = str1[i];
    }
    //allot last memory to null character
    str[i + 1] = '\0';
    //print the new string
    // printf("\nString 1: %s\n", str);
}

// Function to reduce the second string based on user input
void ncopy(char str1[], int n, char str2[], int m) {
    int a, b, i, k;
    //input range of character you want to copy
    printf("From : ");
    scanf("%d", &a);
    printf("To : ");
    scanf("%d", &b);
    //check range to be valid
    if (b < a) {
        printf("\nWrong input\n");
        return;
    }
    //if 'b' is greater than length of given string tha initialize it to length of string
    if (b > length(str1, n)) {
        b = length(str1, n);
    }
    //loop to copy each character of input string (for given range of character) to another string one by one
    for (i = a - 1, k = 0; i <= b - 1; i++, k++) {
        str2[k] = str1[i];
    }
    //allot last memory to null character
    str2[k] = '\0';
    //print the new string
    printf("\nString 1: %s\n", str2);
}

// Function to concatenate two strings
void concat(char str1[], int n, char str2[], int m) {
    char str3[m + n];
    int i;
    //initialize string 3 with string 1
    for (int i = 0; i < length(str1, n); i++) {
        str3[i] = str1[i];
    }
    //initialize string 3 with string 2
    for (i = 0; i < length(str2, m); i++) {
        str3[i + length(str1, n)] = str2[i];
    }
    //allot last memory to null character
    str3[i + length(str1, n)] = '\0';
    //print the new string
    copy(str3, n + m, str1, n);
    printf("\nString 1: %s\n", str1);
}

// Function to concatenate string 1 with some elements of string 2 
void nconcat(char str1[], int n, char str2[], int m) {
    int a, b, i, k;
    //input range of character of string 2 you want to initialize to string 3
    printf("From : ");
    scanf("%d", &a);
    printf("To : ");
    scanf("%d", &b);
    char str3[b - a + n];
    //check range to be valid
    if (b < a) {
        printf("\nWrong input\n");
        return;
    }
    //if 'b' is greater than length of given string tha initialize it to length of string
    if (b > length(str1, n)) {
        b = length(str1, n);
    }
    //initialize string 3 with string 1
    for (i = 0; i < length(str1, n); i++) {
        str3[i] = str1[i];
    }
    //initialize string 3 with string 2(for given range)
    for (i = a - 1, k = 0; i < b; i++, k++) {
        str3[length(str1, n) + k] = str2[i];
    }
    //allot last memory to null character
    str3[length(str1, n) + k] = '\0';
    //print the new string
    copy(str3, n + m, str1, n);
}

// Function to find the first occurrence of a character in a string
void foccurance(char str1[], int n) {
    char a;
    int i;
    printf("Enter 1 if you want to get the first occurance of space else enter the character : ");
    scanf(" %c", &a);
    char c;
    //initialize 'c' to 'space' if input is '1'
    if (a == '1')
        c = ' ';
    //initialize 'c' to input character other than space
    else
        c = a;
    //loop to compare each character of string with c (from index 'o' to last index) one by one until 'c' is equal to character of index 'i' of string
    for (i = 0; i < length(str1, n); i++) {
        if (c == str1[i]) {
            printf("\nFirst occurrence is at: %d\n", i + 1);
            return;
        }
    }
    //print result
    printf("\nThe string doesn't contain '%c'\n", c);
}

// Function to find the last occurrence of a character in a string
void loccurance(char str1[], int n) {
    char a, c;
    int i;

    printf("Enter 1 if you want to get the last occurance of space else enter the character : ");
    scanf(" %c", &a);
    //initialize 'c' to 'space' if input is '1'
    if (a == '1')
        c = ' ';
    //initialize 'c' to input character other than space
    else
        c = a;
    //loop to compare each character of string with c (from last index to index '0') one by one until 'c' is equal to character of index 'i' of string
    for (i = length(str1, n) - 1; i >= 0; i--) {
        if (c == str1[i]) {
            printf("\nFirst occurrence is at: %d\n", i + 1);
            return;
        }
    }
    //print result
    printf("\nThe string doesn't contain '%c'\n", c);
}

// Function to convert all elements of string to uppercase
void uppercase(char str1[])
{
    //Check every charater and if its in lower case it covert that character to upper case
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] = str1[i] - 32;
        }
    }
    printf("\nUpper case string is: %s\n", str1);
}

// Function to convert all elements of string to lowercase
void lowercase(char str1[])
{
    //Check every charater and if its in upper case it covert that character to lowercase
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = str1[i] + 32;
        }
    }
    printf("\nlower case string is: %s\n", str1);
}

// Function to convert some elements of string to uppercase
void nuppercase(char str1[], int n)
{
    int a, b;
    printf("Note: From : ");
    scanf("%d", &a);
    printf("To : ");
    scanf("%d", &b);
    //check range to be valid
    if (b < a) {
        printf("\nWrong input\n");
        return;
    }
    //if 'b' is greater than length of given string tha initialize it to length of string
    if (b > length(str1, n)) {
        b = length(str1, n);
    }
    //Check every charater and if its in lower case it covert that character to upper case
    for (int i = a - 1; i < b; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] = str1[i] - 32;
        }
    }
    printf("\nUpper case string is: %s\n", str1);
}

// Function to convert some elements of string to lowercase
void nlowercase(char str1[], int n)
{
    int a, b;
    printf("From : ");
    scanf("%d", &a);
    printf("To : ");
    scanf("%d", &b);
    //check range to be valid
    if (b < a) {
        printf("\nWrong input\n");
        return;
    }
    //if 'b' is greater than length of given string tha initialize it to length of string
    if (b > length(str1, n)) {
        b = length(str1, n);
    }
    //Check every charater and if its in upper case it covert that character to lowercase
    for (int i = a - 1; i < b; i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = str1[i] + 32;
        }
    }
    printf("\nlower case string is: %s\n", str1);
}