/*******************************************************************************************
*
*   raylib gamejam template
*
*   Template originally created with raylib 4.5-dev, last time updated with raylib 5.0
*
*   Template licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2022-2024 Ramon Santamaria (@raysan5)F
*
********************************************************************************************/

#include "raylib.h"

#if defined(PLATFORM_WEB)
    #define CUSTOM_MODAL_DIALOGS            // Force custom modal dialogs usage
    #include <emscripten/emscripten.h>      // Emscripten library - LLVM to JavaScript compiler
#endif

#include <stdio.h>                          // Required for: printf()
#include <stdlib.h>                         // Required for: 
#include <string.h>                         // Required for: 

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
// Simple log system to avoid printf() calls if required
// NOTE: Avoiding those calls, also avoids const strings memory usage
#define SUPPORT_LOG_INFO
#if defined(SUPPORT_LOG_INFO)
    #define LOG(...) printf(__VA_ARGS__)
#else
    #define LOG(...)
#endif

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum { 
    SCREEN_LOGO = 0, 
    SCREEN_TITLE, 
    SCREEN_GAMEPLAY, 
    SCREEN_ENDING
} GameScreen;

// TODO: Define your custom data types here

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

static RenderTexture2D target = { 0 };  // Render texture to render our game

// TODO: Define global variables here, recommended to make them static

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void);      // Update and Draw one frame

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
#if !defined(_DEBUG)
    SetTraceLogLevel(LOG_NONE);         // Disable raylib trace log messages
#endif

    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib gamejam template");
    
    // TODO: Load resources / Initialize variables at this point
    
    // Render texture to draw full screen, enables screen scaling
    // NOTE: If screen is scaled, mouse input should be scaled proportionally
    target = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);     // Set our game frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button
    {
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadRenderTexture(target);
    
    // TODO: Unload all loaded resources at this point

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//--------------------------------------------------------------------------------------------
// Module functions definition
//--------------------------------------------------------------------------------------------
// Update and draw frame
void UpdateDrawFrame(void)
{
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update variables / Implement example logic at this point
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    // Render game screen to a texture, 
    // it could be useful for scaling or further shader postprocessing
    BeginTextureMode(target);
        ClearBackground(RAYWHITE);
        
        // TODO: Draw your game screen here
        // DrawText("Welcome to Water Defense", 150, 140, 30, BLACK);
        DrawRectangleLinesEx((Rectangle){ 0, 0, screenWidth, screenHeight }, 16, BLACK);
        
    EndTextureMode();
    
    // Render to screen (main framebuffer)
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Draw render texture to screen, scaled if required
        DrawTexturePro(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, -(float)target.texture.height }, (Rectangle){ 0, 0, (float)target.texture.width, (float)target.texture.height }, (Vector2){ 0, 0 }, 0.0f, WHITE);

        // TODO: Draw everything that requires to be drawn at this point, maybe UI?
        DrawCircle(GetMouseX(), GetMouseY(), 5, RED);


        class Grid {
        public:
            int rows;
            int cols;
            int cellSize;

            Grid(int r = 10, int c = 10, int size = 40) : rows(r), cols(c), cellSize(size) {}

            void Draw() {
                int startX = (screenWidth - cols * cellSize) / 2;
                int startY = (screenHeight - rows * cellSize) / 2;

                for (int i = 0; i <= cols; i++) {
                    DrawLine(startX + i * cellSize, startY, startX + i * cellSize, startY + rows * cellSize, LIGHTGRAY);
                }
                for (int j = 0; j <= rows; j++) {
                    DrawLine(startX, startY + j * cellSize, startX + cols * cellSize, startY + j * cellSize, LIGHTGRAY);
                }
            }
        };

        Grid grid;

        grid.Draw();

        // Highlight the box that the mouse is inside
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        int startX = (screenWidth - grid.cols * grid.cellSize) / 2;
        int startY = (screenHeight - grid.rows * grid.cellSize) / 2;

        if (mouseX >= startX && mouseX < startX + grid.cols * grid.cellSize &&
            mouseY >= startY && mouseY < startY + grid.rows * grid.cellSize) {
            int col = (mouseX - startX) / grid.cellSize;
            int row = (mouseY - startY) / grid.cellSize;

            // Draw highlight box
            DrawRectangle(startX + col * grid.cellSize, startY + row * grid.cellSize, grid.cellSize, grid.cellSize, Fade(BLUE, 0.3f));

            // Draw col and row text
            char text[20];
            sprintf(text, "Col: %d, Row: %d", col, row);
            DrawText(text, startX + col * grid.cellSize + 5, startY + row * grid.cellSize + 5, 20, BLACK);
        }

        class Block {
        public:
            int x, y;
            int size;
            Color color;

            Block(int x, int y, int size, Color color) : x(x), y(y), size(size), color(color) {}

            virtual void Draw() {
                DrawRectangle(x, y, size, size, color);
            }
        };

        class Water : public Block {
        public:
            Water(int x, int y, int size) : Block(x, y, size, BLUE) {}

            void Draw() override {
                Block::Draw();
                // Additional drawing logic for Water if needed
            }
        };

        class Obstacle : public Block {
        public:
            Obstacle(int x, int y, int size) : Block(x, y, size, GRAY) {}

            void Draw() override {
                Block::Draw();
                // Additional drawing logic for Obstacle if needed
            }
        };

        // Example usage
        Water waterBlock(startX + 2 * grid.cellSize, startY + 3 * grid.cellSize, grid.cellSize);
        Obstacle obstacleBlock(startX + 4 * grid.cellSize, startY + 5 * grid.cellSize, grid.cellSize);

        waterBlock.Draw();
        obstacleBlock.Draw();
        

    EndDrawing();
    //----------------------------------------------------------------------------------  
}