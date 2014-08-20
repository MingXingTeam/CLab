// 编写expand(s1,s2),将字符串s1中类似于a-z一类的的速记符号在字符串s2
// 中扩展为等价的完整列表abc...xyz。该函数可以处理大小写字母和数字，
// 并可以处理a-b-c、a-z0-9、-a-z等类似情况。作为前导和尾随的-字符原样排印。
#include <ctype.h>
void expand(char s1[], char s2[]){
	int cnt,cnt2;
	int step = 'b'-'a';
	int step2 = '1'-'0';

	while(*s1){
		//a-z
		if(isalpha(*s1)){
			if(*(s1+1) == '-'){
				if(isalpha(*(s1+2)) && (cnt = *(s1+2)-*s1) > 0){
					*s2++ = *s1;
					while(cnt&&cnt--!=1){
						*s2++ = *s1 + step;
						step++;
					}
					s1+=2;
					continue;
				}
			}
		}
		//0-9
		if(isdigit(*s1)){
			if(*(s1+1) == '-'){
				if(isdigit(*(s1+2)) && (cnt2 = *(s1+2)-*s1) > 0){
					*s2++ = *s1;
					while(cnt2&&cnt2--!=1){
						*s2++ = *s1+step2;
						step2++;
					}
					s1+=2;
					continue;
				}
			}
		}	
		//其他情况	
		
			*s2++ = *s1++;	
		
	}
	*s2='\0';
}

void main(void){
	char s[100];
	char t[]="-a-b-c-a-z0-9";
	expand(t,s);
	printf("%s\n",s);
	getchar();
	return 0;
}