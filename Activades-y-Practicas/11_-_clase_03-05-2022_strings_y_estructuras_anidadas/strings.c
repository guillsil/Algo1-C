#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

int main() {
	char hola_mundo[MAX_STRING];
	char hola_mundo2[MAX_STRING];
	strcpy(hola_mundo, "Hola, mundo! Como estan?");
	strcpy(hola_mundo2, "Hola, mundo! Como estan?");

	int largo = strlen(hola_mundo);
	printf("Largo del string: %i\n", largo);

	int iguales = strcmp(hola_mundo, hola_mundo2);
	printf("Son iguales? %i\n", iguales);


	/*if (strcmp(string1, string2) == 0) {
		// Son iguales
	}*/

	char mundo[MAX_STRING];
	strcpy(mundo, strstr(hola_mundo, "mundo"));
	printf("%s\n", mundo);

	printf("%i\n", strstr(hola_mundo, "manu"));

	return 0;
}