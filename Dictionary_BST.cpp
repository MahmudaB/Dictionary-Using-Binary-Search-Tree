#include<bits/stdc++.h>
using namespace std;
#define max 1000
struct dictionary
{
    char word[max],meaning[max],pospeech[max];
    struct dictionary *left;
    struct dictionary *right;
};
typedef struct dictionary *dic;
dic root=NULL;

void Sort(dic p)
{
    fstream file,file1;
    remove("new.txt");
    file.open("new.txt", ios::app | ios::out);
    if(p!=NULL)
    {
        Sort(p->left);
        file<<p->word<<" "<<p->pospeech<<" "<<p->meaning<<endl;
        Sort(p->right);
    }
    file.close();

}

void create()
{
    fstream file;
    dic temp,ptr,par;
    int flag=0;
    file.open("new.txt", ios::in);
    if(!file)
    {
        root=NULL;
        file.close();
    }
    else
    {
        temp=(dictionary*)malloc(sizeof(dictionary));
        temp->right=NULL;
        root=temp;
        file >> temp->word   >> temp->pospeech >> temp->meaning;
        //root=temp;
        dic ptr=root;
        while(!file.eof())
        {
            cout<<ptr->word<<endl;
            ptr->right=(dictionary*)malloc(sizeof(dictionary));
            ptr=ptr->right;
            file >> ptr->word   >> ptr->pospeech >> ptr->meaning;


        }
        ptr->right=NULL;
        file.close();
    }

}


void Insert()
{
    dic temp;
    temp=(dictionary*)malloc(sizeof(dictionary));
    temp->left=NULL;
    temp->right=NULL;
    printf("\nInsert word: ");
    scanf("%s",temp->word);
    printf("\nInsert Parts of Speech: ");
    scanf("%s",temp->pospeech);
    printf("\nInsert meaning: ");
    scanf("%s",temp->meaning);
    int flag=0;
    dic ptr,par;
    ptr=root;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        while(ptr!=NULL )
        {
            if(strcmp(temp->word,ptr->word)>0)
            {
                par=ptr;
                ptr=ptr->right;
            }

            else if(strcmp(temp->word,ptr->word)<0)
            {
                par=ptr;
                ptr=ptr->left;
            }
            else if(strcmp(temp->word,ptr->word)==0)
            {
                flag=1;
                printf("\nWord exists!!");
                break;
            }

        }
        if(flag==0 && ptr==NULL)
        {

            if(strcmp(par->word,temp->word)==1)
                par->left=temp;
            else if(strcmp(par->word,temp->word)==-1)
                par->right=temp;
        }

    }

    Sort(root);
}
/*void Display(dic p)
{
    if(root)
    {
        if(p!=NULL)
        {
            Display(p->left);
            cout << "\n\t\t\t\t\t ---------------------------" << endl;
            cout << "\t\t\t\t\t | WORDS IN THE DICTIONARY |" << endl;
            cout << "\t\t\t\t\t ---------------------------" << endl;
            printf("\t\t\t\t\t       Word: %s\n",p->word);
            printf("\t\t\t\t\t       Parts of Speech: %s\n",p->pospeech);
            printf("\t\t\t\t\t       Meaning : %s\n",p->meaning);
            cout<<endl;
            Display(p->right);
        }
    }
    else printf("\n\n\t\t\t\t\tEmpty Dictionary!!!!\n");
}*/
void Display()
{

    dic p;
    fstream file;
    file.open("new.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tEmpty!!... ";
        file.close();
    }
    else
    {
        file >> p->word   >> p->pospeech >> p->meaning;
        while (!file.eof())
        {
            printf("\nWord: %s",p->word);
            printf("\nPart of Speech: %s",p->pospeech);
            printf("\nMeaning : %s",p->meaning);
            cout<<endl;
            file >>p->word   >> p->pospeech >> p->meaning;
        }
        file.close();
    }
}
void Search()
{
    int flag=0;
    dic ptr;
    char w[max];
    printf("\nEnter word to search from the Dictionary :");
    scanf("%s",w);
    ptr=root;
    while(ptr!=NULL && flag==0)
    {
        if(strcmp(w,ptr->word)>0)
            ptr=ptr->right;
        else if(strcmp(w,ptr->word)<0)
            ptr=ptr->left;
        else if(strcmp(w,ptr->word)==0)
        {
            flag=1;
            printf("\nParts of Speech of %s is : %s",ptr->word,ptr->pospeech);
            printf("\nAND  Meaning of %s  is :  %s\n",ptr->word,ptr->meaning);
        }
    }
    if(flag==0)
        printf("\n%s is not Available in the Dictionary!!!\n",w);
}
void Edit()
{
    int flag=0;
    dic ptr;
    ptr=root;
    char w[max],ch;
    printf("\nEnter word to Edit from the Dictionary :");
    scanf("%s",w);

    while(ptr!=NULL && flag==0)
    {
        if(strcmp(w,ptr->word)>0)
            ptr=ptr->right;
        else if(strcmp(w,ptr->word)<0)
            ptr=ptr->left;
        else if(strcmp(w,ptr->word)==0)
        {
            flag=1;
            printf( "\n\nEnter Choice to EDIT, Parts of Speech or Meaning or Both (p/m/b) : " );
            fflush( stdin );
            scanf( "%c", &ch);
            if(ch=='p')
            {
                printf("\nEnter Correct Parts of Speech of %s: ",ptr->word);
                scanf("%s",ptr->pospeech);

            }
            else if(ch=='m')
            {
                printf("\nEnter Correct Meaning of %s : ",ptr->word);
                scanf("%s",ptr->meaning);
            }
            else
            {
                printf("\nEnter Correct Parts of Speech of %s: ",ptr->word);
                scanf("%s",ptr->pospeech);
                printf("\nEnter Correct Meaning of %s : ",ptr->word);
                scanf("%s",ptr->meaning);
            }
            Sort(root);
        }
    }
     if(flag==0)
        printf("\%s is not Available in the Dictionary!!!\n",w);
}
int menu(void)
{
    int choice;
    do
    {
        cout<<"\n\n\n";
        cout<<"----------------------------------------------------MENU------------------------------------------------------------\n";
        cout<<"***************************************************----*************************************************************\n";
        printf("\n1-Insert\n2-Search\n3-Display\n4-Edit\n5-Exit\n");
        printf("\nYour choice please... ");
        scanf("%d",&choice);
        if(choice<1||choice>5)
            printf("\nWrong...Choice again...\n");
    }
    while(choice<1||choice>5);
    return (choice);
}
int main()
{
    int choice;
    create();
    cout<<"\n\n\n";
    cout<<"---------------------------------------------WELCOME TO THE DICTIONARY-------------------------------------------------------------\n";
    cout<<"********************************************---------------------*************************************************************\n";
    do
    {
        choice=menu();
        switch(choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Search();
            break;
        case 3:
            Display();
            break;
        case 4:
            Edit();
            break;
        case 5:
            printf("\n");
            break;
        }
    }
    while(choice!=5);
    return 0;
}

