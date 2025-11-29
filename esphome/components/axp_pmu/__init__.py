import esphome.codegen as cg
from esphome.components import i2c
import esphome.config_validation as cv
from esphome.const import CONF_ID

DEPENDENCIES = ["i2c"]

CONF_AXP2101_ID = "axp2101_id"


axp_pmu_ns = cg.esphome_ns.namespace("axp_pmu")
AxpPMU = axp_pmu_ns.class_("AxpPMU", i2c.I2CDevice)
Axp2101 = axp_pmu_ns.class_("AXP2101", AxpPMU, cg.PollingComponent)

CONF_BATT_VOLTAGE = "battery_voltage"

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(Axp2101),
        }
    )
    .extend(i2c.i2c_device_schema(0x34))
    .extend(cv.polling_component_schema("60s"))
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add_define("XPOWERS_CHIP_AXP2101")
    cg.add_library("XPowersLib", "0.3.1")
