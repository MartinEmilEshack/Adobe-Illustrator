#include "event.h"

Event::Event(const string event_title, void *event_data)
{
	this->event_title = event_title;
	this->event_data = event_data;
}

Event::Event(const Event &e)
{
	this->event_title = e.event_title;
	this->event_data = e.event_data;
}

inline string Event::get_event_title()
{
	return event_title;
}

inline void *Event::get_event_data()
{
	return event_data;
}