#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include<time.h>

void LogIn();  //���Ա��½��������
void YongHu();  //�û�ȡ��ݺ���
void Send();  //���Ա���Ϳ�ݺ���
void Request();  //���Ա��ѯ��ݺ���
void Get();  //���Աȡ����ݺ���
int GetNumber();  //��ȡ�����������ȡ6λ����ȡ���룩
int Getlen(int zhr[100]);  //�����ݹ�Ŀ�������ĺ�����һ��ȡ�����Ӧһ�����
char txt[]=".txt";  //�洢�ı��ļ���׺��
int a;  //�˱���Ϊһ���������
int mc=0;  //�˱��������ж��Ƿ�ȡ����ݣ���mc==1��ȡ�����
int zhang=0;  //�˱��������ж��Ƿ��˳���ѯ����zhang==1ʱ��ʾ�˳���ѯ
bool flag;  //�ж��Ƿ����ִ��do whileѭ��
int middlelen,biglen;  //�ֱ�洢�и�ںʹ��ڿ�ݹ�Ŀ������
char num[20],type[10];  //����numΪ�洢ȡ�����Ӧ���ַ�����,typeΪ�������
//int middlebag[100]={0},bigbag[100]={0};  //����������ֱ����ڴ洢�и�ںʹ��ڶ�Ӧ��ݵ�ȡ����
//char middlecall[100][20]={0},bigcall[100][20]={0};  //����������ֱ����ڴ洢�и�ںʹ��ڶ�Ӧ��ݵ��ֻ�����
int middlebag[100]={111111,222222},bigbag[100]={555555,666666};  //���и�ںʹ��ڿ�ݹ����ȴ����������
char middlecall[100][20]={{"13824817868"},{"13702688760"}},bigcall[100][20]={{"13824817868"},{"13702688760"}};  //���и�ںʹ��ڿ�ݹ���Ŀ�ݶ�Ӧ���ֻ�����
//int middlebag[100]={0,111111,0,0,222222},bigbag[100]={0,0,555555,666666,0};  //�и�ڿ�ݹ��2�ź�5�Ÿ���п�ݣ����ڿ�ݹ��3�ź�4�Ÿ���п��
//char middlecall[100][20]={{},{"16666666666"},{},{},{"19999999999"}},bigcall[100][20]={{},{},{"16666666666"},{"19999999999"},{}};

int main()  //������
{   
	do{
		printf("��������������ӭʹ�ú������ܿ�ݹ񡭡���������\n");
		printf("������������������1.���Ա��������������������\n");
		printf("������������������2.�û�����������������������\n");
	do{
		printf("��ѡ��������ݣ�");
		scanf("%d",&a);
		switch(a){
		case 1:
			LogIn();  //���Ա��½��������
			break;
		case 2:
			YongHu();  //�û�ȡ��ݺ���
			break;
		default:printf("����1-2֮��ѡ��\n");
				flag=true;
		}
		break; //�˳�do����whileѭ��
	}while(flag);
	printf("��ǰ����ҳ���˳������밴0�����������밴�������ּ���");
	scanf("%d",&a);
	if(a==0)
		flag=false;
	else 
		flag=true;
	}while(flag);	
return 0;
}

void LogIn(){          //���Ա��½��������
int i = 0;
char id[10]={0},password[10] = { 0 };
while (i < 3)
{
printf("�������˺ţ�");
scanf("%s",id);
printf("����������:");
scanf("%s", password);
printf("");
if (strcmp(id, "088168") == 0 && strcmp(password, "888888") == 0)
{
        printf("��¼�ɹ�\n\n");
do{
        printf("�������������������Ա��ӭ������������������\n");
		printf("����������������1.���Ϳ�ݡ�����������������\n");
		printf("����������������2.��ѯ��ݹ���ʹ��״̬����\n");
		printf("����������������3.ȡ����ݡ�����������������\n");
	do{
		printf("��ѡ�������");
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
			default:printf("����1-3֮��ѡ��\n");
					flag=true;
		}
		break; //�˳�do����whileѭ��
	}while(flag);
	printf("��ǰ�ڿ��Աҳ�棬������ҳ�밴0���������Ա�����밴�������ּ���");
	scanf("%d",&a);
	if(a==0)
		flag=false;
	else 
		flag=true;
	}while(flag);
break;  //�˳�whileѭ��
}        //if��������
else
{
printf("�˺Ż����벻��ȷ��\n");
i++;
if (i != 3)
printf("������һ��\n");
}
}//whileѭ��������
if (i == 3)
printf("������������˳���¼����\n");
}


void YongHu(){      //�û�ȡ��ݺ���
	 printf("\n������������������ӭ����ȡ��ݡ���������������\n");
	do{
		char call[100][20];//�洢�ֻ�����
		int pi;  //�ж��ֻ����Ƿ���ȡ����δȡ
		printf("������������(�и��/����)��");
		scanf("%s",type);
	 if(strcmp(type,"�и��")==0||strcmp(type,"����")==0){
		 printf("�����������ɹ���\n");
		if(strcmp(type,"�и��")==0){
		 do{		
			 pi=0;
		 printf("�������и�ڵ�ȡ���룺");
		 scanf("%d",&a);
		 if(strlen(itoa(a,num,10))==6){     //ȡ������6λ����,itoa()�����ǽ�ʮ���Ƶ�����ת��Ϊ�ַ���
			int i;
		 printf("����ɹ���\n");
		 for(i=0;i<100;i++){
			 if(middlebag[i]==a){				 
				 middlebag[i]=0;  //ȡ�����
				 mc=1;            //ȡ����ݳɹ�
				 int q;
				 for(q=0;q<20;q++){
					 call[i][q]=middlecall[i][q];  //ȡ���ֻ�������call����,������middlecall����Ƚ��Ƿ��п��δȡ
					 middlecall[i][q]=0;  //��middlecall�����н�ȡ�����Ӧλ�õ�Ԫ��ɾ������ɾ���ֻ����룩
				 }
				 for(int j=0;j<100;j++){				
					 if(strcmp(middlecall[j],call[i])==0){ 	//��middlecall�����н�ʣ��Ԫ�����κ�֮ǰ���call������ֻ�����Ƚ��Ƿ���ȣ����������ֻ������û����п��δȡ			 
							 pi=1;  //��ʾ���п��δȡ	
							 break;							 										 
					 }	
				 }			 
				 break;
			 }      //�ж��Ƿ��ҵ�ȡ�����if�������� 
			}      //forѭ��������		  
				  if(i==100)
					printf("��ȡ�����Ӧ�Ŀ�ݲ����ڻ���������˴��ڵ�ȡ���룡\n");
				  else{		//mc==1,�ҵ�ȡ���룬�ɹ�ȡ�����			  
						printf("�и�ڿ�ݹ�%d�Ÿ�ڴ򿪳ɹ��������ȡ�����и�ڿ�ݹ�%d�Ÿ�ڴ���δʹ��״̬��\n",(i+1),(i+1));
						if(pi==1)
						    printf("�𾴵��û��������п��δȡ�꣬�뾡��ȡ����\n");
						else
							printf("�𾴵��û������Ŀ����ȡ�꣬��л��ʹ�ú������ܿ�ݹ�\n");					  
				  }				 
				 printf("�������и�ڿ�ݹ�ȡ���밴1��������һ�����ڴ��ڿ�ݹ�ȡ���밴�������ּ�:");
				 scanf("%d",&a);
				if(a==1)
					flag=true;
			    else
					flag=false;			 
		  }	     //�ж�ȡ�����Ƿ���6λ���ֵ�if��������
		 else{
			  printf("���������������\n");
			  printf("�������и�ڿ�ݹ�ȡ���밴1��������һ�����ڴ��ڿ�ݹ�ȡ���밴�������ּ�:");
			  scanf("%d",&a);
			if(a==1)
				flag=true;
			else
			 flag=false;
		 }
	}while(flag);
		 }  //�жϸ������Ϊ�и�ڵ�if��������
	else if(strcmp(type,"����")==0){
		 do{		
			 pi=0;
		 printf("��������ڵ�ȡ���룺");
		 scanf("%d",&a);
		 if(strlen(itoa(a,num,10))==6){     //ȡ������6λ����
			int i;
		 printf("����ɹ���\n");
		 for(i=0;i<100;i++){
			 if(bigbag[i]==a){
				 bigbag[i]=0;  //ȡ�����
				 mc=1;         //ȡ����ݳɹ�
				 int q;
				 for(q=0;q<20;q++){
					 call[i][q]=bigcall[i][q];  //���ֻ�������call����
					 bigcall[i][q]=0;  //��bigcall�����н�ȡ�����Ӧλ�õ�Ԫ��ɾ������ɾ���ֻ����룩
				 }				
				 for(int j=0;j<100;j++){				
					 if(strcmp(bigcall[j],call[i])==0){ 	//��middlecall�����н�ÿ��Ԫ�����κ�֮ǰ���call������ֻ�����Ƚ��Ƿ���ȣ����������ֻ������û����п��δȡ			 
							 pi=1;  //��ʾ���п��δȡ	
							 break;							 										 
					 }	
				 }			 
				 break;
			 }  //�жϸ������Ϊ���ڵ�if��������
			}      //forѭ��������
			  if(i==100)
					printf("��ȡ�����Ӧ�Ŀ�ݲ����ڻ�����������и�ڵ�ȡ���룡\n");
			  else{		//mc==1,�ҵ�ȡ���룬�ɹ�ȡ�����			  
						printf("���ڿ�ݹ�%d�Ÿ�ڴ򿪳ɹ��������ȡ�������ڿ�ݹ�%d�Ÿ�ڴ���δʹ��״̬��\n",(i+1),(i+1));
						if(pi==1)
						    printf("�𾴵��û��������п��δȡ�꣬�뾡��ȡ����\n");
						else
							printf("�𾴵��û������Ŀ����ȡ�꣬��л��ʹ�ú������ܿ�ݹ�\n");					  
				  }				 
				 printf("�����ڴ��ڿ�ݹ�ȡ���밴1��������һ�������и�ڿ�ݹ�ȡ���밴�������ּ�:");
				 scanf("%d",&a);
				if(a==1)
					flag=true;
			    else
					flag=false;			 
		  }	     //�ж�ȡ�����Ƿ���6λ���ֵ�if��������
		 else{
			  printf("���������������\n");
			  printf("�����ڴ��ڿ�ݹ�ȡ���밴1��������һ�������и�ڿ�ݹ�ȡ���밴�������ּ�:");
			  scanf("%d",&a);
			if(a==1)
				flag=true;
			else
			 flag=false;
		 }
	}while(flag);
		 }   //�жϸ������Ϊ���ڵ�else if��������
	 }  //�жϸտ�ʼ����ĸ�������Ƿ�Ϸ���if��䣨�и��/���ڣ�
	 else{
		 printf("���������������\n");
		 printf("���������밴1��������һ���밴�������ּ���:");
		 scanf("%d",&a);
		 if(a==1)
			 flag=true;
		 else
			 flag=false;
	 }
	}while(flag);
}


void Send(){      //���Ա���Ϳ�ݺ���
	int callnumber;  //callnumber���ڴ洢ȡ����
	do{
	char phone[20];//phone[20]�洢�ֻ�����
	FILE *f;
	char *p;  //�����洢�ֻ�����
	printf("\n�������û��ֻ��ţ�");
	scanf("%s",phone);	
	if(strlen(phone)==11){
	printf("����ɹ���\n");
	printf("��������Ҫ�ĸ������и��/���ڣ���");
	scanf("%s",type);
	if(strcmp(type,"�и��")==0||strcmp(type,"����")==0){
	printf("����ɹ���\n");
	callnumber=GetNumber();  //��ȡȡ����浽callnumber������callnumber����������ȡ����
	printf("ȡ����Ϊ��%d\n",callnumber);
	itoa(callnumber,num,10);  //��ʮ���Ƶ�����callnumberת�����ַ�����num�����ں���д���ļ�
	p=phone;  //p����ָ��phone��p����������绰����
	if(strcmp(type,"�и��")==0){
		int sum=0;
		if(middlebag[0]==0){ //���и���޿��
		middlebag[sum]=callnumber; //��ȡ������ȥ									
		strcpy(middlecall[sum],p);  //���ֻ�������ȥ��һ���ֻ������Ӧһ��ȡ����
		printf("ȡ�����Ӧ�İ����ѳɹ�������\n");
		printf("�и�ڿ�ݹ��%d��λ����ռ��\n",(sum+1));		
		}	
		else{  //���и���Ѿ��п��
			for(int j=0;j<100;j++){
			if(middlebag[j]!=0)
				sum=sum+1;	//�ҳ�����Ԫ��Ϊ0�������±꣬���ҵ��ո�ڵ�λ��
			else
				break;
			}	
			middlebag[sum]=callnumber; //������
			strcpy(middlecall[sum],p);  //���ֻ�������ȥ
			printf("ȡ�����Ӧ�İ����ѳɹ�������\n");
			printf("�и�ڿ�ݹ��%d��λ����ռ��\n",(sum+1));	
			}
		//���������middlebag�����ʵ�ʳ���
		middlelen=Getlen(middlebag);
		printf("�и�ڿ�ݹ�Ŀ������Ϊ:%d\n",middlelen);
	}
	else if(strcmp(type,"����")==0){
		int sum=0;
		if(bigbag[0]==0){
			bigbag[sum]=callnumber;
			strcpy(bigcall[sum],p);  //���ֻ�������ȥ
			printf("ȡ�����Ӧ�İ����ѳɹ�������\n");
			printf("���ڿ�ݹ��%d��λ����ռ��\n",(sum+1));			
		}	
		else{
			for(int j=0;j<100;j++){
			if(bigbag[j]!=0)
				sum=sum+1;	//�ҵ��ո�ڵ�λ��
			else
				break;
			}	
			bigbag[sum]=callnumber;
			strcpy(bigcall[sum],p);  //���ֻ�������ȥ
			printf("ȡ�����Ӧ�İ����ѳɹ�������\n");
			printf("���ڿ�ݹ��%d��λ����ռ��\n",(sum+1));	
			}
		biglen=Getlen(bigbag);  //���������bigbag�����ʵ�ʳ���
		printf("���ڿ�ݹ�Ŀ������Ϊ:%d\n",biglen);
	}
	if((f=fopen(strcat(phone,txt),"a"))==NULL){  //�������Ϣд���ļ�
		printf("cannot open file!\n");
		exit(0);  
	}	
	char ing[]="�𾴵�";
	char ang[]="�û�!";
	char str[]="���ã����Ŀ���ѷ���������ܿ�ݹ�����ȡ��ȡ����Ϊ";
	char t[]=",������Ϊ";
	fputs("\r\n",f);   //���ı��ļ��л�����"\r\n"
	fputs(ing,f);
	fputs(p,f);  //�绰����
	fputs(ang,f);
	fputs(str,f);
	fputs(num,f);  //ȡ����
	fputs(t,f);
	fputs(type,f);  //�������
	fputs("\r\n",f);      
	fclose(f);
	printf("ȡ���뷢�ͳɹ���\n");
	printf("��0�˳������������밴�������ּ���");
	scanf("%d",&a);
	if(a==0)		
		flag=false;	
	else
		flag=true;		
	}      //�жϸ���Ƿ�������ȷ��if��������
	else{              //������벻��ȷִ��
		printf("�����������������������\n");
		flag=true;
	}
	}      //�ж��ֻ������Ƿ�������ȷ��if��������
	else{             //�ֻ��������벻��ȷִ��
		printf("�����ֻ�������������������\n");
		flag=true;
	}
	}while(flag);
}

void Request(){     //���Ա��ѯ��ݺ���
	do{
		printf("��������Ҫ�ĸ������и��/���ڣ���");
		scanf("%s",type);
	if(strcmp(type,"�и��")==0||strcmp(type,"����")==0){
		printf("����ɹ���\n");
		if(strcmp(type,"�и��")==0){
			int sum=0;
			for(int i=0;i<100;i++){
				if(middlebag[i]!=0){
					printf("�и�ڿ�ݹ��%d��λ�ô���ʹ��״̬��\n",(i+1));
				    sum=sum+1;    //ͳ�ƿ����Ŀ
					if(sum==100)
						printf("�и�ڿ�ݹ���������\n");
				}
			}	
			for(int j=0;j<middlelen;j++){  //��ѯ���и�ڿ�ݹ�Ŀ�ݱ���ȡ���������Ϊ�洢��ݰ�˳��洢���洢��ɺ����middlelen,������middlelen��Χ����������Ԫ��Ϊ0�����Ӧ�Ŀ���ѱ�ȡ��
				if(middlebag[j]==0)
					printf("�и�ڿ�ݹ�%d�Ÿ�ڿ���ѱ�ȡ��!\n",(j+1));
			}
			printf("�и�ڿ�ݹ���ʹ��%d�����,ʣ��%d�����δʹ�ã�\n",sum,(100-sum));
		}
		else if(strcmp(type,"����")==0){
			int sum=0;
			for(int i=0;i<100;i++){
				if(bigbag[i]!=0){
					printf("���ڿ�ݹ��%d��λ�ô���ʹ��״̬��\n",(i+1));
				    sum=sum+1;
					if(sum==100)
						printf("���ڿ�ݹ���������\n");
				}			
			}	
			for(int j=0;j<biglen;j++){  //��ѯ�ڴ��ڿ�ݹ�Ŀ�ݱ���ȡ�����
				if(bigbag[j]==0)
					printf("���ڿ�ݹ�%d�Ÿ�ڿ���ѱ�ȡ��!\n",(j+1));
			}
			printf("���ڿ�ݹ���ʹ��%d�����,ʣ��%d�����δʹ�ã�\n",sum,(100-sum));
		}
			printf("��0�˳���ѯ��������ѯ�밴�������ּ���");
			scanf("%d",&a);
			if(a==0){		
				flag=false;	
				zhang=1;  //zhang==1ʱ��ʾ�˳���ѯ
			}
			else
				flag=true;
	}      //if��������
	else{
		printf("�����������������������\n");
		flag=true;
	}
	}while(flag);	
}


void Get(){   //���Աȡ����ݺ���
	do{	
		FILE *file;
		char ting[20];//����һ���ַ�����ʹ������pi��ϵ����
		char *pi;
		pi=ting;  //pi��ָ���ַ������ָ�룬��pi���Դ洢����Ԫ��
		Request();  //���Ȳ�ѯ��Щ��ݹ����п��
		if(zhang==1){  //ִ����Request()�������˳���ѯ��zhang==1
		printf("��ѯ������\n");
		do{
		int i=0,f=0;  //iΪ��ں�,f��ʾ����Ƿ��п��
		printf("�������ȡ����ݵĸ�����ͣ�");
		scanf("%s",type);
		if(strcmp(type,"�и��")==0||strcmp(type,"����")==0){
		printf("�����������ɹ���\n");
		if(strcmp(type,"�и��")==0){		
		 do{		
		 printf("�������и�ڵĸ�ںţ�");
		 scanf("%d",&i);
		 if(i>=1&&i<=100){  //��ںŴ�1��100
			  if(middlebag[i-1]!=0){  //��ںŶ�Ӧ�ĸ���п��
				  middlebag[i-1]=0;  //ȡ�����
				  pi=middlecall[i-1];  //ȡ����Ӧ�ĵ绰���룬��pi����
				  mc=1;  //ȡ����ݳɹ�			 
				 if(mc==1){  
					 char pl[20];  //������д���ļ�������
					 strcpy(pl,pi);
					 printf("�и�ڿ�ݹ�%d�Ÿ�ڴ򿪳ɹ��������ȡ�����и�ڿ�ݹ�%d�Ÿ�ڴ���δʹ��״̬��\n",i,i);
				 //�����ｫ֪ͨ��Ϣд���ļ�����֪ͨ�û���
				 if((file=fopen(strcat(pi,txt),"a"))==NULL){  //�����pi�ѱ��pi.txt�ַ���
					printf("cannot open file!\n");
					exit(0);  
					}	
					char ing[]="�𾴵�";
					char ang[]="�û�!";
					char str[]="���ã��������Ŀ���ѳ���24Сʱδ��ȡ�����Ա�Ѱ���ȡ����ȡ������ʧЧ���������쵽����ǰ̨ƾ�ֻ�����ȡ��";
				 fputs("\r\n",file);   //���ı��ļ��л�����"\r\n"
				 fputs(ing,file);
				 fputs(pl,file);  //д���ֻ�����
				 fputs(ang,file);
				 fputs(str,file);
				 fputs("\r\n",file);   //���ı��ļ��л�����"\r\n"
				 fclose(file);
				 printf("���Աȡ����ݵ������Ϣ�ѳɹ�֪ͨ�û���\n");
				 printf("�������и�ڿ�ݹ�ȡ���밴1��������һ�����ڴ��ڿ�ݹ�ȡ���밴�������ּ�:");
				 scanf("%d",&a);
				if(a==1)
					flag=true;
				else
					flag=false;
				 }
			  }
			  else if(middlebag[i-1]==0){  //��ںŶ�Ӧ�ĸ���޿��
				  f=0;  //����ںŶ�Ӧ�ĸ��Ϊ�գ���f==0
				  if(f==0){
					   printf("%d�Ÿ��Ϊ�գ�\n",i);
					   printf("�������и�ڿ�ݹ�ȡ���밴1��������һ�����ڴ��ڿ�ݹ�ȡ���밴�������ּ�:");
					   scanf("%d",&a);
					if(a==1)
						flag=true;
					else
						flag=false;
				  }
			  }
		 }
		 else{
			 printf("�����ں�����!����������!\n");
			 flag=true;
		 }
		 }while(flag);  //flag=falseʱ��������
		}  //�жϸ�������Ƿ�Ϊ�и�ڵ�if��������
	else if(strcmp(type,"����")==0){		
		 do{		
		 printf("��������ڵĸ�ںţ�");
		 scanf("%d",&i);
		 if(i>=1&&i<=100){
			  if(bigbag[i-1]!=0){  //���ڵĸ�ں��п��
				  bigbag[i-1]=0;  //ȡ�����
				  pi=bigcall[i-1];  //ȡ���绰����
				  mc=1;  //ȡ����ݳɹ�			 
				 if(mc==1){  
				 char pl[20];  //������д���ļ�������
				 strcpy(pl,pi);
				 printf("���ڿ�ݹ�%d�Ÿ�ڴ򿪳ɹ��������ȡ�������ڿ�ݹ�%d�Ÿ�ڴ���δʹ��״̬��\n",i,i);
				 //�����ｫ֪ͨ��Ϣд���ļ�����֪ͨ�û���
				  if((file=fopen(strcat(pi,txt),"a"))==NULL){  //�����pi�ѱ��pi.txt�ַ���
					printf("cannot open file!\n");
					exit(0);  
					}	
					char ing[]="�𾴵�";
					char ang[]="�û�!";
					char str[]="���ã��������Ŀ���ѳ���24Сʱδ��ȡ�����Ա�Ѱ���ȡ����ȡ������ʧЧ�����㾡�쵽����ǰ̨ƾ�ֻ�����ȡ��";
				 fputs("\r\n",file);   //���ı��ļ��л�����"\r\n"
				 fputs(ing,file);
				 fputs(pl,file);
				 fputs(ang,file);
				 fputs(str,file);
				 fputs("\r\n",file);   //���ı��ļ��л�����"\r\n"
				 fclose(file);
				 printf("���Աȡ����ݵ������Ϣ�ѳɹ�֪ͨ�û���\n");
				 printf("�����ڴ��ڿ�ݹ�ȡ���밴1��������һ�������и�ڿ�ݹ�ȡ���밴�������ּ�:");
				 scanf("%d",&a);
				if(a==1)
					flag=true;
				else
					flag=false;
				 }
			  }
			  else if(bigbag[i-1]==0){  //���ڵĸ�ں��޿��
				  f=0;  //����ںŶ�Ӧ�ĸ��Ϊ�գ���f==0
				  if(f==0){
					   printf("%d�Ÿ��Ϊ�գ�\n",i);
					   printf("�����ڴ��ڿ�ݹ�ȡ���밴1��������һ�������и�ڿ�ݹ�ȡ���밴�������ּ�:");
					   scanf("%d",&a);
					if(a==1)
						flag=true;
					else
						flag=false;
				  }
			  }
		 }
		 else{
			 printf("�����ں�����!����������!\n");
			 flag=true;
		 }
		 }while(flag);  //flag=falseʱ��������
		}  //�жϸ�������Ƿ�Ϊ���ڵ�if��������
		}  //�жϸ�������Ƿ����������if�����������и��/���ڣ�
		else{
		 printf("���������������\n");
		 printf("���������밴1��������һ���밴�������ּ�:");
		 scanf("%d",&a);
		 if(a==1)
			 flag=true;
		 else
			 flag=false;
	 }
		}while(flag);
		}  //�ж��Ƿ��ѯ�ɹ���if��������
	else{
			printf("��ѯʧ�ܣ�������һ���밴0�����������밴�������ּ���");
			scanf("%d",&a);
			if(a==0)		
				flag=false;			
			else
				flag=true;
		}
	}while(flag);
}     


int GetNumber(){      //��ȡȡ���뺯��
	int number=0,m=100000,n=999999;    //����100000-999999֮�����
	srand((unsigned)time(NULL));        //ʹ�� rand() ���������֮ǰ��Ҫ������������ĳ�ʼ������
		                          //srand(unsigned seed)����α��������г�ʼ����seed �ֽ�������ӣ�
								  //��˼�������ÿ���ṩ�� seed ��һ���ģ���ôÿһ�����ɵļ������ֵҲ����һ���ģ�
								  //ͨ����C����������ʹ��ʱ�亯��time��null)����Ϊseed,��Ϊʱ��ֵÿ�붼��ͬ,����������Ҳ��֮��ͬ
	number=rand()%(n-m+1)+m;       //��ԭ��Ϊ��������������0<=rand()%(n-m+1)<=n-m����0+m<=rand()%(n-m+1)+m<=n-m+m��m<=rand()%(n-m+1)+m<=n,rand()%10�ɲ���10���ڵ�����������10��
	return number;                //rand()%100+1����1-100���ڵ���
}

int Getlen(int zhr[100]){  //�����ݹ�Ŀ�������ĺ���
	int sum=0;
	for(int i=0;i<100;i++){
		if(zhr[i]!=0)
			sum=sum+1;
	}
	return sum;
}