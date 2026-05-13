#include<iostream>

using namespace std;

int addStudent(string name, int a, int b, int c, string s[10], int g1[10], int g2[10], int g3[10], int &size);

double studentAverage(string name, string s[10], int g1[10], int g2[10], int g3[10], int size);

int highestAverage(int g1[10], int g2[10], int g3[10], int size);

void printStudents(string s[10], int size);

int main(){

	string name;
	string student[10];
	int grade1[10];
	int grade2[10];
	int grade3[10];

	int size = 0; // this will tell us where we are in the array
	int choice;
	bool running = true;
	while(running){
		cout << "1. Add Student" << endl;
		cout << "2. Student grade average" << endl;
		cout << "3. Highest student average" << endl;
		cout << "4. Print students" << endl;
		cout << "5. Exit" << endl;

		cin >> choice;

		switch(choice){
			case 1:{
	
				int g1;
				int g2;
				int g3;
				cout << "Please enter the student's name: ";
				cin >> name;
				cout << "Please enter the student's first grade: ";
				cin >> g1;
				cout << "Please enter the student's second grade: ";
				cin >> g2;
				cout << "Please enter the student's third grade: ";
				cin >> g3;
				int check = addStudent(name, g1, g2, g3, student, grade1, grade2, grade3, size);
				if(check){
					cout << "Student added successfully!" << endl;
				}
				else {
					cout << "No student vacancy try again later!" << endl;
				}
				break;
			}

			case 2:{
				
				cout << "Please enter the student's name: ";
				cin >> name;

				double ave = studentAverage(name, student, grade1, grade2, grade3, size);

				if(ave >= 0.0){
					cout << name << "'s average grade is " << ave << endl;
				}
				else{
					cout << name << " is not a student.";
				}
				
				break;
			}

			case 3:{

				int index = highestAverage(grade1, grade2, grade3, size);
				cout << "The student with the highest average is " << student[index] << endl;
				break;
			}

			case 4:{
				printStudents(student, size);
				break;
			}

			case 5:{
				cout << "Goodbye";
				running = false;
				break;
			}

			default:
				cout << "Invalid choice" << endl;

		}
		cout << "\n\n\n\n";
	}






	return 0;
}

int addStudent(string name, int a, int b, int c, string s[10], int g1[10], int g2[10], int g3[10], int &size){

	if(size == 10){
		return 0; // so we can know if the student array is full
	}

	s[size] = name;
	g1[size] = a;
	g2[size] = b;
	g3[size++] = c;

	return 1;

}

double studentAverage(string name, string s[10], int g1[10], int g2[10], int g3[10], int size){

	
	int sum = 0;

	for(int i = 0; i < size; i++){
		if(s[i] == name){
			sum = g1[i] + g2[i] + g3[i];
			return sum / 3.0;
		}
	}

	return -1.0;

	
}

int highestAverage(int g1[10], int g2[10], int g3[10], int size){

	double highAve = (g1[0] + g2[0] + g3[0]) / 3.0;
	double currentAve;
	int k = 0;

	for(int i = 1; i < size; i++){
		currentAve = (g1[i] + g2[i] + g3[i]) / 3.0;
		if(currentAve > highAve){
			highAve = currentAve;
			k = i; // this will tell us the index of the highest average so we can use it later.
		}
	}
	cout << "The highest grade average is: " << highAve << endl;
	return k;
}

void printStudents(string s[10], int size){
	for(int i = 0; i < size; i++){
		cout << s[i] << " ";
	}
}