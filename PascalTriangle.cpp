#include<iostream>
#include<cstring>
#include<string>
using namespace std;

struct bign{
	int d[100];
	int len;
	//下面定义构造函数，用来初始化！ 
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};

bign add(bign a,bign b){
	bign c;
	int carry=0;//这里的carry表示进位
	for(int i=0;i<a.len||i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	} 
	if(carry!=0){//如果最后一位的进位不为0，直接付给结果的最高位
	   c.d[c.len++] =carry;
	}
	return c;
};

bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-i-1]-'0';//这里把大整数的地位切换为高位 
	}
	return a; 
};
void print(bign a){
	for(int i=a.len-1;i>=0;i--)
	{
		printf("%d",a.d[i]);
	}
}

//比较大小
// int compare(bign a,bign b){
// 	if(a.len>b.len)return 1;//a大于b
// 	else if(a.len<b.len)return -1;//a<b
// 	else{
// 		for(int i=a.len-1;i>=0;i++){
// 			if(a.d[i]>b.d[i])return 1;
// 			else if(a.d[i]<b.d[i])return -1;
// 		}
// 		return 0;//两个数相等 
// 	} 
// };
// //减法
// bign sub(bign a,bign b){
// 	bign c;
// 	for(int i=0;i<a.len||i<b.len;i++){
// 		if(a.d[i]<b.d[i]) {//如果不够减法，则向高位借位 
// 			if(a.d[i+1]>0){
			
// 			a.d[i+1]--;
// 			a.d[i]+=10; 
// 		}
// 		}
// 		c.d[c.len++]=a.d[i]-b.d[i];
// 	}
// 	while(c.len-1>=1&&c.d[c.len-1]==0){
// 		c.len--;
// 	}//去除高位为0的！同时保留一个最低位 
// 	return c;
// };

// //高精度与低精度乘法运算规则
// bign multi(bign a,int b){
// 	bign c;
// 	int carry=0;
// 	for(int i=0;i<a.len;i++){
// 		int temp=a.d[i]*b+carry;
// 		c.d[c.len++]=temp%10;
// 		carry=temp/10;
// 	}
// 	while(carry!=0)
// 	{
// 		c.d[c.len++]=carry%10;
// 		carry/=10;
// 	}
// 	return c;
// };

// //高精度与低精度的除法

// bign divide(bign a,int b,int &r){//r为余数，这里表示为引用
//     bign c;
// 	c.len=a.len;
// 	for(int i=a.len-1;i>=0;i--){
// 		r=r*10+a.d[i];
// 		if(r<b) c.d[i]=0;
// 		else{
// 			c.d[i]=r/b;
// 			r=r%b;
// 		}
// 	} 
// 	while(c.len-1>=1&&c.d[c.len-1]==0){
// 		c.len--;
// 	}
// 	return c;
// } 

bign arr1[210];
bign arr2[210];
 
int main()
{
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	//char str1[1000],str2[1000];
	//scanf("%s%s",str1,str2);
	//bign a=change(str1);
	//bign b=change(str2);
	//print(add(a,b)); 
	cout<<"1"<<endl;
    int len=1;
    int count=0;
	char str1[1000];
	char str2[1000];
    while(1){
        len++;
        int i,j;
        cout<<"1 ";
		string s="1";
        strcpy(str1, s.c_str());//string转字符串
		bign a=change(str1);
		arr2[0]=a;
        for(i=1;i<len-1;i++){
            bign x=add(arr1[i-1],arr1[i]);
			arr2[i]=x;
            print(x);
            cout<<" ";
        }
		arr2[len-1]=a;
        cout<<"1"<<endl;

		for(i=0;i<len;i++)
			arr1[i]=arr2[i];

		count++;
        if(count>203)
            break;
    }
	return 0;
}
