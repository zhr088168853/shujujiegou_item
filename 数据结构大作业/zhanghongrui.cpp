#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include<time.h>

void LogIn();  //快递员登陆操作函数
void YongHu();  //用户取快递函数
void Send();  //快递员派送快递函数
void Request();  //快递员查询快递函数
void Get();  //快递员取出快递函数
int GetNumber();  //获取随机数（即获取6位数的取件码）
int Getlen(int zhr[100]);  //计算快递柜的快递数量的函数，一个取件码对应一个快递
char txt[]=".txt";  //存储文本文件后缀名
int a;  //此变量为一个输入变量
int mc=0;  //此变量用于判断是否取出快递，若mc==1则取出快递
int zhang=0;  //此变量用于判断是否退出查询，若zhang==1时表示退出查询
bool flag;  //判断是否继续执行do while循环
int middlelen,biglen;  //分别存储中格口和大格口快递柜的快递数量
char num[20],type[10];  //数组num为存储取件码对应的字符数组,type为格口类型
//int middlebag[100]={0},bigbag[100]={0};  //这两个数组分别用于存储中格口和大格口对应快递的取件码
//char middlecall[100][20]={0},bigcall[100][20]={0};  //这两个数组分别用于存储中格口和大格口对应快递的手机号码
int middlebag[100]={111111,222222},bigbag[100]={555555,666666};  //在中格口和大格口快递柜事先存入两个快递
char middlecall[100][20]={{"13824817868"},{"13702688760"}},bigcall[100][20]={{"13824817868"},{"13702688760"}};  //在中格口和大格口快递柜里的快递对应的手机号码
//int middlebag[100]={0,111111,0,0,222222},bigbag[100]={0,0,555555,666666,0};  //中格口快递柜的2号和5号格口有快递，大格口快递柜的3号和4号格口有快递
//char middlecall[100][20]={{},{"16666666666"},{},{},{"19999999999"}},bigcall[100][20]={{},{},{"16666666666"},{"19999999999"},{}};

int main()  //主函数
{   
	do{
		printf("………………欢迎使用洪瑞智能快递柜………………\n");
		printf("………………………1.快递员…………………………\n");
		printf("………………………2.用户……………………………\n");
	do{
		printf("请选择您的身份：");
		scanf("%d",&a);
		switch(a){
		case 1:
			LogIn();  //快递员登陆操作函数
			break;
		case 2:
			YongHu();  //用户取快递函数
			break;
		default:printf("请在1-2之间选择\n");
				flag=true;
		}
		break; //退出do……while循环
	}while(flag);
	printf("当前在首页，退出程序请按0，继续操作请按其他数字键：");
	scanf("%d",&a);
	if(a==0)
		flag=false;
	else 
		flag=true;
	}while(flag);	
return 0;
}

void LogIn(){          //快递员登陆操作函数
int i = 0;
char id[10]={0},password[10] = { 0 };
while (i < 3)
{
printf("请输入账号：");
scanf("%s",id);
printf("请输入密码:");
scanf("%s", password);
printf("");
if (strcmp(id, "088168") == 0 && strcmp(password, "888888") == 0)
{
        printf("登录成功\n\n");
do{
        printf("……………………快递员欢迎您……………………\n");
		printf("……………………1.派送快递………………………\n");
		printf("……………………2.查询快递柜格口使用状态……\n");
		printf("……………………3.取出快递………………………\n");
	do{
		printf("请选择操作：");
		scanf("%d",&a);
		switch(a){
			case 1:
				Send();
				break;
			case 2:
				Request();			
				break;
			case 3:
				Get();
				break;
			default:printf("请在1-3之间选择\n");
					flag=true;
		}
		break; //退出do……while循环
	}while(flag);
	printf("当前在快递员页面，返回首页请按0，继续快递员操作请按其他数字键：");
	scanf("%d",&a);
	if(a==0)
		flag=false;
	else 
		flag=true;
	}while(flag);
break;  //退出while循环
}        //if语句结束处
else
{
printf("账号或密码不正确！\n");
i++;
if (i != 3)
printf("再输入一次\n");
}
}//while循环结束处
if (i == 3)
printf("密码错误三次退出登录界面\n");
}


void YongHu(){      //用户取快递函数
	 printf("\n……………………欢迎您提取快递……………………\n");
	do{
		char call[100][20];//存储手机号码
		int pi;  //判断手机号是否还有取件码未取
		printf("请输入格口类型(中格口/大格口)：");
		scanf("%s",type);
	 if(strcmp(type,"中格口")==0||strcmp(type,"大格口")==0){
		 printf("格口类型输入成功！\n");
		if(strcmp(type,"中格口")==0){
		 do{		
			 pi=0;
		 printf("请输入中格口的取件码：");
		 scanf("%d",&a);
		 if(strlen(itoa(a,num,10))==6){     //取件码有6位数字,itoa()函数是将十进制的整数转换为字符串
			int i;
		 printf("输入成功！\n");
		 for(i=0;i<100;i++){
			 if(middlebag[i]==a){				 
				 middlebag[i]=0;  //取出快递
				 mc=1;            //取出快递成功
				 int q;
				 for(q=0;q<20;q++){
					 call[i][q]=middlecall[i][q];  //取出手机号码存进call数组,后续与middlecall数组比较是否还有快递未取
					 middlecall[i][q]=0;  //在middlecall数组中将取件码对应位置的元素删掉（即删掉手机号码）
				 }
				 for(int j=0;j<100;j++){				
					 if(strcmp(middlecall[j],call[i])==0){ 	//在middlecall数组中将剩余元素依次和之前存进call数组的手机号码比较是否相等，若相等则该手机号码用户还有快递未取			 
							 pi=1;  //提示还有快递未取	
							 break;							 										 
					 }	
				 }			 
				 break;
			 }      //判断是否找到取件码的if语句结束处 
			}      //for循环结束处		  
				  if(i==100)
					printf("该取件码对应的快递不存在或错误输入了大格口的取件码！\n");
				  else{		//mc==1,找到取件码，成功取出快递			  
						printf("中格口快递柜%d号格口打开成功，快递已取出！中格口快递柜%d号格口处于未使用状态！\n",(i+1),(i+1));
						if(pi==1)
						    printf("尊敬的用户，您还有快递未取完，请尽快取出！\n");
						else
							printf("尊敬的用户，您的快递已取完，感谢您使用洪瑞智能快递柜！\n");					  
				  }				 
				 printf("继续在中格口快递柜取件请按1，返回上一级或在大格口快递柜取件请按其他数字键:");
				 scanf("%d",&a);
				if(a==1)
					flag=true;
			    else
					flag=false;			 
		  }	     //判断取件码是否有6位数字的if语句结束处
		 else{
			  printf("格口类型输入有误！\n");
			  printf("继续在中格口快递柜取件请按1，返回上一级或在大格口快递柜取件请按其他数字键:");
			  scanf("%d",&a);
			if(a==1)
				flag=true;
			else
			 flag=false;
		 }
	}while(flag);
		 }  //判断格口类型为中格口的if语句结束处
	else if(strcmp(type,"大格口")==0){
		 do{		
			 pi=0;
		 printf("请输入大格口的取件码：");
		 scanf("%d",&a);
		 if(strlen(itoa(a,num,10))==6){     //取件码有6位数字
			int i;
		 printf("输入成功！\n");
		 for(i=0;i<100;i++){
			 if(bigbag[i]==a){
				 bigbag[i]=0;  //取出快递
				 mc=1;         //取出快递成功
				 int q;
				 for(q=0;q<20;q++){
					 call[i][q]=bigcall[i][q];  //将手机号码存进call数组
					 bigcall[i][q]=0;  //在bigcall数组中将取件码对应位置的元素删掉（即删掉手机号码）
				 }				
				 for(int j=0;j<100;j++){				
					 if(strcmp(bigcall[j],call[i])==0){ 	//在middlecall数组中将每个元素依次和之前存进call数组的手机号码比较是否相等，若相等则该手机号码用户还有快递未取			 
							 pi=1;  //提示还有快递未取	
							 break;							 										 
					 }	
				 }			 
				 break;
			 }  //判断格口类型为大格口的if语句结束处
			}      //for循环结束处
			  if(i==100)
					printf("该取件码对应的快递不存在或错误输入了中格口的取件码！\n");
			  else{		//mc==1,找到取件码，成功取出快递			  
						printf("大格口快递柜%d号格口打开成功，快递已取出！大格口快递柜%d号格口处于未使用状态！\n",(i+1),(i+1));
						if(pi==1)
						    printf("尊敬的用户，您还有快递未取完，请尽快取出！\n");
						else
							printf("尊敬的用户，您的快递已取完，感谢您使用洪瑞智能快递柜！\n");					  
				  }				 
				 printf("继续在大格口快递柜取件请按1，返回上一级或在中格口快递柜取件请按其他数字键:");
				 scanf("%d",&a);
				if(a==1)
					flag=true;
			    else
					flag=false;			 
		  }	     //判断取件码是否有6位数字的if语句结束处
		 else{
			  printf("格口类型输入有误！\n");
			  printf("继续在大格口快递柜取件请按1，返回上一级或在中格口快递柜取件请按其他数字键:");
			  scanf("%d",&a);
			if(a==1)
				flag=true;
			else
			 flag=false;
		 }
	}while(flag);
		 }   //判断格口类型为大格口的else if语句结束处
	 }  //判断刚开始输入的格口类型是否合法的if语句（中格口/大格口）
	 else{
		 printf("格口类型输入有误！\n");
		 printf("重新输入请按1，返回上一级请按其他数字键：:");
		 scanf("%d",&a);
		 if(a==1)
			 flag=true;
		 else
			 flag=false;
	 }
	}while(flag);
}


void Send(){      //快递员派送快递函数
	int callnumber;  //callnumber用于存储取件码
	do{
	char phone[20];//phone[20]存储手机号码
	FILE *f;
	char *p;  //用来存储手机号码
	printf("\n请输入用户手机号：");
	scanf("%s",phone);	
	if(strlen(phone)==11){
	printf("输入成功！\n");
	printf("请输入需要的格口类别（中格口/大格口）：");
	scanf("%s",type);
	if(strcmp(type,"中格口")==0||strcmp(type,"大格口")==0){
	printf("输入成功！\n");
	callnumber=GetNumber();  //获取取件码存到callnumber变量，callnumber变量即代表取件码
	printf("取件码为：%d\n",callnumber);
	itoa(callnumber,num,10);  //将十进制的数字callnumber转换成字符数组num，用于后续写进文件
	p=phone;  //p变量指向phone，p变量即代表电话号码
	if(strcmp(type,"中格口")==0){
		int sum=0;
		if(middlebag[0]==0){ //若中格口无快递
		middlebag[sum]=callnumber; //将取件码存进去									
		strcpy(middlecall[sum],p);  //将手机号码存进去，一个手机号码对应一个取件码
		printf("取件码对应的包裹已成功存入格口\n");
		printf("中格口快递柜的%d号位置已占用\n",(sum+1));		
		}	
		else{  //若中格口已经有快递
			for(int j=0;j<100;j++){
			if(middlebag[j]!=0)
				sum=sum+1;	//找出数组元素为0的数组下标，即找到空格口的位置
			else
				break;
			}	
			middlebag[sum]=callnumber; //存入快递
			strcpy(middlecall[sum],p);  //将手机号码存进去
			printf("取件码对应的包裹已成功存入格口\n");
			printf("中格口快递柜的%d号位置已占用\n",(sum+1));	
			}
		//在这里求出middlebag数组的实际长度
		middlelen=Getlen(middlebag);
		printf("中格口快递柜的快递数量为:%d\n",middlelen);
	}
	else if(strcmp(type,"大格口")==0){
		int sum=0;
		if(bigbag[0]==0){
			bigbag[sum]=callnumber;
			strcpy(bigcall[sum],p);  //将手机号码存进去
			printf("取件码对应的包裹已成功存入格口\n");
			printf("大格口快递柜的%d号位置已占用\n",(sum+1));			
		}	
		else{
			for(int j=0;j<100;j++){
			if(bigbag[j]!=0)
				sum=sum+1;	//找到空格口的位置
			else
				break;
			}	
			bigbag[sum]=callnumber;
			strcpy(bigcall[sum],p);  //将手机号码存进去
			printf("取件码对应的包裹已成功存入格口\n");
			printf("大格口快递柜的%d号位置已占用\n",(sum+1));	
			}
		biglen=Getlen(bigbag);  //在这里求出bigbag数组的实际长度
		printf("大格口快递柜的快递数量为:%d\n",biglen);
	}
	if((f=fopen(strcat(phone,txt),"a"))==NULL){  //将快递信息写进文件
		printf("cannot open file!\n");
		exit(0);  
	}	
	char ing[]="尊敬的";
	char ang[]="用户!";
	char str[]="您好！您的快递已放入洪瑞智能快递柜，请速取，取件码为";
	char t[]=",格口类别为";
	fputs("\r\n",f);   //在文本文件中换行用"\r\n"
	fputs(ing,f);
	fputs(p,f);  //电话号码
	fputs(ang,f);
	fputs(str,f);
	fputs(num,f);  //取件码
	fputs(t,f);
	fputs(type,f);  //格口类型
	fputs("\r\n",f);      
	fclose(f);
	printf("取件码发送成功！\n");
	printf("按0退出，继续派送请按其他数字键：");
	scanf("%d",&a);
	if(a==0)		
		flag=false;	
	else
		flag=true;		
	}      //判断格口是否输入正确的if语句结束处
	else{              //格口输入不正确执行
		printf("输入格口类别有误，请重新输入\n");
		flag=true;
	}
	}      //判断手机号码是否输入正确的if语句结束处
	else{             //手机号码输入不正确执行
		printf("输入手机号码有误，请重新输入\n");
		flag=true;
	}
	}while(flag);
}

void Request(){     //快递员查询快递函数
	do{
		printf("请输入需要的格口类别（中格口/大格口）：");
		scanf("%s",type);
	if(strcmp(type,"中格口")==0||strcmp(type,"大格口")==0){
		printf("输入成功！\n");
		if(strcmp(type,"中格口")==0){
			int sum=0;
			for(int i=0;i<100;i++){
				if(middlebag[i]!=0){
					printf("中格口快递柜的%d号位置处于使用状态！\n",(i+1));
				    sum=sum+1;    //统计快递数目
					if(sum==100)
						printf("中格口快递柜格口已满！\n");
				}
			}	
			for(int j=0;j<middlelen;j++){  //查询在中格口快递柜的快递被收取的情况，因为存储快递按顺序存储，存储完成后求出middlelen,所以在middlelen范围内若有数组元素为0，则对应的快递已被取出
				if(middlebag[j]==0)
					printf("中格口快递柜%d号格口快递已被取出!\n",(j+1));
			}
			printf("中格口快递柜已使用%d个格口,剩余%d个格口未使用！\n",sum,(100-sum));
		}
		else if(strcmp(type,"大格口")==0){
			int sum=0;
			for(int i=0;i<100;i++){
				if(bigbag[i]!=0){
					printf("大格口快递柜的%d号位置处于使用状态！\n",(i+1));
				    sum=sum+1;
					if(sum==100)
						printf("大格口快递柜格口已满！\n");
				}			
			}	
			for(int j=0;j<biglen;j++){  //查询在大格口快递柜的快递被收取的情况
				if(bigbag[j]==0)
					printf("大格口快递柜%d号格口快递已被取出!\n",(j+1));
			}
			printf("大格口快递柜已使用%d个格口,剩余%d个格口未使用！\n",sum,(100-sum));
		}
			printf("按0退出查询，继续查询请按其他数字键：");
			scanf("%d",&a);
			if(a==0){		
				flag=false;	
				zhang=1;  //zhang==1时表示退出查询
			}
			else
				flag=true;
	}      //if语句结束处
	else{
		printf("输入格口类别有误，请重新输入\n");
		flag=true;
	}
	}while(flag);	
}


void Get(){   //快递员取出快递函数
	do{	
		FILE *file;
		char ting[20];//定义一个字符数组使数组与pi联系起来
		char *pi;
		pi=ting;  //pi是指向字符数组的指针，则pi可以存储数组元素
		Request();  //首先查询哪些快递柜格口有快递
		if(zhang==1){  //执行完Request()函数并退出查询后zhang==1
		printf("查询结束！\n");
		do{
		int i=0,f=0;  //i为格口号,f表示格口是否有快递
		printf("请输入待取出快递的格口类型：");
		scanf("%s",type);
		if(strcmp(type,"中格口")==0||strcmp(type,"大格口")==0){
		printf("格口类型输入成功！\n");
		if(strcmp(type,"中格口")==0){		
		 do{		
		 printf("请输入中格口的格口号：");
		 scanf("%d",&i);
		 if(i>=1&&i<=100){  //格口号从1到100
			  if(middlebag[i-1]!=0){  //格口号对应的格口有快递
				  middlebag[i-1]=0;  //取出快递
				  pi=middlecall[i-1];  //取出对应的电话号码，用pi接收
				  mc=1;  //取出快递成功			 
				 if(mc==1){  
					 char pl[20];  //待复制写到文件的数组
					 strcpy(pl,pi);
					 printf("中格口快递柜%d号格口打开成功，快递已取出！中格口快递柜%d号格口处于未使用状态！\n",i,i);
				 //在这里将通知信息写入文件（即通知用户）
				 if((file=fopen(strcat(pi,txt),"a"))==NULL){  //这里的pi已变成pi.txt字符串
					printf("cannot open file!\n");
					exit(0);  
					}	
					char ing[]="尊敬的";
					char ang[]="用户!";
					char str[]="您好！由于您的快递已超过24小时未领取，快递员已帮您取出，取件码已失效，请您尽快到服务前台凭手机号领取。";
				 fputs("\r\n",file);   //在文本文件中换行用"\r\n"
				 fputs(ing,file);
				 fputs(pl,file);  //写入手机号码
				 fputs(ang,file);
				 fputs(str,file);
				 fputs("\r\n",file);   //在文本文件中换行用"\r\n"
				 fclose(file);
				 printf("快递员取出快递的相关信息已成功通知用户！\n");
				 printf("继续在中格口快递柜取件请按1，返回上一级或在大格口快递柜取件请按其他数字键:");
				 scanf("%d",&a);
				if(a==1)
					flag=true;
				else
					flag=false;
				 }
			  }
			  else if(middlebag[i-1]==0){  //格口号对应的格口无快递
				  f=0;  //若格口号对应的格口为空，则f==0
				  if(f==0){
					   printf("%d号格口为空！\n",i);
					   printf("继续在中格口快递柜取件请按1，返回上一级或在大格口快递柜取件请按其他数字键:");
					   scanf("%d",&a);
					if(a==1)
						flag=true;
					else
						flag=false;
				  }
			  }
		 }
		 else{
			 printf("输入格口号有误!请重新输入!\n");
			 flag=true;
		 }
		 }while(flag);  //flag=false时跳到这里
		}  //判断格口类型是否为中格口的if语句结束处
	else if(strcmp(type,"大格口")==0){		
		 do{		
		 printf("请输入大格口的格口号：");
		 scanf("%d",&i);
		 if(i>=1&&i<=100){
			  if(bigbag[i-1]!=0){  //大格口的格口号有快递
				  bigbag[i-1]=0;  //取出快递
				  pi=bigcall[i-1];  //取出电话号码
				  mc=1;  //取出快递成功			 
				 if(mc==1){  
				 char pl[20];  //待复制写到文件的数组
				 strcpy(pl,pi);
				 printf("大格口快递柜%d号格口打开成功，快递已取出！大格口快递柜%d号格口处于未使用状态！\n",i,i);
				 //在这里将通知信息写入文件（即通知用户）
				  if((file=fopen(strcat(pi,txt),"a"))==NULL){  //这里的pi已变成pi.txt字符串
					printf("cannot open file!\n");
					exit(0);  
					}	
					char ing[]="尊敬的";
					char ang[]="用户!";
					char str[]="您好！由于您的快递已超过24小时未领取，快递员已帮您取出，取件码已失效，请你尽快到服务前台凭手机号领取。";
				 fputs("\r\n",file);   //在文本文件中换行用"\r\n"
				 fputs(ing,file);
				 fputs(pl,file);
				 fputs(ang,file);
				 fputs(str,file);
				 fputs("\r\n",file);   //在文本文件中换行用"\r\n"
				 fclose(file);
				 printf("快递员取出快递的相关信息已成功通知用户！\n");
				 printf("继续在大格口快递柜取件请按1，返回上一级或在中格口快递柜取件请按其他数字键:");
				 scanf("%d",&a);
				if(a==1)
					flag=true;
				else
					flag=false;
				 }
			  }
			  else if(bigbag[i-1]==0){  //大格口的格口号无快递
				  f=0;  //若格口号对应的格口为空，则f==0
				  if(f==0){
					   printf("%d号格口为空！\n",i);
					   printf("继续在大格口快递柜取件请按1，返回上一级或在中格口快递柜取件请按其他数字键:");
					   scanf("%d",&a);
					if(a==1)
						flag=true;
					else
						flag=false;
				  }
			  }
		 }
		 else{
			 printf("输入格口号有误!请重新输入!\n");
			 flag=true;
		 }
		 }while(flag);  //flag=false时跳到这里
		}  //判断格口类型是否为大格口的if语句结束处
		}  //判断格口类型是否输入有误的if语句结束处（中格口/大格口）
		else{
		 printf("格口类型输入有误！\n");
		 printf("重新输入请按1，返回上一级请按其他数字键:");
		 scanf("%d",&a);
		 if(a==1)
			 flag=true;
		 else
			 flag=false;
	 }
		}while(flag);
		}  //判断是否查询成功的if语句结束处
	else{
			printf("查询失败！返回上一级请按0，继续操作请按其他数字键：");
			scanf("%d",&a);
			if(a==0)		
				flag=false;			
			else
				flag=true;
		}
	}while(flag);
}     


int GetNumber(){      //获取取件码函数
	int number=0,m=100000,n=999999;    //产生100000-999999之间的数
	srand((unsigned)time(NULL));        //使用 rand() 生成随机数之前需要用随机发生器的初始化函数
		                          //srand(unsigned seed)进行伪随机数序列初始化，seed 又叫随机种子，
								  //意思就是如果每次提供的 seed 是一样的，那么每一轮生成的几个随机值也都是一样的，
								  //通常在C语言中我们使用时间函数time（null)来作为seed,因为时间值每秒都不同,所产生的数也随之不同
	number=rand()%(n-m+1)+m;       //其原理为，对于任意数，0<=rand()%(n-m+1)<=n-m于是0+m<=rand()%(n-m+1)+m<=n-m+m即m<=rand()%(n-m+1)+m<=n,rand()%10可产生10以内的数（不包括10）
	return number;                //rand()%100+1产生1-100以内的数
}

int Getlen(int zhr[100]){  //计算快递柜的快递数量的函数
	int sum=0;
	for(int i=0;i<100;i++){
		if(zhr[i]!=0)
			sum=sum+1;
	}
	return sum;
}