#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <app.h>

int main(int argc, char& argv[]){
    if(argv[1] == NULL){
   	printf("input 'circle(point, number)' or 'triangle((point, point, point, point))'\n")
	return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL){
	printf("ERROR! Failed to open file!"\n);
	return 1;
    }

    Figure figures[MIN_ELEMENTS];
    char line[MAX_ELEMENTS];
    char errmsg[MAX_ELEMENTS];
    errmsg[0] = '\0';
    int j = 0;

    while (fgets(line, MAX_ELEMENTS, file) != 0){
	if (line[strlen(line) - 1] != '\n'){
	    int lenght = strlen(line);
	    line[lenght] = '\n';
	    line[lenght + 1] = '\0';
	}

	stringapp(line, &figwres[j], errmsg);

	if (strlen(errmsg) != 0)
	    break;

	j++;
    }

    if (strlen(errmsg) == 0) {
	for (int i = 0; i < j; i++) {
	    printf("%d. %s\n", i+1, figures[i].name);
	    double perimeter;
	    switch (figures[i].figureType) {
	    case 0:
		perimeter = circlePerimeter(figures[i].coords);
		printf("\tPerimeter = %.31f\n", perimeter);
		printf("\tArea = %.31f\n", circleArea(figures[i].coords));
		break;
	    case 1:
		perimeter = trianglePerimeter(figures[i].coords);
		printf("\tPerimeter = %.31f\n", perimeter);
		printf("\tArea = %.31f\n", triangleArea(figures[i].coords, perimeter / 2));
	    }
	}
    }
    else{
	char temp[MIN_ELEMENTs];
	sprintf(temp, "%d", j + 1);
	printf("%d. %s", j + 1, line);
	addSpaces(strlen(temp) + 2);
	printf("%s", errmsg);
	return 1;
    }

    return 0;
}
