#include <iostream>
using namespace std;

class Car 
{
	string body;
	string typeOfTransmission;
	int EnginePower;
	int wheelRadius;
	int numOfTransmissions;
public:
	void SetBody(string body) 
	{
		this->body = body;
	}
	string GetBody() 
	{
		return body;
	}
	void SetEnginePower(int EnginePower)
	{
		this->EnginePower = EnginePower;
	}
	int GetEnginePower() 
	{
		return EnginePower;
	}
	void SetWheelRadius(int wheelRadius) 
	{
		this->wheelRadius = wheelRadius;
	}
	int GetWheelRadius() 
	{
		return wheelRadius;
	}
	void SetNumOfTransmissions(int numOfTransmissions)
	{
		this->numOfTransmissions = numOfTransmissions;
	}
	int GetNumOfTransmissions()
	{
		return numOfTransmissions;
	}
	void SetTypeOfTransmission(string typeOfTransmission)
	{
		this->typeOfTransmission = typeOfTransmission;
	}
	std::string GetTypeOfTransmission()
	{
		return typeOfTransmission;
	}
	void Print() 
	{
		cout << "New car\n";
		cout << "\nBody: " << body;
		cout << "\nEngine power: " << EnginePower;
		cout << "\nWheel Radius: " << wheelRadius;
		cout << "\nTransmission Type: " << typeOfTransmission;
		cout << "\nNumber of Transmissions: " << numOfTransmissions;
	}
};

class CarFactory abstract 
{
protected:
	Car car;
public:
	Car GetCar() 
	{
		return car;
	}
	virtual void BuildBody() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildGearbox() abstract; 
	virtual void BuildWheel() abstract;
};
class DaewooLanosFactory : public CarFactory 
{
public:
	void BuildBody() override
	{
		car.SetBody("Sedan");
	};
	void BuildWheel()
	{
		car.SetWheelRadius(13);
	};
	void BuildEngine() 
	{
		car.SetEnginePower(98);
	};
	void BuildGearbox()
	{
		car.SetNumOfTransmissions(5);
		car.SetTypeOfTransmission("Manual");
	};
};

class FordProbeFactory : public CarFactory
{
public:
	void BuildBody() override
	{
		car.SetBody("Coupe ");
	};
	void BuildEngine()
	{
		car.SetEnginePower(160);
	};
	void BuildWheel()
	{
		car.SetWheelRadius(14);
	};
	void BuildGearbox() 
	{
		car.SetNumOfTransmissions(4);
		car.SetTypeOfTransmission("Auto");
	};
};

class UAZPatriotFactory : public CarFactory 
{
public:
	void BuildBody() override
	{
		car.SetBody("Universal");
	};
	void BuildEngine()
	{
		car.SetEnginePower(120);
	};
	void BuildWheel() 
	{
		car.SetWheelRadius(16);
	};
	void BuildGearbox() 
	{
		car.SetNumOfTransmissions(4);
		car.SetTypeOfTransmission("Manual");
	};
};

class HyundaiGetzFactory : public CarFactory
{
public:
	void BuildBody() override
	{
		car.SetBody("Hatchback");
	};
	void BuildEngine()
	{
		car.SetEnginePower(66);
	};
	void BuildWheel()
	{
		car.SetWheelRadius(13);
	};
	void BuildGearbox()
	{
		car.SetNumOfTransmissions(4);
		car.SetTypeOfTransmission("Auto");
	};
};

class Shop
{
	CarFactory* carFactory;
public:
	void SetCarFactory(CarFactory* carFactory)
	{
		this->carFactory = carFactory;
	}
	Car GetCar()
	{
		return carFactory->GetCar();
	}
	void ConstructCar()
	{
		carFactory->BuildBody();
		carFactory->BuildEngine();
		carFactory->BuildWheel();
		carFactory->BuildGearbox();
	}
};

void Client(CarFactory* carFactory) 
{
	Shop shop;
	shop.SetCarFactory(carFactory);
	shop.ConstructCar();
	Car car = shop.GetCar();
	car.Print();
}

int main() 
{

	CarFactory* car = new DaewooLanosFactory();
	Client(car);
	delete car;

	car = new FordProbeFactory();
	Client(car);
	delete car;

	car = new UAZPatriotFactory();
	Client(car);
	delete car;

	cout << "\n\n\tAdd new car\t\n";
	CarFactory* AddNewcar = new HyundaiGetzFactory();
	Client(AddNewcar);
	delete AddNewcar;

	

	return 0;
}