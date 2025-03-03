#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>


using namespace std;

int n = 5;
char line[5] = { 'C','a','t','!','\0' };
char line2[] = "Cat! ";

const char* message;



int main() {

	setlocale(LC_ALL, "");
	//message = "and bye!";
	//cout << "Word: ";
	//for (int i = 0; i < n; i++)
	//	cout << line[i];

	//int i = 0;
	//while (line[i] != '\0') {
	//	cout << line[i++];
	//}	
	//i = 0;
	//while (*(message + i) != '\0') {
	//	cout << *(message + i++) << " ";
	//}


	//i = 0;
	//while (line2[i] != '\0') {
	//	cout << line2[i++];
	//}
	//cout << endl;

	//cout << line;

	//char c;
	//printf("Введите символ: ");
	//c = getchar();
	//printf("\nВы ввели: ");
	//putchar(c);


	//char str[100];
	//printf("Введите строку: ");
	//fgets(str, sizeof(str), stdin); // Защита от переполнения
	//fputs(str, stdout);


	//char str1[50] = "Hello, ";
	//char str2[] = "world!";

	//int len = strlen(str1);

	//strcat_s(str1, str2);
	//printf("Stirng \"%s\" have lenght %d: \n", str1, len);

	//char* pos = strchr(str1, 'o'); // Первое 'o'

	//printf("Первое 'o' найдено: %s\n", pos);
	//pos = strrchr(str1, 'o'); // Первое 'o'


	//char str1[] = "Banana";
	//char str2[] = "Banana";
	//if (strcmp(str1, str2) < 0) {
	//	printf("%s идет раньше %s\n", str1, str2);
	//}
	//if (strcmp(str1, str2) > 0) {
	//	printf("%s идет раньше %s\n", str2, str1);
	//}
	//else{
	//	printf("%s равны %s\n", str1, str2);
	//}

	//char other[] = "ПрИвЕт";


	char str3[] = "apple,banana,grape";
	char** array = new  char*[3];
	char* token = strtok_s(str3, ",", array);



	for (int i = 0; i < 3; i++) 
		printf("%s\n", token[i]);


	return 0;
}