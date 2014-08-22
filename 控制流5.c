// 编写itob函数(n,s,b)，将整数n转换为b为底的数，并将转换结果以字符的形式保存到字符串s中。
// 例如itob(n,s,16)把整数n格式化为十六进制整数保存在s中。

void itob(int n,char *s,int b){
	int i=0;
	int tmp=n;

	while( (tmp=tmp/b) >= b ){
		s[i++]='0' + n%b;
		n = tmp;
	}

	s[i++]=tmp+'0';
	s[i] = '\0';
	reverse(s);
}

int main(void){
	char s[100];
	itob(35,s,2);

	printf("%s\n",s);
	getchar();
	return 0;
}
