#ifndef _EVENT_H_
#define _EVENT_H_

#include<string>

using namespace std;

class Event
{

	public:
		string event_title;
		void* event_data;

		Event(const string event_title, void* event_data);
		Event(const Event &e);

		~Event(){}

		string get_event_title();
		void* get_event_data();
};

#endif