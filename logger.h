#ifndef LOGGER_H
#define LOGGER_H

// Установка пути для лог-файла
void set_log_path(const char *path);

// Запись сообщения в лог-файл или на экран
void log_message(const char *message);

#endif // LOGGER_H

