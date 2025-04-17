#include <stdio.h>
#include <string.h>

int main() {
    char input[64];
    char password[] = "FLAG{StringsFindsThisEasily}";

    printf("Simple Challenge v1\n");
    printf("Enter Password: ");
    fflush(stdout);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Input error.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, password) == 0) {
        printf("You found the flag!\n");
        fflush(stdout);
    } else {
        printf("Access Denied.\n");
        fflush(stdout);
    }

    return 0;
}
