#pragma once
#include "network.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

#define ADDRESS { 130, 240, 40, 7 }
#define PORT 49152

int main()
{
	spark::MsgHead head = { sizeof(spark::JoinMsg), 1, 1, spark::MsgType::JOIN };
	spark::JoinMsg join = { head, spark::ObjectDesc::HUMAN, spark::ObjectForm::CONE, "sparky" };

	char mData[sizeof(join)];
	memcpy(mData, &join, sizeof(join));

	char mmData[sizeof(spark::JoinMsg)];
	spark::Msg::Join("Sparky", 1, spark::ObjectDesc::HUMAN, spark::ObjectForm::CONE, mmData);
	

	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	//char message[] = "GET / HTTP/1.1\r\n\r\n";
	char *server_reply = new char[2000];
	int sent_size, recv_size;

	// Winsock init
	std::cout << "Initializing Winsock.." << std::endl;
	if (WSAStartup(MAKEWORD(2,2), &wsa) !=0)
	{
		std::cout << "Failed: Error code : " << WSAGetLastError() << std::endl;
	}
	std::cout << "Initialized" << std::endl;

	// Socket init
	std::cout << "\nCreating socket.." << std::endl;
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		std::cout << "Could not create socket : " << WSAGetLastError() << std::endl;
	}
	std::cout << "Socket created" << std::endl;

	//Server init
	std::cout << "\nInitializing socket data.." << std::endl;
	const char addr[] = "130.240.40.7";			// Linux
	//const char addr[] = "172.217.20.36";		// Google
	if (inet_pton(AF_INET, addr, &(server.sin_addr))  != 1)
	{
		std::cout << "Failed: Error code : " << WSAGetLastError() << std::endl;
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(49152);				// Linux
	//server.sin_port = htons(80);				// Google
	std::cout << "Socket data initialied" << std::endl;

	// Connect to remote server
	std::cout << "\nConnection to server.." << std::endl;
	if (connect(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		std::cout << "Connection error : " << WSAGetLastError() << std::endl;
	}
	std::cout << "Connected" << std::endl;

	// Send data
	std::cout << "\nSending data.." << std::endl;
	if ((sent_size = send(s, mData, sizeof(mData), 0)) == SOCKET_ERROR)				// Linux
	//if ((sent_size = send(s, message, strlen(message), 0)) == SOCKET_ERROR)		// Google
	{
		std::cout << "Error sending data : " << WSAGetLastError() << std::endl;
	}
	std::cout << "Sent " << sent_size << " bytes of data" << std::endl;

	// Receive data
	std::cout << "\nReceiving data.." << std::endl;
	if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR)
	{
		std::cout << "Error receiving data : " << WSAGetLastError() << std::endl;
	}
	std::cout << "Received " << recv_size << " bytes of data" << std::endl << std::endl;

	if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR)
	{
		std::cout << "Error receiving data : " << WSAGetLastError() << std::endl;
	}
	std::cout << "Received " << recv_size << " bytes of data" << std::endl << std::endl;


	server_reply[recv_size-1] = '\0';

	
	std::cout << server_reply;



	// Cleanup
	closesocket(s);
	WSACleanup();


	delete[] server_reply;
	server_reply = nullptr;
}