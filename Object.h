#pragma once
#include "Image.h"

/*
ģ���� : ʵ����
�ļ��� : Object.h
����ļ� : Image.h
�ļ�ʵ�ֹ��� :��Ϊֲ���࣬��ʬ�࣬�ӵ����������ĸ��࣬�洢����ͼ��Ѫ����λ������ڵ���Ϣ��
				�����ṩ�����ֳ�ʼ����������������ͼ�ĳ�Ա���������ֳ�ʼ�����������͸���
				������get��set����
*/

class Object
{
	public:		
		Object(int po_x , int po_y , int hp=0 , const Image other = Image("1.jpg"), const Image other_bk = Image("1.jpg"));												//���ֳ�ʼ����ʽ��ʼ����Ա����staMapping��staMapping_bk

		int getHealthPoint();
		void setHealthPoint(int hp);
														//Ѫ����get��set����
		int getPozition_x() const;
		void setPozition_x(int po_x);
														//����x��get��set����
		int getPozition_y() const;
		void setPozition_y(int po_y);
				
		virtual ~Object();							    //����������

		virtual void update() = 0;
		virtual void show() = 0;

	protected:
		int healthPoint;								//ʵ�����Ѫ���������ӵ��಻����Ѫ��
		int position_x;
		int position_y;									//ʵ�����λ�ã�x��y���꣩
		Image staMapping;								//��̬��ͼ
		Image staMapping_bk;							//��̬����ͼ
};