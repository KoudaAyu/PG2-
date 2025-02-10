#include <Novice.h>
#include"Bullet.h"
#include"Conster.h"
#include"Distance.h"
#include"Enemy.h"
#include"Enumuration.h"
#include"Object.h"
#include"Player.h"
#include"Texture.h"
#include"Scene.h"


int gh;

const char kWindowTitle[] = "LC1B_09_コウダ_アユ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	gh = Novice::LoadTexture("white1x1.png");

	Player* player =new Player({640.0f,360.0f});

	Enemy* enemy[kMaxEnemies];
	for (int i = 0; i < kMaxEnemies; i++)
	{
		enemy[i] = new Enemy();
	}

	Scene* scene = new Scene();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (Scene::sceneNo_)
		{

		case SCENE_TITLE:
			
			scene->SetFrame(scene->GetFrame()+1);
			Novice::ScreenPrintf(0, 60, "PUSH SPACE KEYS");
			Novice::ScreenPrintf(0, 30, "Title");


			if (keys[DIK_SPACE] && scene->GetFrame() >= 120.0f)
			{
				Scene::sceneNo_ = SCENE_GAME;
				scene->SetFrame(0);
			}
			break;

		case SCENE_GAME:


			player->Move(keys);
			player->Draw();

			Novice::ScreenPrintf(0, 30, "GAME");

			for (int i = 0; i < kMaxBullet; i++)
			{
				for (int j = 0; j < kMaxEnemies; j++)
				{
					if (player->GetBullets()[i].GetIsActive() && enemy[j]->GetIsAlive())
					{
						if (CircleToCircle(player->GetBullets()[i].GetPos(), player->GetBullets()->GetRadius(), enemy[j]->GetPos(), enemy[j]->size_.x / 2))
						{
							player->GetBullets()[i].SetIsActive(false);
							enemy[j]->SetIsAlive(false);
							player->SetScore(player->GetScore() + 1);
						}
					}
				}
			}

			for (int i = 0; i < kMaxEnemies; i++)
			{
				if (player->GetIsAlive() && enemy[i]->GetIsAlive())
				{
					if (CircleToCircle(player->GetPos(),player->GetSize() / 2,enemy[i]->GetPos(),enemy[i]->size_.x / 2))
					{
						player->SetIsAlive(false);
						Scene::sceneNo_ = SCENE_GAMEOVER;
					}
				}
			}


			for (int i = 0; i < kMaxEnemies; i++)
			{
				enemy[i]->Update();
				enemy[i]->Draw();
			}

			if (player->GetScore() == kMaxEnemies)
			{
				Scene::sceneNo_ = SCENE_CLEAR;
			}

			break;

		case SCENE_CLEAR:
			
			Novice::ScreenPrintf(0, 30, "CLEAR");
			Novice::ScreenPrintf(0, 60, "PUSH SPACE KEYS");

			scene->SetFrame(scene->GetFrame() + 1);

			if (keys[DIK_SPACE] && scene->GetFrame() >= 60.0f)
			{
				Scene::sceneNo_ = SCENE_TITLE;
				scene->SetFrame(0);
			}

			break;

		case SCENE_GAMEOVER:
			
			Novice::ScreenPrintf(0, 30, "GAMEOVER");
			Novice::ScreenPrintf(0, 60, "PUSH SPACE KEYS");

			scene->SetFrame(scene->GetFrame() + 1);

			if (keys[DIK_SPACE] && scene->GetFrame() >= 60.0f)
			{
				Scene::sceneNo_ = SCENE_TITLE;
				scene->SetFrame(0);
			}

			break;
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
