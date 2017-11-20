#ifndef _PID_POSITION_H_
#define _PID_POSITION_H_

//λ��ʽPID
class PID_Position
{
private:
	float kp;		//����ϵ��
	float ki;		//����ϵ��
	float kd;		//΢��ϵ��
	float T;
	float target;	//Ŀ��ֵ
	float actual;	//ʵ��ֵ
	float err;		//���
	float err_pre;	//��һ�����
	float integral;	//������
public:
	PID_Position();
	PID_Position(float p, float i, float d, float t);
	~PID_Position();
	void set(float p, float i, float d, float t);
	float pid_control(float tar, float act);			//ִ��PID����
	float ShowKp();
};

#endif //_PID_POSITION_H_