#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* altkey(char* key, int len);
char* encrypt(char* unencryptedstr, char* key);
char* decrypt(char* undecryptedstr, char* key);

int main() {

	char input_str[100], input_key[100];
	int T;

	printf("1. decrypt\n2. encrypt\n");
	scanf("%d", &T);
	printf("input string: ");
	scanf(" %[^\n]s", input_str);
	printf("\ninput key: ");
	scanf("%s", input_key);

	int ordlen = strlen(input_str);
		
	char *alteredkey = altkey(input_key, ordlen);

	if (T == 2) {
		char* result = encrypt(input_str, alteredkey);
		printf("\n%s", result);
	}
	if (T == 1) {
		char* result = decrypt(input_str, alteredkey);
		printf("\n%s", result);
	}
}

char* altkey(char* key, int len) {
	char altedkey[100] = "\0";
	char *alteredkey = (char*)malloc(len + 1);
	int temp;
	int ordkey = strlen(key);
	temp = len / ordkey + 1;
	for (int i = 0; i < temp; i++) {
		strcat(altedkey, key);
	}
	strncpy(alteredkey, altedkey, len);
	alteredkey[len] = '\0';

	return alteredkey;
}

char* encrypt(char* unencryptedstr, char* key) {
	int len = strlen(unencryptedstr);
	char* encryptedstr = (char*)malloc(len + 1);
	for (int i = 0; i < len; i++) {
		if (unencryptedstr[i] == ' ') { encryptedstr[i] = ' '; }
		else {
			if ((int)unencryptedstr[i] + (int)key[i] - 97 > 122) {
				encryptedstr[i] = (int)unencryptedstr[i] + (int)key[i] - 97 - 26;
			}
			if ((int)unencryptedstr[i] + (int)key[i] - 97 <= 122) {
				encryptedstr[i] = (int)unencryptedstr[i] + (int)key[i] - 97;
			}
		}
	}
	encryptedstr[len] = '\0';

	return encryptedstr;
}

char* decrypt(char* undecryptedstr, char* key) {
	int len = strlen(undecryptedstr);
	char* decryptedstr = (char*)malloc(len + 1);
	for (int i = 0; i < len; i++) {
		if (undecryptedstr[i] == ' ') { decryptedstr[i] = ' '; }
		else {
			if ((int)undecryptedstr[i] - (int)key[i] >= 0) {
				decryptedstr[i] = (int)undecryptedstr[i] - (int)key[i] + 97;
			}
			if ((int)undecryptedstr[i] - (int)key[i] < 0) {
				decryptedstr[i] = (int)undecryptedstr[i] - (int)key[i] + 97 + 26;
			}
		}
	}
	decryptedstr[len] = '\0';

	return decryptedstr;

}
