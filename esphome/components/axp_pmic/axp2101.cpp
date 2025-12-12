#include "esphome/core/log.h"
#include "axp2101.h"

namespace esphome {
namespace axp_pmic {

static const char *const TAG = "axp2101";

void AXP2101::setup() {
  ESP_LOGD(TAG, "Setup");
  // Initialization code here
  if (!this->init_pmu()) {
    ESP_LOGE(TAG, "Failed to initialize PMU");
    this->mark_failed();
  }
  if (!this->pmu_.enableBattVoltageMeasure()) {
    ESP_LOGE(TAG, "Failed to enable battery voltage measurement");
    this->mark_failed();
  }
}

void AXP2101::loop() {
  // Loop code here
  uint16_t batt_voltage = this->pmu_.getBattVoltage();
  this->batt_voltage_update_ = batt_voltage;
}

void AXP2101::update() {
  // Update sensor readings here
  this->batt_voltage_->publish_state(this->batt_voltage_update_);
}

void AXP2101::dump_config() {
  ESP_LOGCONFIG(TAG, "AXP2101:");
  LOG_I2C_DEVICE(this);

  // Dump configuration here
}

}  // namespace axp_pmic
}  // namespace esphome
