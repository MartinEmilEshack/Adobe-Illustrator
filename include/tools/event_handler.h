#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

class EventHandler
{
	protected:
		void (*callback_method)();

	public:
		EventHandler(void (*callback_method)());
		EventHandler(EventHandler &eh);

		~EventHandler(){}

		void run();
};

#endif
