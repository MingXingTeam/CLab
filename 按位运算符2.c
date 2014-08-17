// 编写一个invert(x,p,n),该函数返回对x执行下列操作后的结果值：将x中从第p位开始的n个位求反，x的其余各位保持不变。

void invert(unsigned x,int p,int n){
	// return (x | ~(~0 << n) << (p+1-n))//为1，保留了其他位
	//  	   &  (~x & ~(~0 << n) << (p+1-n));//取反的,其他的位为0

	return x ^ ~(~0 << n) << (p+1-n);
}