#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/gpio.h>


/*
#include <linux/interrupt.h>

    int gpio_is_valid(int number);
    int gpio_direction_input(unsigned gpio);
    int gpio_direction_output(unsigned gpio, int value);

    // GPIO INPUT:  return zero or nonzero 
    int gpio_get_value(unsigned gpio);

    // GPIO OUTPUT 
    void gpio_set_value(unsigned gpio, int value);

    // release previously-claimed GPIO 
    void gpio_free(unsigned gpio);

*/
struct mgpio {
    unsigned    gpio;
    unsigned long   flags;
    const char  *label;
};

static struct mgpio motor_gpios[] = {
    { 15, GPIOF_OUT_INIT_LOW,  "Motor P9_15" }, /* default to OFF */
    { 16, GPIOF_OUT_INIT_LOW,  "Motor P9_16"   }, /* default to OFF */
};


static int __init bbb_l293d_init(void)
{
    int err;
    err = gpio_request_array(motor_gpios, ARRAY_SIZE(motor_gpios));
    if (err)
        gpio_free_array(motor_gpios, ARRAY_SIZE(motor_gpios));

    return true;
   // return i2c_add_driver(&mxt_driver);
}

static void __exit bbb_l293d_exit(void)
{
    gpio_free_array(motor_gpios, ARRAY_SIZE(motor_gpios));
//    i2c_del_driver(&mxt_driver);
}

module_init(bbb_l293d_init);
module_exit(bbb_l293d_exit);

/* Module information */
MODULE_AUTHOR("Heidi Ao <heidiao126@me.com>");
MODULE_DESCRIPTION("BBB l293d motor driver");
MODULE_LICENSE("GPL"); 
