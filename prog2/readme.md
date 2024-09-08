typedef struct photo {
    char filename[50];
    struct photo *next;
} phototype;

typedef phototype *gallery;

Using the structure and typedef statements above, write the implementation of the following functions:

1. bool addNewPhoto(gallery *my_gallery, char *photo_filename);
   -This function will create a new phototype node by heap memory allocation and set the filename
    field with the photo_filename passed as parameter. 
        
    It should check whether the filename is notempty and not beyond the filename character limit (50) including the filename extension.
    
    If photo_filename is valid, the new node will be inserted to the my_gallery linked list in an
    alphabetical order by filename. (Hint: You can use a built-in string function to help determine how to insert the new node in an alphabetical order.) Return true if the new photo was successfully inserted (valid filename). Otherwise, return false.

2. void display(gallery my_gallery);
   -This function will display the filenames of the photos in the my_gallery linked list.

3. int removeAllNonPhotos(gallery *my_gallery);
   -This function will remove from the my_gallery linked list all nodes that are not among the
    accepted image formats of the gallery. 
    
    Only Bitmap (.bmp), Portable Network Graphics (.png) and Joint Photographic Expert Group 
    (.jpg) image formats are acceptable in this gallery. Nodes in the my_gallery linked list whose filenames do not end with the aforementioned filename extensions will be removed from the my_gallery linked list. (Hint: Filenames can be flipped using a built-in string function so that the filename extension will now be in front of the filename. 
    
    Therefore, this function will remove the phototype node if its filename does not begin with pmb. or gnp. or gpj. You can use strncmp() to compare the first 4 characters of the
    filename) Filenames without a filename extension will also be removed. 
    
    Display in this function the filename of the photo to be removed from the gallery before removing from the linked list. Return the number of removed phototype nodes from the my_gallery linked list.

4. void writeToFile(gallery my_gallery);
   -This function will write to “mygallery.txt” file the photo filenames in the my_gallery linked list.

5. main()
   -This function will do the following tasks in the same sequence listed below:
    1. Declare a linked list my_gallery which has gallery as its data type.

    2. Ask for a filename of a photo and call addNewPhoto(&amp;my_gallery, photo_filename)
    multiple times and will only stop once the addNewPhoto() function returns false,
    meaning a photo was not successfully inserted because of an invalid filename.
    3. Call display(my_gallery) to check the contents of the my_gallery linked list after adding
    photos.
    4. Call removeAllNonPhotos(&amp;my_gallery) once and display how many phototype nodes
    were removed from the my_gallery linked list.
    5. Call writetoFile(my_gallery) to write the contents of the my_gallery linked list after
    removing non-image format filenames.
    
    SAMPLE PROGRAM OUTPUT
    ![demo](/pat-gallery-act-testcase.png)
   