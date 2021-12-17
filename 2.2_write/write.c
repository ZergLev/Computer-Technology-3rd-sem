#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>


int main (int argc, char* argv[])
{
    if (argc != 3)
    {
        //Error in case there are not 3 arguments.
        //Outright rejects an attempt to run with wrong input.
        fprintf (stderr, "Usage: %s filename text-to-write\n", argv[0]);
        return 1;
    }

    //The owner can read and write to the file, everyone else can only 
    //read the file.
    int fd = open (argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd < 0) 
    {
        //If failed to open file, return the corresponding error code
        perror ("Failed to open the file.");
        return 2;
    }

    if (dprintf (fd, "%s", argv[2]) < 0)
    {
        //Should the writing fail, close the file descriptor,
        //then return the corresponding error code.
        close (fd);
        perror ("An error occurred while trying to write into the file.");
        return 3;
    }

    if (close (fd) < 0)
    {
        //If couldn't close the file, return the corresponding error code.
        perror ("Couldn't close the file.");
        return 4;
    }

    return 0;
}
