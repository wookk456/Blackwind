#include <stdio.h>
#include <string.h>

int main() {
	char str[99999];

	scanf("%s", str);
	int ptr = 0;
	int mem[99999] = {0, };

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '>') {
			ptr++;
		}
		if (str[i] == '<') {
			ptr--;
		}
		if (str[i] == '+') {
			mem[ptr]++;
		}
		if (str[i] == '-') {
			mem[ptr]--;
		}
		if (str[i] == '.') {
			printf("%c", mem[ptr]);
		}
		if (str[i] == ',') {
			char inp;
			scanf("%c", &inp);
			mem[ptr] = (int)inp;
		}
		if (str[i] == '[') {
			if (mem[ptr] != 0) continue;
			while (str[i] != ']') {
				i++;
			}
			continue;
		}
		if (str[i] == ']') {
			while (str[i] != '[') {
				i--;
			}
			i--;
		}
	}
}
