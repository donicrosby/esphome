#pragma once

#include "esphome/components/i2c/i2c.h"
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/hal.h"
#include "esphome/core/defines.h"
#include "XPowersLib.h"

namespace esphome {
namespace axp_pmic {

class AxpPmic : public i2c::I2CDevice, public sensor::Sensor, public PollingComponent {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  void update() override;

 protected:
  // Return the set voltage for each power channel
  // If voltage is zero the channel is disabled
  // The subclassed PMU class will handle storing the proper voltage settings for a specific PMU
  virtual uint16_t get_dcdc1_voltage() { return 0; }
  virtual uint16_t get_dcdc2_voltage() { return 0; }
  virtual uint16_t get_dcdc3_voltage() { return 0; }
  virtual uint16_t get_dcdc4_voltage() { return 0; }
  virtual uint16_t get_dcdc5_voltage() { return 0; }
  virtual uint16_t get_ldo1_voltage() { return 0; }
  virtual uint16_t get_ldo2_voltage() { return 0; }
  virtual uint16_t get_ldo3_voltage() { return 0; }
  virtual uint16_t get_ldo4_voltage() { return 0; }
  virtual uint16_t get_ldo5_voltage() { return 0; }
  virtual uint16_t get_ldoio_voltage() { return 0; }
  virtual uint16_t get_aldo1_voltage() { return 0; }
  virtual uint16_t get_aldo2_voltage() { return 0; }
  virtual uint16_t get_aldo3_voltage() { return 0; }
  virtual uint16_t get_aldo4_voltage() { return 0; }
  virtual uint16_t get_bldo1_voltage() { return 0; }
  virtual uint16_t get_bldo2_voltage() { return 0; }
  virtual uint16_t get_dldo1_voltage() { return 0; }
  virtual uint16_t get_dldo2_voltage() { return 0; }
  virtual uint16_t get_vbackup_voltage() { return 0; }
  virtual uint16_t get_cpusldo_voltage() { return 0; }
  bool init_pmu();
  static int pmu_register_read(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len);
  static int pmu_register_write(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len);

  XPowersPMU pmu_;
  GPIOPin *irqPin;
};

static AxpPmic *global_pmu = nullptr;
}  // namespace axp_pmic
}  // namespace esphome
