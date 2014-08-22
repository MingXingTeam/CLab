// 编写函数strrindex(s,t)，它返回字符串t在s最右边出现的位置。如果s中不包含t，则返回-1。

int strrindex(char *s, char *t){
	int flag,i,j,tmpI,tmpJ;
	char *tmp;
	int result=-1;

	for(i=0,j=0;s[i];i++){
		if(s[i]==t[j]){
			tmpI = i;
			tmpJ = j;


			flag = 1;
			while(t[tmpJ]){
				if(s[tmpI++]!=t[tmpJ++]){
					flag = 0;
					break;
				}
			}
			if(flag){
				result = i;
			}
		}
	}
	return result>=0?result:-1;
}

int main(void){
	char s[]={"adfasfasf"};
	char t[]={"asf"};

	printf("%d\n",strrindex(s,t));

	getchar();
	return 0;
}