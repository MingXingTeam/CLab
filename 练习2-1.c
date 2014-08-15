/**
* @desc:编写一个程序以确定分别由signed及unsigned限定的char、short、int
* 与long类型变量的取值范围。采用打印标准头文件中的相应值以及直接计算两种方式实现。
*/

#include <stdio.h>
#include <limits.h>
//标准头文件
void methodOne(){
	printf("signed char最大：%d；最小：%d\n",SCHAR_MAX,SCHAR_MIN);
	//printf("unsigned char最大：%d；最小：%d\n",UCHAR_MAX,UCHAR_MIN);错误。无符号最小值：UCHAR_MIN  不存在
	//printf("unsigned char最大：%d\n", UCHAR_MAX);和下面的一致。
	printf("unsigned char最大：%u\n", UCHAR_MAX);

	//printf("signed short最大：%d；最小：%d\n",SSHRT_MAX,SSHRT_MIN);错误。
	printf("signed short最大：%d；最小：%d\n", SHRT_MAX, SHRT_MIN);
	//printf("unsigned short最大：%d；最小：%d\n",USHRT_MAX,USHRT_MIN);错误。
	//printf("unsigned short最大：%d\n", USHRT_MAX);和下面的一致。
	printf("unsigned short最大：%u\n", USHRT_MAX);

	//printf("signed int最大：%d；最小：%d\n",SINT_MAX,SINT_MIN);错误。
	printf("signed int最大：%d；最小：%d\n", INT_MAX, INT_MIN);
	//printf("unsigned short最大：%d；最小：%d\n", USHRT_MAX, USHRT_MIN); 错误。
	//printf("unsigned short最大：%d\n", USHRT_MAX); 和下面的一致。
	printf("unsigned short最大：%u\n", USHRT_MAX);

	//printf("signed long最大：%ld；最小：%ld\n",SLONG_MAX,SLONG_MIN);错误。
	printf("signed long最大：%ld；最小：%ld\n", LONG_MAX, LONG_MIN);
	//printf("unsigned long最大：%ld；最小：%ld\n", ULONG_MAX, ULONG_MIN); 错误。
	//printf("unsigned long最大：%ld\n", ULONG_MAX);错误,结果为-1。不一致。应该用无符号输出。
	printf("unsigned long最大：%lu\n", ULONG_MAX);
}
//计算
void methodTwo(){
	//一开始我在想这个：~0  但是位数怎么确定？？我想到了sizeof,可以计算字节数  但是取字节数没用，没法截位数（没想到用强制类型转换）。
	//unsigned和signed怎么区分。一开始没想，因前面已经想不明白了。

	//正确的做法：利用强制类型
	//疑问：
	//1、强制类型转换的作用？？
	//强制类型转换是告诉编译器怎么处理。也就是上下文。
	//2、无符号没有最小值？
	//浮点类型？？


	signed char sChar_MAX = (signed char)((unsigned char)~0 >> 1);//011111....
	signed char sChar_MIN = -(signed char)((unsigned char)~0 >> 1);//10000...


	//这个是不对的 显然最大的无符号应该是：1111111
	//unsigned char uChar_MAX = (unsigned char)((unsigned char)~0 >> 1);
	//正确的应该是
	unsigned char uChar_MAX = (unsigned char)~0;

	//unsigned char uChar_MIN = -((unsigned char)~0);错误。


	signed short sShort_MAX = (short)((unsigned short)~0 >> 1);
	signed short sShort_MIN = -(short)((unsigned short)~0 >> 1);

	unsigned short uShort_MAX = (unsigned short)~0;
	//unsigned short uShort_MIN = -((unsigned short)~0);错误。

	signed int sInt_MAC = (int)((unsigned int)~0 >> 1);
	signed int sInt_MIN = (int)((unsigned int)~0 >> 1);

	unsigned int uInt_MAX = (unsigned int)~0;
	//unsigned int uInt_MIN = -(unsigned int)~0;错误。

	signed long sLong_MAX = (long)((unsigned long)~0 >> 1);
	signed long sLong_MIN = -(long)((unsigned long)~0 >> 1);

	unsigned long uLong_MAX = (unsigned long)~0;
	//unsigned long uLong_MIN = -(unsigned long)~0;错误。

	printf("signed char最大：%d；最小：%d\n",sChar_MAX,sChar_MIN);
	printf("unsigned char最大：%u\n",uChar_MAX);
	printf("signed short最大：%d；最小：%d\n",sShort_MAX,sShort_MIN);
	printf("unsigned short最大：%u\n",uShort_MAX);
	printf("signed int最大：%d；最小：%d\n",sInt_MAC,sInt_MAC);
	printf("unsigned int最大：%u\n",uInt_MAX);
	printf("signed long最大：%ld；最小：%ld\n",sLong_MAX,sLong_MIN);
	printf("unsigned long最大：%lu\n",uLong_MAX);
}
int main(void){
	methodOne();
	methodTwo();
	getchar();
}

// 总结几点：
// 1.无符号没有最小值。
// 2.强制类型转换很有用处，可以将一个数的上下文体现出来。
// 3.输出无符号数要用\u如果用\d，当数值超出了\d所能表示的最大正整数的范围就会得到-1的结果。