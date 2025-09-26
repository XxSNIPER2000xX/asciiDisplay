#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *asciiArtDir;
    char *line = NULL;
    size_t len = 0;
    FILE *fp;

    asciiArtDir = getenv("ASCII_DIR");
    if(!asciiArtDir) {
        fprintf(stderr, "asciiArtDir environment variable is not set!\n");
        return EXIT_FAILURE;
    }
    
    fp = fopen(asciiArtDir, "r");
    if(!fp) {
        fprintf(stderr, "failed to open file path:\n%s\n", asciiArtDir);
        return EXIT_FAILURE;
    }
    
    while(getline(&line, &len, fp) != -1)
        printf("%s", line);
    
    fclose(fp);
    return 0;
}
