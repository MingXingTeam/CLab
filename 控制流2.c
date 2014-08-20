// 编写escapse(s,t)，将字符串t复制到字符串s中，
// 并在复制的过程中将换行符、制表符等不可见字符分别转换为\n，\t等相应的可见的
// 转义字符序列。要求使用switch语句。

void escape(char *s, char *t){
	while(*t){
		switch(*t){
			case '\n':
				*s++ = '\\';
				*s++ = 'n';
				break;
			case '\t':
				*s++ = '\\';
				*s++ = 't';
				break;
			default:
				*s++ = *t++;
				break;
		}
	}
	*s = '\0';
}
//在复制过程中，将转义字符转为实际字符
void ctescape(char *s, char *t){
	while(*t){
		if(*t =='\\'){
			switch(*(t+1)){
				case 'n':
					*s++ = '\n';
					t = t + 2;
					break;
				case 't':
					*s++ = '\t';
					t = t + 2;
					break;
				default:
					*s++ = *t++;
					break;
			}
		}else{
			*s++ = *t++;
		}
	}
	*s = '\0';
}
void main(void){
	char s[100];
	char t[]="as\nfasd\\f";
	ctescape(s,t);
	printf("%s\n",s);
	getchar();
	return 0;
}