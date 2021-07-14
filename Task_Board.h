#pragma once
#include<Siv3D.hpp>
#include"TaskSystem.h"

namespace Board	{
	//�^�X�N�Ɋ��蓖�Ă�O���[�v�l�[���ƌŗL��
	const string defGroupName("�{�[�h");
	const string defTaskName("�{�[�h");

	//--------------------------------------------------------------------------------------------------------
	//���\�[�X�Ǘ�
	class Resorce {
	public:
		using WP = weak_ptr<Resorce>;
		using SP = shared_ptr<Resorce>;
		
	
		//�C���X�^���X
		static WP instance;

		//�R���X�g���N�^�I
		Resorce();

		//�f�X�g���N�^�I
		~Resorce();

		//���\�[�X����
		static Resorce::SP Create();

	//-----------------------------------------------------
	//						�ǉ��ϐ��@
	//-----------------------------------------------------
	
	};

	//------------------------------------------------------------------------------------------------------
	class Object : public BTask {
	
	public:
		using WP = weak_ptr<Object>;
		using SP = shared_ptr  <Object>;
		//�f�X�g���N�^�I
		~Object();

		//�����������\�[�X�ւ̃A�N�Z�X
		Resorce::SP res;

		//��������
		static Object::SP Create();
	
		//�R���X�g���N�^�I
		Object();

		//������
		void Init()override;
		
		//�I������
		void Finalize()override;

		//�X�V
		void Update()override;

		//�`��
		void Draw()override;

	//-----------------------------------------------------
	//				�ǉ��ϐ��@�ǉ����\�b�h
	//-----------------------------------------------------
	private:
		#define _arrLeg_X 48
		#define _arrLeg_Y 27
	public:
		//��`�\���p
		Rect _cell;

		//��`�T�C�Y
		int _size;

		//�\��
		int _arr[_arrLeg_Y][_arrLeg_X];
		int _cpy_arr[_arrLeg_Y][_arrLeg_X];

		//���s�Ԋu�ύX
		int _cnt;

		//���������
		int CheckAround(int x_,int y_);

	};

};

