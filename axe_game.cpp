/*
Opens a popup window using raylib
*/
#include <cstdio>
#include "raylib.h"
int main()
{


//variables for window size
    int width{800};
    int height{800};
    InitWindow(width, height, "Axe Game");

//cirlce coord
    int circle_x{width/2};
    int circle_y{height/2};

    int circle_rad{30};

//cirlce edges
    int lcircle_edge{circle_x - circle_rad};
    int rcircle_edge{circle_x + circle_rad};
    int bcircle_edge{circle_y + circle_rad};
    int ucircle_edge{circle_y - circle_rad};

//rectangle coord
    int rec_x{width/4};
    int rec_y{height/4};
    int direction{15};

    int rec_length{60};

//rectangle edges
    int lrec{rec_x};
    int rrec{rec_x + rec_length};
    int urec{rec_y};
    int brec{rec_y + rec_length};

//Rec collision
    bool Collision_With_Rec = 
                    (lcircle_edge <= rrec) && 
                    (rcircle_edge >= lrec) && 
                    (bcircle_edge >= urec) && 
                    (ucircle_edge <= brec);

SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {

    BeginDrawing();
    ClearBackground(DARKGRAY);

    //Fale State and Game Over
        if (Collision_With_Rec)
        {
            DrawText("You Are Dead", width/4, height/2, 60, WHITE);
        }
        else
        {

//game logic begins

    //update edges
        lcircle_edge = circle_x - circle_rad;
        rcircle_edge = circle_x + circle_rad;
        bcircle_edge = circle_y + circle_rad;
        ucircle_edge = circle_y - circle_rad;
        lrec = rec_x;
        rrec = rec_x + rec_length;
        urec = rec_y;
        brec = rec_y + rec_length;

    //update collision
        Collision_With_Rec = 
                    (lcircle_edge <= rrec) && 
                    (rcircle_edge >= lrec) && 
                    (bcircle_edge >= urec) && 
                    (ucircle_edge <= brec);

        DrawCircle(circle_x, circle_y, circle_rad, RED);
        DrawRectangle(rec_x, rec_y, rec_length, rec_length, PINK);

        //move rectangle
        rec_y += direction;

            if (rec_y > height-60 || rec_y < 0)
            {
                direction = -direction;
            }

    
        //moves circle
            if (IsKeyDown(KEY_D) && circle_x < width - circle_rad - 5)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > circle_rad)
            {
                circle_x -= 10;
            }
            if (IsKeyDown(KEY_W) && circle_y > circle_rad + 5) 
            {
                circle_y -= 10;
            }
            if (IsKeyDown(KEY_S) && circle_y < height-circle_rad)
            {
                circle_y += 10;
            }

//game logic ends
        }


    EndDrawing();

    }

}