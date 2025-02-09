#include <Novice.h>
#include "Constant.h"
#include "Enemy.h"

// 出現しているかどうか（出現フラグ）
int Enemy::isArrival_ = true;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="posX">X軸の位置</param>
/// <param name="posY">Y軸の位置</param>
/// <param name="velX">X軸の移動速度</param>
/// <param name="velY">Y軸の移動速度</param>
/// <param name="radius">図形の半径</param>
Enemy::Enemy(float posX, float posY, float velX, float velY, float radius)
{
	// 出現しているかどうか（出現フラグ）
	isArrival_ = true;

	// 位置
	pos_ = { posX , posY };

	// 移動速度
	vel_ = { velX , velY };

	// 図形の半径
	radius_ = radius;
}

/// <summary>
/// デストラクタ
/// </summary>
Enemy::~Enemy()
{
	
}

/// <summary>
/// 復活させる
/// </summary>
void Enemy::Respawn(const char* keys , const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}

	// Rキーで、敵を復活させる（出現フラグをtrueにする）
	if (!preKeys[DIK_R] && keys[DIK_R])
	{
		if (isArrival_ == false)
		{
			isArrival_ = true;
		}
	}
}

void Enemy::Move()
{
	// 出現している（出現フラグがtrueである）敵を動かす
	if (isArrival_)
	{
		pos_.x += vel_.x;
		pos_.y += vel_.y;

		// 画面端で跳ね返る
		if (pos_.x - radius_ < 0.0f || pos_.x + radius_ > static_cast<float>(kScreenWitdh))
		{
			vel_.x *= -1.0f;
		}

		if (pos_.y - radius_ < 0.0f || pos_.y + radius_ > static_cast<float>(kScreenHeight))
		{
			vel_.y *= -1.0f;
		}
	}
}

/// <summary>
/// 描画する
/// </summary>
void Enemy::Draw()
{
	// 出現している（出現フラグがtrueである）敵を描画する
	if (isArrival_)
	{
		Novice::DrawEllipse
		(
			static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, 0xFF0000FF, kFillModeSolid
		);
	}
}