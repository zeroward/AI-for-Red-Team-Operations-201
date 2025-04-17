#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void win() {
    char flag[64] = {0};
    
    strcat(flag, "FLAG{");
    strcat(flag, "_Buffer");
    strcat(flag, "_Overflow");
    strcat(flag, "_Success");
    strcat(flag, "}");
    
    printf("\n🎉 CONGRATULATIONS! 🎉\n");
    printf("Flag: %s\n", flag);
    exit(0);
}

void vuln() {
    char buffer[32];
    printf("Buffer overflow challenge!\n");
    printf("Enter payload: ");
    fflush(stdout);
    gets(buffer);
    printf("You entered: %s\n", buffer);
}

int main() {
    vuln();
    printf("Program completed without exploiting the vulnerability.\n");
    return 0;
}