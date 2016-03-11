#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/gpio.h>

static struct gpio bbb_gpios[] = {
    { 48, GPIOF_OUT_INIT_LOW,  "Motor P9_15" }, // default to OFF 
    { 51, GPIOF_OUT_INIT_LOW,  "Motor P9_16"   }, // default to OFF 
};

static int __init bbb_l293d_init(void)
{
    int err;
    err = gpio_request_array(bbb_gpios, ARRAY_SIZE(bbb_gpios));
    if (err){
        gpio_free_array(bbb_gpios, ARRAY_SIZE(bbb_gpios));
        return false;
    }
    gpio_export(bbb_gpios[0].gpio, true);
    gpio_export(bbb_gpios[1].gpio, true);

    return true;
}

static void __exit bbb_l293d_exit(void)
{
    gpio_unexport(bbb_gpios[0].gpio);
    gpio_unexport(bbb_gpios[1].gpio);
    gpio_free_array(bbb_gpios, ARRAY_SIZE(bbb_gpios));
}

module_init(bbb_l293d_init);
module_exit(bbb_l293d_exit);

/* Module information */
MODULE_AUTHOR("Heidi Ao <heidiao126@me.com>");
MODULE_DESCRIPTION("BBB l293d motor driver");
MODULE_LICENSE("GPL"); 
