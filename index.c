#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flap[10]={0};  //用于统计得票数 

struct student{  //结构体变量，存储优秀团员信息 
		char name[30];
		char sex; 
		char nation[12];   //民族 
		int id;     //学号 
		int age;
		int score;    //综合成绩 
	}student_num[10]={        //人员名单 
			"郭明德",'M',"汉族",16120,20,95,
			"李泽辉",'M',"汉族",16119,19,95,
			"谢宝剑",'M',"汉族",16101,19,95,
	}; 

main(){
	printf("\n欢迎来到 通信工程16级 优秀团员投票系统！"); 
	int fun_vote();  // 投票函数
	int fun_rank();  // 查看当前排名函数
	int fun_search();  //搜索成员函数 
	int fun_add();     //增加优秀团员数目函数 
	int fun_in_record();   //写入投票函数 
	int fun_out_record();   //读取投票函数 
	int fun_manager();  //高级管理员权限函数 
	int fun_report();   //举报函数 
	int fun_door(char *x[20],int y);  //写入磁盘文件数据函数 
	int fun_menu();       //菜单函数 
	fun_out_record();    //获取当前投票情况 
	
	fun_menu();
};

fun_vote(){  //投票函数 
	int i;  //用于输出团员信息
	int j;  //用于接受投票的学号
	printf("当前参与竞选人员有：\n");
	for(i=0; i<10; i++){       //输出团员信息 
		if(student_num[i].id!=0)
			printf("%s(080703%d)     ",student_num[i].name,student_num[i].id);
		else break;
	}
	printf("\n请输入你选举的人员的学号(最后五位)："); 
	scanf("%d",&j); 
	for(i=0; i<10; i++){
		if (j!=0 && j==student_num[i].id){
		printf("\n投票成功，感谢您投出宝贵的一票！");
		flap[i]++;
		fun_in_record();
		break; 
		}
	}
	if(i==10) printf("\n投票失败！你输入的学号不存在！");
	return fun_menu();
}

fun_rank(){       //查看当前排名函数
	int max,i,j,a,k=0;
	for(j=0; j<10; j++){
		if(student_num[j].id==0) continue;   //提高效率 
		max=flap[j];a=j;
		for(i=1; i<10;i++)        //获取最大的数字的序号 
			if(flap[i]!=0)
				if(max<flap[i]) 
					a=i;
		printf("第%d名:%s  得票数：%d\n",++k,student_num[a].name,flap[a]);  // 排名输出 
		flap[a]=0;
		if(flap[j]!=0) j=0;
	}
	fun_out_record();   //排序结束重新获取投票情况 
	return fun_menu();
}; 

fun_search(){   //搜索成员函数 
	int num,i;
	printf("请输入你要搜索的成员的学号(最后五位)：");	
	scanf("%d",&num); 
	if(num<16100 || num>16244){   //提高搜索效率，减小不必要的循环 
		printf("\n输入的学号错误！\n");
		return 1; 
	}
	for(i=0; i<10; i++){
		if(student_num[i].id==0) continue;   //提高搜索效率 
		else if(num==student_num[i].id){     //搜索成功时的输出 
			printf("\n姓名：%s   性别：%c   学号：080703%d",student_num[i].name,student_num[i].sex,student_num[i].id);
			printf("\n民族：%s    年龄：%d    成绩：%d",student_num[i].nation,student_num[i].age,student_num[i].score);
			printf("\n当前得票数：%d",flap[i]); break;
		}
	}
	if(i==10){
		printf("学号不存在！");  //搜索失败，结束程序 
		printf("\n你想推荐 TA 为优秀团员吗？(1、确认):");
		scanf("%d",&num);
		if(num==1) fun_add();
		else printf("你已退出搜索！\n");
		return fun_menu();
	}
	printf("\n你想投 TA 一票吗？(1 确认):"); 
	scanf("%d",&num);       //搜索成功，确认是否投票 
	if(num==1){
		flap[i]++;
		fun_in_record();
		printf("\n投票成功，感谢您投出宝贵的一票！"); 
	}else printf("你已退出投票系统！\n");
	return fun_menu();
} 

fun_manager(){   //高级管理员权限函数
	int i; 	
	int password,news;
	printf("请输入管理员密码："); 
	scanf("%d",&password); 
	if(password==8866){
		printf("您获得管理员权限！可修改或删除任何相关信息！\n");
		for(i=0; i<10; i++){           //输出所有成员信息 
			if(student_num[i].id==0) continue; 
			printf("\n姓名：%s   性别：%c   学号：080703%d",student_num[i].name,student_num[i].sex,student_num[i].id);
			printf("\n民族：%s    年龄：%d    成绩：%d",student_num[i].nation,student_num[i].age,student_num[i].score);
			printf("\n当前得票数：%d\n",flap[i]); 
		}
	}else{
		system("warning.vbs");     //安全防护，对非管理员电脑执行强制关机 
		return 1;
	}
	return fun_menu();
};

fun_in_record(){    //写入投票函数 
	int i;
    //将投票数据保存到file1.txt磁盘文件中   
    FILE *fpWrite=fopen("file1.txt","w");  
    if(fpWrite==NULL)  
    {  
        printf("无法打开文件\n");
		exit(0);  
    }  
   	for(i=0; i<10; i++){
   		fprintf(fpWrite,"%d ",flap[i]); 
	} 
    fclose(fpWrite); 
	return 0; 
}; 

fun_out_record(){  	//读取投票函数 
    //从file1.txt磁盘文件中读出投票数据  
    int i;
    FILE *fpRead=fopen("file1.txt","r");  
    if(fpRead==NULL)  
    {  
        printf("无法打开文件\n");
		exit(0);  
    }  
    for(i=0;i<10;i++) fscanf(fpRead,"%d ",&flap[i]); 
    fclose(fpRead); 
};

fun_add(){      //增加优秀团员数目函数 
	int i,j;
	for(i=0; i<10; i++) if(student_num[i].id==0) break;   //检查当前是否可以增加推荐人数 
	if(i==10){
		printf("参与选举的人数已达上限！已关闭推荐成员功能！");return fun_menu(); 
	} 
	printf("\n请输入你推荐的人员的学号（五位）：");     //检查学号的有效性 
	scanf("%d",&student_num[i].id);
	if(student_num[i].id<16100 || student_num[i].id>16244){
		printf("投票失败！不存在该学号！\n"); return fun_menu();
	}
	for(j=0; j<i; j++) if(student_num[j].id == student_num[i].id){
		printf("存在该学号！请勿推荐！\n");
		return fun_menu(); 
	}
	printf("请输入你推荐的人员的姓名："); 
	scanf("%s",&student_num[i].name); 
	fun_door(&student_num[i].name,student_num[i].id);     //将推荐数据写入磁盘文件 
	printf("推荐成功！感谢你的参与！管理员正在处理~");
	return fun_menu(); 
}; 

fun_report(){        //举报函数 
	int i;
	char abc[20]="举报"; 
	printf("你确定要举报吗？(1 确定)：");
	scanf("%d",&i); 
	if(i==1) printf("请输入你要举报的人的学号(五位)：");    //检查举报学号的有效性 
	else {
		printf("你已退出举报！\n"); 
		return fun_menu(); 
	}
	scanf("%d",&i);
	if(i<16100 || i>16244){
		printf("举报失败！不存在该学号！\n");
		return fun_menu(); 
	} else{
		fun_door(abc,i);   // 将举报信息输入磁盘文件 
		printf("举报成功！正在通知老师！感谢你的配合！");
	}  
	return fun_menu();
}; 

fun_door(char *x[20],int y){    //写入磁盘文件数据函数 
	//将数据保存到file1.txt磁盘文件中   
    FILE *fpWrite=fopen("file1.txt","a");  
    if(fpWrite==NULL)  
    {  
        printf("无法打开文件\n");
		exit(0);  
    }  
   	fprintf(fpWrite,"\n\n%s ",x); 
   	fprintf(fpWrite,"%d",y); 
    fclose(fpWrite); 
};

fun_menu(){          //菜单函数 
	int power_num;  
	printf("\n\n1、参与投票\n"); 
	printf("2、查看当前排名\n"); 
	printf("3、搜索被选举成员\n"); 
	printf("4、推荐优秀团员\n");
	printf("5、高级管理员权限\n"); 
	printf("6、举报\n");
	printf("0、退出\n");
	printf("请选择你要执行的功能：");
	scanf("%d",&power_num);
		switch(power_num){
			case 1: fun_vote();break;
			case 2: fun_rank();break;
			case 3: fun_search();break;
			case 4: fun_add();break;
			case 5: fun_manager();break;
			case 6: fun_report();break;
			case 0: exit(0); 
			default:printf("功能尚未开通或发生未知错误！请联系管理员！");exit(0);
		}
}
