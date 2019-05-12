#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
//DECLERATION
ofstream Data, Data2;
double revenue[100], busy[100], plate_no[100], spaces[100], hour_rate[100];
int ID[100][100],TOKEN[100],choice, sub_choice,ID_deletion,ID_search,sum,ID_Certain,P_ID,hrs,plate_search;
int i=0,j=-1,ii,jj,nn,ff=0,jmax=0,flag=0,cc=0,pp=0,; // Iterations and Flags
string username[100],password[100],user_del,user_search,pass_search;
//SETTING ARRAYS TO 0
for(int iii=0;iii<100;iii++)
{revenue[iii]=0;
busy[iii]=0;
TOKEN[iii]=0;
plate_no[iii]=0;}

while(1){
    here:
    cout<<"Please Enter you console type (1: Admin, 2: Operator, 3: Customer\n";
    cin>>choice;
    switch (choice){
    case 1:
        while(1){
        cout<<"what would you like to do:\nAdd Operator (1)\nDelete Operator (2)\nAdd Parking lot (3)\nDelete Parking lot (4)\nList All Available Operators (5)\nList all parking lot IDs (6)\nSave operators (7)\nLoad Operators  (8)\nGo back  (0)\n";
        cin>>sub_choice;
        if (sub_choice==0)//GOING BACK
            goto here;
        switch (sub_choice){


        case 1:
            j=-1;
            cout<<"please enter the User ID\n";
            cin>>username[i];
            cout<<"please enter the User Password\n";
            cin>>password[i];
            cout<<"please enter the parking lot that the operator has access to, then end with 0\n";
            do{
                j++;
                cin>>ID[i][j];
                }while(ID[i][j]!=0);
            i++;
            if (j>jmax)
                jmax=j;
            break;


        case 2:
            cout<<"please enter the User ID\n";
            cin>>user_del;
            for(ii=0;ii<i;ii++)
                if(user_del==username[ii])
                    {for(nn=ii;nn<i;nn++){
                        username[ii]=username[ii+1];
                        password[ii]=password[ii+1];
                        for(jj=0;jj<j;jj++)
                            ID[nn][jj]=ID[nn+1][jj]; }
                        username[ii+1]="";
                        password[ii+1]="";
                        i--;}
            break;


        case 3:
           cout<<"please enter the parking lot ID number\n";
           cin>>ID[99][ff];
           cout<<"please enter the parking lot spaces\n";
           cin>>spaces[ff];
           cout<<"please enter the parking lot hour_rate\n";
           cin>>hour_rate[ff];
           ff++;
           break;


        case 4:
            cout<<"please enter the parking lot ID number\n";
            cin>>ID_deletion;
            for(ii=0;ii<ff;ii++){
                if(ID_deletion == ID[99][ii])
                    {cout<<"hi";
                    for(nn=ii;nn<ff;nn++){
                        ID[99][ii]=ID[99][ii+1];
                        spaces[ii]=spaces[ii+1];
                        hour_rate[ii]=hour_rate[ii+1];}
                    ff--;}}
            break;


        case 5:
            for(ii=0;ii<i;ii++){
                cout<<"Username: " << username[ii] <<", Password: "<< password[ii]<<", IDs: " ;
                for(jj=0;jj<jmax;jj++)
                    if(ID[ii][jj]!=0){
                    cout<<endl<<ID[ii][jj];
                    cout<<endl;}}
            break;


        case 6:
            for(ii=0;ii<ff;ii++){
                cout<<"Parking lot ID: " << ID[99][ii] <<", spaces: "<< spaces[ii]<<", Hour-rate: "<<hour_rate[ii]<<endl ;}
            break;


        case 7:
            Data.open("out.txt");
            for(ii=0;ii<i;ii++){
                Data<<"Username: " << username[ii] <<", Password: "<< password[ii]<<", IDs: ";
            for(jj=0;jj<jmax;jj++)
                if(ID[ii][jj]!=0){
                    Data<<endl<<ID[ii][jj];
                    Data<<endl;}}
            Data.close();
            Data2.open("out2.csv");
            for(ii=0;ii<ff;ii++){
                Data2<<"Parking lot ID: " << ID[99][ii] <<", spaces: "<< spaces[ii]<<", Hour-rate: "<<hour_rate[ii]<<endl ;}
                Data2.close();
            break;



    default:
            cout<<"Wrong number";}}
    case 2:

        while(1){
            cout<<"please enter your username, 0 for going back\n";
            cin>>user_search;
            if (user_search=="0")
                goto here;
            cout<<"please enter your password\n";
            cin>>pass_search;
            for(ii=0;ii<i;ii++){
                if(user_search==username[ii]&&pass_search==password[ii]){
                ID_Certain=ii;
                goto there;}}
            cout<<"Wrong Credentials, ";}
            there:


        while(1){
            cout<<"What would you like to do\nList parking slots (1)\nGet revenue for your parking lots (2)\nSearch for a car plate number (3)\nGo back  (0)\n";
            cin>>sub_choice;
            if (sub_choice==0)
                goto here;
            switch (sub_choice){
            case 1:
                cout<<"please enter the parking lot ID number\n";
                cin>>ID_search;
                for(ii=0;ii<ff;ii++)
                  {if (ID_search==ID[99][ii]){
                      cout<<"Parking lot ID: " << ID[99][ii] <<", spaces: "<< spaces[ii]<<", Busy: "<<busy[ii]<<", free: "<<spaces[ii]-busy[ii]<<endl;break;flag=1;}                }
                  if (flag==0)
                      cout<<"No matching\n";
                break;


            case 2:
                for(ii=0;ii<100;ii++){
                    for(cc=0;cc<100;cc++)
                        if(ID[99][ii]==ID[ID_Certain][cc]&&ID[ID_Certain][cc]!=0){
                            cout<<"Parking lot ID: " << ID[99][ii] <<", Revenue: " << revenue[ii]<<endl;
                            sum+=revenue[ii];}}
                break;


            case 3:
                cout<<"Please enter your plate number";
                cin>>plate_search;
                for(int qq=0;qq<100;qq++){
                    if (plate_search==plate_no[qq]){
                        cout<<"parking lot id="<<TOKEN[qq]+1;}}
                break;
              default:
                cout<<"Wrong number\n";}}


    case 3:
        hhere:
        cout<<"What would you like to do\nPark (1)\nLeave(2)\nGo back  (0)\n";
        cin>>sub_choice;
        if (sub_choice==0)
            goto here;
       switch (sub_choice){
          case 1:
                cout<<"Please enter your parking ID";
                cin>>P_ID;
                cout<<"Please enter your plate number";
                cin>>plate_search;
                for(int qq=0;qq<100;qq++){
                    if (plate_search==plate_no[qq])
                        {cout<<"Already registered";
                        goto hhere;}
                    else
                            {plate_no[pp]=plate_search;
                            break;}}
                TOKEN[pp]=P_ID-1;
                busy[P_ID]++;
                pp++;
                break;
          case 2:
                cout<<"Please enter the number of hours";
                cin>>hrs;
                cout<<"Please enter your plate number";
                cin>>plate_search;
                for(int qq=0;qq<100;qq++){
                    if (plate_search==plate_no[qq]){
                        busy[TOKEN[qq]]--;
                        revenue[TOKEN[qq]]=hrs+revenue[TOKEN[qq]];}}
                break;
                default:
                cout<<"Wrong number\n";}}}}
