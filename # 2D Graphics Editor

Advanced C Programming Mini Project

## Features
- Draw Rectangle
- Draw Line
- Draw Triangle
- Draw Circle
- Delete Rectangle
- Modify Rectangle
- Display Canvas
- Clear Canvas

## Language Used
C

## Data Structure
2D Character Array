#include <stdio.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

void deleteRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void drawLine(int x, int y, int length)
{
    int i;

    if(y < 0 || y >= ROWS)
        return;

    for(i = x; i < x + length && i < COLS; i++)
    {
        if(i >= 0)
            canvas[y][i] = '*';
    }
}

void drawTriangle(int x, int y, int height)
{
    int i, j;

    for(i = 0; i < height && y + i < ROWS; i++)
    {
        for(j = 0; j <= i && x + j < COLS; j++)
        {
            if(x + j >= 0)
                canvas[y + i][x + j] = '*';
        }
    }
}

void drawCircle(int cx, int cy, int r)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            int d = (x - cx) * (x - cx) +
                    (y - cy) * (y - cy);

            if(d <= r * r)
            {
                canvas[y][x] = '*';
            }
        }
    }
}

int main()
{
    int choice;

    int x, y, width, height;
    int length;
    int radius;

    int oldx, oldy;
    int newx, newy;

    initializeCanvas();

    do
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Rectangle\n");
        printf("6. Modify Rectangle\n");
        printf("7. Display Canvas\n");
        printf("8. Clear Canvas\n");
        printf("9. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",
                      &x, &y,
                      &width, &height);

                drawRectangle(x, y, width, height);
                break;

            case 2:
                printf("Enter x y length: ");
                scanf("%d%d%d",
                      &x, &y, &length);

                drawLine(x, y, length);
                break;

            case 3:
                printf("Enter x y height: ");
                scanf("%d%d%d",
                      &x, &y, &height);

                drawTriangle(x, y, height);
                break;

            case 4:
                printf("Enter center x y radius: ");
                scanf("%d%d%d",
                      &x, &y, &radius);

                drawCircle(x, y, radius);
                break;

            case 5:
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",
                      &x, &y,
                      &width, &height);

                deleteRectangle(x, y, width, height);

                printf("Rectangle Deleted!\n");
                break;

            case 6:
                printf("Old Rectangle x y: ");
                scanf("%d%d",
                      &oldx, &oldy);

                printf("Width Height: ");
                scanf("%d%d",
                      &width, &height);

                printf("New Rectangle x y: ");
                scanf("%d%d",
                      &newx, &newy);

                deleteRectangle(oldx,
                                oldy,
                                width,
                                height);

                drawRectangle(newx,
                              newy,
                              width,
                              height);

                printf("Rectangle Modified!\n");
                break;

            case 7:
                displayCanvas();
                break;

            case 8:
                initializeCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 9:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 9);

    return 0;
}