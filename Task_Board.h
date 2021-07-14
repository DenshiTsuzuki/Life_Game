#pragma once
#include<Siv3D.hpp>
#include"TaskSystem.h"

namespace Board	{
	//タスクに割り当てるグループネームと固有名
	const string defGroupName("ボード");
	const string defTaskName("ボード");

	//--------------------------------------------------------------------------------------------------------
	//リソース管理
	class Resorce {
	public:
		using WP = weak_ptr<Resorce>;
		using SP = shared_ptr<Resorce>;
		
	
		//インスタンス
		static WP instance;

		//コンストラクタ！
		Resorce();

		//デストラクタ！
		~Resorce();

		//リソース生成
		static Resorce::SP Create();

	//-----------------------------------------------------
	//						追加変数　
	//-----------------------------------------------------
	
	};

	//------------------------------------------------------------------------------------------------------
	class Object : public BTask {
	
	public:
		using WP = weak_ptr<Object>;
		using SP = shared_ptr  <Object>;
		//デストラクタ！
		~Object();

		//生成したリソースへのアクセス
		Resorce::SP res;

		//生成する
		static Object::SP Create();
	
		//コンストラクタ！
		Object();

		//初期化
		void Init()override;
		
		//終了処理
		void Finalize()override;

		//更新
		void Update()override;

		//描画
		void Draw()override;

	//-----------------------------------------------------
	//				追加変数　追加メソッド
	//-----------------------------------------------------
	private:
		#define _arrLeg_X 48
		#define _arrLeg_Y 27
	public:
		//矩形表示用
		Rect _cell;

		//矩形サイズ
		int _size;

		//表示
		int _arr[_arrLeg_Y][_arrLeg_X];
		int _cpy_arr[_arrLeg_Y][_arrLeg_X];

		//実行間隔変更
		int _cnt;

		//周りを見る
		int CheckAround(int x_,int y_);

	};

};

