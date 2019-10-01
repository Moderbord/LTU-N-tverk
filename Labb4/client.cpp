#pragma once
#include "network.h"
#include <winsock.h>
#include <iostream>

#define ADDRESS { 130, 240, 40, 7 }
#define PORT 49152

int main()
{

	WSADATA data;
	WSAStartup(MAKEWORD(2,2), &data);

	char message[] = "Heeeeej";

	sockaddr_in address;

	WSADATA wsaData;

	address.sin_family = AF_INET;
	address.sin_addr = ADDRESS;
	address.sin_port = htons(PORT);
	//address.sin_flowinfo = 0;
	//address.sin_scope_id = 0;

	wsaData.iMaxSockets = 0;
	wsaData.iMaxUdpDg = 0;
	wsaData.lpVendorInfo = 0;
	wsaData.wHighVersion = 0;
	wsaData.wVersion = 0;


	SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock == INVALID_SOCKET) {

		std::cout << WSAGetLastError() << std::endl; 
	}

	if (sendto(sock, message, 7, 0, (struct sockaddr*) & address, 32) == SOCKET_ERROR)
	{
		std::cout << WSAGetLastError() << std::endl;
	}

	closesocket(sock);
	WSACleanup();
		 


}