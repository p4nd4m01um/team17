#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]){
	
	float r_humd, temp, humd, c1, c1_1, c2, c3;

	temp = atoi(argv[1]);
	humd = atoi(argv[2]);

	cout<<"temp in :"<<temp<<endl;
	cout<<"humd in :"<<humd<<endl;

	c1 = (-17.27*temp)/(temp +238.3);
	c1_1 = exp(c1);
	c2 = (10.5 - temp) * 10;

	cout<< "c1 :"<<c1<<endl;
	cout<< "c1_1"<<c1_1<<endl;
	cout<< "c2 :"<<c2<<endl;

//	r_humd = 9.5*exp((-17.27*temp)/temp+238.3)*(10.5-temp);
	r_humd = c1_1 * c2;

	cout<< "the r_humd is :"<< r_humd <<endl;
	cout<< "the humd comparison :"<< humd <<endl;

	c3 = r_humd/humd;

	if (c3 >= 1){
		cout<< "it will snow" <<endl;
	}
	else{
		cout<< "Probability for any precipitation to be snow is about "<< c3*100 <<endl;
	}


	return 0;
}
