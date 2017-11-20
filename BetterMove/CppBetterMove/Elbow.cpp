#include "Elbow.h"


Elbow::Elbow() : pi(3.14159f)
{
	m1 = 0;
	m2 = 0;
	angle = 0;
	rad = 0;
	float kp = 1;
	float ki = 7.5;
	float kd = 0;
	float t = 0.01;
	PID4Elbow.set(kp, ki, kd, t);
}


Elbow::~Elbow()
{
}

float Elbow::ShowRad()
{
	return rad;
}

float Elbow::ShowAngle()
{
	return angle;
}

float Elbow::ShowM1()
{
	return m1;
}

float Elbow::ShowM2()
{
	return m2;
}

void Elbow::GetAngle(float InputAngle)
{
	angle = InputAngle;
	rad = angle / 180 * pi;
}

void Elbow::SetMuscleRelative(float r1, float r2)
{
	m1 += r1;
	m2 += r2;

	if (m1 > 5)
	{
		m1 = 5;
	}
	if (m1 < 0)
	{
		m1 = 0;
	}

	if (m2 > 5)
	{
		m2 = 5;
	}
	if (m2 < 0)
	{
		m2 = 0;
	}

	//if (m1 > 10)
	//{
	//	m1 = 10;
	//}
	//if (m1 < 0)
	//{
	//	m1 = 0;
	//}

	//if (m2 > 10)
	//{
	//	m2 = 10;
	//}
	//if (m2 < 0)
	//{
	//	m2 = 0;
	//}
}

void Elbow::SetMuscleAboslute(float a1, float a2)
{
	m1 = (5.0/6.0)*5.5 - a1;
	m2 = a2;

	if (m1 > 5)
	{
		m1 = 5;
	}
	if (m1 < 0)
	{
		m1 = 0;
	}

	if (m2 > 5)
	{
		m2 = 5;
	}
	if (m2 < 0)
	{
		m2 = 0;
	}

	//if (m1 > 10)
	//{
	//	m1 = 10;
	//}
	//if (m1 < 0)
	//{
	//	m1 = 0;
	//}

	//if (m2 > 10)
	//{
	//	m2 = 10;
	//}
	//if (m2 < 0)
	//{
	//	m2 = 0;
	//}
}

void Elbow::SetTargetRad(float tar)
{
	tarRad = tar;
}

void Elbow::run()
{
	pressure = PID4Elbow.pid_control(tarRad, rad);
	SetMuscleAboslute(pressure, pressure);
}