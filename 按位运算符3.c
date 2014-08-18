// 编写函数rightrot(x,n),该函数返回将x循环右移n位后所得到的值

//计算字长
int getIntBit(){
	unsigned tmp = (unsigned)~0;
	int result = 0;
	do{
		result++;
	}while(tmp=(tmp<<1));
	return result;
}

int rightrot(int x,int n){
	int tmp = x;

	return ((~(~0 << n) & 1) & x) << (getIntBit() - n)
	 	   |  (tmp >> n);
}

int main(void){
	int a = 0x60;
	int result = rightrot(a,4);
	printf("%x\n",result);
	getchar();
	return 0;
}