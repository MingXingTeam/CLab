// 对atof函数进行扩充，使它可以处理形如123.45e-6的科学表示法。
// 其中，浮点数后面可能会紧跟一个e或E以及一个指针（可能有正负号）


//把字符串转为相应的双精度浮点数
double atof(char *s){
	int i;
	double result=0;
	double result2=1;
	int tmp;
	int flag = 0;
	for(i=0;s[i];i++){
		if(flag){//小数
			result2 *= 10;
		}else{//整数
			if(s[i]=='.'){
				i++;
				flag = 1;
				continue;
			}	
		}
		tmp = s[i]-'0';
		result = result * 10 + tmp;
	}
	return result /= result2;
}

int main(void){
	printf("%.3f\n",atof("123.45"));
	getchar();
	return 0;
}