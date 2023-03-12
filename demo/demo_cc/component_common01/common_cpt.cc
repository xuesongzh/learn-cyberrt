#include "cyber/demo_cc/component_common01/common_cpt.h"

bool CommonCpt::Init() {
  AINFO << "................................... int .........................";
  return true;
}

bool CommonCpt::Proc(const std::shared_ptr<Student>& stu) {
  AINFO << "name = " << stu->name() << ", age = " << stu->age();
  return true;
}