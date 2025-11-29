#pragma once

#include "esphome/components/i2c/i2c.h"
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/hal.h"
#include "esphome/core/defines.h"
#include "esphome/core/optional.h"
#include "XPowersLib.h"

namespace esphome {
namespace axp_pmu {

class AxpPMU : public i2c::I2CDevice, public sensor::Sensor, public PollingComponent {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  void update() override;
  float get_setup_priority() const override { return setup_priority::HARDWARE; }

 protected:
  bool setup_pmu();
  virtual bool setup_voltages();

  static int pmu_register_read(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len);
  static int pmu_register_write(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len);

  XPowersPMU pmu_;

  GPIOPin *irqPin;
};

static AxpPMU *global_pmu = nullptr;
}  // namespace axp_pmu
}  // namespace esphome
