// 将大写字母转为小写字母

char* toLowerCase(char *str){
	char *tmp = str;
	while(*tmp){
		if(isalpha(*tmp)){
			if(*tmp >= 'A' && *tmp <= 'Z'){
				(*tmp) = (*tmp) + ('a' - 'A');
			}
		}
		tmp++;
	}

	return str;
}

int main(void){
	char b[] = "aDDDasdf";
	printf("%s\n",toLowerCase(b));

	getchar();
	return 0;
}