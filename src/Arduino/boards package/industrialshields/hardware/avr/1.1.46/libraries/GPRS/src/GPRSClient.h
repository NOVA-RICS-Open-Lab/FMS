#ifndef __GPRSCLIENT_H__
#define __GPRSCLIENT_H__

#include <Arduino.h>
#include <Client.h>

#if defined(HAVE_SIM800L)
#include "utilities/sim800l.h"
#else
#error "Undefined GPRS module"
#endif

class GPRSClient : public Client {
	public:
		explicit GPRSClient();
		explicit GPRSClient(uint8_t sock);

	public:
		virtual int connect(IPAddress ip, uint16_t port);
		virtual int connect(const char *host, uint16_t port);
		virtual size_t write(uint8_t);
		virtual size_t write(const uint8_t *buf, size_t size);
		virtual int available();
		virtual int read();
		virtual int read(uint8_t *buf, size_t size);
		virtual int peek();
		virtual void flush();
		virtual void stop();
		virtual uint8_t connected();
		virtual operator bool();

		inline bool isRemoteClient() const {
			return remoteClient;
		}

		using Print::write;

	private:
		bool remoteClient;
		uint8_t sock;
};

#endif
