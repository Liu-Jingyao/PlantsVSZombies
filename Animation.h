#pragma once
#include <vector>
#include <string>
#include "Image.h"
#pragma comment(lib,"Winmm.lib")

/*
ģ���� : ������
�ļ��� : Animation.h
����ļ� : Animation.cpp
�ļ�ʵ�ֹ��� :��Ϊֲ���ʬ��Ļ��࣬��Ŷ���֡ͼ�������ṩ�Զ����¡���ʾ����֡ͼ�Ĺ��ܡ�
�÷�ʾ����
		class Plant : public Object, public Movable, public Animation 
		{
			...
			void show() {
				Animation::show(position_x, position_y);
			}
		}

		class PeaShooter : public Plant
		{
			PeaShooter(...)...{
				loadImages��"Plant\\PeaShooter\\", 12����
			}

		}
ע�����	��������һ�����ࣨ�����տ��ࣩ�Ĺ��캯���е���loadAnimation
			��ע��path�����ĸ�ʽ�����㶹���ֶ���·��Ϊ"images\\Plant\\PeaShooter\\1.jpg"...
			��pathӦ��д"Plant\\PeaShooter\\"
*/

class Animation
{
public:
	int getAnimationStatus() const;			    // ����״̬��get��set����
	void setAnimationStatus(int animationStatus);
	void randomAnimation();
protected:

	Animation(int s = 0, bool png = 0);			// ��ʼ�����������Ϊ����״̬�͡��Ƿ�Ϊpng��ʽ��
	void animationUpdate();					    // �������£����Զ����־�̬/��̬
	int animationStatus = 0;					// ����״̬��0 ��̬��1 ��̬
	std::vector<Image> Images;					// ����֡vector
	std::vector<Image> BackImages;				// ����֡vector
	std::vector<Image>::iterator ImageIter;		// ����������
	std::vector<Image>::iterator BackImageIter;	// �������ֲ������
	bool is_loadItertor = 0;					// �Ƿ��Ѽ��ص�����
	bool is_loadAnimation = 0;					// �Ƿ��Ѽ��ض���
	bool is_png;								//! �����Ƿ�Ϊpng��ʽ

	void loadAnimation(const std::string& path, int n, bool png = 0); // �����������
	void play(int x, int y);				    // ������ʾ�������������޲�show�����������������ṩ����
};
