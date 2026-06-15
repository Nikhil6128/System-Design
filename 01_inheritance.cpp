#include<iostream>
#include<string>

using namespace std;

class car {
protected: 
	string brand;
	string model;
	bool isEngineOn;
	int currentSpeed;

public: 
	car(string b, string m){
		this-> brand = b;
		this-> model = m;
		isEngineOn = false;
		currentSpeed = 0;
	}

	void startEngine(){
		isEngineOn = true;
		cout << brand << " " << model << ": Engine started." << endl;
	}

	void stopEngine(){
		isEngineOn = false;
		cout << brand << " " << model << ": Engine turned off." << endl;
	}

	void accelerate(){
		if(! isEngineOn){
			cout << brand << " " << model << ": cannot accelerate! Engine is off." << endl;
		}
		currentSpeed += 20;
		cout << brand << " " << model << ": accelerating to " << currentSpeed << "km/h" << endl;
	}

	void brake(){
		currentSpeed -= 20;
		if(currentSpeed < 0) currentSpeed = 0;
		cout << brand << " " << model << ": Breaking! Speed is now " << currentSpeed << "km/h" << endl;
	}
	virtual ~car() {}
};


class manualcar : public car {
private: 
	int currentGear;
public: 
	manualcar(string b , string m) : car(b,m){
		currentGear = 0;
	}

	void shiftGear(int Gear){
		currentGear = Gear;
		cout << brand << " " << model << ": shifted to gear " << currentGear << endl;
	}
};

class electriccar : public car {
private: 
	int batterylevel;
public: 
	electriccar(string b , string m) : car(b,m){
		batterylevel = 100;

		cout << brand << " " << model << ": battery fully charged " << endl;
	}
};


int main (){
	manualcar *mymanualcar = new manualcar("suzuki", "Wagon R");
	mymanualcar -> startEngine();
	mymanualcar -> shiftGear(1); // specific to manual car
	mymanualcar -> accelerate();
	mymanualcar -> brake();
	mymanualcar -> stopEngine();
	delete mymanualcar;

	cout << ".............." << endl;

	electriccar * myelectriccar = new electriccar("Tesla", "model s");
	//myelectriccar -> chargeBattery();
	myelectriccar -> startEngine();
	myelectriccar -> accelerate();
	myelectriccar -> brake();
	myelectriccar -> stopEngine();
	delete myelectriccar;
	return 0;
}
