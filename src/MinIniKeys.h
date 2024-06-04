/*
 * Copyright (c) 2022-2023, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MININIKEYS_H_
#define MININIKEYS_H_

/* strings and names used in minINI configuration file */

#include "platform.h"

#define NVMC_MININI_FILE_NAME       "settings.ini" /* 'file' name used */

#if PL_CONFIG_USE_WIFI
  /* section for WiFi settings
   * configure them using the shell and the following commands:
   * McuMinINI write settings.ini WiFi ssid YOUR_SSID
   * McuMinINI write settings.ini WiFi pass YOUR_PASSWORD
   */
  #define NVMC_MININI_SECTION_WIFI              "WiFi"
  #define NVMC_MININI_KEY_WIFI_SSID                "DROP TABLE *"     /* SSID of network */
  #define NVMC_MININI_KEY_WIFI_PASS                "microROS"     /* pass */
  #define NVMC_MININI_KEY_WIFI_HOSTNAME            "pico" /* hostname to be used */
#endif

#if PL_CONFIG_USE_MQTT_CLIENT
  /* section for MQTT settings */
  #define NVMC_MININI_SECTION_MQTT              "MQTT"
  #define NVMC_MININI_KEY_MQTT_BROKER              "broker"   /* broker IP */
  #define NVMC_MININI_KEY_MQTT_CLIENT              "client"   /* client ID */
  #define NVMC_MININI_KEY_MQTT_USER                "user"     /* username */
  #define NVMC_MININI_KEY_MQTT_PASS                "pass"     /* password */
#endif

#endif /* MININIKEYS_H_ */
