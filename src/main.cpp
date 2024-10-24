#include <raylib.h>
#include <libavutil/imgutils.h>

int main()
{
	const double aspect_ratio = 16 / 9;
	const int screenHeight = 900;
	const int screenWidth = 1600;

	InitWindow(screenWidth, screenHeight, "Animation");
    Camera2D camera2d = { 0 };

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = { 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        //DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        //DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

        DrawGrid(100, 1.0f);

        EndMode3D();



        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
