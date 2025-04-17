#include <stdio.h>
#include <string.h>

void rot13_decode(const char *input, char *output) {
    for (int i = 0; input[i]; i++) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') output[i] = 'A' + ((c - 'A' + 13) % 26);
        else if (c >= 'a' && c <= 'z') output[i] = 'a' + ((c - 'a' + 13) % 26);
        else output[i] = c; // Keep non-alphabetic
    }
}

int main() {
    char input[64];
    // ROT13-encoded password ("FrmYI6luBP" -> "SezLV6yhOC")
    char rot13_password[] = "SezLV6yhOC";
    char real_password[64] = {0}; 

    // ROT13-encoded flag ("FLAG{Rot13IsNotASafeEncryptionAlgorithm}" -> "SYNT{Ebg13VfAbgNFnsrRapelcgvbaNytbevguz}")
    char rot13_flag[] = "SYNT{Ebg13VfAbgNFnsrRapelcgvbaNytbevguz}";
    char real_flag[64] = {0};

    printf("=== Super Trivial Flag Printer ===\n");
    printf("Enter Password (hint: ROT13 'cnffjbeq123'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    rot13_decode(rot13_password, real_password);
    rot13_decode(rot13_flag, real_flag);

    if (strcmp(input, real_password) == 0) {
        printf("\nACCESS GRANTED. HERE'S YOUR FLAG:\n");
        printf("%s\n", real_flag);
    } else {
        printf("\nACCESS DENIED. TRY HARDER.\n");
    }

    return 0;
}