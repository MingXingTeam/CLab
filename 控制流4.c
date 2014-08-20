// 在数的对二的补码表示中，编写的itoa函数不能处理最大的负数：-2^（字长-1）。
// 解释原因。修改函数，使任何机器上都可以打印最大的负数。

//原来的函数
//把数字转换为字符串
void itoa(int n,char s[]){
	int i,sign;
	if((sign=n)<0){
		n=-n;//这里有问题？ -128
	}
	i=0;
	do{
		s[i++] = n % 10 + '0';
	}while((n/=10)>0);
	if(sign<0){
		s[i++]='-';
	}
	s[i]='\0';
	reverse(s);
}

//我的修改
void itoa(int n,char s[]){
	int i,sign;
	if((sign=n)<0){
	}
	i=0;
	do{
		s[i++] = abs(n % 10) + '0';//加上一个取绝对值就ok了
	}while((n/=10)>0);
	if(sign<0){
		s[i++]='-';
	}
	s[i]='\0';
	reverse(s);
}
