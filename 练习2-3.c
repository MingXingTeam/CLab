// 编写htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀0x或0X）转换为与之等价的整型值。
//字符串中允许包含的数字包括：0-9、a~f以及A-F

//十六进制的字符串是什么样子的？？
//我觉得应该是这样的："0x12,3,0x24,。。。"
//转换为整型值应该是这样的："18,3,36..."
#include <stdio.h>
#include <string.h>
#include <Math.h>

void htoi(int *s){
	printf("%s\n", s[0]); return;
	int i,j,m,n=0;
	char tmp[20];
	int temp;

	for(i=0,j=0;s[i];i++){
		if (isdigit(s[i])){//如果是数字
			if(s[i] == 0){//并且是0
				if(s[i+1] == 'x' || s[i+1] == 'X'){//判断下一位是否是x或者X
					i++;continue;//跳过x或者X
				}	
			}else{
				tmp[j++] = s[i];
			}
		}else{
			for(temp=0,m=0;m<j;m++){
				temp += pow(16,j-1)*tmp[m];
				j--;
			}
			s[n++] = temp;

			//重置
			j = 0;
			n = 0;
		}
	}
}

int main(void){
	//int *s = "0x12,3,0x24";//常量 无法修改
	int s[100] = {"0x12","3","0x24"};
	//printf("%s\n",s[0]);
	htoi(s);
	getchar();
	return 0;
}
