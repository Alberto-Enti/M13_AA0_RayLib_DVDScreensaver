#include "raylib.h"
#include "vector"
#include "string"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

bool ColorEquals(Color c1, Color c2) {
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}

Color GetRandomColor(Color actual, std::vector<Color> colors) {
    Color tmp;
    do {
        tmp = colors[GetRandomValue(0, colors.size() - 1)];
    } while (ColorEquals(tmp, actual));
    return tmp;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int bounceCounter = 0;
    int textWidth;
    int posY = 200;
    int posX = 190;
    std::vector<Color> colorArray = { RED, GREEN ,BLUE, MAGENTA, YELLOW, SKYBLUE };
    Color actualColor;
    float speed = 100;
    short dirY = 1;
    short dirX = 1;
    float deltaTime;
    Vector2 textureSize;
    Vector2 position = {screenWidth/2, screenHeight/2};
    std::string textContent;
    Texture2D dvdLogo;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    textWidth = MeasureText("Congrats! You created your first window!", 20);
    dvdLogo = LoadTexture("rayLibDVD.png");
    actualColor = BLUE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        textContent = "Bounces: " + std::to_string(bounceCounter);
        deltaTime = GetFrameTime();
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        if (position.x < 0 || position.x + dvdLogo.width*.5f > screenWidth) {
            dirX = -dirX;
            actualColor = GetRandomColor(actualColor,colorArray);
            bounceCounter++;
        }
        
        
        if (position.y < 0 || position.y + dvdLogo.height*.5f> screenHeight) {
            dirY = -dirY;
            actualColor = GetRandomColor(actualColor,colorArray);
            bounceCounter++;
        }

        position.x += dirX * speed * deltaTime;
        position.y += dirY * speed * deltaTime;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(textContent.c_str(), 0, 0, 20, Color{ 255, 255, 255, 50 });
        DrawTextureEx(dvdLogo, position, 0, .5f, actualColor);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}