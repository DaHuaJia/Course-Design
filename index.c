#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flap[10]={0};  //����ͳ�Ƶ�Ʊ�� 

struct student{  //�ṹ��������洢������Ա��Ϣ 
		char name[30];
		char sex; 
		char nation[12];   //���� 
		int id;     //ѧ�� 
		int age;
		int score;    //�ۺϳɼ� 
	}student_num[10]={        //��Ա���� 
			"������",'M',"����",16120,20,95,
			"�����",'M',"����",16119,19,95,
			"л����",'M',"����",16101,19,95,
	}; 

main(){
	printf("\n��ӭ���� ͨ�Ź���16�� ������ԱͶƱϵͳ��"); 
	int fun_vote();  // ͶƱ����
	int fun_rank();  // �鿴��ǰ��������
	int fun_search();  //������Ա���� 
	int fun_add();     //����������Ա��Ŀ���� 
	int fun_in_record();   //д��ͶƱ���� 
	int fun_out_record();   //��ȡͶƱ���� 
	int fun_manager();  //�߼�����ԱȨ�޺��� 
	int fun_report();   //�ٱ����� 
	int fun_door(char *x[20],int y);  //д������ļ����ݺ��� 
	int fun_menu();       //�˵����� 
	fun_out_record();    //��ȡ��ǰͶƱ��� 
	
	fun_menu();
};

fun_vote(){  //ͶƱ���� 
	int i;  //���������Ա��Ϣ
	int j;  //���ڽ���ͶƱ��ѧ��
	printf("��ǰ���뾺ѡ��Ա�У�\n");
	for(i=0; i<10; i++){       //�����Ա��Ϣ 
		if(student_num[i].id!=0)
			printf("%s(080703%d)     ",student_num[i].name,student_num[i].id);
		else break;
	}
	printf("\n��������ѡ�ٵ���Ա��ѧ��(�����λ)��"); 
	scanf("%d",&j); 
	for(i=0; i<10; i++){
		if (j!=0 && j==student_num[i].id){
		printf("\nͶƱ�ɹ�����л��Ͷ�������һƱ��");
		flap[i]++;
		fun_in_record();
		break; 
		}
	}
	if(i==10) printf("\nͶƱʧ�ܣ��������ѧ�Ų����ڣ�");
	return fun_menu();
}

fun_rank(){       //�鿴��ǰ��������
	int max,i,j,a,k=0;
	for(j=0; j<10; j++){
		if(student_num[j].id==0) continue;   //���Ч�� 
		max=flap[j];a=j;
		for(i=1; i<10;i++)        //��ȡ�������ֵ���� 
			if(flap[i]!=0)
				if(max<flap[i]) 
					a=i;
		printf("��%d��:%s  ��Ʊ����%d\n",++k,student_num[a].name,flap[a]);  // ������� 
		flap[a]=0;
		if(flap[j]!=0) j=0;
	}
	fun_out_record();   //����������»�ȡͶƱ��� 
	return fun_menu();
}; 

fun_search(){   //������Ա���� 
	int num,i;
	printf("��������Ҫ�����ĳ�Ա��ѧ��(�����λ)��");	
	scanf("%d",&num); 
	if(num<16100 || num>16244){   //�������Ч�ʣ���С����Ҫ��ѭ�� 
		printf("\n�����ѧ�Ŵ���\n");
		return 1; 
	}
	for(i=0; i<10; i++){
		if(student_num[i].id==0) continue;   //�������Ч�� 
		else if(num==student_num[i].id){     //�����ɹ�ʱ����� 
			printf("\n������%s   �Ա�%c   ѧ�ţ�080703%d",student_num[i].name,student_num[i].sex,student_num[i].id);
			printf("\n���壺%s    ���䣺%d    �ɼ���%d",student_num[i].nation,student_num[i].age,student_num[i].score);
			printf("\n��ǰ��Ʊ����%d",flap[i]); break;
		}
	}
	if(i==10){
		printf("ѧ�Ų����ڣ�");  //����ʧ�ܣ��������� 
		printf("\n�����Ƽ� TA Ϊ������Ա��(1��ȷ��):");
		scanf("%d",&num);
		if(num==1) fun_add();
		else printf("�����˳�������\n");
		return fun_menu();
	}
	printf("\n����Ͷ TA һƱ��(1 ȷ��):"); 
	scanf("%d",&num);       //�����ɹ���ȷ���Ƿ�ͶƱ 
	if(num==1){
		flap[i]++;
		fun_in_record();
		printf("\nͶƱ�ɹ�����л��Ͷ�������һƱ��"); 
	}else printf("�����˳�ͶƱϵͳ��\n");
	return fun_menu();
} 

fun_manager(){   //�߼�����ԱȨ�޺���
	int i; 	
	int password,news;
	printf("���������Ա���룺"); 
	scanf("%d",&password); 
	if(password==8866){
		printf("����ù���ԱȨ�ޣ����޸Ļ�ɾ���κ������Ϣ��\n");
		for(i=0; i<10; i++){           //������г�Ա��Ϣ 
			if(student_num[i].id==0) continue; 
			printf("\n������%s   �Ա�%c   ѧ�ţ�080703%d",student_num[i].name,student_num[i].sex,student_num[i].id);
			printf("\n���壺%s    ���䣺%d    �ɼ���%d",student_num[i].nation,student_num[i].age,student_num[i].score);
			printf("\n��ǰ��Ʊ����%d\n",flap[i]); 
		}
	}else{
		system("warning.vbs");     //��ȫ�������Էǹ���Ա����ִ��ǿ�ƹػ� 
		return 1;
	}
	return fun_menu();
};

fun_in_record(){    //д��ͶƱ���� 
	int i;
    //��ͶƱ���ݱ��浽file1.txt�����ļ���   
    FILE *fpWrite=fopen("file1.txt","w");  
    if(fpWrite==NULL)  
    {  
        printf("�޷����ļ�\n");
		exit(0);  
    }  
   	for(i=0; i<10; i++){
   		fprintf(fpWrite,"%d ",flap[i]); 
	} 
    fclose(fpWrite); 
	return 0; 
}; 

fun_out_record(){  	//��ȡͶƱ���� 
    //��file1.txt�����ļ��ж���ͶƱ����  
    int i;
    FILE *fpRead=fopen("file1.txt","r");  
    if(fpRead==NULL)  
    {  
        printf("�޷����ļ�\n");
		exit(0);  
    }  
    for(i=0;i<10;i++) fscanf(fpRead,"%d ",&flap[i]); 
    fclose(fpRead); 
};

fun_add(){      //����������Ա��Ŀ���� 
	int i,j;
	for(i=0; i<10; i++) if(student_num[i].id==0) break;   //��鵱ǰ�Ƿ���������Ƽ����� 
	if(i==10){
		printf("����ѡ�ٵ������Ѵ����ޣ��ѹر��Ƽ���Ա���ܣ�");return fun_menu(); 
	} 
	printf("\n���������Ƽ�����Ա��ѧ�ţ���λ����");     //���ѧ�ŵ���Ч�� 
	scanf("%d",&student_num[i].id);
	if(student_num[i].id<16100 || student_num[i].id>16244){
		printf("ͶƱʧ�ܣ������ڸ�ѧ�ţ�\n"); return fun_menu();
	}
	for(j=0; j<i; j++) if(student_num[j].id == student_num[i].id){
		printf("���ڸ�ѧ�ţ������Ƽ���\n");
		return fun_menu(); 
	}
	printf("���������Ƽ�����Ա��������"); 
	scanf("%s",&student_num[i].name); 
	fun_door(&student_num[i].name,student_num[i].id);     //���Ƽ�����д������ļ� 
	printf("�Ƽ��ɹ�����л��Ĳ��룡����Ա���ڴ���~");
	return fun_menu(); 
}; 

fun_report(){        //�ٱ����� 
	int i;
	char abc[20]="�ٱ�"; 
	printf("��ȷ��Ҫ�ٱ���(1 ȷ��)��");
	scanf("%d",&i); 
	if(i==1) printf("��������Ҫ�ٱ����˵�ѧ��(��λ)��");    //���ٱ�ѧ�ŵ���Ч�� 
	else {
		printf("�����˳��ٱ���\n"); 
		return fun_menu(); 
	}
	scanf("%d",&i);
	if(i<16100 || i>16244){
		printf("�ٱ�ʧ�ܣ������ڸ�ѧ�ţ�\n");
		return fun_menu(); 
	} else{
		fun_door(abc,i);   // ���ٱ���Ϣ��������ļ� 
		printf("�ٱ��ɹ�������֪ͨ��ʦ����л�����ϣ�");
	}  
	return fun_menu();
}; 

fun_door(char *x[20],int y){    //д������ļ����ݺ��� 
	//�����ݱ��浽file1.txt�����ļ���   
    FILE *fpWrite=fopen("file1.txt","a");  
    if(fpWrite==NULL)  
    {  
        printf("�޷����ļ�\n");
		exit(0);  
    }  
   	fprintf(fpWrite,"\n\n%s ",x); 
   	fprintf(fpWrite,"%d",y); 
    fclose(fpWrite); 
};

fun_menu(){          //�˵����� 
	int power_num;  
	printf("\n\n1������ͶƱ\n"); 
	printf("2���鿴��ǰ����\n"); 
	printf("3��������ѡ�ٳ�Ա\n"); 
	printf("4���Ƽ�������Ա\n");
	printf("5���߼�����ԱȨ��\n"); 
	printf("6���ٱ�\n");
	printf("0���˳�\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�");
	scanf("%d",&power_num);
		switch(power_num){
			case 1: fun_vote();break;
			case 2: fun_rank();break;
			case 3: fun_search();break;
			case 4: fun_add();break;
			case 5: fun_manager();break;
			case 6: fun_report();break;
			case 0: exit(0); 
			default:printf("������δ��ͨ����δ֪��������ϵ����Ա��");exit(0);
		}
}
