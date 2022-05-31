#include <iostream>
using namespace std;

// linked list for patient

class node{
	

public:
	string name, fname, disease, ward, age,city, consulted_doc;
	int id;
	node *next;
	
};

// linked for doctor

class Node{
	
public:
	string  fname, age,lname,experience,specialization,city,Qual;
	int id;
	Node *next;
	
};
node *head = new node();
Node *Head = new Node();

// function to check weather record exist or not.

bool check(int x)
{
    
    if (head == NULL)
        return false;
 
    node* t = new node;
    t = head;
 
    
    while (t != NULL) {
        if (t->id == x)
            return true;
        t = t->next;
    }
 
    return false;
}

bool checkD(int x)
{
    
    if (head == NULL)
        return false;
 
    Node* t = new Node;
    t = Head;
 
    
    while (t != NULL) {
        if (t->id == x)
            return true;
        t = t->next;
    }
 
    return false;
}

			

string get_doc(){

	string cd, bill;
	cout<<"\n1 >> Dr. John  (GENERAL_MEDICINE)"<<endl;
	cout<<"2 >> Dr. Roy  (NEUROLOGY)"<<endl;
	cout<<"3 >> Dr. David  (CARDIOLOGY)"<<endl;
	cout<<"4 >> Dr. Mark  (HAEMATOLOGY)"<<endl;
	cout<<"5 >> Dr. Zuck (GASTROLOGY)"<<endl;
	cout<<"6 >> Dr. Grainy  (GYNAECOLOGY): "<<endl;
	int s;
	cin>>s;

	switch(s){
		
		case 1:{
			cd = "Dr. John";
			break;
		}
		case 2:{
			cd = "Dr. Roy";
			break;
		}
		case 3:{
		    cd = "Dr. David";
			break;
		}
		case 4:{
			cd = "Dr. Mark";
			break;
		}
		case 5:{
			
			cd = "Dr. Zuck";
			break;
			
		}
		case 6:{
			cd = "Dr. Grainy ";
			break;
		}
		default:{
			
			cout<<"\nEnter a valid option."<<endl;
			
		}
	
	}
		return cd;
		
	
}


string getSpec(){

	string sp;
	cout<<"\n1 >> GENERAL_MEDICINE"<<endl;
	cout<<"2 >> NEUROLOGY"<<endl;
	cout<<"3 >> CARDIOLOGY"<<endl;
	cout<<"4 >> HAEMATOLOGY"<<endl;
	cout<<"5 >> GASTROLOGY"<<endl;
	cout<<"6 >> GYNAECOLOGY "<<endl;
	int s;
	cin>>s;

	switch(s){
		
		case 1:{
			sp= "GENERAL_MEDICINE";
			break;
		}
		case 2:{
			sp="NEUROLOGY";
			break;
		}
		case 3:{
		    sp="CARDIOLOGY";
			break;
		}
		case 4:{
			sp= "HAEMATOLOGY";
			break;
		}
		case 5:{
			sp= "GASTROLOGY";
			break;
		}
		case 6:{
			sp= "GYNAECOLOGY ";
			break;
		}
		default:{
			cout<<"\nCome on!Enter a valid option."<<endl;
			
		}
	
	}
		return sp;
	
}




void addPatient(int id){
	
	if (check(id)) {
        cout << "Patient with this "
             << "record Already Exists\n";
        return;
    }
	
	node *t = new node();
	t->id = id;

	
	cout << "Patient Name: ";
	cin >> t->name;
	
	cout << "Father Name: ";
	cin >> t->fname;
	
	cout << "Patient Age: ";
	cin >> t->age;
	
	cout << "Disease: ";
	cin >> t->disease;
	
	cout << "\nAssign a Ward: ";
	t->ward = getSpec();
	
	cout << "city: ";
	cin >> t->city;
	
	cout << "\nAssign a Doctor: ";
	t->consulted_doc = get_doc();

	
	t->next = NULL;
	
	if(head == NULL || (head->id >= t->id)){
		
		t->next = head;
		head = t;
		
	} else {
		
		node *c = head;
		
			while(c->next!=NULL && (c->next->id > t->id))
			{
				c = c->next;
			}
			
			t->next = c->next;
			c->next = t;
		
	}
		system("cls");
		cout << "\nRecord Inserted!" << endl;
			
}

int Del_Record(int id){
	
	int choose;
	
	cout << "Press: \n1 >> to delete the patient \n2 >> to delete the doctor: ";
	cin >> choose;
	
	cout << "Enter Id of patient: " << endl;
	cin >> id;
	
	if(choose == 1){
	
	node *t = head;
	node *p = NULL;
	
	if(t != NULL && t->id == id){
		
		head = t->next;
		delete t;
		
		cout << "Record with id " << id << " is deleted!" << endl;
		return 0;
		
	} 
		
		while(t != NULL && t->id != id){
			
			p = t;
			t=t->next;
			
			if(t == NULL){
				
				cout << "No such record found!";
				return -1;
				p->next = t->next;
				delete t;
				
				cout << "Record with id " << id << " is deleted!" << endl;
				return 0;	
			}	
		}
		
	// delete doctor	
	
		
	} else {
		
		Node *t = Head;
		Node *p = NULL;
	
	if(t != NULL && t->id == id){
		
		Head = t->next;
		delete t;
		
		cout << "Record with id " << id << " is deleted!" << endl;
		return 0;
		
	} 
		
		while(t != NULL && t->id != id){
			
			p = t;
			t=t->next;
			
			if(t == NULL){
				
				cout << "No such record found!";
				return -1;
				p->next = t->next;
				delete t;
				
				cout << "Record with id " << id << " is deleted!" << endl;
				return 0;	
			}	
		}
		
		
	}
}

void Search_Patient(int id){
	
	if(head == NULL){
		
		cout << "No Record Found!" << endl;
		return;
		
	} else {
		
		node* p = head;
		
		while(p){
			
			if(p->id == id){
			cout << "\n\t---------Enter Patient Id Do You Want To Search----\n";
			cout << "\n\t*************************************************************************************\n";
			cout << "\tID\tName\t Father Name\t Age\t Disease\t Ward \tCity \tConsultant" << endl;
			cout << "\n\t*************************************************************************************\n";
			
			cout << "\n\t-------------------------------------------------------------------------------------\n";		
			cout <<"\t"<< p->id << "\t"
				 << p->name << "\t"
				 << p->fname << "\t\t"
				 << p->age << "\t"
				 << p->disease << "\t    "
				 << p->ward << "\t" 
				 << p->city << "\t"
				 << p->consulted_doc << "\t" << endl;
			cout << "\n\t-------------------------------------------------------------------------------------\n";	
				return;
			}
				
				p=p->next;
		}
		
		
		if(p == NULL)
			
			cout << "No such record found!" << endl;
		
		
	}
	
}

void Disp_Record(){
	
	node *r = head;
	Node *Q = Head;
	
	int choose;
	
	cout<<"Press: \n1 >> For Patient \n2 >> For Doctor: ";
	cin>>choose;
 	
	if(choose ==1){

		if(r == NULL){
		
		cout << "No Record Found!" << endl;
		
	} else {
		
		system("cls");
		cout << "\n\t\t*****************************************************************************************************\n";
		cout << "\t\t\t\t\t Patient Records" << endl;
		cout << "\n\t\t*****************************************************************************************************\n";
		cout << "\t\tID \tName \t\tFatherName \tAge \tDisease \tWard \t\tcity \tConsultant" << endl;
		
		while(r != NULL){
		
			cout << "\n\t\t----------------------------------------------------------------------------------------------------\n";
		
			cout <<"\t\t"<< r->id << "\t"
				 << r->name << "\t\t"
				 << r->fname << "\t        "
				 << r->age << "\t"
				 << r->disease << "\t\t"
				 << r->ward << "\t" 
				 << r->city <<"\t " 
				 << r->consulted_doc << "";
				 
				
		
			cout <<  "\n\t\t----------------------------------------------------------------------------------------------------\n";	 
				
					r = r->next;			
		}
	
	}
}

	else {
		
		if(Q == NULL){
		
		cout << "No Record Found!" << endl;
		
	} else {
		
		system("cls");
		cout << "\n\t\t***************************************************************************************************************\n";
		cout << "\t\t\t\t\t\t\t Doctor Records" << endl;
		cout << "\n\t\t***************************************************************************************************************\n";
		
		cout << "\t\tID\tName \t\tlastName \tAge \tqualification \tspecialization \t\texperience \tcity" << endl;
		
		while(Q->next!= NULL){
			
			cout << "\n\t\t-----------------------------------------------------------------------------------------------------------\n";	 
			cout <<"\t\t"<< Q->id << "\t"
				 << Q->fname << "\t\t"
				 << Q->lname << "\t\t"
				 << Q->age << "\t"
				 << Q->Qual << "\t\t"
				 << Q->specialization << "\t\t" 
				 << Q->experience << "\t\t"
				 << Q->city << "\t" << endl;
		    cout << "\n\t\t----------------------------------------------------------------------------------------------------------\n";	 	 
				
					Q = Q->next;			
			}
	
		}
	}
	
}






void addDoc(int id){
		

		if (checkD(id)) {
        cout << "Doctor with this "
             << "record Already Exists\n";
        return;
    
	}
	    Node *t = new Node();
	    t->id = id;

	    cout<<"Fill up the following details"<<endl;

   		cout<<"First Name:"<<endl;
   		cin>>t->fname;

   		cout<<"Last Name:"<<endl;
   		cin>>t->lname;

   		cout<<"Age:"<<endl;
   		cin>>t->age;

   		cout<<"Choose Qualification among the following:\n1.MBBS\n2.BDS"<<endl;
   		
   		int q;
   		cin>>q;
   		
		if(q==1)
   			
			t->Qual="MBBS";
			
		else t->Qual="BDS";
		
		cout<<"Choose Specialization among the following:"<<endl;
		t->specialization=getSpec();
		
		cout<<"Experience (in Years):"<<endl;
		cin>>t->experience;
		
		cout<<"City:"<<endl;
		cin>>t->city;
		
		system("cls");
	
		t->next = NULL;
	
		if(head == NULL || (head->id >= t->id)){                        //PRIORITY QUEUE ALGORITHM 
		
			t->next = Head;
			Head = t;
		
		} else {
		
			Node *c = Head;
		
			while(c->next!=NULL && (c->next->id > t->id))
			
			{
				c = c->next;
			}
			
				t->next = c->next;
				c->next = t;
		
		}
	
			cout << "\nRecord Inserted!" << endl;
		 
	}
	
	
void Search_doctor(int id){
	
		Node* D = Head;
		
		while(D){
			
			if(D->id == id){
			cout << "\n\t***************************Doctor with ID("<<id<<")******************************\n";
			cout << "\n\t*********************************************************************************************\n";
			cout << "\tID\t Name\t last Name\t Age\t qualification\tspecialization\texperience\t city" << endl;
			cout << "\n\t*********************************************************************************************\n";
			cout <<	"\n\t---------------------------------------------------------------------------------------------\n";	
			cout <<"\t"<< D->id << "\t"
				 << D->fname << "\t"
				 << D->lname << "\t\t"
				 << D->age << "\t\t"
				 << D-> Qual << "\t"
				 << D->specialization << "\t"
				 << D->experience <<"\t\t"
				 << D->city << "\t" << endl;
			cout <<	"\n\t---------------------------------------------------------------------------------------------\n";		
				return;
			}
				
				D=D->next;
		}
		
		
		if(D == NULL)
			
			cout << "No such record found!" << endl;
			
	}
	
	
	// Edit Doctor Record
	
int Doctor_edit(int id,string fname,string lname,string age,string Qual,string experience,string specialization,string city){
	
	int count =0, id_edit;
	
	Node *current =Head;
		
		while(current!=NULL){
			
			if(current ->id==id){
			count++;
			break;
			
		}
		
			current = current->next;
	}
	
	if(count==0){
		
		cout<<"id not found"<<endl;
	
     
	 	return 0;
	
	}
	
	else
	{
		system("cls");
		cout<<"Enter Details to edit: "<<endl;
		
		cout<<"Enter first name: "<<endl;
		cin>>fname;
	
		cout<<"Enter last name: "<<endl;
		cin>>lname;
	
		cout<<"Enter age: "<<endl;
		cin>>age;
	
		cout<<"Choose Qualification: \nMBBS\nBDS: "<<endl;
   		cin>>Qual;
		
		cout<<"Enter experience (in years): "<<endl;
		cin>>experience;
		
		cout<<"Enter city: "<<endl;
		cin>>city;
		
		cout<<"Enter specialization: "<<endl;
		
		
		current->fname =fname;
			current->lname =lname;
				current->age =age;
					current->Qual =Qual;
						current->experience =experience;
						current->specialization = getSpec();
							current->city =city;
		
		
		system("cls");
		cout<<"--Updated Record--"<<endl<<endl;
		
		cout<<"\n1.First Name: "<<fname<<endl<<"2.Last Name: "<<lname<<endl<<"3.Age: "
			
			<<age<<endl<<"4.Qualification: "<<Qual<<endl<<"5.Experience: "<<experience<<endl<<"6.specialization: "
			
			<<current->specialization<<endl<<"7.City: "<<city<<endl<<endl;
		
		return 1;
	}
}


void editDoc(){
		
		node* E = head;
		
		string fname, lname, age, Qual, experience, specialization, city; 		
		
		int id_edit,out;
	
		repeat:	

		cout<<"Enter id you want to Edit: "<<endl;
		cin>>id_edit;
		

		out = Doctor_edit(id_edit,fname,lname,age,Qual,experience,specialization,city);
		
	
		cout<<"\nPress 1 to Enter again: \nPress 2 to return to watch updated data\nPress 3 to Exit."<<endl;
		int c;
		
		cin>>c;
		
		if(c == 1){
			
			goto repeat;
		
		} else if(c==2){
	  	
		  	system("cls");
			Disp_Record();
		
		} else
	  		
			  exit(0);	
	}
	
	


// patient record edit


int Patient_edit(int id,string name,string fname,string age,string disease, string ward,string consulted_doc,string city){
	
	int count =0, id_edit;
	
	node *current =head;
		
		while(current!=NULL){
			
			if(current ->id==id){
			count++;
			break;
			
		}
		
			current = current->next;
	}
	
	if(count==0){
		
		cout<<"id not found"<<endl;
	
     
	 	return 0;
	
	}
	
	else
	{
		system("cls");
		cout<<"Enter Details to edit: "<<endl;
		
		cout<<"Enter Patient name: "<<endl;
		cin>>name;
	
		cout<<"Enter Father name: "<<endl;
		cin>>fname;
	
		cout<<"Enter age: "<<endl;
		cin>>age;
	
		cout<<"Enter Disease: "<<endl;
   		cin>>disease;
		
		cout<<"\nAssign a ward: "<<endl;
		current->ward = getSpec();
		
		cout<<"\nAssign a Doctor: "<<endl;
		current->consulted_doc = get_doc();
		
		cout<<"Enter city: "<<endl;
		cin>>city;
		
		
		current->name =name;
			current->fname =fname;
				current->age =age;
					current->disease =disease;
							current->city =city;
		
		
		system("cls");
		cout<<"--Updated Record--"<<endl<<endl;
		
		
		cout<<"\n1.Patient Name: "<<name<<endl<<"2.Father Name: "<<fname<<endl<<"3.Age: "
			
			<<age<<endl<<"4.Disease "<<disease<<endl<<"5.Ward Assigned: "<<current->ward<<endl<<"6.Consultant: "
			
			<<current->consulted_doc<<endl<<"7.City: "<<city<<endl<<endl;
		
		return 1;
	}
}


	
void edit_patient(){
	
	node* E = head;
		
		string name, fname, age, disease, ward, consulted_doc, city; 		
		
		int id_edit,out;
	
		repeat:	

		cout<<"Enter id you want to Edit: "<<endl;
		cin>>id_edit;
		

		out = Patient_edit(id_edit, name, fname, age, disease, ward, consulted_doc, city);
		
	
		cout<<"\nPress 1 to Enter again: \nPress 2 to return to watch updated data\nPress 3 to Exit."<<endl;
		int c;
		
		cin>>c;
		
		if(c == 1){
			
			goto repeat;
		
		} else if(c==2){
	  	
		  	system("cls");
			Disp_Record();
		
		} else
	  		
			  exit(0);	
	}
	
	


int main(){
  system("Color E0");
	head = NULL;
	int id, choice, pass;

	
	
	while(true){
		
		cout << "\n\n";
	 	system("pause");
		system("cls");
		cout<<"\n\t\t\t\t\t\tWELCOME TO HOSPITAL MANAGMENT SYSTEM\t\t"<<endl;
		cout << "\n\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
		cout << "\n\t\t\t%%%% \t\t\t1 << Add new patient record: \t\t\t%%%% " << endl;
		cout << "\n\t\t\t%%%% \t\t\t2 << Delete Patient Record:\t\t\t%%%%" << endl;
		cout << "\n\t\t\t%%%% \t\t\t3 << Search Patient Record:\t\t\t%%%% " << endl;
		cout << "\n\t\t\t%%%% \t\t\t4 << Display all  records: \t\t\t%%%%" << endl;
		cout << "\n\t\t\t%%%% \t\t\t5 << Add new doctor record:\t\t\t%%%% " << endl;
		cout << "\n\t\t\t%%%% \t\t\t6 << Search Doctor Record: \t\t\t%%%% " <<endl;
		cout << "\n\t\t\t%%%% \t\t\t7 << Edit Doctor Record: \t\t\t%%%% " << endl;
		cout << "\n\t\t\t%%%% \t\t\t8 << Edit Patient Record: \t\t\t%%%% " << endl;
		cout << "\n\t\t\t%%%% \t\t\t9 << Exit: \t\t\t\t\t%%%% ";
		cout << "\n\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		cin >> choice;
		
		switch(choice){
		
			
			case 1:	
					
					system("cls");
					ID:
					fflush(stdin);
					
					cout << "\nEnter id: " ;
					cin >> id;
					
					if(!cin) {
					
						std::cin.clear();
					
					cout << "\nPlease enter id in numbers: " ;
					
					goto ID;
					}
					
					addPatient(id);
					break;
			
			case 2:
					
					Del_Record(id);	
					break;
				
			case 3:
					
					system("cls");
					cout << "\nEnter Id of patient: " << endl;
					cin >> id;
					Search_Patient(id);	
					break;
					
			case 4:
				
				    Disp_Record();
					break;
	  		
			case 5:	
					
					system("cls");
					
					A:
					fflush(stdin);
					cout << "\nEnter id: " ;
					cin >> id;
					
					if(!cin) {
					
						std::cin.clear();
					
					cout << "\nPlease enter id in numbers: " ;
					
					goto A;
					}
					
					addDoc(id);
					break;
					
			case 6:
					
					system("cls");
					cout << "\nEnter Id of doctor: " << endl;
					cin >> id;
					Search_doctor(id);	
					break;
					
			case 7:
		        
		           editDoc();
				   break;
				   
			case 8:
		        
		           edit_patient();
				   break;
			
			case 9:
		        	
		        	system("cls");
		        	exit(0);
				   	   
			
	}

}

return 0;
	
	
}
