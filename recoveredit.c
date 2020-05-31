#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    //BITMAPFILEHEADER bf;



    typedef uint8_t BYTE;// defines a byte as 8 bits

    //FILE *File = fopen(argv[1],"r");//open pointer to a file called File in read mode
    //if (!File)
        //return 1;
    FILE *jpgread = fopen("card.raw","r");
    FILE *jpgwrit = NULL;
    BYTE buffer[512];
    int filenumber = 0;
    bool newjpg = false;
    //BYTE *BUFFER = malloc(sizeof(BYTE)*512);//allocate a memory space the size of 1 byte
    //this is your buffer to compare the values of the file to
    //daily revelation while thinking about this problem
    // if you use malloc to store the buffer information, that's when you use &buffer to store the info into the addres where the array is stored


    //unsigned char bufer[4];
    //char filenames[8];
    //unsigned char buffer[512];
    //BYTE *buffarray = malloc(sizeof(BYTE)*512);
    // allocate a pointer a to byte 512 the disk space in bytes.
    // if you use malloc you must pass fwrite by addres with &buffarray

    //char *imgname[8]; this should not be an array of pointers, but rather
    //a single string. telling fwrite() to write to an unintialized pointer
    //is undefined behavior
    char imgname[8];
    //fread() reads 1 item of data, each 512 bytes long from file into buffer
    //fread() will return the number of items read or written.
    //this number equals the number of bytes transfered only when size is 1.
    //if an error occurs or the end of the file is reached, the return value is a 0
    //while (fread(buffer, 512,1,jpgread) == 1)
    // looks through pointer to card.raw called jpgread in 512 byte chunks
    //and stores it in an array of bytes called buffer
    //  while you have not reached the end of the file
    while (fread(buffer, 512,1,jpgread) == 1)
    {
        newjpg = false;
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)

        {
            newjpg = true;
        }
        if (newjpg == true)
        {
            sprintf(imgname, "%03i.jpg",filenumber);
            jpgwrit = fopen(imgname,"w");
            fwrite(jpgwrit,512,1,jpgread);
            filenumber++;
        }
        else
        {
            continue;
        }


            //this line seems wrong... you may be incorrect with how fwrite works

            //fclose(jpgwrit);
            //fclose(jpgread);
                // how do i know when to stop checking with fread when it detects values indicated new jpg?
            //sprintf(imgname, "%03i.jpg",filenumber);
            //jpgwrit = fopen(imgname,"w");
        }
    if (jpgwrit != NULL)
    {
        fclose(jpgread);
    }
    //fclose(jpgread);
}

    //newjpg = true;
            /*
            if (newjpg == true)
            {
                fclose(jpgread);
                filenumber++;
            }
            */

            //newjpg = true;


            //writes to the character string str

            //open pointer to a file called File in write mode
            //newjpg = true;
            // you can't open your output file before you actually
            //generate the file name.
            //use sprintf() to get the name of your file first,
            //then open it with fopen after
    //fread(buffer, 1,512,File);
    //read 512 byte blocks back to back
    //if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)//bitwise & will carry only if both values are true
        /*
        do
        {
            fwrite(jpgwrit,1,512, File);
            sprintf(jpgwrit, "%03i.jpg",filenumber);
            filenumber++;
        }
        while (buffer[0] != 0xff && buffer[1] != 0xd8 && buffer[2] != 0xff && (buffer[3] & 0xf0) != 0xe0);
        {
            fwrite(jpgwrit,512,1, File);
            sprintf(jpgwrit, "%03i.jpg",filenumber);
            filenumber++;
        }
    int n = 0;
    BYTE recording = fread(jpgread, sizeof(BYTE), 512, File);//read data from file store in jpgrec
    BYTE buffera = fread(BUFFER, sizeof(BYTE), 512, File);
    BYTE bufferb = fread(buffer, sizeof(BYTE), 512, File);
    FILE *writing = fwrite(jpgwrit,sizeof(BYTE),512, File);
    FILE *fendofile = feof(jpgread);
    for (int i = 0; i < 512; i++)
    {
        char c = fread(buffer,512,1,jpgread);
        fread(buffer, 4, 1, jpgread);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fwrite(jpgwrit,sizeof(BYTE),512*i, writing);
            sprintf(jpgwrit, "%03i.jpg",filenumber);
            filenumber++;
        }
    }
    */

    //fclose(File);
    //free(BUFFER);
