#include<iostream>
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include"head.h"

using namespace std;

node* load(){
    int i=0;
    node *head,*tail,*p;
    head=tail=new node;

    tail->next=NULL;
    ifstream in("D:\\program\\git\\project1\\tongxunlu\\test.txt");
    if(! in.is_open())
    {cout<<"erro opening file"<<endl;}
    while(!in.eof()){
        p=new node;
        in.read(p->info.no,9);
        in.read(p->info.num,11);
        
       printf("���ڶ�ȡ��%d������\n",i);
       i++;
       p->next=NULL;
       tail->next=p;
       tail=p;

    }
    in.close();
    return head;
}

int add(node* head){
    printf("�������Ƿ�������ϵ�ˣ�<y/n>");
    char h;
    cin>>h;
    if(h=='Y'||h=='y'){
        node* p;
      while(h=='Y'||h=='y'){
        p=new node;
        printf("����������\n");
        fflush(stdin);
        scanf("%s",p->info.no);
        printf("�������ֻ���\n");
        fflush(stdin);
        scanf("%s",p->info.num);
        p->next=head->next;
        head->next=p;
        printf("�����Ƿ�Ҫ������ϵ�ˣ�<y/n>");
        fflush(stdin);
        cin>>h;
          }
    ofstream out("D:\\program\\git\\project1\\tongxunlu\\test.txt",ios::app);
    if(!out.is_open()){
        printf("��ʧ��\n");
    }
    else{
        while(head->next!=NULL){
            head=head->next;
         out.write(head->info.no,9);
         out.write(head->info.num,11);
         out<<endl;
        }

        out.close();
        printf("����ɹ�");
    }
    }
    return 0;
}

int freelist(node*head){
    node*p1,*p2;
    p1=p2=head;
    p2=p2->next;
    while(p2!=NULL){
        delete(p1);
        p1=p2;
        p2=p2->next;
    }
    delete(p1);
    return 0;
}
int view(node*head){
    node *p1;
    p1=head;
    if(head->next==NULL){
        printf("����Ϊ��\n");
        return 0;
    }
    printf(".......................................\n");
    printf("����            �ֻ���\n");
    p1=head->next;
    while(p1!=NULL){
        printf("%-11s   %s\n",p1->info.no,p1->info.num);
       
        p1=p1->next;
    }
    return 0;
}
int main(){
node* head;
cout<<"���ڶ�ȡ���ݣ����Ժ󡣡�����"<<endl;
head=load();


    printf("........................\n");
    printf(".......����ͨѶϵͳ.......\n");
    printf("��ӭ����ͨѶ¼\n");
    printf("��ѡ��\n");
    printf("1.......������ϵ��\n");
    printf("2.......�鿴ͨѶ¼\n");
    printf("3.......\n");
    printf("7.......�˳�\n");
    int s=1;
    cin>>s;
    switch(s){
        case 1:add(head);
        case 2:view(head);
        case 7:freelist(head);exit(0);
        default:printf("erro!����������\n");
    }



}