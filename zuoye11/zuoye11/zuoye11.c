#include<stdio.h>
#include<stdlib.h>
//1.
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�


//�������
//int main(){
//	//���ö�ά�����ӡ�������
//	int arr[7][7] =  { 0 };
//	for (int row = 0; row < 7; ++row){
//		for (int col = 0; col < row ; ++col){
//			//����һ����ÿһ�е����һ����ӡ��1
//			if (col == 0 || row == col){
//				arr[row][col] = 1;
//			}
//			else {
//				//���������ִ�ӡ����
//				arr[row][col] = arr[row - 1][col] + arr[row - 1][col - 1];
//			}
//		        printf("%d ", arr[row][col]);
//		}
//		printf("\n");
//	}



	int a = 1;//������1����A
	int b = 2;//������2����B
	int c = 3;//������3����C
	int d = 4;//������4����D
	for (int murderer = 1; murderer <= 4; ++murderer){
		if (((murderer != 1) + (murderer == 3) + (murderer == 4) + (murderer != 4)) == 3){
			printf("%d\n",murderer);
		}
	}


	/*for (int a = 1; a < 6; ++a){
		for (int b = 1; b < 6; ++b){
			for (int c = 1; c < 6; ++c){
				for (int d = 1; d < 6; ++d){
					for (int e = 1; e < 6; ++e){
						if ((a + b + c + d + e == 15) && (a*b*c*d*e == 120)){
							if (((b == 2)+  (a == 3) == 1) && ((b == 2)  + (e == 4) == 1) && ((c == 1) + (d == 2) == 1)
								&& ((c == 5) +( d == 3) == 1) && ((e == 4) + (a == 1) == 1)){
								printf("a�ǵ�%d��\nb�ǵ�%d��\nc�ǵ�%d��\nd�ǵ�%d��\ne�ǵ�%d��\n", a, b, c, d, e);
							}		
					 }
						
					}
				}
			}
		}
	}*/
	system("pause");
	return 0;
}