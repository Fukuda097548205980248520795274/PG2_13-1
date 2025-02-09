#pragma once
#include "./Class/Object/Object.h"

class Bullet : public Object
{
public:

	// 発射されているかどうか（発射フラグ）
	int isShot_;
	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bullet();

	/// <summary>
	/// 発射する
	/// </summary>
	/// <param name="posX">X軸の位置</param>
	/// <param name="posY">Y軸の位置</param>
	void Shot(float posX , float posY);

	/// <summary>
	/// 動かす
	/// </summary>
	void Move();

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};

