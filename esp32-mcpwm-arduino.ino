#include "driver/mcpwm.h"

#define GPIO_PWM0A_OUT 33
const uint8_t doPress = GPIO_PWM0A_OUT;  // PWM

void setup() {
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, doPress);
    mcpwm_config_t pwm_config = {};
    pwm_config.frequency = 1;
    pwm_config.cmpr_a = 0;
    pwm_config.cmpr_b = 0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_group_set_resolution(MCPWM_UNIT_0, 100000);
    mcpwm_timer_set_resolution(MCPWM_UNIT_0, MCPWM_TIMER_0, 1000);
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);

    // Frequency doesn't update till this is called.
    mcpwm_set_frequency(MCPWM_UNIT_0, MCPWM_TIMER_0, 1);

    // Set test duty cycle at 50%
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 50.0);
}

void loop() {}