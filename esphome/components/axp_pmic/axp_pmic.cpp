#include "esphome/core/log.h"
#include "axp_pmic.h"

namespace esphome {
namespace axp_pmic {

static const char *TAG = "axp_pmic";

bool AxpPmic::setup_pmu() {
  ESP_LOGD(TAG, "Setting up PMU");
  if (global_pmu == nullptr) {
    global_pmu = this;
  }

  return this->pmu_.begin(this->address_, AxpPmic::pmu_register_read, AxpPmic::pmu_register_write);
}

int AxpPmic::pmu_register_read(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len) {
  AxpPmic *self = global_pmu;
  if (!self) {
    return -1;
  }

  if (addr != self->address_) {
    ESP_LOGE(TAG, "Invalid PMU address; addr = %02X", addr);
    return -1;
  }

  return self->read_register(regAddr, data, len);
}

int AxpPmic::pmu_register_write(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t len) {
  AxpPmic *self = global_pmu;
  if (!self) {
    return -1;
  }

  if (addr != self->address_) {
    ESP_LOGE(TAG, "Invalid PMU address; addr = 0x %02X", addr);
    return -1;
  }

  return self->write_register(regAddr, data, len);
}

}  // namespace axp_pmic
}  // namespace esphome
