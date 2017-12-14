#include "Elbow.h"

Elbow::Elbow() : pi(3.14159)
{
	//肘关节初始化参数
	m1 = 0;
	m2 = 0;
	angle = 0;
	rad = 0;
	maxout = 5;
	minout = 0;

	//肘关节PID初始化参数
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
	/* 电压值转换，直接抄的计量程序 */
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

/* 下面的代码是放在CycleUpdate函数所在的类里的 */
/* CModule1改为CycleUpdate函数所在类的类名 *****/
/* m_Outputs.m1Int这些改为所链接的变量名 *******/
////void CModule1::ElbowUpdateInputs()
////{
////	//elbow.GetAngle(m_Inputs.Angle - 270);//不受力状态时，角度为270，减去，角度会增大//旧的肘
////
////	elbow.GetActualAngle(350 - m_Inputs.Angle);//不受力状态时，角度为350，减去，角度会减少//新的肘
////
////}
////
////void CModule1::ElbowUpdateOutputs()
////{
////	/* 输出给EL4004，用来控制比例压力阀。压力阀接收电压为0-10V */
////	//电压转换为（0-10V）->（0-32767）
////	m_Outputs.m1Int = static_cast<int>(elbow.ShowM1() / 10 * 32767);
////	m_Outputs.m2Int = static_cast<int>(elbow.ShowM2() / 10 * 32767);
////
////	/* 输出个PLC用来观察的 */
////	m_Outputs.rad = elbow.ShowRad();
////	m_Outputs.tarrad = SetRad;
////	m_Outputs.m1v = elbow.ShowM1();
////	m_Outputs.m2v = elbow.ShowM2();
////}
