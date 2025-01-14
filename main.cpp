#include <Novice.h>
#include <math.h>
#include "Constant.h"
#include "./Class/Object/Player/Player.h"
#include "./Class/Object/Enemy/Enemy.h"

const char kWindowTitle[] = "LC1C_20_フクダソウワ_PG2_13-1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kScreenWitdh, kScreenHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	/*---------------
	    変数を作る
	---------------*/

	// 敵
	Enemy* enemy[2];
	enemy[0] = new Enemy(320.0f, 360.0f, -4.0f, 0.0f, 16.0f);
	enemy[1] = new Enemy(960.0f, 180.0f, 4.0f, 0.0f, 16.0f);

	// プレイヤー
	Player* player = new Player(640.0f, 540.0f, 32.0f);


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

		// 操作する
		player->Operation(keys , preKeys);

		// 弾を動かす
		for (int i = 0; i < kPlayerBulletNum; i++)
		{
			player->bullet[i]->Move();
		}

		// 敵を復活させる
		Enemy::Respawn(keys, preKeys);

		// 敵を動かす
		enemy[0]->Move();
		enemy[1]->Move();

		// プレイヤーの弾 と 敵
		for (int i = 0; i < kPlayerBulletNum; i++)
		{
			if (player->bullet[i]->isShot_)
			{
				for (int j = 0; j < 2; j++)
				{
					if (enemy[j]->isArrival_)
					{
						if (powf(player->bullet[i]->radius_ + enemy[j]->radius_, 2) >=
							powf(enemy[j]->pos_.x - player->bullet[i]->pos_.x, 2) + powf(enemy[j]->pos_.y - player->bullet[i]->pos_.y, 2))
						{
							Enemy::GetHit();

							player->bullet[i]->isShot_ = false;
						}
					}
				}
			}
		}
		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/*-------------
		    描画する
		-------------*/

		// プレイヤー
		player->Draw();

		// プレイヤーの弾
		for (int i = 0; i < kPlayerBulletNum; i++)
		{
			player->bullet[i]->Draw();
		}

		// 敵
		enemy[0]->Draw();
		enemy[1]->Draw();

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


	/*--------------------------
	    インスタンスを削除する
	--------------------------*/

	// プレイヤー
	delete player;
	
	// 敵
	delete enemy[0];
	delete enemy[1];


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
