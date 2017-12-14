#ifndef _ELBOW_H_
#define _ELBOW_H_

#include "PID_Position.h"

class Elbow
{
public:
	Elbow();
	~Elbow();
	void GetActualAngle(double InputAngle);//��ȡʵ�ʽǶ�ֵ��ת��Ϊ����ֵ
	//�������������������ѹֵ
	//a1����������һ�ߣ�a2����2������һ��
	void SetMuscleAboslute(double a1, double a2);//���þ��Ե�ѹֵ
	void SetTargetRad(double tarR);
	void SetTargetAngle(double tarA);
	void run();
	double ShowRad();//���ص�ǰ����ֵ
	double ShowAngle();
	double ShowM1();
	double ShowM2();

protected:
	const double pi;	//��ѧ����PI
	double angle;		//��ؽڽǶ�
	double rad;			//��ؽڻ����ƽǶ�
	double m1, m2;		//���������������ѹֵ��m1����������һ�ߣ�m2����2������һ��
	double tarRad;		//��ؽ�Ŀ��Ƕ�
	double pressure;	//��������ѹ��ֵ
	double maxout;		//��������������ѹ
	double minout;		//��������С�����ѹ
	PID_Position PID4Elbow;
};

#endif //_ELBOW_H_
