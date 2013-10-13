#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cstdlib>
#include <sstream>

using namespace std;

int main() {

	const int SIZE = 512;
	short img[SIZE][SIZE];

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if(i%2 == 0 || j%3 == 0 || (i*j)%5 == 0)
				img[i][j] = 0;
			else
				img[i][j] = 1;
		}
	}
	srand(time(NULL));
	int color_red = 0;
	int color_green = 0;
	int color_blue = 0;

	//for loop to check what i value to put after out_.ppm
	int fileNum = 0;
	bool fileExists = true;
	char filename[256]; 
	
	do{
		fileNum++;
		strcpy(filename, "C:\\Users\\Max\\SkyDrive\\C++\\imgOutput\\out");
		
		stringstream ss;
		ss << fileNum;
		string str = ss.str();


		strcat(filename, str.c_str());
		strcat(filename, ".ppm");
		cout << filename << endl;
		
		struct stat buf;
		if(stat(filename, &buf) != -1) {
			fileExists = true;
			cout << filename << " exists" << endl;
		}
		else
			fileExists = false;

	}while(fileExists);



	FILE *f = fopen(filename, "wb");
	fprintf(f, "P6\n%i %i 255 \n", SIZE, SIZE);
	for (int i = 0; i < SIZE; ++i) {
		for(int j = 0; j < SIZE; ++j) {

			color_red = rand() % 256;
			color_green = rand() % 256;
			color_blue = rand() % 256;

			fputc(color_red, f);
			fputc(color_green, f);
			fputc(color_blue, f);
		}
	}
	fclose(f);

	cout << "Done!" << endl;
	return 0;

}

/* OLD CODE SNIPPETS

FILE *f = fopen("C:\\Users\\Max\\SkyDrive\\C++\\out.ppm", "wb");
	fprintf(f, "P6\n%i %i 255 \n", SIZE, SIZE);
	for (int i = 0; i < SIZE; ++i) {
		for(int j = 0; j < SIZE; ++j) {
			if(i < SIZE/2) {
				fputc(255, f); //red
				fputc(0, f); //green
				fputc(0, f); //blue
			}	
			else {
				fputc(0, f); //red
				fputc(0, f); //green
				fputc(255, f); //blue
			}
		}
	}


*/


