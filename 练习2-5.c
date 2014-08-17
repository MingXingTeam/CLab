// 编写any(s1,s2)，将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回。如果s1中不包含s2中的字符则返回-1

int any(char *s1,char *s2){
	int n = 0;

	for(;*s1;s1++){
		for(;*s2&&*s1!=*s2++;){
			n++;
		}
		if(!(*s2)){
			return -1;
		}else{
			return n;
		}
	}
}

int main(void){
	char s1[]={"abcd"};
	char s2[]={"gaggann"};
	printf("%d\n",any(s1,s2));
	getchar();
	return 0;
}