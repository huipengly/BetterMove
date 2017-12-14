#ifndef _ELBOW_H_
#define _ELBOW_H_

#include "PID_Position.h"

class Elbow
{
public:
	Elbow();
	~Elbow();
	void GetActualAngle(double InputAngle);//获取实际角度值并转换为弧度值
	//设置气动肌肉比例阀电压值
	//a1代表单个肌肉一边，a2代表2根肌肉一边
	void SetMuscleAboslute(double a1, double a2);//设置绝对电压值
	void SetTargetRad(double tarR);
	void SetTargetAngle(double tarA);
	void run();
	double ShowRad();//返回当前弧度值
	double ShowAngle();
	double ShowM1();
	double ShowM2();

protected:
	const double pi;	//数学常量PI
	double angle;		//肘关节角度
	double rad;			//肘关节弧度制角度
	double m1, m2;		//气动肌肉比例阀电压值，m1代表单个肌肉一边，m2代表2根肌肉一边
	double tarRad;		//肘关节目标角度
	double pressure;	//气动肌肉压力值
	double maxout;		//气动阀最大输出电压
	double minout;		//气动阀最小输出电压
	PID_Position PID4Elbow;
};

#endif //_ELBOW_H_
