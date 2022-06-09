/**
* @file main
*
*/

/*********************
*      INCLUDES
*********************/
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED        /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_examples/lv_examples.h"
#include "lv_lib_bmp/lv_bmp.h"
#include "porting/lv_port_fs.h"
#include "my_examples/my_examples.h"

#include "Demo_1/Inc/smart_app.h"
#include "Demo_1/Inc/smart_program.h"
#include "Demo_1/Inc/smart_smartctrl_page.h"



/*********************
*      DEFINES
*********************/

/**********************
*      TYPEDEFS
**********************/

/**********************
*  STATIC PROTOTYPES
**********************/
static void hal_init(void);
static int tick_thread(void *data);

/**********************
*  STATIC VARIABLES
**********************/
static lv_indev_t * kb_indev;

/**********************
*      MACROS
**********************/

/**********************
*   GLOBAL FUNCTIONS
**********************/

int main(int argc, char** argv)
{
    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL for LittlevGL*/
    hal_init();

    /* Add win32 filesystem drive */
    lv_port_fs_init();

    /* Initialize bmp decoder */
    lv_bmp_init();

    /*
     * My demo.
     */
   // my_bmp_1();
    //app_create();             // 安卓风格

    Smart_App_Demo();

    
    /*
     * Demo, benchmark, tests and tutorial.
     *
     * Uncomment any one (and only one) of the functions below to run that
     * particular demo, test or tutorial.
     */


    // lv_demo_benchmark();

    // lv_demo_keypad_encoder();

    // lv_demo_music();

    // lv_demo_printer();

    // lv_demo_stress();

    // lv_demo_widgets();

    // lv_ex_get_started_1();
    // lv_ex_get_started_2();
    // lv_ex_get_started_3();

    // lv_ex_style_1();
    // lv_ex_style_2();
    // lv_ex_style_3();
    // lv_ex_style_4();
    // lv_ex_style_5();
    // lv_ex_style_6();
    // lv_ex_style_7();
    // lv_ex_style_8();
    // lv_ex_style_9();
    // lv_ex_style_10();
    // lv_ex_style_11();

    // lv_ex_arc_1();
    // lv_ex_arc_2();
    // lv_ex_bar_1();
    // lv_ex_btn_1();
    // lv_ex_btn_2();
    // lv_ex_btnmatrix_1();
    // lv_ex_calendar_1();
    // lv_ex_canvas_1();
    // lv_ex_canvas_2();
    // lv_ex_checkbox_1();
    // lv_ex_chart_1();
    // lv_ex_chart_2();
    // lv_ex_cont_1();
    // lv_ex_cpicker_1();
    // lv_ex_dropdown_1();
    // lv_ex_dropdown_2();
    // lv_ex_gauge_1();
    // lv_ex_img_1();
    // lv_ex_img_2();
    // lv_ex_img_3();
    // lv_ex_imgbtn_1();
    // lv_ex_keyboard_1();
    // lv_ex_label_1();
    // lv_ex_label_2();
    // lv_ex_label_3();
    // lv_ex_led_1();
    // lv_ex_line_1();
    // lv_ex_list_1();
    // lv_ex_linemeter_1();
    // lv_ex_msgbox_1();
    // lv_ex_msgbox_2();
    // lv_ex_obj_1();
    // lv_ex_page_1();
    // lv_ex_spinner_1();
    // lv_ex_roller_1();
    // lv_ex_slider_1();
    // lv_ex_slider_2();
    // lv_ex_spinbox_1();
    // lv_ex_switch_1();
    // lv_ex_textarea_1();
    // lv_ex_textarea_2();
    // lv_ex_textarea_3();
    // lv_ex_objmask_1();
    // lv_ex_table_1();
    // lv_ex_tabview_1();
    // lv_ex_tileview_1();
    // lv_ex_win_1();

    while (1) {
        /* Periodically call the lv_task handler.
        * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        Sleep(10);       /*Just to let the system breathe */
    }

    return 0;
}

/**********************
*   STATIC FUNCTIONS
**********************/


/**
* Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library
*/
static void hal_init(void)
{
    /* Add a display
    * Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    monitor_init();

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);            /*Basic initialization*/

    static lv_disp_buf_t disp_buf1;
    static lv_color_t buf1_1[LV_HOR_RES_MAX*LV_VER_RES_MAX];
    static lv_color_t buf1_2[LV_HOR_RES_MAX*LV_VER_RES_MAX];
    lv_disp_buf_init(&disp_buf1, buf1_1, buf1_2, LV_HOR_RES_MAX*LV_VER_RES_MAX);

    disp_drv.buffer = &disp_buf1;
    disp_drv.flush_cb = monitor_flush;
    lv_disp_drv_register(&disp_drv);

    /* Add the mouse (or touchpad) as input device
    * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = mouse_read;         /*This function will be called periodically (by the library) to get the mouse position and state*/
    lv_indev_drv_register(&indev_drv);

    /* If the PC keyboard driver is enabled in`lv_drv_conf.h`
    * add this as an input device. It might be used in some examples. */
#if USE_KEYBOARD
    lv_indev_drv_t kb_drv;
    lv_indev_drv_init(&kb_drv);
    kb_drv.type = LV_INDEV_TYPE_KEYPAD;
    kb_drv.read_cb = keyboard_read;
    kb_indev = lv_indev_drv_register(&kb_drv);
#endif

    /* Tick init.
    * You have to call 'lv_tick_inc()' in every milliseconds
    * Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);
}

/**
* A task to measure the elapsed time for LittlevGL
* @param data unused
* @return never return
*/
static int tick_thread(void *data)
{
    while (1) {
        lv_tick_inc(5);
        SDL_Delay(5);   /*Sleep for 1 millisecond*/
    }

    return 0;
}
