#ifndef _PID_POSITION_H_
#define _PID_POSITION_H_

//位置式PID
class PID_Position
{
private:
	double kp;		//比例系数
	double ki;		//积分系数
	double kd;		//微分系数
	double T;		//运行周期
	double target;	//目标值
	double actual;	//实际值
	double err;		//误差
	double err_pre;	//上一次误差
	double integral;	//积分项
public:
	PID_Position();
	PID_Position(double p, double i, double d, double t);
	~PID_Position();
	void set(double p, double i, double d, double t);
	double pid_control(double tar, double act);			//执行PID控制
	double ShowKp();
	double ShowKi();
	double ShowKd();
	double ShowT();
};

#endif //_PID_POSITION_H_