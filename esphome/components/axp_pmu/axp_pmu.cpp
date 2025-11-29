#include "esphome/core/log.h"
#include "axp_pmu.h"

namespace esphome {
namespace axp_pmu {

static const char *TAG = "axp_pmu";

bool AxpPMU::setup_pmu() {
  ESP_LOGD(TAG, "Setting up PMU");
  if (global_pmu == nullptr) {
    global_pmu = this;
  } else {
    ESP_LOGE(TAG, "Only one AXP PMU instance is supported");
    return false;
  }

  return this->pmu_.begin(this->address_, AxpPMU::pmu_register_read, AxpPMU::pmu_register_write);
}

void AxpPMU::setup() {
  if (!this->setup_pmu()) {
    this->mark_failed();
    return;
  }
  if (!this->setup_voltages()) {
    this->mark_failed();
    return;
  }
  ESP_LOGD(TAG, "Setup complete");
}

int AxpPMU::pmu_register_read(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len) {
  AxpPMU *self = global_pmu;
  if (self == nullptr) {
    return -1;
  }

  if (addr != self->address_) {
    ESP_LOGE(TAG, "Invalid PMU address; addr = %02X", addr);
    return -1;
  }

  if (self->read_register(regAddr, data, len) != i2c::ErrorCode::NO_ERROR) {
    return -1;
  }

  return i2c::ErrorCode::NO_ERROR;
}

int AxpPMU::pmu_register_write(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len) {
  AxpPMU *self = global_pmu;
  if (self == nullptr) {
    return -1;
  }

  if (addr != self->address_) {
    ESP_LOGE(TAG, "Invalid PMU address; addr = %02X", addr);
    return -1;
  }

  if (self->write_register(regAddr, data, len) != i2c::ErrorCode::NO_ERROR) {
    return -1;
  }

  return i2c::ErrorCode::NO_ERROR;
}

}  // namespace axp_pmu
}  // namespace esphome
