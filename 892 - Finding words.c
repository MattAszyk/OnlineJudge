#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
int show(char chart) {
	int index = (int)chart;
	if ((65 <= chart && chart <= 90) || (97 <= chart && chart <= 122) || chart == ' ') return 1;
	else return 0;
}

int id_of_next(char* tab) {
	int i = 0;
	int length = strlen(tab);
	int id_of_last_space = 0;
	for (; i < length; ++i) {
		if (tab[i] == ' ') id_of_last_space = i;
		else if (tab[i] == '-') break;
	}
	
	return (i == length ? length : id_of_last_space+1);
}

int id_of_first(char* tab) {
	int i = 0, length = strlen(tab);
	for (; i < length; ++i) if (tab[i] == ' ') break;
	return i;
}

int main()
{
	int id_next,id_first,i, skiped = 0, length;
	char tab[61];
	while (fgets(tab, 61, stdin)) {
		if (tab[0] == '#' && strlen(tab) == 2) break;
		i = 0;
		length = strlen(tab);
		id_next = id_of_next(tab);
		id_first = id_of_first(tab);
		if (skiped) {
			for (i = 0; i < id_first; ++i)
				if (show(tab[i])) printf("%c",tab[i]);
			printf("\n");
			skiped = false;
		}
		for(;i < id_next; ++i)
			if (show(tab[i])) printf("%c", tab[i]);
		printf("\n");
		if (id_next != length) {
			skiped = true;
			for(; i < length; ++i)
				if (show(tab[i])) printf("%c", tab[i]);
		}
	}
	return 0;
}
