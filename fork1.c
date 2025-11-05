#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before fork\n");

    fork();  // ایجاد یک فرآیند جدید (فرزند)

    printf("After fork\n");
    return 0;
}
