/****************************************************************************************************************************
  AsyncDNSServer_WT32_ETH01.h

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

#ifndef AsyncDNSServer_WT32_ETH01_h
#define AsyncDNSServer_WT32_ETH01_h

#if !( defined(ESP32) )
  #error This code is designed for WT32_ETH01 or (ESP32 + LAN8720) to run on ESP32 platform
#endif

////////////////////////////////////////////////

#define ASYNC_DNS_SERVER_WT32_ETH01_VERSION            "AsyncDNSServer_WT32_ETH01 v1.0.0"

#define ASYNC_DNS_SERVER_WT32_ETH01_VERSION_MAJOR      1
#define ASYNC_DNS_SERVER_WT32_ETH01_VERSION_MINOR      0
#define ASYNC_DNS_SERVER_WT32_ETH01_VERSION_PATCH      0

#define ASYNC_DNS_SERVER_WT32_ETH01_VERSION_INT        1000000

////////////////////////////////////////////////

#include <AsyncUDP_WT32_ETH01.h>
#include "AsyncDNSServer_WT32_ETH01_Debug.h"

////////////////////////////////////////////////

#include "AsyncDNSServer_WT32_ETH01.hpp"
#include "AsyncDNSServer_WT32_ETH01_Impl.h"

////////////////////////////////////////////////

#endif    // AsyncDNSServer_WT32_ETH01_h
