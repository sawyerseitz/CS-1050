#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MOVIES_SIZE 10

struct Movie;

int checkUserInput(char* sortType, char* sortOrder);

int findMovieCount(FILE* fp);

void registerMovies(FILE* fp, struct Movie* movies, int numMovies);
void printMovies(struct Movie* movies, char* sortType, int numMovies);

void sortAscending(struct Movie* movies, char* sortType, int numMovies);
void sortDecending(struct Movie* movies, char* sortType, int numMovies);

void swap(struct Movie* movie1, struct Movie* movie2);


struct Movie
{
    char title[30];
    unsigned int revenue;
    short year;
};

int main(int argc, char* argv[])
{
    FILE* fp;
    int numMovies;
    struct Movie movies[MOVIES_SIZE];

    fp = fopen(argv[1], "r");

    if (fp)
    {
        if (checkUserInput(argv[2], argv[3]))
        {
            numMovies = findMovieCount(fp);
            registerMovies(fp, movies, numMovies);

            if (strcmp(argv[3], "Ascending") == 0)
                sortAscending(movies, argv[2], numMovies);
            else
                sortDecending(movies, argv[2], numMovies);

            printf("\n");
            printMovies(movies, argv[2], numMovies);

            fclose(fp);
 

        } else
        {
            printf("./a.out filename [sort_field [sort_order]]\n");
            printf("\t- sort_field must be one of \"Title\", \"Gross\", or \"Year\" if specified.\n");
            printf("\t- sort_order must be one of \"Ascending\" or \"Descending\" if specified.\n");
            return 0;
        }
                                                                                                                        
    } else
        printf("*** Error: could not open file ***\n");

    return 0;
}

// Checks to see if the user inputed the correct 
int checkUserInput(char* sortType, char* sortOrder)
{ 
    if (sortType && (strcmp(sortType, "Title") == 0 || strcmp(sortType, "Gross") == 0 || strcmp(sortType, "Year") == 0))
        if (sortOrder && (strcmp(sortOrder, "Ascending") == 0 || strcmp(sortOrder, "Decending") == 0))
            return 1;

    return 0;
}

int findMovieCount(FILE* fp)
{
    int numLines = 0;

    for (char c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n') 
            ++numLines;

    return numLines;
}

void registerMovies(FILE* fp, struct Movie* movies, int numMovies)
{
   for (int i = 0; i < numMovies; ++i)
   {
        fscanf(fp, "%s %u %hi", movies[i].title, &movies[i].revenue, &movies[i].year);
        printf("%30s\n", movies[i].title);
   }
}

void printMovies(struct Movie* movies, char* sortType, int numMovies)
{
    char* header[3] = {"Title", "Gross", "Year"};
            
    printf("Sorted movies:\n");                                                                                                                              
    printf("%30s %20s %15s\n", header[0], header[1], header[2]);
                                                                                                    
    for (int i = 0; i < numMovies; ++i)
        printf("%30s %20u %15hi\n", movies[i].title, movies[i].revenue, movies[i].year);
}

void sortAscending(struct Movie* movies, char* sortType, int numMovies)
{
    for (int i = 0; i < numMovies - 1; ++i)
    {
        for (int j = 0; j < numMovies - 1 - i; ++j)
        {
            if (strcmp(sortType, "Title") == 0)
            {
                if (strcmp(movies[j].title, movies[j + 1].title) > 0)
                    swap(&movies[j], &movies[j + 1]);
                                                                                                                                    
            } else if (strcmp(sortType, "Gross") == 0)
            {
                if (movies[j].revenue > movies[j + 1].revenue)
                    swap(&movies[j], &movies[j + 1]);
                                                                                                                                                                                                                        
            } else if (strcmp(sortType, "Year") == 0)
            {
                if (movies[j].year > movies[j + 1].year)
                        swap(&movies[j], &movies[j + 1]);
            }
        }
    }
}

void sortDecending(struct Movie* movies, char* sortType, int numMovies)
{
    for (int i = 0; i < numMovies - 1; ++i)
    {
        for (int j = 0; j < numMovies - 1 - i; ++j)
        {
            if (strcmp(sortType, "Title") == 0)
            {
                if (strcmp(movies[j].title, movies[j + 1].title) < 0)
                    swap(&movies[j], &movies[j + 1]);
                                                                                                                                    
            } else if (strcmp(sortType, "Gross") == 0)
            {
                if (movies[j].revenue < movies[j + 1].revenue)
                    swap(&movies[j], &movies[j + 1]);
                                                                                                                                                                                                                        
            } else if (strcmp(sortType, "Year") == 0)
            {
                if (movies[j].year < movies[j + 1].year)
                        swap(&movies[j], &movies[j + 1]);
            }
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
