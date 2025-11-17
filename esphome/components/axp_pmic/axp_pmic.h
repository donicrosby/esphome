#pragma once

#include "esphome/components/i2c/i2c.h"
#include "esphome/core/defines.h"
#include "XPowersLib.h"

namespace esphome {
namespace axp_pmic {

class AxpPmic : public i2c::I2CDevice {
 public:
  bool init_pmu();
  static int pmu_register_read(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len);
  static int pmu_register_write(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len);

 protected:
  XPowersPMU pmu_;
};

static AxpPmic *global_pmu = nullptr;
}  // namespace axp_pmic
}  // namespace esphome
