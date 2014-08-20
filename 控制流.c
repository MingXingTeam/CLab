// 折半查找，使while内部只有两次测试
// int binsearch(int x, int v[], int n){
// 	int low = 0,high=n;
// 	int mid;
// 	while(low<=high){
// 		mid  = (low+high)/2;
// 		if(x > v[mid]){
// 			low = mid+1;
// 		}else if(x<v[mid]){
// 			high = mid-1;
// 		}else{
// 			return mid;
// 		}
// 	}
// 	return -1;
// }
//将while内的一个符合结束循环的条件移到while条件测试
int binsearch(int x, int v[], int n){
	int low = 0,high=n;
	int mid = (low+high)/2;
	while(low<=high && x != v[mid]){
		mid  = (low+high)/2;
		if(x > v[mid]){
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	if(x==v[mid]){
		return mid;
	}else{
		return -1;
	}
}




