#include "inotify.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Trasforma un percorso relativo in un percorso assoluto pulito.
 */
char *getAbsPath(const char *relativePath, char *absolutePath)
{
    return realpath(relativePath, absolutePath);
}

/*
 * Converte la maschera di bit di inotify in testo leggibile.
 */
void getEventNameFromMask(uint32_t mask, char *dest, size_t dest_size)
{
    if (!dest || dest_size == 0)  // Controllo che il puntatore sia valido
        return;

    dest[0] = '\0';  // Inizializzo una stringa vuota

    if (mask & IN_CREATE) // Se l'elemento è stato creato
        strncat(dest, "IN_CREATE ", dest_size - strlen(dest) - 1);

    if (mask & IN_DELETE) // Se l'elemento è stato cancellato
        strncat(dest, "IN_DELETE ", dest_size - strlen(dest) - 1);

    if (mask & IN_MOVED_FROM) // Se l'elemento è stato spostato via
        strncat(dest, "IN_MOVED_FROM ", dest_size - strlen(dest) - 1);

    if (mask & IN_MOVED_TO) // Se un elemento è stato spostato dentro
        strncat(dest, "IN_MOVED_TO ", dest_size - strlen(dest) - 1);

    if (mask & IN_ISDIR) // Se l'evento riguarda una directory
        strncat(dest, "IN_ISDIR ", dest_size - strlen(dest) - 1);

    if (mask & IN_DELETE_SELF) // Se la cartella osservata stessa è stata eliminata
        strncat(dest, "IN_DELETE_SELF ", dest_size - strlen(dest) - 1);

    if (mask & IN_IGNORED) // Se il watch è stato rimosso dal sistema
        strncat(dest, "IN_IGNORED ", dest_size - strlen(dest) - 1);

    if (dest[0] == '\0') // Se nessun evento combacia
        strncpy(dest, "unknown", dest_size - 1);
}