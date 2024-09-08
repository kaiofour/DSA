#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define FILENAME_LIMIT 50
typedef struct photo{
char filename[FILENAME_LIMIT];
struct photo *next;
}phototype;
typedef phototype *gallery;

bool addNewPhoto(gallery *my_gallery, char *photo_filename);
int removeAllNonPhotos(gallery *my_gallery);
void display(gallery my_gallery);

int main(){
	
	gallery my_gallery;
	bool result=false;
	char photo_filename[FILENAME_LIMIT]={""};
	
	//Call addNewPhoto() n times until a blank filename is inputted by user
	
	//Call display() function to display all photos added to the gallery 
	
	//Call removeAllNonPhotos() and display the return count
	
	//Call display() to show the remaining photos in gallery after delete
}

bool addNewPhoto(gallery *my_gallery, char *photo_filename){
	
	gallery *trav=NULL,temp=NULL;
	
	//Write the implementation
	
}

int removeAllNonPhotos(gallery *my_gallery){
	
	gallery *trav=NULL,temp=NULL;
	
	int count=0;
	char reversedFileName[FILENAME_LIMIT];	
	printf("\n-------REMOVING NON-PHOTO FILES--------\n\n\n\n\n");
	
	//Write the implementation
	
}

void display(gallery my_gallery){
	
	gallery trav=my_gallery;
	printf("\n-----DISPLAYING FILES IN THE GALLERY:------\n");

	//Write the implementation
}