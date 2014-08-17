// 编写一个函数，setbits(x,p,n,y)。返回对x执行下列操作的结果：将x中从第p位开始的n个位设置为y中最右边的值，其他的位不变。


//p是从右边开始计算的。而不是从有效位开始计算。（一开始我理解错误）

int getBitLen(int x){
	int a = (unsigned int)~0 & x;
	int len = 0;
	//while(a << 1){   错误
	do{
		len++;
	} while (a = (a >> 1));  

	return len;
}

int getIntBitLen(){
	int a = (unsigned int)~0;
	int len = 0;
	do{
		len++;
	} while (a = (a << 1));

	return len;
}

void setbits(int *x,int p,int n,int *y){
	int xLen = getBitLen(*x);
	int yLen = getBitLen(*y);
	
	//将要设置的bit位设置为0。其他位不变。
	unsigned int a = (unsigned int)~0 >> (getIntBitLen() - n);//000...11 右边留出n位
	unsigned int b = ~(a << (xLen - n - p)); //011000.... 
	*x = b & (*x);//..00.... 	 

	//将y最右边的保留，其他bit位设置为0。然后移到x需要重置的位置。
	//具体做法是：先~0左移取反，然后和y相&；将y左移，右移
	*y = (*y) & ~((unsigned int)~0 << n);
	*y = (*y) << (xLen - n);//
	*y = (*y) >> p;//这里可能会出现问题

 	//计算最后
	*x = (*x | *y);
}

int main(void){
	int x = 0xDF;//11011111
	int y = 0x37;//00110111
	
	//printf("%d\n",getBitLen());
	setbits(&x,1,2,&y);
	printf("%x\n",x);
	getchar();
	return 0;
}