// 编写itoa函数，使得该函数可以接收三个参数。其中，第三个参数为最小字段宽度。
// 为了保证转换后所得的结果至少具有第三个参数指定的最小宽度，在必要时应在所得结果的
// 左边填充一定的空格。

//将数字转换为字符串。
void itoa(int x, char *s, int w){
	int tmp=x;
	int i=0;
	do{
		s[i++]=x%10 + '0';
		tmp = tmp/10;
		x = tmp;
	}while(tmp);

	//补空格
	while(i<w){
		s[i++] = ' ';
	}

	s[i]='\0';

	//reverse(s);
}

int main(void){
	char s[100];
	itoa(12,s,4);
	printf("%s\n",s);
	getchar();
	return 0;
}