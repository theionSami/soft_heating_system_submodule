#include "heating_controller.h"
#include <iostream>
#include <string>

enum options {
	CLOSE = 0,
	IS_CONNECTED = 1,
	RELOAD_CONFIG = 2,
	CONNECT = 3,
	SEND_CMD = 4,
	CHANGE_IP = 5,
	TURN_ON = 6,
	TURN_OFF = 7,
	GET_TEMP = 8,
	SET_TEMP = 9,
};

int main(int argc, char* argv[]) {
	heating_controller heatControl= heating_controller("127.0.0.1", 8881);
	options choices = CLOSE;
	int choice = -1;
	std::string cmd = "";
	std::string ip = "";
	double temp = 0;

	while (choice != CLOSE) {
		std::cout << "Please choose an option: \n";
		std::cout << "0: CLOSE\n";
		std::cout << "1: IS_CONNECTED\n";
		std::cout << "2: RELOAD_CONFIG\n";
		std::cout << "3: CONNECT\n";
		std::cout << "4: SEND_CMD\n";
		std::cout << "5: CHANGE_IP\n";
		std::cout << "6: TURN_ON\n";
		std::cout << "7: TURN_OFF\n";
		std::cout << "8: GET_TEMP\n";
		std::cout << "9: SET_TEMP\n";
		std::cin >> choice;

		switch (choice) {
		case CLOSE:
			break;
		case IS_CONNECTED:
			std::cout<<"status: "<<heatControl.get_heating_controller_status()<<"\n";
			break;
		case RELOAD_CONFIG:
			heatControl.reload_config_file();
			break;
		case CONNECT:
			heatControl.heating_controller_connect();
			break;
		case SEND_CMD:
			std::cout << "Enter command: ";
			std::cin >> cmd;
			std::cout << heatControl.sendDirectCmd(cmd) << "\n";
			break;
		case CHANGE_IP:
			std::cout << "Enter IP: ";
			std::cin >> ip;
			std::cout << "New IP: " << ip << "\n";
			break;
		case TURN_ON:
			heatControl.heating_controller_activate();
			break;
		case TURN_OFF:
			heatControl.heating_controller_deactivate();
			break;
		case GET_TEMP:
			heatControl.get_heating_sulfur_temperature();
			break;
		case SET_TEMP:
			std::cout << "Enter temperature: ";
			std::cin >> temp;
			heatControl.heating_controller_settemperature(temp);
			break;
		default:
			std::cout << "Invalid option. Please choose again.\n";
			break;
		}
	}

	return 0;
}
