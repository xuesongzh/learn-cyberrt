
#include "cyber/cyber.h"

int main(int argc, char *argv[]) {
  apollo::cyber::Init(argv[0]);

  AINFO << "INFO LOG";
  AWARN << "WARN LOG";
  AERROR << "ERROR LOG";
  AFATAL << "FATAL LOG";

  return 0;
}