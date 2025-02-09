#include <Novice.h>
#include "Bullet.h"
#include "Constant.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bullet::Bullet()
{
	// 発射しているかどうか（発射フラグ）
	isShot_ = false;

	// 位置
	pos_ = { 0.0f , 0.0f };

	// 移動速度
	vel_ = { 0.0f , 0.0f };

	// 図形の半径
	radius_ = 8.0f;
}

Bullet::~Bullet()
{
	
}

/// <summary>
/// 発射する
/// </summary>
/// <param name="posX">X軸の位置</param>
/// <param name="posY">Y軸の位置</param>
void Bullet::Shot(float posX, float posY)
{

	// 発射する（発射フラグをtrueにする）
	isShot_ = true;
	// 位置
	pos_ = { posX , posY };

	// 上に発射する
	vel_ = { 0.0f , -8.0f };
}

/// <summary>
/// 動かす
/// </summary>
void Bullet::Move()
{
	// 発射されている（発射フラグがtrueである）ときに動かす
	if (isShot_)
	{
		pos_.x += vel_.x;
		pos_.y += vel_.y;

		// 画面外に出たら、弾が消える（発射フラグがfalseになる）
		if (pos_.x + radius_ < 0.0f || pos_.x - radius_ > static_cast<float>(kScreenWitdh) ||
			pos_.y + radius_ < 0.0f || pos_.y - radius_ > static_cast<float>(kScreenHeight))
		{
			isShot_ = false;
		}
	}
}

/// <summary>
/// 描画する
/// </summary>
void Bullet::Draw()
{
	// 発射されている（発射フラグがtrueである）弾を描画する
	if (isShot_)
	{
		Novice::DrawEllipse
		(
			static_cast<int>(pos_.x) , static_cast<int>(pos_.y) ,
			static_cast<int>(radius_) , static_cast<int>(radius_) , 
			0.0f , 0xFFFFFFFF , kFillModeSolid
		);
	}
}