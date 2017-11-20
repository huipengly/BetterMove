#ifndef _PID_POSITION_H_
#define _PID_POSITION_H_

//位置式PID
class PID_Position
{
private:
	float kp;		//比例系数
	float ki;		//积分系数
	float kd;		//微分系数
	float T;
	float target;	//目标值
	float actual;	//实际值
	float err;		//误差
	float err_pre;	//上一次误差
	float integral;	//积分项
public:
	PID_Position();
	PID_Position(float p, float i, float d, float t);
	~PID_Position();
	void set(float p, float i, float d, float t);
	float pid_control(float tar, float act);			//执行PID控制
	float ShowKp();
};

#endif //_PID_POSITION_H_