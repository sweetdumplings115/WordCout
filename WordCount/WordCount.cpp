// WordCount.cpp : �������̨Ӧ�ó������ڵ㡣
//

  
  #include <string.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <ctype.h>
  bool matching(char a);
  int main(int argc, char *argv[])
  {
     //argv[1]�ǿ��Ʋ�����argv[2]���ļ���
         


    if( argc == 3 ){//argcΪ���յĲ�������
         //�Բ��������ж�
		 char data;
		FILE *fp = fopen(argv[2],"r"); //���Զ�ȡ�ļ�������
         if(!fp){
             printf("�ļ���ȡ�������󣡣���\n");
             return -1;
         }   
    
         if( !strcmp(argv[1],"-c") ){//�ַ���
             int numc = 0;
             while(fgetc(fp)!=EOF){
                 numc++;
             }
             printf("���ı��ļ����ַ���Ϊ��%d\n",numc);
             
         }
         else if( !strcmp(argv[1],"-w") ){//������
             int numw = 0;
             char a = fgetc(fp);
             while( a != EOF){
                 if( matching(a) ){
                     while(matching(a))
					 {
                        a =fgetc(fp);
					 }
                     numw++;
                     a =fgetc(fp);
                     
                 }
                 else{
                     a =fgetc(fp);
				 }
                    
             }
            printf("���ı��ļ��ĵ�����Ϊ��%d\n",numw);
         }
         else{
             printf("���󣺲�������\n");
             printf("���������-c��-w\n");
         }
         fclose(fp);
     }
     else{
         printf("�������в�������Ҫ�п��Ʋ������ı��ļ���\n");
         printf("�÷���WordCount.exe [parameter] [file_name]\n");
     }
     system("pause");
     return 0;

  
}

 bool matching(char a){
	   return (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9');
   }