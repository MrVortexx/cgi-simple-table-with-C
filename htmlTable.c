
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024
#define PEOPLES 5
char elementContainer [SIZE];
char styleContainer[SIZE];
char initialState [2]= ""; 


#define MAX 10
 // data structure
typedef struct
{
	char name [35];
    char email[35];
    char telephone[10];
		
}people;

typedef struct
{
	people peop[PEOPLES];
	int total_People;
}peopleList;

void insertPeople (peopleList* list, char name[], char email[], char telephone[])
{
    int pos = list->total_People;
    strcpy(list->peop[pos].name, name);
    strcpy(list->peop[pos].email, email);
    strcpy(list->peop[pos].telephone, telephone);

    list->total_People++;

}
void startPeopleList(peopleList*list)
{
    list->total_People = 0;
}
 

// html manipulation
char *insertClassInTag(char *tagName, char *className)
{

    char class[20] = " class =";
    strcat(class, className);
    int size = (int)strlen(tagName);
     strcpy(&tagName[ size -1],class );
 
    strcat(tagName, ">");
 
    return tagName;    
}

//use  "<tag>"  && " "class" " (double quote inside double quote, char class = ""class"")format
void createELement(char *tagName, char *className, char *htmlContent)
{ 
 
    char closingTag[20];
    strcpy(elementContainer, insertClassInTag(tagName, className));
    strcat(elementContainer, htmlContent);

    //insert the '/' at closing tag
    for(int i = 0; i < 3; i++){
         if( i == 0){ 
            strcpy(&closingTag[i], &tagName[i ]);
 
         }else if(i==1){
            strcpy(&closingTag[i],"/");
 
         }else{
            strcpy(&closingTag[i], &tagName[i-1 ]);
 
         }
 
    }
     
    strcat(elementContainer, closingTag);
    printf("%s",elementContainer);

}

//use 'tag' or '.class' format for call and 'style:style;' format
void insertStyle(char *className, char *tagName, char *style)
{        
    memset(styleContainer, 0, sizeof(styleContainer));
 
  if(className != NULL){
       strcpy(styleContainer, className );
 
  }else{    
        strcpy(styleContainer, tagName ); 
 
    }
    strcat(styleContainer, "{");
    strcat(styleContainer, style );
    strcat(styleContainer, "}");

    printf("%s",styleContainer);
}

void addTdToTable(char table[],  char name[], char email[], char telephone[])
{
        char aux [SIZE]= "<tr>";
        char tdName [100]= "<td><span>                      </span></td>";
        char tdEmail [100]= "<td><span>                     </span></td>";
        char tdPhone [100]= "<td><span>                     </span></td>";

    
     if(name == NULL || email == NULL || telephone == NULL){
        return;
     }else{
            strcpy(&tdName[10],name );
            strcpy(&tdEmail[10], email );
            strcpy(&tdPhone[10], telephone );

            strcat(aux,tdName);
            strcat(aux, tdEmail);
            strcat(aux,tdPhone);
            strcat(aux, "</tr>");
            strcat(table, aux);
     }
            
    

}
int main(void)
{   //starting  structure list for table
    peopleList peopleL;
    startPeopleList(&peopleL);
    insertPeople(&peopleL, "cccc", "teto@teo", "222204444");
    insertPeople(&peopleL, "abc", "adsdo@teo", "222204444");
    insertPeople(&peopleL, "dd", "sadjuo@teo", "222204444");
    insertPeople(&peopleL, "aa", "teoasido@teo", "222204444");
    insertPeople(&peopleL, "zzzzz", "tsadiasidio@teo", "222204444");
 

    // html content
    printf("Content-Type: text/html\n\n");

    printf("<html>");
 
         printf("<head><title> comeco com cgi! </title>");
            //add style
            printf("<style>");
                char bodyTag [10] = "body";
                char bodyStyle[SIZE] = "Display: flex; flex-direction: Column; justify-content:center; align-items: center;";
                insertStyle (NULL, bodyTag, bodyStyle);

                char titleStyle [SIZE] = "color: rgb(113, 89, 193); font-family: monospace;";
                char titleClass [100] = " .title";
                insertStyle(titleClass, NULL, titleStyle);

                char tableCLass [10] = ".table";
                char tableStyle [SIZE] = "border: solid 1px #ddd; border-radios: 3px !important; background-color: #2ea3f2;";
                insertStyle(tableCLass, NULL, tableStyle);

                char thTag [10] = "th";
                char thStyle [SIZE] = "width: 300px; font-weight: bold; font-family: sans-serif; border:solid 2px #ccc;";
                insertStyle(NULL, thTag, thStyle);

                char tdTag [10] = "td";
                char tdStyle [SIZE] = "width: 300px;  font-family: sans-serif; border-bottom: solid 1px;border-right: solid 1px;padding: 5px;";
                insertStyle(NULL, tdTag, tdStyle);

                char footerCLass [10] = ".footer";
                char footerStyle [SIZE] = "width: 300px;  font-family: sans-serif; border-bottom: solid 1px;border-right: solid 1px;padding: 5px; background-color: #000;";
                insertStyle(footerCLass, NULL, footerStyle);
     
            printf("</style></head>") ;

    printf("<body>");
        char h1 [20] = "<h1>";
        char h1Class [20] = "\"title\"";
        char h1Content[1024] = "Usuarios ";
        createELement(h1, h1Class, h1Content);

        char table [20]= "<table>";
        char tableClass [20]= "table";
        char tableContent [1024] = "<tr> <th> Nome</th> <th>EMail </th><th>Telefone</th> </tr>";
        char footer [1024] ="<tr ><td class=\"footer\"> </td ><td class=\"footer\"></td> <td class=\"footer\"></td></tr>";

        //add td for table
        for(int i = 0; i <PEOPLES; i++){
            addTdToTable(tableContent, peopleL.peop[i].name, peopleL.peop[i].email, peopleL.peop[i].telephone );

            if(i == PEOPLES -1){
                strcat(tableContent, footer);
            } ;
        }
         createELement(table, tableClass, tableContent);
 
    printf("</body> ");

    printf("</html> ");
    
   
    return 0;
}

