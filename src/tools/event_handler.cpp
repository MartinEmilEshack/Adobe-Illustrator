#include"event_handler.h"

EventHandler::EventHandler(void (*callback_method)())
{
	this->callback_method = callback_method;
}

EventHandler::EventHandler(EventHandler &eh)
{
	this->callback_method = eh.callback_method;
}

void EventHandler::run()
{
	(*(*this).callback_method)();
}