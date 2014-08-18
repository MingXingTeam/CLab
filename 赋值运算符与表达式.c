//统计x中值为1的二进制位数
int bitcount(int x){
	int count=0;

	while(x){
		if(!(~(~0<<1) & x)){//最右边为0
			x=x>>1;
		}else{
			x &= (x-1);
			x=x>>1;
			count++;
		}
	}

	return count;
}

int main(void){
	printf("%d\n",bitcount(0x60));
	getchar();
	return 0;
}