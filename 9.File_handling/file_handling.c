#include <stdlib.h>
#include <stdio.h>
#define FILENAME "example.txt"

void fileHandling(){
    FILE *f = fopen("file_handling.txt", "w");
    if(f == NULL){
        perror("Error opening file.txt");
        exit(1);
    }

    fprintf(f, "Hello, World!\n");
    fclose(f);
}

int fileHandlingWithArgs(int argc, char **argv)
{
    int e = EXIT_SUCCESS;
    /* Get path from argument to main else default to output.txt */
    char *path = (argc > 1) ? argv[0] : "output.txt";
    /* Open file for writing and obtain file pointer */
    FILE *file = fopen(path, "w");

    /* Print error message and exit if fopen() failed */
    if (!file)
    {
        perror(path);
        return EXIT_FAILURE;
    }
    /* Writes text to file. Unlike puts(), fputs() does not add a new-line. */
    if (fputs("Output in file.\n", file) == EOF)
    {
        perror(path);
        e = EXIT_FAILURE;
    }
    /* Close file */
    if (fclose(file))
    {
        perror(path);
        return EXIT_FAILURE;
    }
    return e;
}


void printAllWords(FILE * fp)
{
    char tmp[20];
    int i = 1;
    while (fscanf(fp, "%19s", tmp) != EOF) {
        printf("Word %d: %s\n", i, tmp);
        i++;
    }
}

int printAllTheWords(void)
{
    FILE *fp;
    if ((fp = fopen(FILENAME, "r")) == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    printAllWords(fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

int writeBinFile(){
    int result = EXIT_SUCCESS;
    char file_name[] = "outbut.bin";
    char str[] = "This is a binary file example";
    FILE * fp = fopen(file_name, "wb");

    if (fp == NULL) /* If an error occurs during the file creation */
    {
        result = EXIT_FAILURE;
        fprintf(stderr, "fopen() failed for '%s'\n", file_name);
    }
    else
    {
        size_t element_size = sizeof *str;
        size_t elements_to_write = sizeof str;
        /* Writes str (_including_ the NUL-terminator) to the binary file. */
        size_t elements_written = fwrite(str, element_size, elements_to_write, fp);
        if (elements_written != elements_to_write)
        {
            result = EXIT_FAILURE;
            /* This works for >=c99 only, else the z length modifier is unknown. */
            fprintf(stderr, "fwrite() failed: wrote only %zu out of %zu elements.\n",
            elements_written, elements_to_write);
            /* Use this for <c99: *
            fprintf(stderr, "fwrite() failed: wrote only %lu out of %lu elements.\n",
            (unsigned long) elements_written, (unsigned long) elements_to_write);
            */
        }
        fclose(fp);
    }
    return result;
}

int main(){
    fileHandling();
    char *args[] = {"output.txt", "file_handling.txt"};
    int result = fileHandlingWithArgs(2, args);
    printf("Result: %d\n", result);
    printAllTheWords();
    writeBinFile();
    return 0;
}