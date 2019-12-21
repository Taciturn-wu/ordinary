#include <stdio.h>
int main()
{
	//数组的地址是一个数组指针类型
    int a[5]={1,2,3,4,5};
    int *ptr=(int *)(&a+1);//&a指向数组a的开头,+1指向数组a的结尾.
    printf("%d,%d",*(a+1),*(ptr-1));//第二个元素地址解引用,ptr-1向前移动一个元素再解引用
}


struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;//这个结构体类型的指针变量　20
int main()
{
	p=(struct Test*)0x10000;
	printf("%p\n",p+0x1);//100014一个结构体指针+1就是加上20的十六进制14
	printf("%p\n",(unsigned long)p+0x1);//100001 十进制为1048576+1后1048577再转为十六进制
	printf("%p\n",(unsigned int*)p+0x1);//100004强转成整型指针，+1表示加上一个整型的大小
}

int main()
{
	int a[4]={1,2,3,4};//大端小端    01000000 02000000 03000000 04000000
	int *ptr1=(int *)(&a+1);//跳过整个数组,指向最后面
    int *ptr2=(int *)((int)a+1);//a指向数组首元素地址，地址+1向后偏移一个字节00000002,因为小端模式所以为02 00 00 00
    printf("%x,%x",ptr1[-1],*ptr2);//4,2000000　ptr1指向数组最后面，-1指向了4
}


int main(int argc, char * argv[])
{
    int a[3][2]={(0,1),(2,3),(4,5)};//逗号表达式,1,3,5,0,0,0
    int *p；
    p=a[0];//第一行第一个元素地址
    printf("%d",p[0]);//1
}


int main()
{
    int a[5][5];
    int(*p)[4];//p+1一次跳过四个整型
    p=a;
    printf("%p,%d\n",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);//FFFFFFFc,-4   *(*(p+4)+2)
 	//10000000 00000000 00000000 00000100
	//11111111 11111111 11111111 11111011
	//11111111 11111111 11111111 11111100
	// F    F   F    F   F    F    F  c(1100为十六进制12)    
}


int main()
{
    int aa[2][5]={1,2,3,4,5,6,7,8,9,10};
 	//1 2 3 4 5
	//6 7 8 9 10
    int *ptr1=(int *)(&aa + 1);//取二维数组地址+1指向10的后面
    int *ptr2=(int *)(*(aa + 1));//aa是首元素地址+1就指向了第二行开头再解引用相当于*(aa+1)=aa[1][0]
    printf("%d,%d",*(ptr1-1),*(ptr2 - 1));//10 5
 	//整型指针-1向前移动一位就指向10的地址再解引用
	//
}

int main()
{ 
	char *a[]={"work","at","aliba"};
	//该数组表示三个char*
	//char* 放的是字符串首字母地址
	char* *pa=a; 
	//pa指向第一个char*，即w的地址
	pa++;
	//pa+1跳过一个char*
	printf("%s\n",*pa);//将第二个char*地址的字符串解引用，即at
}

int main()
{
	char *c[]={"ENTER","NEW","POINT","FIRST"};
	//字符指针数组有四个元素
	//ENTER NEW POINT FIRST
	char**cp[]={c+3,c+2,c+1,c};
	//      c+3 　　　　　　　　　　　　　　 　　c+2　　　　　　　　　       c+1 　　　　　　　　　c
	//指向最后一个元素的起始地址　　　倒数第二个元素起始地址　　第二个元素起始地址　　第一个元素的起始地址
	char***cpp=cp;
	printf("%s\n",**++cpp);//POINT  先++cpp指向了c+2再解引用，c+2指向倒数第二个元素地址再解引用,打印该地址的字符串
	printf("%s\n",*--*++cpp+3);//ER  ++cpp指向c+1再解引用拿到了第二个元素的地址,再--指向了第一个元素(起始位置)，再解引用拿到该空间的内容,E的地址+3到了第二个E的地方
	printf("%s\n",*cpp[-2]+3);//ST  cpp[-2]=**(cpp-2)+3,cpp-2指向c+3再解引用拿到了最后一个元素地址再解引用拿到该空间的内容,F的地址+3
	printf("%s\n",cpp[-1][-1]+1);//EW  *(*(cpp-1)-1)+1 cpp-1指向c+2再解引用倒数第二元素地址-1拿到了第二元素地址再解引用拿到该空间的内容，N的地址+1
}


