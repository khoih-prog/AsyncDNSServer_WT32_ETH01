/****************************************************************************************************************************
  AsyncDNSServer_WT32_ETH01.hpp

  For WT32_ETH01 (ESP32 + LAN8720)

  AsyncDNSServer_WT32_ETH01 is a Async DNS Server library for the WT32_ETH01

  Based on and modified from ESPAsyncDNSServer Library (https://github.com/devyte/ESPAsyncDNSServer)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncDNSServer_WT32_ETH01
  Licensed under MIT license

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      28/11/2022 Initial coding for WT32_ETH01. Sync with AsyncDNSServer_STM32
  *****************************************************************************************************************************/

#pragma once

#ifndef AsyncDNSServer_WT32_ETH01_hpp
#define AsyncDNSServer_WT32_ETH01_hpp

////////////////////////////////////////////////

#define ASYNC_DNS_SERVER_WT32_ETH01_VERSION      "AsyncDNSServer_WT32_ETH01 v1.0.0"

////////////////////////////////////////////////

#include <AsyncUDP_WT32_ETH01.hpp>
#include "AsyncDNSServer_WT32_ETH01_Debug.h"

////////////////////////////////////////////////

#define DNS_QR_QUERY 0
#define DNS_QR_RESPONSE 1
#define DNS_OPCODE_QUERY 0

////////////////////////////////////////////////

enum class AsyncDNSReplyCode : unsigned char
{
  NoError = 0,
  FormError = 1,
  ServerFailure = 2,
  NonExistentDomain = 3,
  NotImplemented = 4,
  Refused = 5,
  YXDomain = 6,
  YXRRSet = 7,
  NXRRSet = 8
};

////////////////////////////////////////////////

class AsyncDNSServer
{
  public:
    AsyncDNSServer();
    void setErrorReplyCode(const AsyncDNSReplyCode &replyCode);
    void setTTL(const uint32_t ttl);

    // Returns true if successful, false if there are no sockets available
    bool start(const uint16_t port, const String &domainName, const IPAddress &resolvedIP);

    // stops the DNS server
    void stop();

  private:
    AsyncUDP _udp;
    uint16_t _port;
    String _domainName;
    unsigned char _resolvedIP[4];
    uint32_t _ttl;
    AsyncDNSReplyCode _errorReplyCode;

    void processRequest(AsyncUDPPacket &packet);
    void replyWithIP(AsyncUDPPacket &packet);
    void replyWithCustomCode(AsyncUDPPacket &packet);
};

////////////////////////////////////////////////

#endif    // AsyncDNSServer_WT32_ETH01_hpp
