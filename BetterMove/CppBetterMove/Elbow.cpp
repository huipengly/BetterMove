#include "Elbow.h"

Elbow::Elbow() : pi(3.14159)
{
	//��ؽڳ�ʼ������
	m1 = 0;
	m2 = 0;
	angle = 0;
	rad = 0;
	maxout = 5;
	minout = 0;

	//��ؽ�PID��ʼ������
	double kp = 1;
	double ki = 7.5;
	double kd = 0;
	double t = 0.01;
	PID4Elbow.set(kp, ki, kd, t);
}


Elbow::~Elbow()
{
}

void Elbow::GetActualAngle(double InputAngle)
{
	angle = InputAngle;
	rad = angle / 180 * pi;
}

void Elbow::SetMuscleAboslute(double a1, double a2)
{
	/* ��ѹֵת����ֱ�ӳ��ļ������� */
	m1 = (5.0/6.0)*5.5 - a1;
	m2 = a2;

	if (m1 > maxout)
	{
		m1 = maxout;
	}
	if (m1 < minout)
	{
		m1 = minout;
	}

	if (m2 > maxout)
	{
		m2 = maxout;
	}
	if (m2 < minout)
	{
		m2 = minout;
	}
}

void Elbow::SetTargetRad(double tarR)
{
	tarRad = tarR;
}

void Elbow::SetTargetAngle(double tarA)
{
	tarRad = tarA / 180.0 * pi;
}

void Elbow::run()
{
	pressure = PID4Elbow.pid_control(tarRad, rad);
	SetMuscleAboslute(pressure, pressure);
}

double Elbow::ShowRad()
{
	return rad;
}

double Elbow::ShowAngle()
{
	return angle;
}

double Elbow::ShowM1()
{
	return m1;
}

double Elbow::ShowM2()
{
	return m2;
}

/* ����Ĵ����Ƿ���CycleUpdate�������ڵ������ */
/* CModule1��ΪCycleUpdate��������������� *****/
/* m_Outputs.m1Int��Щ��Ϊ�����ӵı����� *******/
////void CModule1::ElbowUpdateInputs()
////{
////	//elbow.GetAngle(m_Inputs.Angle - 270);//������״̬ʱ���Ƕ�Ϊ270����ȥ���ǶȻ�����//�ɵ���
////
////	elbow.GetActualAngle(350 - m_Inputs.Angle);//������״̬ʱ���Ƕ�Ϊ350����ȥ���ǶȻ����//�µ���
////
////}
////
////void CModule1::ElbowUpdateOutputs()
////{
////	/* �����EL4004���������Ʊ���ѹ������ѹ�������յ�ѹΪ0-10V */
////	//��ѹת��Ϊ��0-10V��->��0-32767��
////	m_Outputs.m1Int = static_cast<int>(elbow.ShowM1() / 10 * 32767);
////	m_Outputs.m2Int = static_cast<int>(elbow.ShowM2() / 10 * 32767);
////
////	/* �����PLC�����۲�� */
////	m_Outputs.rad = elbow.ShowRad();
////	m_Outputs.tarrad = SetRad;
////	m_Outputs.m1v = elbow.ShowM1();
////	m_Outputs.m2v = elbow.ShowM2();
////}
