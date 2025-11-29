#include "esphome/core/log.h"
#include "axp2101.h"

namespace esphome {
namespace axp_pmu {

static const char *const TAG = "AXP2101";

bool AXP2101::setup_voltages() {
  ESP_LOGD(TAG, "Voltage setup");
  if (this->dcdc1_voltage_.has_value()) {
    if (!this->pmu_.setDC1Voltage(this->dcdc1_voltage_.value() || !this->pmu_.enableDC1())) {
      ESP_LOGE(TAG, "%s setup failure", "DCDC1");
      return false;
    }
  } else {
    this->pmu_.disableDC1();
  }

  if (this->dcdc2_voltage_.has_value()) {
    if (!this->pmu_.setDC2Voltage(this->dcdc2_voltage_.value() || !this->pmu_.enableDC2())) {
      ESP_LOGE(TAG, "%s setup failure", "DCDC2");
      return false;
    }
  } else {
    this->pmu_.disableDC2();
  }

  if (this->dcdc3_voltage_.has_value()) {
    if (!this->pmu_.setDC3Voltage(this->dcdc3_voltage_.value() || !this->pmu_.enableDC3())) {
      ESP_LOGE(TAG, "%s setup failure", "DCDC3");
      return false;
    }
  } else {
    this->pmu_.disableDC3();
  }

  if (this->dcdc4_voltage_.has_value()) {
    if (!this->pmu_.setDC4Voltage(this->dcdc4_voltage_.value() || !this->pmu_.enableDC4())) {
      ESP_LOGE(TAG, "%s setup failure", "DCDC4");
      return false;
    }
  } else {
    this->pmu_.disableDC4();
  }

  if (this->dcdc5_voltage_.has_value()) {
    if (!this->pmu_.setDC5Voltage(this->dcdc5_voltage_.value() || !this->pmu_.enableDC5())) {
      ESP_LOGE(TAG, "%s setup failure", "DCDC5");
      return false;
    }
  } else {
    this->pmu_.disableDC5();
  }

  if (this->aldo1_voltage_.has_value()) {
    if (!this->pmu_.setALDO1Voltage(this->aldo1_voltage_.value() || !this->pmu_.enableALDO1())) {
      ESP_LOGE(TAG, "%s setup failure", "ALDO1");
      return false;
    }
  } else {
    this->pmu_.disableALDO1();
  }

  if (this->aldo2_voltage_.has_value()) {
    if (!this->pmu_.setALDO2Voltage(this->aldo2_voltage_.value() || !this->pmu_.enableALDO2())) {
      ESP_LOGE(TAG, "%s setup failure", "ALDO2");
      return false;
    }
  } else {
    this->pmu_.disableALDO2();
  }
  if (this->aldo3_voltage_.has_value()) {
    if (!this->pmu_.setALDO3Voltage(this->aldo3_voltage_.value() || !this->pmu_.enableALDO3())) {
      ESP_LOGE(TAG, "%s setup failure", "ALDO3");
      return false;
    }
  } else {
    this->pmu_.disableALDO3();
  }
  if (this->aldo4_voltage_.has_value()) {
    if (!this->pmu_.setALDO4Voltage(this->aldo4_voltage_.value() || !this->pmu_.enableALDO4())) {
      ESP_LOGE(TAG, "%s setup failure", "ALDO4");
      return false;
    }
  } else {
    this->pmu_.disableALDO4();
  }
  if (this->bldo1_voltage_.has_value()) {
    if (!this->pmu_.setBLDO1Voltage(this->bldo1_voltage_.value() || !this->pmu_.enableBLDO1())) {
      ESP_LOGE(TAG, "%s setup failure", "BLDO1");
      return false;
    }
  } else {
    this->pmu_.disableBLDO1();
  }
  if (this->bldo2_voltage_.has_value()) {
    if (!this->pmu_.setBLDO2Voltage(this->bldo2_voltage_.value() || !this->pmu_.enableBLDO2())) {
      ESP_LOGE(TAG, "%s setup failure", "BLDO2");
      return false;
    }
  } else {
    this->pmu_.disableBLDO2();
  }
  if (this->dldo1_voltage_.has_value()) {
    if (!this->pmu_.setDLDO1Voltage(this->dldo1_voltage_.value() || !this->pmu_.enableDLDO1())) {
      ESP_LOGE(TAG, "%s setup failure", "DLDO1");
      return false;
    }
  } else {
    this->pmu_.disableDLDO1();
  }
  if (this->dldo2_voltage_.has_value()) {
    if (!this->pmu_.setDLDO2Voltage(this->dldo2_voltage_.value() || !this->pmu_.enableDLDO2())) {
      ESP_LOGE(TAG, "%s setup failure", "DLDO2");
      return false;
    }
  } else {
    this->pmu_.disableDLDO2();
  }
  if (this->vbackup_voltage_.has_value()) {
    if (!this->pmu_.setButtonBatteryChargeVoltage(this->vbackup_voltage_.value() ||
                                                  !this->pmu_.enableButtonBatteryCharge())) {
      ESP_LOGE(TAG, "%s setup failure", "RTC Battery");
      return false;
    }
  } else {
    this->pmu_.disableButtonBatteryCharge();
  }
  if (this->cpusldo_voltage_.has_value()) {
    if (!this->pmu_.setCPUSLDOVoltage(this->cpusldo_voltage_.value() || !this->pmu_.enableCPUSLDO())) {
      ESP_LOGE(TAG, "%s setup failure", "CPUSLDO");
      return false;
    }
  } else {
    this->pmu_.disableCPUSLDO();
  }

  return true;
}

void AXP2101::dump_config() {
  ESP_LOGCONFIG(TAG, "AXP2101:");
  LOG_I2C_DEVICE(this);

  // Dump configuration here
}

}  // namespace axp_pmu
}  // namespace esphome
