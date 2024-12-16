#include <Novice.h>
#include <math.h>
#include "Constant.h"
#include "./Class/Object/Player/Player.h"
#include "./Class/Object/Enemy/Enemy.h"

const char kWindowTitle[] = "LC1C_20_フクダソウワ_PG2_13-1";

int Bullet::count;
int Enemy::count;
int Enemy::isArrival_;

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
	Enemy* enemyA = new Enemy(320.0f , 360.0f , -4.0f , 0.0f , 16.0f);
	Enemy* enemyB = new Enemy(960.0f, 180.0f, 4.0f, 0.0f, 16.0f);

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
		enemyA->Move();
		enemyB->Move();

		// プレイヤーの弾 と 敵
		for (int i = 0; i < kPlayerBulletNum; i++)
		{
			if (player->bullet[i]->isShot_)
			{
				// 敵A
				if (enemyA->isArrival_)
				{
					if (powf(player->bullet[i]->radius_ + enemyA->radius_, 2) >=
						powf(enemyA->pos_.x - player->bullet[i]->pos_.x, 2) + powf(enemyA->pos_.y - player->bullet[i]->pos_.y, 2))
					{
						Enemy::GetHit();

						player->bullet[i]->isShot_ = false;
					}
				}

				// 敵B
				if (enemyB->isArrival_)
				{
					if (powf(player->bullet[i]->radius_ + enemyB->radius_, 2) >=
						powf(enemyB->pos_.x - player->bullet[i]->pos_.x, 2) + powf(enemyB->pos_.y - player->bullet[i]->pos_.y, 2))
					{
						Enemy::GetHit();

						player->bullet[i]->isShot_ = false;
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
		enemyA->Draw();
		enemyB->Draw();

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

	delete player;
	delete enemyA;
	delete enemyB;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
