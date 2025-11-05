#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_PROCESSES 4     // تعداد فرآیندها
#define STEPS 12            // تعداد گام‌ها در هر نمونه
#define HIST_SIZE 25        // از -12 تا +12

int main() {
    int iteration;
    printf("Enter the number of iterations: ");
    scanf("%d", &iteration);

    int hist[HIST_SIZE] = {0};  // هیستوگرام نهایی در پدر
    clock_t start = clock();

    --------- // تقسیم نمونه‌ها بین فرزندان

    // ایجاد فرآیندهای فرزند
    for (int p = 0; p < NUM_PROCESSES; p++) {
        pid_t pid = fork();

        if (pid == 0) {
            // ======== فرآیند فرزند ========
            srand(time(NULL) + getpid()); // بذر تصادفی متفاوت

       .
....
....

            }

            // ذخیره نتیجه در فایل اختصاصی
            char filename[32];
            sprintf(filename, "child_%d.txt", p);
            FILE *f = fopen(filename, "w");
            if (!f) {
                perror("File error");
                exit(1);
            }
            for (int i = 0; i < HIST_SIZE; i++) {
                fprintf(f, "%d\n", local_hist[i]);
            }
            fclose(f);

            exit(0); // فرزند بعد از اتمام خارج می‌شود
        }
        else if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
    }

    // ======== فرآیند پدر ========
    for (int i = 0; i < NUM_PROCESSES; i++) {
        ........ // منتظر بمان تا همه‌ی فرزندان تمام شوند
    }

    // خواندن فایل‌های فرزندان و جمع کردن نتایج
    for (int p = 0; p < NUM_PROCESSES; p++) {
        ............
        }

        for (int i = 0; i < HIST_SIZE; i++) {
            ...........
        }
        fclose(f);
    }

    clock_t end = clock();
    double runtime = (double)(end - start) / CLOCKS_PER_SEC;

    // ======== چاپ نتایج ========
    ..............

    // نمایش گرافیکی ساده با ستاره‌ها
    ..............

    return 0;
}
