#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>

void list_users() {
    struct passwd *pw;
    setpwent(); // Открываем базу данных пользователей

    // Собираем всех пользователей в массив
    struct passwd *users[1000];
    int count = 0;

    while ((pw = getpwent()) != NULL) {
        users[count] = malloc(sizeof(struct passwd));
        *users[count] = *pw;
        count++;
    }
    endpwent(); // Закрываем базу данных

    // Сортировка по алфавиту
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(users[i]->pw_name, users[j]->pw_name) > 0) {
                struct passwd *temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
    }

    // Вывод пользователей
    for (int i = 0; i < count; i++) {
        printf("User: %s, Home Directory: %s\n", users[i]->pw_name, users[i]->pw_dir);
        free(users[i]);
    }
}

