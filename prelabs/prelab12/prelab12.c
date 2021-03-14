#include <stdio.h>
#include <string.h>

#define MOVIES_SIZE 10

struct Movie;

void registerMovies(FILE* fp, struct Movie* movies);
void printMovies(struct Movie* movies, int sorted);

void sort(struct Movie* movies);
void swap(struct Movie* movie1, struct Movie* movie2);


struct Movie
{
    char title[30];
    unsigned int revenue;
    short year;
};

int main(int argc, char* argv[])
{
    FILE* fp = NULL;
    struct Movie movies[MOVIES_SIZE];
    int sorted = 0;

    if ((fp = fopen(argv[1], "r")) != NULL)
    {
        registerMovies(fp, movies);
        printMovies(movies, sorted);
                                                                                
        sort(movies);
        sorted = 1;

        printf("\n");
        printMovies(movies, sorted);

        fclose(fp);

    } else
        printf("ERROR: Could not open file %s\n", argv[1]);

    return 0;
}

void registerMovies(FILE* fp, struct Movie* movies)
{
    for (int i = 0; i < MOVIES_SIZE; ++i)
        fscanf(fp, "%s %u %hi", movies[i].title, &movies[i].revenue, &movies[i].year);
}

void printMovies(struct Movie* movies, int sorted)
{
    char* header[3] = {"Title", "Gross", "Year"};
            
    if (sorted)
        printf("Year:\n");
    else
        printf("Original:\n");
                                                                                            
    printf("%30s %20s %15s\n", header[0], header[1], header[2]);
                                                                                            
    for (int i = 0; i < MOVIES_SIZE; ++i)
        printf("%30s %20u %15hi\n", movies[i].title, movies[i].revenue, movies[i].year);
}

void sort(struct Movie* movies)
{
    for (int i = 0; i < MOVIES_SIZE - 1; ++i)
    {
        for (int j = 0; j < MOVIES_SIZE - 1 - i; ++j)
        {
            if (movies[j].year > movies[j + 1].year)
                swap(&movies[j], &movies[j + 1]);
        }
    }
}

void swap(struct Movie* movie1, struct Movie* movie2)
{
    struct Movie temp;

    temp = *movie1;
    *movie1 = *movie2;
    *movie2 = temp;
}

