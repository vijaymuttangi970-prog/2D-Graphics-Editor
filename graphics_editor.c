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
    int startY = (y < 0) ? 0 : y;
    int startX = (x < 0) ? 0 : x;

    for(i = startY; i < y + height && i < ROWS; i++)
    {
        for(j = startX; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

void deleteRectangle(int x, int y, int width, int height)
{
    int i, j;
    int startY = (y < 0) ? 0 : y;
    int startX = (x < 0) ? 0 : x;

    for(i = startY; i < y + height && i < ROWS; i++)
    {
        for(j = startX; j < x + width && j < COLS; j++)
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

    int startX = (x < 0) ? 0 : x;

    for(i = startX; i < x + length && i < COLS; i++)
    {
        canvas[y][i] = '*';
    }
}

void drawTriangle(int x, int y, int height)
{
    int i, j;
    for(i = 0; i < height && y + i < ROWS; i++)
    {
        if (y + i < 0) continue;
        
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
            double dx = (x - cx) * 0.55; 
            double dy = (y - cy);
            
            if((dx * dx) + (dy * dy) <= (r * r))
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
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = 0;
        }

        switch(choice)
        {
            case 1:
                printf("\n--- Draw Rectangle ---\n");
                printf("Enter Starting X Coordinate: ");
                scanf("%d", &x);
                printf("Enter Starting Y Coordinate: ");
                scanf("%d", &y);
                printf("Enter Width: ");
                scanf("%d", &width);
                printf("Enter Height: ");
                scanf("%d", &height);

                drawRectangle(x, y, width, height);
                printf("Rectangle Drawn!\n");
                break;

            case 2:
                printf("\n--- Draw Line ---\n");
                printf("Enter Starting X Coordinate: ");
                scanf("%d", &x);
                printf("Enter Starting Y Coordinate: ");
                scanf("%d", &y);
                printf("Enter Line Length: ");
                scanf("%d", &length);

                drawLine(x, y, length);
                printf("Line Drawn!\n");
                break;

            case 3:
                printf("\n--- Draw Triangle ---\n");
                printf("Enter Peak X Coordinate: ");
                scanf("%d", &x);
                printf("Enter Peak Y Coordinate: ");
                scanf("%d", &y);
                printf("Enter Height: ");
                scanf("%d", &height);

                drawTriangle(x, y, height);
                printf("Triangle Drawn!\n");
                break;

            case 4:
                printf("\n--- Draw Circle ---\n");
                printf("Enter Center X Coordinate: ");
                scanf("%d", &x);
                printf("Enter Center Y Coordinate: ");
                scanf("%d", &y);
                printf("Enter Radius: ");
                scanf("%d", &radius);

                drawCircle(x, y, radius);
                printf("Circle Drawn!\n");
                break;

            case 5:
                printf("\n--- Delete Rectangle ---\n");
                printf("Enter Rectangle X Coordinate: ");
                scanf("%d", &x);
                printf("Enter Rectangle Y Coordinate: ");
                scanf("%d", &y);
                printf("Enter Width: ");
                scanf("%d", &width);
                printf("Enter Height: ");
                scanf("%d", &height);

                deleteRectangle(x, y, width, height);
                printf("Rectangle Deleted!\n");
                break;

            case 6:
                printf("\n--- Modify Rectangle ---\n");
                printf("[Old Rectangle Details]\n");
                printf("Enter Old X: ");
                scanf("%d", &oldx);
                printf("Enter Old Y: ");
                scanf("%d", &oldy);
                printf("Enter Current Width: ");
                scanf("%d", &width);
                printf("Enter Current Height: ");
                scanf("%d", &height);

                printf("\n[New Rectangle Details]\n");
                printf("Enter New X: ");
                scanf("%d", &newx);
                printf("Enter New Y: ");
                scanf("%d", &newy);

                deleteRectangle(oldx, oldy, width, height);
                drawRectangle(newx, newy, width, height);
                printf("Rectangle Moved & Modified!\n");
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