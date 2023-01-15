#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
void color(short x){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
void clear_screen(int x,int y){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    CONSOLE_CURSOR_INFO info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}
int mp[101][101]={
	{7,1,1,1,1,4,1,1,3,1,6},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{2,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,3},
	{5,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,4},
	{1,0,0,0,0,0,0,0,0,0,1},
	{8,1,1,1,5,1,1,2,1,1,7},
};
int hm[101][101]={
	{0,2200,2200,2000,1500,0,2000,3200,0,2000,0},
	{3500,0,0,0,0,0,0,0,0,0,3000},
	{2000,0,0,0,0,0,0,0,0,0,1800},
	{0,0,0,0,0,0,0,0,0,0,2500},
	{3000,0,0,0,0,0,0,0,0,0,4000},
	{1500,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,2000},
	{2500,0,0,0,0,0,0,0,0,0,2500},
	{1000,0,0,0,0,0,0,0,0,0,0},
	{4000,0,0,0,0,0,0,0,0,0,1200},
	{0,1800,2500,3200,0,1200,2000,0,3500,2000,0},
};
int n,p,t,m[11],x[11],y[11],st,pr,sm,pl,sp,ra,stp[11],sh[11],dh[11][101],sum;
char c1[11][101]={"得到500金币","得到800金币","得到1000金币","使一个对手减少500金币","使一个对手减少800金币","每个对手给你500金币"};
char c2[11][101]={"失去500金币","失去800金币","失去1000金币","给一个对手500金币","给一个对手800金币","给每个对手500金币"};
char ch,p1[101],p2[101];
bool flag,flag2,flag3;
void find(int xx,int yy){
	int cnt=0;
	for(int i=1;i<=p;i++){
		if(x[i]==xx&&y[i]==yy)cnt++;
	}
	if(cnt==0)st=0;
	else if(cnt==1){
		st=1;
		for(int i=1;i<=p;i++){
			if(x[i]==xx&&y[i]==yy){
				pr=i;
				break;
			}
		}
	}
	else st=2;
}
void rule(){
	clear_screen(43,7);
	color(10);
	printf("●空余(可通过金币占领)");
	clear_screen(43,8);
	color(2);
	printf("●已占领(需向所有者支付金币)");
	clear_screen(43,9);
	color(11);
	printf("●奖励格(得到500枚金币)");
	clear_screen(43,10);
	color(12);
	printf("●惩罚格(失去500枚金币)");
	clear_screen(43,11);
	color(13);
	printf("●命运格(随机惩罚)");
	clear_screen(43,12);
	color(14);
	printf("●机会格(随机奖励)");
	clear_screen(43,13);
	color(15);
	printf("●起点(经过此地可得2000金币)");
	clear_screen(43,14);
	color(8);
	printf("●监狱(暂停一次机会)");
	clear_screen(43,15);
	color(9);
	printf("●停车场(暂停两次机会)");
}
void solve(){
	switch(pr){
		case 1:{
			printf("①");
			break;
		}
		case 2:{
			printf("②");
			break;
		}
		case 3:{
			printf("③");
			break;
		}
		case 4:{
			printf("④");
			break;
		}
	}
}
void deal(){
	if(mp[x[pl]][y[pl]]==2){
		Sleep(100);
		clear_screen(13,20);
		color(15);
		printf("Player%d获得了500金币(按任意键确定)",pl);
		ch=getch();
		system("cls");
		m[pl]+=500;
	}
	if(mp[x[pl]][y[pl]]==3){
		Sleep(100);
		clear_screen(13,20);
		color(15);
		printf("Player%d失去了500金币(按任意键确定)",pl);
		ch=getch();
		system("cls");
		if(m[pl]<500)m[pl]=0;
		else m[pl]-=500;
	}
	if(mp[x[pl]][y[pl]]==4){
		Sleep(100);
		clear_screen(13,20);
		color(15);
		printf("Player%d开始随机惩罚(按任意键开始)",pl);
		Sleep(50);
		clear_screen(13,21);
		color(15);
		printf("得到的惩罚:");
		ch=getch();
		clear_screen(41,20);
		color(15);
		printf("停止");
		while(1){
			clear_screen(24,21);
			color(15);
			ra=rand()%6;
			printf("%-30s",c2[ra]);
			if(kbhit()){
				ch=getch();
				break;
			}
		}
		switch(ra){
			case 0:{
				clear_screen(13,22);
				color(15);
				printf("Player%d失去了500金币(按任意键确定)",pl);
				ch=getch();
				system("cls");
				if(m[pl]<500)m[pl]=0;
				else m[pl]-=500;
				break;
			}
			case 1:{
				clear_screen(13,22);
				color(15);
				printf("Player%d失去了800金币(按任意键确定)",pl);
				ch=getch();
				system("cls");
				if(m[pl]<800)m[pl]=0;
				else m[pl]-=800;
				break;
			}
			case 2:{
				clear_screen(13,22);
				color(15);
				printf("Player%d失去了1000金币(按任意键确定)",pl);
				ch=getch();
				system("cls");
				if(m[pl]<1000)m[pl]=0;
				else m[pl]-=1000;
				break;
			}
			case 3:{
				ra=rand()%p+1;
				if(ra==pl){
					if(ra==p)ra=1;
					else ra++;
				}
				clear_screen(13,22);
				color(15);
				printf("你需向Player%d支付500金币(按任意键确定)",ra);
				ch=getch();
				system("cls");
				if(m[pl]<500){
					m[ra]+=m[pl];
					m[pl]=0;
				}
				else{
					m[ra]+=500;
					m[pl]-=500;
				}
				break;
			}
			case 4:{
				ra=rand()%p+1;
				if(ra==pl){
					if(ra==p)ra=1;
					else ra++;
				}
				clear_screen(13,22);
				color(15);
				printf("你需向Player%d支付800金币(按任意键确定)",ra);
				ch=getch();
				system("cls");
				if(m[pl]<800){
					m[ra]+=m[pl];
					m[pl]=0;
				}
				else{
					m[ra]+=800;
					m[pl]-=800;
				}
				break;
			}
			case 5:{
				clear_screen(13,22);
				color(15);
				printf("你需向每个对手支付500金币(按任意键确定)",ra);
				ch=getch();
				system("cls");
				if(m[pl]<500*(p-1)){
					for(int i=1;i<=p;i++){
						if(i!=pl)m[i]+=m[pl]/(p-1);
					}
					m[pl]=0;
				}
				else{
					for(int i=1;i<=p;i++){
						if(i!=pl)m[i]+=500;
					}
					m[pl]-=500*(p-1);
				}
				break;
			}
		}
	}
	if(mp[x[pl]][y[pl]]==5){
		Sleep(100);
		clear_screen(13,20);
		color(15);
		printf("Player%d开始随机奖励(按任意键开始)",pl);
		Sleep(50);
		clear_screen(13,21);
		color(15);
		printf("得到的奖励:");
		ch=getch();
		clear_screen(41,20);
		color(15);
		printf("停止");
		while(1){
			clear_screen(24,21);
			color(15);
			ra=rand()%6;
			printf("%-30s",c1[ra]);
			if(kbhit()){
				ch=getch();
				break;
			}
		}
		switch(ra){
			case 0:{
				clear_screen(13,22);
				color(15);
				printf("Player%d获得了500金币(按任意键确定)",pl);
				ch=getch();
				system("cls");
				m[pl]+=500;
				break;
			}
			case 1:{
				clear_screen(13,22);
				color(15);
				printf("Player%d获得了800金币(按任意键确定)",pl);
				ch=getch();
				system("cls");
				m[pl]+=800;
				break;
			}
			case 2:{
				clear_screen(13,22);
				color(15);
				printf("Player%d获得了1000金币(按任意键确定)",pl);
				ch=getch();
				system("cls");
				m[pl]+=1000;
				break;
			}
			case 3:{
				ra=rand()%p+1;
				if(ra==pl){
					if(ra==p)ra=1;
					else ra++;
				}
				clear_screen(13,22);
				color(15);
				printf("Player%d失去了500金币(按任意键确定)",ra);
				ch=getch();
				system("cls");
				if(m[ra]<500)m[ra]=0;
				else m[ra]-=500;
				break;
			}
			case 4:{
				ra=rand()%p+1;
				if(ra==pl){
					if(ra==p)ra=1;
					else ra++;
				}
				clear_screen(13,22);
				color(15);
				printf("Player%d失去了800金币(按任意键确定)",ra);
				ch=getch();
				system("cls");
				if(m[ra]<800)m[ra]=0;
				else m[ra]-=800;
				break;
			}
			case 5:{
				clear_screen(13,22);
				color(15);
				printf("每个对手需向你支付500金币(按任意键确定)",ra);
				ch=getch();
				system("cls");
				for(int i=1;i<=p;i++){
					if(i!=pl){
						if(m[i]<500){
							m[pl]+=m[i];
							m[i]=0;
						}
						else{
							m[pl]+=500;
							m[i]-=500;
						}
					}
				}
				break;
			}
		}
	}
	if(mp[x[pl]][y[pl]]==7)stp[pl]=1;
	if(mp[x[pl]][y[pl]]==8)stp[pl]=2;
	if(mp[x[pl]][y[pl]]==1){
		Sleep(100);
		clear_screen(13,20);
		color(15);
		printf("是否要购买此地房产?(y为是,任意键为否)");
		clear_screen(13,21);
		color(15);
		printf("价格:%4d  抵押价格:%.0lf  过路费:%.0lf  奖励:%.0lf",hm[x[pl]][y[pl]],hm[x[pl]][y[pl]]*0.3,hm[x[pl]][y[pl]]*0.4,hm[x[pl]][y[pl]]*0.5);
		ch=getch();
		if(ch=='y'){
			if(m[pl]<hm[x[pl]][y[pl]]){
				clear_screen(13,22);
				color(15);
				printf("金币数量不够");
				Sleep(500);
				system("cls");
			}
			else{
				sh[pl]++;
				dh[pl][sh[pl]]=x[pl]*11+y[pl];
				m[pl]-=hm[x[pl]][y[pl]];
				mp[x[pl]][y[pl]]=10;
				clear_screen(13,22);
				color(15);
				printf("购买成功!");
				Sleep(500);
				system("cls");
			}
		}
		else system("cls");
	}
	else if(mp[x[pl]][y[pl]]==10){
		for(int i=1;i<=p;i++){
			for(int j=1;j<=sh[i];j++){
				if(x[pl]*11+y[pl]==dh[i][j]){
					if(i==pl){
						Sleep(100);
						clear_screen(13,20);
						color(15);
						printf("你得到了%.0lf金币(按任意键确定)",hm[x[pl]][y[pl]]*0.5);
						ch=getch();
						m[pl]+=hm[x[pl]][y[pl]]*0.5;
						system("cls");
					}
					else{
						Sleep(100);
						clear_screen(13,20);
						color(15);
						printf("你需给Player%d %.0lf金币(按任意键确定)",i,hm[x[pl]][y[pl]]*0.4);
						ch=getch();
						if(m[pl]<hm[x[pl]][y[pl]]*0.4){
							m[i]+=m[pl];
							m[pl]=0;
						}
						else{
							m[i]+=hm[x[pl]][y[pl]]*0.4;
							m[pl]-=hm[x[pl]][y[pl]]*0.4;
						}
						system("cls");
					}
					return;
				}
			}
		}
	}
}
void desktop(){
	SetConsoleTitleA("大富翁 v2.2.1");
	system("mode con cols=75 lines=25");
	system("cls");
	t=1;
	while(1){
		color(15);
		clear_screen(11,8);
		printf("请选择游戏人数:");
		if(t==1)color(240);
		else color(15);
		clear_screen(11,10);
		printf("☆2人");
		if(t==2)color(240);
		else color(15);
		clear_screen(11,12);
		printf("☆3人");
		if(t==3)color(240);
		else color(15);
		clear_screen(11,14);
		printf("☆4人");
		ch=getch();
		if(ch==72){
			if(t==1)t=3;
			else t--;
		}
		if(ch==80){
			if(t==3)t=1;
			else t++;
		}
		if(ch=='\r'||ch==' '){
			if(t==1)p=2;
			if(t==2)p=3;
			if(t==3)p=4;
			break;
		}
	}
	color(0);
	system("cls");
	t=1;
	while(1){
		color(15);
		clear_screen(11,8);
		printf("请选择回合数:");
		if(t==1)color(240);
		else color(15);
		clear_screen(11,10);
		printf("☆15回合");
		if(t==2)color(240);
		else color(15);
		clear_screen(11,12);
		printf("☆20回合");
		if(t==3)color(240);
		else color(15);
		clear_screen(11,14);
		printf("☆30回合");
		ch=getch();
		if(ch==72){
			if(t==1)t=3;
			else t--;
		}
		if(ch==80){
			if(t==3)t=1;
			else t++;
		}
		if(ch=='\r'||ch==' '){
			if(t==1)n=15;
			if(t==2)n=20;
			if(t==3)n=30;
			break;
		}
	}
	game();
}
void game(){
	color(0);
	system("cls");
	sm=1;
	pl=1;
	flag=0;
	flag2=0;
	flag3=0;
	memset(stp,0,sizeof(stp));
	memset(sh,0,sizeof(sh));
	memset(dh,0,sizeof(dh));
	for(int i=1;i<=p;i++){
		m[i]=2000;
	}
	for(int i=1;i<=p;i++){
		x[i]=0;
		y[i]=10;
	}
	while(1){
		clear_screen(6,1);
		color(15);
		printf("第%d回合",sm);
		for(int i=1;i<=p;i++){
			clear_screen(i*12,3);
			color(15);
			printf("     Player%d",i);
			clear_screen(i*12,4);
			color(14);
			printf("     ◎");
			color(15);
			printf("%5d",m[i]);
		}
		for(int i=0;i<11;i++){
			clear_screen(13,6+i);
			for(int j=0;j<11;j++){
				find(i,j);
				switch(mp[i][j]){
					case 0:{
						color(15);
						printf("  ");
						break;
					}
					case 1:{
						color(10);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
					case 2:{
						color(11);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
					case 3:{
						color(12);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
					case 4:{
						color(13);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
					case 5:{
						color(14);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
					case 6:{
						color(15);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
					case 7:{
						color(8);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
					case 8:{
						color(9);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
					case 10:{
						color(2);
						if(st==0)printf("●");
						else if(st==1)solve();
						else printf("⊙");
						break;
					}
				}
			}
		}
		rule();
		if(flag3==1){
			clear_screen(13,18);
			color(15);
			printf("按任意键退出游戏");
			ch=getch();
			return;
		}
		if(sm==n+1){
			for(int i=1;i<=p;i++){
				sum=0;
				for(int j=1;j<=sh[i];j++){
					sum+=hm[dh[i][j]/11][dh[i][j]%11]*0.3;
				}
				clear_screen(13,18);
				color(15);
				printf("Player%d得到了抵押%4d金币(按任意键确定)",i,sum);
				ch=getch();
				m[i]+=sum;
			}
			flag3=1;
			continue;
		}
		if(flag==1){
			sp--;
			clear_screen(26,19);
			color(15);
			printf("%2d",sp);
			if(y[pl]==10&&x[pl]!=10)x[pl]++;
			else if(x[pl]==10&&y[pl]!=0)y[pl]--;
			else if(y[pl]==0&&x[pl]!=0)x[pl]--;
			else if(x[pl]==0&&y[pl]!=10)y[pl]++;
			if(x[pl]==0&&y[pl]==10)m[pl]+=2000;
			if(sp==0){
				flag=0;
				flag2=1;
			}
			Sleep(100);
			continue;
		}
		if(flag2==1){
			deal();
			flag2=0;
			if(pl==p){
				sm++;
				pl=1;
			}
			else pl++;
			continue;
		}
		Sleep(100);
		clear_screen(13,18);
		color(15);
		printf("Player%d开始(按任意键开始)",pl);
		if(stp[pl]==0){
			Sleep(50);
			clear_screen(13,19);
			color(15);
			printf("向前移动步数:");
			ch=getch();
			clear_screen(33,18);
			color(15);
			printf("停止");
			while(1){
				clear_screen(26,19);
				color(15);
				sp=rand()%12+1;
				printf("%2d",sp);
				if(kbhit()){
					ch=getch();
					flag=1;
					Sleep(500);
					break;
				}
			}
		}
		else{
			clear_screen(13,19);
			color(15);
			printf("入狱中...");
			Sleep(500);
			system("cls");
			stp[pl]--;
			if(pl==p){
				sm++;
				pl=1;
			}
			else pl++;
		}
	}
}
int main(int argc,char *argv[])
{
	srand((unsigned)time(NULL));
	desktop();
}
