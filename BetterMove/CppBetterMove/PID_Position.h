#ifndef _PID_POSITION_H_
#define _PID_POSITION_H_

//λ��ʽPID
class PID_Position
{
private:
	double kp;		//����ϵ��
	double ki;		//����ϵ��
	double kd;		//΢��ϵ��
	double T;		//��������
	double target;	//Ŀ��ֵ
	double actual;	//ʵ��ֵ
	double err;		//���
	double err_pre;	//��һ�����
	double integral;	//������
public:
	PID_Position();
	PID_Position(double p, double i, double d, double t);
	~PID_Position();
	void set(double p, double i, double d, double t);
	double pid_control(double tar, double act);			//ִ��PID����
	double ShowKp();
	double ShowKi();
	double ShowKd();
	double ShowT();
};

#endif //_PID_POSITION_H_