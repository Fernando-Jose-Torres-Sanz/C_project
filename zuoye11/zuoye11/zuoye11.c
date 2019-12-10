#include<stdio.h>
#include<stdlib.h>
//1.
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。


//杨辉三角
//int main(){
//	//利用二维数组打印杨辉三角
//	int arr[7][7] =  { 0 };
//	for (int row = 0; row < 7; ++row){
//		for (int col = 0; col < row ; ++col){
//			//将第一行与每一行的最后一个打印成1
//			if (col == 0 || row == col){
//				arr[row][col] = 1;
//			}
//			else {
//				//将其他部分打印出来
//				arr[row][col] = arr[row - 1][col] + arr[row - 1][col - 1];
//			}
//		        printf("%d ", arr[row][col]);
//		}
//		printf("\n");
//	}



	int a = 1;//用数字1代表A
	int b = 2;//用数字2代表B
	int c = 3;//用数字3代表C
	int d = 4;//用数字4代表D
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
								printf("a是第%d名\nb是第%d名\nc是第%d名\nd是第%d名\ne是第%d名\n", a, b, c, d, e);
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