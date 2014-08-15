/**
* @desc 
	for(i=0;i<lim-1 && (c=getchar())!='\n' && c != EOF;++i)
		s[i] = c;
	不用&&和||写一个等价的for循环语句

  @我的理解：&&和if。。else的作用类似 
*/
//我的答案：
for(i = 0; i < lim - 1;){
	if((c = getchar()) != '\n'){
		if(c != EOF){
			s[i] = c;
			++i;
		}
	}
}

//书本答案
enum loop {NO, YES};
enum loop okloop = YES;
i = 0;
while(okloop == YES){
	if(i >= lim - 1)
		okloop= NO;
	else if((c = getchar()) == '\n')
		okloop = NO;
	else if(c == EOF)
		okloop = NO;
	else{
		s[i] = c;
		++i;
	}
}

// 总结：
// 感觉我的会更简单点