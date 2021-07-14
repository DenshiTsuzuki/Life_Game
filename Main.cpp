#pragma once
#include <Siv3D.hpp>
#include"TaskSystem.h"
#include"Task_Game.h"
/*	
	ライフゲーム制作
	タスクシステムテスト
		
	
*/
void Main()
{
	//シーンサイズ変更
	const int s_x = 960;
	const int s_y = 540;
	Scene::Resize(s_x, s_y);
	Window::Resize(s_x, s_y);

	//初期で生成するタスクを書く
	auto st = Task_Game::Object::Create();

	while (System::Update())
	{
		ML::Task_System.Update();
		ML::Task_System.Draw();
	}

	ML::Task_System.AllDeleteTask();
}

