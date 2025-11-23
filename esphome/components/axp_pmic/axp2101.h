#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "axp_pmic.h"

namespace esphome {
namespace axp_pmic {

class AXP2101 : public AxpPmic {
 public:
  void set_dcdc1_voltage(uint16_t voltage) { dcdc1_voltage_ = voltage; }
  void set_dcdc2_voltage(uint16_t voltage) { dcdc2_voltage_ = voltage; }
  void set_dcdc3_voltage(uint16_t voltage) { dcdc3_voltage_ = voltage; }
  void set_dcdc4_voltage(uint16_t voltage) { dcdc4_voltage_ = voltage; }
  void set_dcdc5_voltage(uint16_t voltage) { dcdc5_voltage_ = voltage; }
  void set_ldo1_voltage(uint16_t voltage) { ldo1_voltage_ = voltage; }
  void set_aldo1_voltage(uint16_t voltage) { aldo1_voltage_ = voltage; }
  void set_aldo2_voltage(uint16_t voltage) { aldo2_voltage_ = voltage; }
  void set_aldo3_voltage(uint16_t voltage) { aldo3_voltage_ = voltage; }
  void set_aldo4_voltage(uint16_t voltage) { aldo4_voltage_ = voltage; }
  void set_bldo1_voltage(uint16_t voltage) { bldo1_voltage_ = voltage; }
  void set_bldo2_voltage(uint16_t voltage) { bldo2_voltage_ = voltage; }
  void set_dldo1_voltage(uint16_t voltage) { dldo1_voltage_ = voltage; }
  void set_dldo2_voltage(uint16_t voltage) { dldo2_voltage_ = voltage; }
  void set_cpusldo_voltage(uint16_t voltage) { cpusldo_voltage_ = voltage; }

  void set_battery_voltage_sensor(sensor::Sensor *sensor) { batt_voltage_ = sensor; }

  void setup() override;
  void loop() override;
  void update() override;
  void dump_config() override;

 protected:
  uint16_t dcdc1_voltage_{0};
  uint16_t dcdc2_voltage_{0};
  uint16_t dcdc3_voltage_{0};
  uint16_t dcdc4_voltage_{0};
  uint16_t dcdc5_voltage_{0};
  uint16_t ldo1_voltage_{0};
  uint16_t aldo1_voltage_{0};
  uint16_t aldo2_voltage_{0};
  uint16_t aldo3_voltage_{0};
  uint16_t aldo4_voltage_{0};
  uint16_t bldo1_voltage_{0};
  uint16_t bldo2_voltage_{0};
  uint16_t dldo1_voltage_{0};
  uint16_t dldo2_voltage_{0};
  uint16_t cpusldo_voltage_{0};

  sensor::Sensor *batt_voltage_{nullptr};
  uint16_t batt_voltage_update_{0};
};
}  // namespace axp_pmic
}  // namespace esphome
