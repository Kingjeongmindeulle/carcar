#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void recommendMenu(char *cuisine) {
    const char *koreanMenus[] = {"Kimchi", "Bibimbap", "Bulgogi"};
    const char *chineseMenus[] = {"Sweet and Sour Pork", "Kung Pao Chicken", "Mapo Tofu"};
    const char *japaneseMenus[] = {"Sushi", "Ramen", "Tempura"};
    int menuIndex;

    srand(time(NULL));

    if (strcmp(cuisine, "Korean") == 0) {
        menuIndex = rand() % 3;
        printf("Recommended Korean menu: %s\n", koreanMenus[menuIndex]);
    } else if (strcmp(cuisine, "Chinese") == 0) {
        menuIndex = rand() % 3;
        printf("Recommended Chinese menu: %s\n", chineseMenus[menuIndex]);
    } else if (strcmp(cuisine, "Japanese") == 0) {
        menuIndex = rand() % 3;
        printf("Recommended Japanese menu: %s\n", japaneseMenus[menuIndex]);
    } else {
        printf("Invalid cuisine type.\n");
    }
}

int main() {
    char cuisine[20];
    char input[20];
    int retry = 1;

    while (1) {
        printf("Choose a cuisine (Korean, Chinese, Japanese): ");
        scanf("%s", cuisine);

        while (retry) {
            recommendMenu(cuisine);
            printf("Enter 'Retry' to get another recommendation, 'Reset' to choose another cuisine, or 'Exit' to quit: ");
            scanf("%s", input);

            if (strcmp(input, "Retry") == 0) {
                continue;
            } else if (strcmp(input, "Reset") == 0) {
                break;
            } else if (strcmp(input, "Exit") == 0) {
                return 0;
            } else {
                printf("Invalid input. Please try again.\n");
            }
        }
    }

    return 0;
}