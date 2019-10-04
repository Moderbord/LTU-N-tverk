#pragma once

#include <cstring>
#include <string>

namespace spark
{

#define MAX_NAMELEN 32
#define DEF_BUFLEN 512

	enum MsgType
	{
		JOIN,			// Client joining game at server
		LEAVE,			// Client leaving game
		CHANGE,			// Information to clients
		EVENT,			// Information from clients to server
		TEXT_MESSAGE	// Send text messages to one or all
	};

	enum ChangeType
	{
		NEW_PLAYER,
		PLAYER_LEAVE,
		NEW_PLAYER_POSITION
	};

	enum ObjectDesc
	{
		HUMAN,
		NON_HUMAN,
		VEHICLE,
		STATIC_OBJECT
	};

	enum ObjectForm
	{
		CUBE,
		SPHERE,
		PYRAMID,
		CONE
	};

	enum EventType
	{
		MOVE
	};

	struct MsgHead
	{
		unsigned int length;	// Total length for whole message
		unsigned int seq_no;	// Sequence number
		unsigned int id;		// Client ID or 0
		MsgType type;			// Type of message
	};

	struct JoinMsg
	{
		MsgHead head;
		ObjectDesc desc;
		ObjectForm form;
		char name[MAX_NAMELEN];
	};

	struct LeaveMsg
	{
		MsgHead head;
	};

	struct ChangeMsg
	{
		MsgHead head;
		ChangeType type;
	};

	struct NewPlayerMessage
	{
		ChangeMsg msg;		//Change message header with new client id
		ObjectDesc desc;
		ObjectDesc form;
		char name[MAX_NAMELEN];
	};

	struct PlayerLeaveMsg
	{
		ChangeMsg msg;		//Change message header with new client id
	};

	struct Coordinate
	{
		int x;
		int y;
	};

	struct NewPlayerPositionMsg
	{
		ChangeMsg msg;		//Change message header
		Coordinate pos;		//New object position 
		Coordinate dir;		//New object direction 
	};

	struct EventMsg
	{
		MsgHead head;
		EventType type;
	};



	class Msg
	{
	public:

		static void Join(const std::string sName, unsigned int id, ObjectDesc desc, ObjectForm form, char* buf, unsigned int& seqNm)
		{
			MsgHead head = { sizeof(JoinMsg), seqNm, id, spark::MsgType::JOIN };
			JoinMsg join = { head, desc, form, "" };
			memcpy(join.name, sName.c_str(), sName.size());
			memcpy(buf, &join, sizeof(join));
			seqNm++;
		}



	
	};


}