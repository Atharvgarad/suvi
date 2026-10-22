#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#define SIZE 300
 
int main() {
    char text[SIZE], word[SIZE], small[SIZE];
    int choice, i, j, length, longest, count;
    char ch;
 
    printf("Enter a string: ");
    fgets(text, SIZE, stdin);
    text[strcspn(text, "\n")] = '\0';
 
    do {
        printf("\n1. Find longest word");
        printf("\n2. Count a character");
        printf("\n3. Reverse the string");
        printf("\n4. Check palindrome");
        printf("\n5. Search substring");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
 
        if (choice == 1) {
            length = 0;
            longest = 0;
            j = 0;
            for (i = 0; ; i++) {
                if (text[i] != ' ' && text[i] != '\0') {
                    length++;
                } else {
                    if (length > longest) longest = length;
                    length = 0;
                }
                if (text[i] == '\0') break;
            }
            printf("Length of longest word: %d\n", longest);
        }
        else if (choice == 2) {
            printf("Enter character: ");
            scanf(" %c", &ch);
            count = 0;
            for (i = 0; text[i] != '\0'; i++)
                if (text[i] == ch) count++;
            printf("Character occurs %d times.\n", count);
        }
        else if (choice == 3) {
            printf("Reversed string: ");
            for (i = (int)strlen(text) - 1; i >= 0; i--)
                printf("%c", text[i]);
            printf("\n");
        }
        else if (choice == 4) {
            i = 0;
            j = (int)strlen(text) - 1;
            while (i < j && text[i] == text[j]) {
                i++;
                j--;
            }
            if (i >= j) printf("String is a palindrome.\n");
            else printf("String is not a palindrome.\n");
        }
        else if (choice == 5) {
            printf("Enter substring (one word): ");
            scanf("%299s", small);
            if (strstr(text, small) != NULL)
                printf("Substring found.\n");
            else
                printf("Substring not found.\n");
        }
        else if (choice == 0) {
            printf("Program ended.\n");
        }
        else {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
 
    return 0;
}
