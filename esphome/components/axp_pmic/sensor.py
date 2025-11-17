import esphome.codegen as cg
from esphome.components import sensor
import esphome.config_validation as cv
from esphome.const import (
    CONF_NAME,
    DEVICE_CLASS_VOLTAGE,
    STATE_CLASS_MEASUREMENT,
    UNIT_MILLIVOLT,
)

from . import CONF_AXP2101_ID, Axp2101

DEPENDENCIES = ["axp_pmic"]

CONF_BATT_VOLTAGE = "battery_voltage"

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.Optional(CONF_BATT_VOLTAGE): cv.maybe_simple_value(
                sensor.sensor_schema(
                    unit_of_measurement=UNIT_MILLIVOLT,
                    accuracy_decimals=0,
                    device_class=DEVICE_CLASS_VOLTAGE,
                    state_class=STATE_CLASS_MEASUREMENT,
                ),
                key=CONF_NAME,
            ),
        }
    )
    .extend({cv.GenerateID(CONF_AXP2101_ID): cv.use_id(Axp2101)})
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    paren = await cg.get_variable(config[CONF_AXP2101_ID])

    if CONF_BATT_VOLTAGE in config:
        sens = await sensor.new_sensor(config[CONF_BATT_VOLTAGE])
        cg.add(paren.set_battery_voltage_sensor(sens))
