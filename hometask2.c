#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

int found(int val, int j, int check[1000]) {
	int j1 = 0;
	for (int i = 0; i <= j; i++) {
		if (val == check[i]) {
			return j;
		}
		if (val != check[i]) {
			j1++;
		}
		if ((val != check[i]) & (j1-1 == j) & (i == j)) {
			check[i] = val;
			j++;
			return j;
		}
	}
}

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	int check[1000];
	char name[255];
	char namesupp[255];
	char supportdot[] = ".dot";
	int menu = 0;
	int a, b, x;
	int j = 0;
	int way = 0;
	printf("Введите имя файла (без разрешения .dot)\n");
	scanf("%s", &name);
	snprintf(namesupp, sizeof name, "%s%s", name, supportdot);

	FILE* graphs;
	graphs = fopen(namesupp, "w");
	fprintf(graphs, "graph %s {\n", name);
	while (menu == 0) {
		printf("\nВыберите действие:\n");
		printf("1) Добавить неориентировачный граф\n");
		printf("2) Добавить ориентировачный граф\n");
		printf("3) Проверка на связность графа графа\n");
		printf("Любое другое число) Выйти\n");
		scanf("%d", &menu);
		switch (menu) {
		    case 1:
				printf("\nВведите номера вершин:\n");
				printf("1) ");
				scanf("%d", &a);
				j = found(a, j, check);
				printf("2) ");
				scanf("%d", &b);
				j = found(b, j, check);
				fprintf(graphs, "\"%d\" -- \"%d\";\n", a, b);
				way++;
				menu = 0;
			    break;
			case 2:
				printf("\nВведите номера вершин:\n");
				printf("1) ");
				scanf("%d", &a);
				j = found(a, j, check);
				printf("2) ");
				scanf("%d", &b);
				j = found(b, j, check);
				fprintf(graphs, "\"%d\"->\"%d\";\n", a, b);
				way++;
				menu = 0;
			    break;
			case 3:
				x = ((j - 1) * (j - 2)) / 2;
				if (way > x) {
					printf("Граф связан\n");
				}
				if (way <= x) {
					printf("Граф не связан\n");
				}
				menu = 0;
				break;
		}
	}
	fprintf(graphs, "}");
	fclose(graphs);

}