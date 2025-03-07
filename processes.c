#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        return;
    }

    // Собираем PID процессов
    int pids[1000];
    int count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            pids[count++] = atoi(entry->d_name);
        }
    }
    closedir(dir);

    // Сортировка по PID
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (pids[i] > pids[j]) {
                int temp = pids[i];
                pids[i] = pids[j];
                pids[j] = temp;
            }
        }
    }

    // Вывод процессов
    for (int i = 0; i < count; i++) {
        printf("PID: %d\n", pids[i]);
    }
}

