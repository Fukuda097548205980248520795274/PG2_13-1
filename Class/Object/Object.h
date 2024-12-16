#pragma once
#include "Structure.h"

class Object
{
public:

	// 位置
	struct Pos2 pos_;

	// 移動速度
	struct Vel2 vel_;

	// 図形の半径
	float radius_;

	/// <summary>
	/// 描画する
	/// </summary>
	virtual void Draw();
};

