#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "UP_API.h"
#include "UP_DATA.h"

int main(int argc, char * argv[]) {
  int res;
  BYTE b8Val;
  /** Initialize the SDK **/
  res = Initialize();
  if (res != MONITOR_SUCCESS) {
    fprintf(stderr, "Error initializing SDK\n");
    return 1;
  }
  /** Get Available Monitors **/
  MonitorDetailStructType * arrMonitorDetail = NULL;
  res = GetAvailableMonitorsDetail( & b8Val, & arrMonitorDetail);
  if (res != MONITOR_SUCCESS) {
    fprintf(stderr, "Error discovering supported monitors\n");
    Shutdown();
    return 1;
  }
  /** Check if any supported monitor found **/
  if (b8Val == 0) {
    fprintf(stderr, "No supported monitor found\n");
    free(arrMonitorDetail);
    Shutdown();
    return 1;
  }
  /** OPTIONAL - Let's print out **/
  for (int m = 0; m < (int) b8Val; m++) {
    fprintf(stdout, "[%d] Monitor: %s / ServiceTag %s ", m,
      arrMonitorDetail[m].MonitorName, arrMonitorDetail[m].ServiceTag);
    free(arrMonitorDetail);
    /** Connect to the first monitor **/
    res = ConnectMonitor(0);
    if (res != MONITOR_SUCCESS) {
      fprintf(stderr, "Error connecting to monitor[0]\n");
      Shutdown();
      return 1;
    }
  }

  /** Switch to Color Space Native **/
  res = SetColorSpaceState(COLOR_SPACE2_NATIVE);
  if (res != MONITOR_SUCCESS) {
    fprintf(stderr, "Error switching to color space NATIVE\n");
    Shutdown();
    return 1;
  }
  /** Set the luminance to lowest **/
  res = SetLuminance(45);
  if (res != MONITOR_SUCCESS) {
    fprintf(stderr, "Error setting luminance level to 45\n");
    Shutdown();
    return 1;
  }
  /**********************************************************/
  /** END OF OUR SIMPLE APPLICATION PROCESS **/ /**********************************************************/
  /** Disconnect Monitor **/
  res = DisconnectMonitor();
  /** Shutdown SDK **/
  res = Shutdown();
  return 0;
}
