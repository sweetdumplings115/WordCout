// WordCount.cpp : 定义控制台应用程序的入口点。
//

  
  #include <string.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <ctype.h>
  bool matching(char a);
  int main(int argc, char *argv[])
  {
     //argv[1]是控制参数，argv[2]是文件名
         


    if( argc == 3 ){//argc为接收的参数个数
         //对参数进行判断
		 char data;
		FILE *fp = fopen(argv[2],"r"); //尝试读取文件的内容
         if(!fp){
             printf("文件读取发生错误！！！\n");
             return -1;
         }   
    
         if( !strcmp(argv[1],"-c") ){//字符数
             int numc = 0;
             while(fgetc(fp)!=EOF){
                 numc++;
             }
             printf("该文本文件的字符数为：%d\n",numc);
             
         }
         else if( !strcmp(argv[1],"-w") ){//单词数
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
            printf("该文本文件的单词数为：%d\n",numw);
         }
         else{
             printf("错误：参数错误！\n");
             printf("允许参数：-c，-w\n");
         }
         fclose(fp);
     }
     else{
         printf("错误：运行参数必须要有控制参数和文本文件名\n");
         printf("用法：WordCount.exe [parameter] [file_name]\n");
     }
     system("pause");
     return 0;

  
}

 bool matching(char a){
	   return (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9');
   }