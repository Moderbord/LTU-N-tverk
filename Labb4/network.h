//#pragma once
//
//namespace spark
//{
//
//#define MAX_NAMELEN 32
//#define DEF_BUFLEN 512
//
//	struct MsgHead
//	{
//		unsigned int length;	// Total length for whole message
//		unsigned int seq_no;	// Sequence number
//		unsigned int id;		// Client ID or 0
//		MsgType type;			// Type of message
//	};
//
//	struct JoinMsg
//	{
//		MsgHead head;
//		ObjectDesc desc;
//		//ClientForm form;
//		char name[MAX_NAMELEN];
//	};
//
//	struct LeaveMsg
//	{
//		MsgHead head;
//	};
//
//	struct ChangeMsg
//	{
//		MsgHead head;
//		ChangeType type;
//	};
//
//	struct MewPlayerMessage
//	{
//		ChangeMsg msg;		//Change message header with new client id
//		ObjectDesc desc;
//		ObjectDesc form;
//		char name[MAX_NAMELEN];
//	};
//
//	struct PlayerLeaveMsg
//	{
//		ChangeMsg msg;		//Change message header with new client id
//	};
//
//	struct NewPlayerPositionMsg
//	{
//		ChangeMsg msg;		//Change message header
//		Coordinate pos;		//New object position 
//		Coordinate dir;		//New object direction 
//	};
//
//	struct Coordinate
//	{
//		int x;
//		int y;
//	};
//
//	struct EventMsg
//	{
//		MsgHead head;
//		EventType type;
//	};
//
//	enum MsgType
//	{
//		JOIN,			// Client joining game at server
//		LEAVE,			// Client leaving game
//		CHANGE,			// Information to clients
//		EVENT,			// Information from clients to server
//		TEXT_MESSAGE	// Send text messages to one or all
//	};
//
//	enum ChangeType
//	{
//		NEW_PLAYER,
//		PLAYER_LEAVE,
//		NEW_PLAYER_POSITION
//	};
//
//	enum ObjectDesc
//	{
//		HUMAN,
//		NON_HUMAN,
//		VEHICLE,
//		STATIC_OBJECT
//	};
//
//	enum ObjectForm
//	{
//		CUBE,
//		SPHERE,
//		PYRAMID,
//		CONE
//	};
//
//	enum EventType
//	{
//		MOVE
//	};
//
//}