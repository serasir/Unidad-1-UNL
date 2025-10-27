#ifndef NDEBUG
#include <vld.h> 
#endif

#include "raylib.h"
#include <cstdio>

static const char* ColorToName(Color c)
{
    if (c.r == WHITE.r && c.g == WHITE.g && c.b == WHITE.b && c.a == WHITE.a) return "WHITE";
    if (c.r == BLACK.r && c.g == BLACK.g && c.b == BLACK.b && c.a == BLACK.a) return "BLACK";
    if (c.r == RED.r && c.g == RED.g && c.b == RED.b && c.a == RED.a)   return "RED";
    if (c.r == GREEN.r && c.g == GREEN.g && c.b == GREEN.b && c.a == GREEN.a) return "GREEN";
    if (c.r == BLUE.r && c.g == BLUE.g && c.b == BLUE.b && c.a == BLUE.a)  return "BLUE";
    if (c.r == DARKPURPLE.r && c.g == DARKPURPLE.g && c.b == DARKPURPLE.b && c.a == DARKPURPLE.a) return "DARKPURPLE";
    // Añade más comparaciones si usas otros colores predefinidos

    static char buf[64];
    std::snprintf(buf, sizeof(buf), "R=%u G=%u B=%u A=%u", c.r, c.g, c.b, c.a);
    return buf;
}

int main(void)
{
    InitWindow(800, 450, "Tomas Malisani, TP 3");

    SetTargetFPS(60);

	bool IsSweaping = false;
	Texture2D Sora = LoadTexture("Sora2D.png");
	Vector2 SoraPosition = { 100.0f, 100.0f };
	Vector2 SecondSoraPosition = { 400.0f, 100.0f };
	float SoraScale = 0.2f;
	float SecondSoraScale = 0.5f;
	Color MainSoraColor = WHITE;
    Color SecondSoraColor = BLUE;


    Color fondo = { 110, 100, 215, 255 };
    Color texto = DARKPURPLE;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(fondo);

        //SORA PRINCIPAL
        DrawTextureEx(Sora,(SoraPosition), 0.0f, SoraScale, MainSoraColor);
        //SORA SECUNDARIO
		DrawTextureEx(Sora, (SecondSoraPosition), 0.0f, SecondSoraScale, SecondSoraColor);

        //INFORMACION SORA PRINCIPAL
        DrawText(TextFormat("Posicion X= %.0f", SoraPosition.x), 10, 10, 20, WHITE);
        DrawText(TextFormat("Posicion Y= %.0f", SoraPosition.y), 10, 40, 20, WHITE);
        DrawText(TextFormat("Escala = %.1f", SoraScale),10, 70, 20, WHITE);
        DrawText(TextFormat("Color = %s",ColorToName(MainSoraColor)), 10, 100, 20, WHITE);

        //INFORMACION SORA SECUNDARIO
        DrawText(TextFormat("Posicion X= %.0f", SecondSoraPosition.x), 600, 10, 20, WHITE);
        DrawText(TextFormat("Posicion Y= %.0f", SecondSoraPosition.y), 600, 40, 20, WHITE);
        DrawText(TextFormat("Escala = %.1f", SecondSoraScale), 600, 70, 20, WHITE);
        DrawText(TextFormat("Color = %s", ColorToName(SecondSoraColor)), 600, 100, 20, WHITE);


        //APLICAR EFECTO AL SPRITE
        SetTextureFilter(Sora, TEXTURE_FILTER_BILINEAR);



        //MOVIMIENTO SPRITE 
        if (IsKeyDown(KEY_D)) 
        {
			SoraPosition.x += 5.0f;
        }
        if (IsKeyDown(KEY_A)) 
        {
			SoraPosition.x -= 5.0f;
        }
        if (IsKeyDown(KEY_W)) 
        {
			SoraPosition.y -= 5.0f;
        }
        if (IsKeyDown(KEY_S)) 
        {
			SoraPosition.y += 5.0f;
        }



        //MANTENER AL SPRITE DENTRO DE LA VENTANA
        if (SoraPosition.x < -25) 
        {
			SoraPosition.x = -25;
        }
        if (SoraPosition.x > 710) 
        {
			SoraPosition.x = 710;
        }
        if (SoraPosition.y > 355) 
        {
			SoraPosition.y = 355;
        }
        if (SoraPosition.y < -20) 
        {
			SoraPosition.y = -20;
        }


        //MOVIMIENTO SPRITE SECOIND SORA
        if (IsKeyDown(KEY_L))
        {
            SecondSoraPosition.x += 5.0f;
        }
        if (IsKeyDown(KEY_J))
        {
            SecondSoraPosition.x -= 5.0f;
        }
        if (IsKeyDown(KEY_I))
        {
            SecondSoraPosition.y -= 5.0f;
        }
        if (IsKeyDown(KEY_K))
        {
            SecondSoraPosition.y += 5.0f;
        }


        //MANTENER AL SPRITE 2 DENTRO DE LA VENTANA
        if (SecondSoraPosition.x < -25)
        {
            SecondSoraPosition.x = -25;
        }
        if (SecondSoraPosition.x > 710)
        {
            SecondSoraPosition.x = 710;
        }
        if (SecondSoraPosition.y > 355)
        {
            SecondSoraPosition.y = 355;
        }
        if (SecondSoraPosition.y < -20)
        {
            SecondSoraPosition.y = -20;
        }



        //CAMBIO DE PROPIEADES
        if (IsKeyPressed(KEY_SPACE) && IsSweaping==false) 
        {
            MainSoraColor = BLUE;
			SecondSoraColor = WHITE;
            SoraScale = 0.5f;
            SecondSoraScale = 0.2f;
			IsSweaping = true;
        }
        else if (IsKeyPressed(KEY_SPACE) && IsSweaping==true) 
        {
			MainSoraColor = WHITE;
            SecondSoraColor = BLUE;
            SoraScale = 0.2f;
            SecondSoraScale = 0.5f;
			IsSweaping = false;
		}
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

