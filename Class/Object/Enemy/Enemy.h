#pragma once
#include "./Class/Object/Object.h"

class Enemy : public Object
{
public:

	// 出現しているかどうか（出現フラグ）
	static int isArrival_;

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">X軸の位置</param>
	/// <param name="posY">Y軸の位置</param>
	/// <param name="velX">X軸の移動速度</param>
	/// <param name="velY">Y軸の移動速度</param>
	/// <param name="radius">図形の半径</param>
	Enemy(float posX, float posY, float velX, float velY, float radius);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Enemy();

	/// <summary>
	/// 復活させる
	/// </summary>
	static void Respawn(const char* keys, const char* preKeys);

	/// <summary>
	/// 動かす
	/// </summary>
	void Move();

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};

