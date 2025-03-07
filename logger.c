#include <stdio.h>
#include <stdlib.h>

static FILE *log_file = NULL;

void set_log_path(const char *path) {
    if (log_file) {
        fclose(log_file);
    }
    log_file = fopen(path, "w");
    if (!log_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
}

void log_message(const char *message) {
    if (log_file) {
        fprintf(log_file, "%s\n", message);
    } else {
        printf("%s\n", message);
    }
}

