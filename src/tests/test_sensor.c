/*
 * Copyright (c) 2023, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "platform.h"
#if PL_CONFIG_USE_UNIT_TESTS
#include "test_sensor.h"
#include "unity.h"
#include "sensor.h"
#include "McuRTOS.h"

void TestSensor_Humidity(void) {
  float h;
  h = Sensor_GetHumidity();
  TEST_ASSERT_GREATER_OR_EQUAL_FLOAT(0.0f, h);
  TEST_ASSERT_LESS_OR_EQUAL_FLOAT(100.0f, h);
}

void TestSensor_Temperature(void) {
  float t;
  t = Sensor_GetTemperature();
  TEST_ASSERT_GREATER_OR_EQUAL_FLOAT(-10.0f, t);
  TEST_ASSERT_LESS_OR_EQUAL_FLOAT(100.0f, t);
}

void TestSensor_Both(void) {
  float h, t;
  
  h = Sensor_GetHumidity();
  t = Sensor_GetTemperature();
  TEST_ASSERT_FLOAT_WITHIN(50.0f, 50.0f, h); /* +/-50 around 50 */
  TEST_ASSERT_FLOAT_WITHIN(30.0f, 25.0f, t); /* +/-30 around 25 */
  //TEST_ASSERT(false); /* just testing a failure */
}
#endif /* PL_CONFIG_USE_UNIT_TESTS */