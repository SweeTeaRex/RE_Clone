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
    const int screenWidth = 1387;
    const int screenHeight = 780;

    InitWindow(screenWidth, screenHeight, "RECLONE");

    // GameScreen currentScreen = TITLE;
    GameScreen currentScreen = LEVEL1;

    // TITLE screen //

    Texture2D zombie1 = LoadTexture("images/zombie2.jpg");

    Rectangle srcRect = { 0.0f, 0.0f, (float)zombie1.width, (float)zombie1.height};
    Rectangle destRect = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight};
    Vector2 rectOrigin = { 0.0f, 0.0f };

    


    // LEVEL1 screen //


    bool pause = false;

    // CAMERA
    Camera mainCamera = { 0 };
    mainCamera.position = (Vector3){ 0.7f, 0.4f, 15.2f };
    mainCamera.target = (Vector3){ 13.0f, 0.0f, 0.0f };
    mainCamera.fovy = 45.0f;
    mainCamera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    mainCamera.projection = CAMERA_PERSPECTIVE;

    // CUBIC MAP
    Image mapImage = LoadImage("assets/map2.png");    TextureCubemap cubicMap = LoadTextureCubemap(mapImage, CUBEMAP_LAYOUT_AUTO_DETECT);
    Texture2D level1text = LoadTexture("assets/panelAtlas.png");
    Mesh cubicMapMesh = GenMeshCubicmap(mapImage, (Vector3){ 1.0f, 1.0f, 1.0f });
    
    Model mapModel = LoadModelFromMesh(cubicMapMesh);

    mapModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = level1text;

    Vector3 mapPosition = { 0.0f, 0.0f, -1.0f };

    // zombie sprite

    Texture2D zombieSprite = LoadTexture("assets/zombieSprite.png");
    Rectangle zombieSpriteFrame = { 0.0f, 0.0f, (float)zombieSprite.width/9, (float)zombieSprite.height/5};
    
    Vector2 zombieSpriteSize = { 1.0f, 1.0f };

    // zombie 1
    Vector3 zombieSprite1Pos = { 5.0f, 0.5f, 1.0f };
    int zombieDirection = 1;
    // zombie 2
    Vector3 zombieSprite2Pos = { 15.0f, 0.5f, 1.0f };

    int currentFrame = 0;

    int framerCounter = 0;
    int frameSpeed = 4;

    DisableCursor();
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
                if (IsKeyPressed(KEY_P)) pause = !pause;

                if (!pause) UpdateCamera(&mainCamera, CAMERA_FIRST_PERSON);

                framerCounter++;

                if(framerCounter >= (60/frameSpeed))
                {
                    framerCounter = 0;
                    currentFrame++;

                if(currentFrame > 5) currentFrame = 0;

                zombieSpriteFrame.x = (float)currentFrame*(float)zombieSprite.width/9;

                if(currentFrame == 5)
                {
                    zombieSpriteFrame.y = zombieSpriteFrame.y + zombieSprite.height/5;
                }


        }
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
                    DrawText("RESIDENT EVIL CLONE", screenWidth/2-(reText/2), 20, fontSize, RED);                    
                    DrawText("PRESS START", screenWidth/2-(startText/2), screenHeight-60, fontSize, RED);

                } break;
                case LEVEL1:
                {
                    BeginMode3D(mainCamera);

                        DrawModel(mapModel, mapPosition, 1.0f, RAYWHITE);

                        DrawBillboardRec(mainCamera, zombieSprite, zombieSpriteFrame, zombieSprite1Pos, zombieSpriteSize, WHITE); 

                        DrawBillboardRec(mainCamera, zombieSprite, zombieSpriteFrame, zombieSprite2Pos, zombieSpriteSize, WHITE);
                    
                    EndMode3D();

                    // LEVEL1 TEXT
                    int fontSize = 20;
                                        
                    DrawText("LEVEL1", 2, 2, fontSize, BLACK);

                    

                } break;
            }



        EndDrawing();
    }

    UnloadTexture(zombie1);
    CloseWindow();
    return 0;
}