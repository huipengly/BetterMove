#include "PID_Position.h"
//位置PID
PID_Position::PID_Position()
{
	kp = 0;
	ki = 0;
	kd = 0;
	T = 0;
	target = 0;
	actual = 0;
	integral = 0;
	err = target - actual;
	err_pre = err;
}

PID_Position::PID_Position(double p, double i, double d, double t)
{
	kp = p;
	ki = i;
	kd = d;
	target = 0;
	actual = 0;
	integral = 0;
	T = t;
	err = target - actual;
	err_pre = err;
}

PID_Position::~PID_Position()
{
	
}

void PID_Position::set(double p, double i, double d, double t)
{
	kp = p;
	ki = i;
	kd = d;
	T = t;
}

double PID_Position::pid_control(double tar, double act)
{
	double u = 0;
	target = tar;
	actual = act;
	err = target - actual;
	integral += err;
	if(T != 0)//防止未初始化的对象调用
	{
		u = kp * err + ki * T * integral + kd / T * (err - err_pre);
	}
	err_pre = err;
	return u;
}

double PID_Position::ShowKp()
{
	return kp;
}

double PID_Position::ShowKi()
{
	return ki;
}

double PID_Position::ShowKd()
{
	return kd;
}

double PID_Position::ShowT()
{
	return T;
}