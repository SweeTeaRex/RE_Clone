//
//
//  MMP""MM""YMM              `7MM"""Mq.                        `7MM"""Mq.
//  P'   MM   `7                MM   `MM.                         MM   `MM.
//       MM  .gP"Ya   ,6"Yb.    MM   ,M9  .gP"Ya `7M'   `MF'      MM   ,M9 `7Mb,od8 ,pW"Wq.   .P"Ybmmm `7Mb,od8 ,6"Yb.  `7MMpMMMb.pMMMb.  ,pP"Ybd
//       MM ,M'   Yb 8)   MM    MMmmdM9  ,M'   Yb  `VA ,V'        MMmmdM9    MM' "'6W'   `Wb :MI  I8     MM' "'8)   MM    MM    MM    MM  8I   `"
//       MM 8M""""""  ,pm9MM    MM  YM.  8M""""""    XMX          MM         MM    8M     M8  WmmmP"     MM     ,pm9MM    MM    MM    MM  `YMMMa.
//       MM YM.    , 8M   MM    MM   `Mb.YM.    ,  ,V' VA.        MM         MM    YA.   ,A9 8M          MM    8M   MM    MM    MM    MM  L.   I8
//     .JMML.`Mbmmd' `Moo9^Yo..JMML. .JMM.`Mbmmd'.AM.   .MA.    .JMML.     .JMML.   `Ybmd9'   YMMMMMb  .JMML.  `Moo9^Yo..JMML  JMML  JMML.M9mmmP'
//                                                                                           6'     dP
//                                                                                           Ybmmmd'
//
//
// Created by: Trey Adams


#include <stdio.h>
#include <string.h>
#include <raylib.h>

typedef enum GameScreen {
    TITLE=0,
    LEVEL1
} GameScreen;






int main(void)
{
    // INITIALAZATION 
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RECLONE");

    GameScreen currentScreen = TITLE;

    // TITLE screen //

    Texture2D zombie1 = LoadTexture("images/zombie1.jpg");

    Rectangle srcRect = { 0.0f, 0.0f, (float)zombie1.width, (float)zombie1.height};
    Rectangle destRect = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight};
    Vector2 rectOrigin = { 0.0f, 0.0f };

    if(zombie1.id == 0)
    {
        printf("Failed to load zombie1.\n");
    }


    // LEVEL1 screen //

    SetTargetFPS(60);
    // MAIN GAME LOOP //
    while(!WindowShouldClose())
    {   
        if(IsGamepadAvailable(0))
        {
        switch (currentScreen)
        {
            case TITLE:
            {
                if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsKeyPressed(KEY_SPACE))
                {
                    currentScreen = LEVEL1;
                }
            
            } break;

            case LEVEL1:
            {

            } break;
        }
        }
        
        BeginDrawing();

            ClearBackground(WHITE);

            switch(currentScreen)
            {
                case TITLE:
                {
                    // background image
                    DrawTexturePro(zombie1, srcRect, destRect, rectOrigin, 0.0f, WHITE);
                    // TITLE SCREEN TEXT
                    int fontSize = 40;
                    int startText = MeasureText("PRESS START", fontSize);
                    int reText = MeasureText("RESIDENT EVIL CLONE", fontSize);
                    DrawText("RESIDENT EVIL CLONE", screenWidth/2-(reText/2), 20, fontSize, RED);                    DrawText("PRESS START", screenWidth/2-(startText/2), screenHeight-60, fontSize, RED);

                } break;
                case LEVEL1:
                {
                    // LEVEL1 TEXT
                    int fontSize = 20;
                    // int level1Size = MeasureText("LEVEL1", fontSize);
                    DrawText("LEVEL1", 2, 2, fontSize, BLACK);

                } break;
            }



        EndDrawing();
    }

    UnloadTexture(zombie1);
    CloseWindow();
    return 0;
}