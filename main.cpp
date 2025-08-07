#include<raylib.h>
#include<string>
using namespace std;

int main() {
	int length = 800;
	int width = 800;
	InitWindow(width, length, "Star Game");
	int Xstar = GetRandomValue(0, 800);
	int Ystar = 5;
	int Xbasket = 400;
	int Ybasket = 750;
	bool starCheck = true;
	int score = 0;
	bool check = true;
	string sc;
	bool permission = false;
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		sc = to_string(score);
		DrawText("score : ", 10, 10, 20, DARKGRAY);
		DrawText(sc.c_str(), 10, 30, 20, DARKGRAY);
		ClearBackground(BLACK);
		DrawRectangleLines(Xbasket, Ybasket, 50, 50, RED);
		DrawRectangleLines(Xbasket + 5, Ybasket + 5, 45, 45, RED);
		DrawRectangleLines(Xbasket + 10, Ybasket + 10, 40, 40, RED);
		if (IsKeyDown(KEY_LEFT) && Xbasket  >= 0) {
			Xbasket -= 5;
		}
		if (IsKeyDown(KEY_RIGHT) && Xbasket + 50 <= width) {
			Xbasket += 5;
		}
		if (starCheck) {
			DrawRectangle(Xstar, Ystar, 30, 30, BLUE);
			Ystar += 3;
			if (Ystar >= 800) {
				while(1){
					BeginDrawing();
					DrawText("Score: ", 300, 400, 20, RED);
					DrawText(sc.c_str(), 340, 450, 20, RED);
					DrawText("Press ESC to EXIT", 300, 500, 20, RED);
					DrawText("Press P to PLAY", 300, 550, 20, RED);
					if (IsKeyDown(KEY_ESCAPE)) {
						permission = false;
						break;
					}
					if (IsKeyDown(KEY_P)) {
						permission = true;
						score = 0;
						Xstar = GetRandomValue(0,800);
						Ystar = 0;
						break;
					}
					EndDrawing();
				}
				if (permission)
					continue;
				else
					break;
			}
		}
		Rectangle basket = { Xbasket,Ybasket,50,50 };
		Rectangle star = { Xstar,Ystar,30,30 };
		if (CheckCollisionRecs(basket, star)) {
			score++;
			Xstar = GetRandomValue(0, 800);
			Ystar = 0;
		}
		

		

		
		
		EndDrawing();
	}
	CloseWindow();
}