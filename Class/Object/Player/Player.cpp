#include <Novice.h>
#include "Player.h"
#include "Constant.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="posX">X軸の位置</param>
/// <param name="posY">Y軸の位置</param>
/// <param name="radius">図形の半径</param>
Player::Player(float posX, float posY, float radius)
{
	// 位置
	pos_ = { posX , posY };

	// 移動速度
	vel_ = { 0.0f , 0.0f };

	// 図形の半径
	radius_ = radius;

	// 弾
	for (int i = 0; i < kPlayerBulletNum; i++)
	{
		bullet[i] = new Bullet();
	}
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
	for (int i = 0; i < kPlayerBulletNum; i++)
	{
		delete bullet[i];
	}
}

/// <summary>
/// 操作する
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前のキー</param>
void Player::Operation(const char* keys, const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}


	/*   移動操作   */

	// 移動速度を初期化する
	vel_ = { 0.0f , 0.0f };

	// Wキーで、上に移動する
	if (keys[DIK_W])
	{
		if (pos_.y - radius_ > 0.0f)
		{
			vel_.y = -4.0f;
		}
	}

	// Aキーで、左に移動する
	if (keys[DIK_A])
	{
		if (pos_.x - radius_ > 0.0f)
		{
			vel_.x = -4.0f;
		}
	}

	// Sキーで、下に移動する
	if (keys[DIK_S])
	{
		if (pos_.y + radius_ < static_cast<float>(kScreenHeight))
		{
			vel_.y = 4.0f;
		}
	}

	// Dキーで、右に移動する
	if (keys[DIK_D])
	{
		if (pos_.x + radius_ < static_cast<float>(kScreenWitdh))
		{
			vel_.x = 4.0f;
		}
	}

	// 動かす
	pos_.x += vel_.x;
	pos_.y += vel_.y;


	/*   発射操作   */

	// スペースキーで、弾を発射する
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE])
	{
		for (int i = 0; i < kPlayerBulletNum; i++)
		{
 			if (bullet[i]->isShot_ == false)
			{
				bullet[i]->Shot(pos_.x, pos_.y);

				break;
			}
		}
	}
}

/// <summary>
/// 描画する
/// </summary>
void Player::Draw()
{
	Novice::DrawEllipse
	(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xFFFF00FF, kFillModeSolid);
}