#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "pixel.h"

#define CONST_R 0.30
#define CONST_G 0.59
#define CONST_B 0.11

#define GET_PIXEL(a, i, j) (*(*(a + i) + j))

/*
	TODO a
	Functia primeste ca parametru o imagine si intoarce imaginea rasturnata.
	Prin imagine rasturnata se intelege inversarea liniilor matricei pix_array
	din structura lui Picture, astfel: Linia 1 devine linia n, linia 2 devine
	linia n - 1, etc.
*/

void reversePic(Picture *pic) {
	Pixel* pixel;
	for (int i = 0; i < pic->height / 2; i++) {
		pixel = pic->pix_array[i];
		pic->pix_array[i] = pic->pix_array[pic->height - 1 - i];
		pic->pix_array[pic->height - 1 - i] = pixel;
	}
}

/*
	TODO b
	Functia primeste ca parametru o imagine si intoarce noua imagine obtinuta
	prin convertirea fiecarui pixel la valoarea sa grayscale.
	Valoarea grayscale a unui pixel sa calculeaza dupa urmatoarea formula:
	p.r = 0.3 * p.r;
	p.g = 0.59 * p.g;
	p.b = 0.11 * p.b;
*/

void colorToGray(Picture *pic) {
	for (int i = 0; i < pic->height; i++) {
		for (int j = 0; j < pic->width; j++) {
			GET_PIXEL(pic->pix_array, i, j).R *= CONST_R;
			GET_PIXEL(pic->pix_array, i, j).G *= CONST_G;
			GET_PIXEL(pic->pix_array, i, j).B *= CONST_B;
		}
	}
}

/*
	Structura unui pixel, cea a unei imagini, precum si generarea acestora
	sunt definite in pixel.h. Programul primeste de la tastatura inaltimea
	si latimea imaginii. De preferat, introduceti valori mici pentru
	a fi usor de verificat ulterior.
	Folositi functia printPicture pentru a printa componentele imaginii.
	Dupa ce ati realizat un TODO, apelati functia corespunzatoare in main
	urmata de printPicture pentru a vedea daca se obtine rezultatul dorit.
*/

int main() {
	int height, width;
	scanf("%d%d", &height, &width);
	Pixel **pix_array = generatePixelArray(height, width);
	Picture *pic = generatePicture(height, width, pix_array);

	printPicture(pic);
	printf("\n");

	reversePic(pic);
	colorToGray(pic);
	printPicture(pic);

	freePicture(&pic);
	freePixelArray(&pix_array, height, width);

	return 0;
}
