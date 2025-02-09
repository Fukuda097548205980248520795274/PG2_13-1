#pragma once
#include "Constant.h"
#include "./Class/Object/Object.h"
#include "./Class/Object/Bullet/Bullet.h"

class Player : public Object
{
public:

	// 弾
	Bullet* bullet[kPlayerBulletNum];

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">X軸の位置</param>
	/// <param name="posY">Y軸の位置</param>
	/// <param name="radius">図形の半径</param>
	Player(float posX , float posY , float radius);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 操作する
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前のキー</param>
	void Operation(const char* keys , const char* preKeys);

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};
