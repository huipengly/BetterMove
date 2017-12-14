#ifndef _KINEMATICS_H_
#define _KINEMATICS_H_


//#include "math.h"
#include <Fpu87.h>
//#include <stdio.h>
#include <string.h>   


#ifndef PI
#define PI 3.14159265358979
#endif




/************************************************
* �˶�ѧ����
* R[3][3]				3��3��ת����
* X[3]					�ѿ����ռ�xyzλ��(��λ��mm)
* joint[3]				�ؽڽǶȣ���λ���㣩
* kps[3]				��Чת��3������ת��
* Kine_Forward			�˶�ѧ���⣨��֪joint[3] -> ���X[3]��R[3][3]��
* Kine_Inverse			�˶�ѧ���⣨��֪X[3]��R[3][3] -> ���joint[3]��
* **********************************************/


double kinematics_forward(double* pos, double* R, double* r);
void kinematics_inverse(double x, double y, double phi, double* Ajoint);



#endif         /* KINEMATICS_H_ */