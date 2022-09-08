#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("No. of vertices : ");
    int i, j, size;
    char *tk;           
    char delim[] = " "; 
    char line[BUFSIZ];
    int *m; 

    fgets(line, BUFSIZ, stdin); 
    size = atoi(line);          
    printf("\nEnter the matrix\n");
    if (NULL == (m = malloc(sizeof(int) * size * size)))
    {
        
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    for (i = 0; i < size; i++)
    {
        if (NULL == fgets(line, BUFSIZ, stdin))
        {
            fprintf(stderr, "insufficient lines\n");
            exit(1);
        }
        j = 0;
        tk = strtok(line, delim);
        while (tk != NULL)
        {
            m[i * size + j] = atoi(tk); 
            j++;
            if (j > size)
            {
                fprintf(stderr, "too many columns\n");
                exit(1);
            }
            tk = strtok(NULL, delim);
        }
        if (j < size)
        {
            fprintf(stderr, "insufficient columns\n");
            exit(1);
        }
    }
   
    printf("\nAdjacency list is\n");
    for (i = 0; i < size; i++)
    {
        printf("%d", i + 1);
        for (j = 0; j < size; j++)
        {
            if (m[i * size + j])
            {
                printf(" -> %d", j + 1);
            }
        }
        printf("\n");
    }

    return 3;
}