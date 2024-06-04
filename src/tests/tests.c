/*
 * Copyright (c) 2023, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "platform.h"
#if PL_CONFIG_USE_UNIT_TESTS
#include "tests.h"
#include "unity.h"
#include "McuUnity.h"
#include "McuRTOS.h"
#include "McuShell.h"
#include "McuRTT.h"
#include "McuLog.h"
#include "test_sensor.h"
#include "test_leds.h"
#include "test_dns_resolver.h"

static void TestArgFailed(void) {
  TEST_ASSERT_MESSAGE(false, "wrong test_arg value, check JLinkScript file");
}

void Tests_Run(void) {
  int nofFailures;
  uint32_t test_arg;

  test_arg = McuUnity_GetArgument(); /* get test arguments */
  UNITY_BEGIN();
  switch(test_arg) {
    case 1: /* led */
      RUN_TEST(TestLeds_OnOff); 
      RUN_TEST(TestLeds_Toggle);
      break;
    case 2:  /* sensor */
      RUN_TEST(TestSensor_Temperature);
      RUN_TEST(TestSensor_Humidity);
      RUN_TEST(TestSensor_Both);
      break;
    case 3:
      RUN_TEST(TestDnsResolver_Test);
      break;
    default:  RUN_TEST(TestArgFailed); break;
  }
  nofFailures = UNITY_END();
  /* report failed or pass */
  if (nofFailures==0) {
    McuShell_SendStr("*** PASSED ***\n", McuRTT_stdio.stdOut);
  } else {
    McuShell_SendStr("*** FAILED ***\n", McuRTT_stdio.stdOut);
  }
  McuShell_SendStr("*STOP*\n", McuRTT_stdio.stdOut); /* stop JRun */
}

static void TestTask(void *pv) {
  McuLog_info("starting test task");
  vTaskDelay(pdMS_TO_TICKS(100)); /* give sensor some time */
  Tests_Run();
  vTaskDelete(NULL); /* terminate task */
}

void Tests_Init(void) {
  if (xTaskCreate(
      TestTask,  /* pointer to the task */
      "Test", /* task name for kernel awareness debugging */
      1500/sizeof(StackType_t), /* task stack size */
      (void*)NULL, /* optional task startup argument */
      tskIDLE_PRIORITY,  /* initial priority */
      (TaskHandle_t*)NULL /* optional task handle to create */
    ) != pdPASS)
  {
    McuLog_fatal("Failed creating task");
    for(;;){} /* error! probably out of memory */
  }
}
#endif /* PL_CONFIG_USE_UNIT_TESTS */