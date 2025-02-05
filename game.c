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

// init game screens
typedef enum GameScreen
{
    SplashScreen = 0,
    StartScreen,
    Level_1
} GameScreen;


int main(void)
{
    // init game screen 
    const int screenWidth = 1800;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "RE_CLONE");    
    SetTargetFPS(60);
    // init current screen
    GameScreen currentScreen = SplashScreen;
    
    // init audio devices 
    InitAudioDevice();

    // Splash Screen

    Image zombieSplashImage = LoadImage("images/zombie.jpg");
    Texture2D zombieTexture = LoadTextureFromImage(zombieSplashImage);
    UnloadImage(zombieSplashImage);

    // Start Screen
    Image zombieStartImage = LoadImage("images/zombie2.jpg");
    Texture2D zombie2Texture = LoadTextureFromImage(zombieStartImage);
    UnloadImage(zombieStartImage);

    
    // level 1



    while (!WindowShouldClose())
    {
        if(IsGamepadAvailable(0))
        {
        switch(currentScreen)
        {
            case SplashScreen:
            {
                if(IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
                {
                    currentScreen = StartScreen;
                }
                break;
            }
            case StartScreen:
            {
                if(IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT))
                {
                    currentScreen = Level_1;
                }

                if(IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_UP))
                {
                    currentScreen = SplashScreen;
                }
                break;
            }
            case Level_1:
            {
                
            }
        }
        }

        BeginDrawing();

        ClearBackground(WHITE);

        if(IsGamepadAvailable(0))
        {
        switch(currentScreen)
        {
            case SplashScreen:
            {
                Rectangle source = {0,0, zombieSplashImage.width, zombieSplashImage.height};
                Rectangle dest = {0,0, screenWidth, screenHeight};
                Vector2 origin = {0,0};
                DrawTexturePro(zombieTexture, source, dest, origin, 0.0f, WHITE);
                int fontSizeSplash = 50;
                int splashLength = MeasureText("SplashScreen", fontSizeSplash);
                DrawText("SplashScreen", (screenWidth/2-splashLength/2), 5, fontSizeSplash, RED);

               

                int continueLength = MeasureText("Press X to continue", fontSizeSplash);               
                DrawText("Press X to continue", (screenWidth/2-continueLength/2), screenHeight-fontSizeSplash, 50, RED);
                break;
            }
            case StartScreen:
            {
                
                Rectangle source = {0,0, zombieStartImage.width, zombieStartImage.height};
                Rectangle dest = {0,0, screenWidth, screenHeight};
                Vector2 origin = {0,0};
                DrawTexturePro(zombie2Texture, source, dest, origin, 0.0f, WHITE);
                int fontSizeStart = 50;
                int startMeasure = MeasureText("StartScreen", fontSizeStart);
                int backMeasure = MeasureText("Press top button on right face to go back", fontSizeStart);
                DrawText("StartScreen", (screenWidth/2)-(startMeasure/2), 5, fontSizeStart, RED);
                DrawText("Press top button on right face to go back", (screenWidth/2)-(backMeasure/2), 5+fontSizeStart, fontSizeStart, RED);
                
                break;
            }
            case Level_1:
            {
                DrawText("Level 1", (screenWidth/2), 5, 50, RED);
                break;
            }
        }
        }
        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();

    return 0;    

    
}