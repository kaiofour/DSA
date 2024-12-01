#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 50

typedef struct photo
{
	char filename[MAX];
	struct photo *next;
} *gallery;


bool addNewPhoto(gallery *my_gallery, char *photo_filename);
int removeAllNonPhotos(gallery *my_gallery);
void display(gallery my_gallery);

int main()
{
	
	gallery my_gallery = NULL;
	bool result=false;
	char photo_filename[MAX]={""};
	
	//Call addNewPhoto() n times until a blank filename is inputted by user
	
	//Call display() function to display all photos added to the gallery 
	
	//Call removeAllNonPhotos() and display the return count
	
	//Call display() to show the remaining photos in gallery after delete
}

bool addNewPhoto(gallery *my_gallery, char photo_filename[])
{
	gallery *trav = my_gallery;
	
	while(*trav != NULL)
	{
		
	}
}




// int removeAllNonPhotos(gallery *my_gallery)
// {
// 	int count=0;
// 	char reversedFileName[MAX];	
// 	printf("\n-------REMOVING NON-PHOTO FILES--------\n\n\n\n\n");
		
// }

// void display(gallery my_gallery)
// {
// 	gallery trav = my_gallery;
// 	printf("\n-----DISPLAYING FILES IN THE GALLERY:------\n");

// }
