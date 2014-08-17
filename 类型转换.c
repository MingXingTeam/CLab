// 编写htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀0x或0X）转换为与之等价的整型值。
//字符串中允许包含的数字包括：0-9、a~f以及A-F

//十六进制的字符串是什么样子的？？
//我觉得应该是这样的："0x12"
//转换为整型值应该是这样的："18"
#include <stdio.h>
#include <Math.h>
//我的答案
// int htoi(char *s){
// 	int i,j,m,n=0;
// 	char tmp[20];
// 	int temp;
// 	//保存为：['1','2']
// 	for(i=0,j=0;s[i];i++){
// 		if (isdigit(s[i])){//如果是数字
// 			if(s[i] == 0){//并且是0
// 				if(s[i+1] == 'x' || s[i+1] == 'X'){//判断下一位是否是x或者X
// 					i++;continue;//跳过x或者X
// 				}	
// 			}else{
// 				tmp[j++] = s[i];
// 			}
// 		}
// 	}
// 	//计算结果：18
// 	for (temp = 0, m = 0; m<j; m++){
// 		temp += pow(16, j - m - 1)*(tmp[m] - '0');
// 	}
// 	return temp;
// }

//书本答案
#define YES 1
#define NO 0
int htoi(char s[]){
	int hexdigit,i,inhex,n;

	i=0;
	if(s[i] == '0'){//跳过0x和0X
		++i;
		if(s[i]=='x' || s[i] == 'X')
			++i;
	}

	n = 0;//保存返回的结果
	inhex = YES;//判断是有效的16进制数
	for(;inhex==YES;++i){
		if(s[i]>='0'&&s[i]<='9'){
			hexdigit = s[i] - '0';
		}else if(s[i] >= 'a' && s[i] <= 'f'){
			hexdigit = s[i] - 'a' + 10;
		}else if(s[i] >= 'A' && s[i] <= 'F'){
			hexdigit = s[i] - 'A' + 10;
		}else{
			inhex = NO;
		}
		if(inhex == YES){
			n = 16 * n + hexdigit;
		}
	}
	
	return n;
}


int main(void){
	char *s = "1021";
	printf("%d\n",htoi(s));
	//if ('\0'){ printf("adf"); }
	getchar();
	return 0;
}

// 总结几点：
// 1.char *s = "ba"和int *a = "ba";不要混淆了
// 2.'0'是true而'\0'是false
// 3.常量字符串无法修改

// 跳过0x和0X放在循环外面  这点比我好
// 我忘记处理a和A的情况了；忘记判断是否是16进制数字这个逻辑
// n = 16 * n + hexdigit;这个逻辑比我没有想到。这个应该是数学上的特性。
// 任何一个数字：比如是10进制的125 =（（10*0+1）*10+2）*10+5 
// 都是这种形式：n = 进制 * n + 数字 有多少位就计算多少次这个运算