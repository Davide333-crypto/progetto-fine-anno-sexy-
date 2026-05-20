#ifndef INOTIFY_H
#define INOTIFY_H

#include <sys/types.h>
#include <sys/inotify.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

// Definizione del buffer per contenere gli eventi di inotify
#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

// Trasforma un percorso relativo in un percorso assoluto 
char *getAbsPath(const char *relativePath, char *absolutePath);

// Converte la maschera di bit di inotify in testo leggibile
void getEventNameFromMask(uint32_t mask, char *dest, size_t dest_size);

#endf