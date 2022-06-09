/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_program.c
 * \author    yifeng
 * \version   1.0
 * \date      2021??12??17??
 * \brief     ???????
 *
 *----------------------------------------------------------------------------
 * \attention
 *
 *
 *****************************************************************************
 */

/*****************************************************************************
 change history:
    1.date  : 2021??12??17??
      author: yifeng
      change: create file

*****************************************************************************/
#include "Demo_1/Inc/smart_program.h"
#include "Demo_1/Inc/smart_version_page.h"
#include "Demo_1/Inc/smart_device_page.h"
#include "Demo_1/Inc/smart_rfid_page.h"
#include "Demo_1/Inc/smart_setting_page.h"
#include "Demo_1/Inc/smart_phone_page.h"
#include "Demo_1/Inc/smart_history_page.h"
#include "Demo_1/Inc/smart_smartctrl_page.h"
#include "Demo_1/Inc/smart_photo_page.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static lv_obj_t *smart_taskbar1[3];
static lv_obj_t *smart_taskbar2[3];

static lv_obj_t *smart_backmainbtn[2];

static lv_obj_t *program_tileview;
static lv_obj_t *program_tile1;
static lv_obj_t *program_tile2;

static lv_obj_t *program_img;
static lv_obj_t *close_btn;

// ???????
static lv_obj_t *program_img1[4];
static lv_obj_t *program_img2[4];
static lv_obj_t *program_imglabel1[4];
static lv_obj_t *program_imglabel2[4];

LV_IMG_DECLARE(device);
LV_IMG_DECLARE(history);
LV_IMG_DECLARE(phone);
LV_IMG_DECLARE(photo);
LV_IMG_DECLARE(record);
LV_IMG_DECLARE(rfid);
LV_IMG_DECLARE(setting);
LV_IMG_DECLARE(smartctrl);
LV_IMG_DECLARE(time);
LV_IMG_DECLARE(version);
LV_IMG_DECLARE(Black_bg1);
LV_IMG_DECLARE(Black_bg);
LV_IMG_DECLARE(BackMain);

static const lv_img_dsc_t *program_img_array[8] =
{
  &device,  &time,
  &photo,   &smartctrl,
  &phone,   &setting,
  &history, &version,
};


static const char *program_img_name1[4] =
{
  "Device",
  "time",
  "Photo",
  "Led"
};

static const char *program_img_name2[4] =
{
  "Phone",
  "Setting",
  "History",
  "Version"
};

static int program_icon_pos[4][2] =
{
  {64, 64},
  {192, 64},
  {64, 185},
  {192, 185},
};



static lv_event_cb_t program_img_click_event_cb(lv_obj_t *icon, lv_event_t e);
static lv_event_cb_t program_backmain_click_event_cb(lv_obj_t *icon, lv_event_t e);

static void smart_taskbar_create1(lv_obj_t *par);
static void smart_taskbar_create2(lv_obj_t *par);
/*!
 * \fn     Smart_Program_Create
 * \brief  ???????
 *
 * \param  [in] lv_obj_t* parent   #
 *
 * \retval void
 */
void Smart_Program_Create(lv_obj_t* parent)
{
  int i;
  static lv_point_t valid_pos[] = {{0,0}, {0, 1}};
  static lv_style_t style_label;

  lv_style_init(&style_label);
  lv_style_set_text_font(&style_label, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  lv_style_set_text_color(&style_label, LV_LABEL_PART_MAIN, LV_COLOR_WHITE);


  program_tileview = lv_tileview_create(parent, NULL);
  lv_tileview_set_valid_positions(program_tileview, valid_pos, 2);
  lv_tileview_set_edge_flash(program_tileview, true);

  program_tile1 = lv_img_create(program_tileview, NULL);
  lv_obj_set_size(program_tile1, LV_HOR_RES, LV_VER_RES);
  lv_img_set_src(program_tile1, &Black_bg1);
  lv_tileview_add_element(program_tileview, program_tile1);

  smart_taskbar_create1(program_tile1);
  /* 显示主页按钮 */
  smart_backmainbtn[0] = lv_imgbtn_create(program_tile1, NULL);
  lv_obj_set_event_cb(smart_backmainbtn[0], program_backmain_click_event_cb);
  lv_imgbtn_set_src(smart_backmainbtn[0], LV_BTN_STATE_RELEASED, &BackMain);
  lv_imgbtn_set_src(smart_backmainbtn[0], LV_BTN_STATE_PRESSED, &BackMain);
  lv_obj_align(smart_backmainbtn[0], program_tile1, LV_ALIGN_IN_BOTTOM_MID, 0, -8);

  /* 鏄剧ず鍥炬爣 */
  i = 0;
  program_img1[i] = lv_imgbtn_create(program_tile1, NULL);
  lv_obj_set_event_cb(program_img1[i], program_img_click_event_cb);
  lv_imgbtn_set_src(program_img1[i], LV_BTN_STATE_RELEASED, &device);
  lv_imgbtn_set_src(program_img1[i], LV_BTN_STATE_PRESSED, &device);
  lv_obj_align(program_img1[i], program_tile1, LV_ALIGN_IN_TOP_LEFT, program_icon_pos[i][0], program_icon_pos[i][1]);

  i = 1;
  program_img1[i] = lv_imgbtn_create(program_tile1, NULL);
  lv_obj_set_event_cb(program_img1[i], program_img_click_event_cb);
  lv_imgbtn_set_src(program_img1[i], LV_BTN_STATE_RELEASED, &time);
  lv_imgbtn_set_src(program_img1[i], LV_BTN_STATE_PRESSED, &time);
  lv_obj_align(program_img1[i], program_tile1, LV_ALIGN_IN_TOP_LEFT, program_icon_pos[i][0], program_icon_pos[i][1]);

  i = 2;
  program_img1[i] = lv_imgbtn_create(program_tile1, NULL);
  lv_obj_set_event_cb(program_img1[i], program_img_click_event_cb);
  lv_imgbtn_set_src(program_img1[i], LV_BTN_STATE_RELEASED, &photo);
  lv_imgbtn_set_src(program_img1[i], LV_BTN_STATE_PRESSED, &photo);
  lv_obj_align(program_img1[i], program_tile1, LV_ALIGN_IN_TOP_LEFT, program_icon_pos[i][0], program_icon_pos[i][1]);

  i = 3;
  program_img1[i] = lv_imgbtn_create(program_tile1, NULL);
  lv_obj_set_event_cb(program_img1[i], program_img_click_event_cb);
  lv_imgbtn_set_src(program_img1[i], LV_BTN_STATE_RELEASED, &smartctrl);
  lv_imgbtn_set_src(program_img1[i], LV_BTN_STATE_PRESSED, &smartctrl);
  lv_obj_align(program_img1[i], program_tile1, LV_ALIGN_IN_TOP_LEFT, program_icon_pos[i][0], program_icon_pos[i][1]);

  /* 鏄剧ず鏂囧瓧 */
  for(i = 0; i < 4; i++)
  {
    program_imglabel1[i] = lv_label_create(program_tile1, NULL);
    lv_obj_add_style(program_imglabel1[i], LV_OBJ_PART_MAIN, &style_label);
    lv_label_set_text(program_imglabel1[i], program_img_name1[i]);
    lv_obj_align(program_imglabel1[i], program_img1[i], LV_ALIGN_OUT_BOTTOM_MID, 0, 8);
  }


  /*Tile2: a list*/
  program_tile2 = lv_img_create(program_tileview, NULL);
  lv_obj_set_size(program_tile2, LV_HOR_RES, LV_VER_RES);
  lv_obj_set_pos(program_tile2, 0, LV_VER_RES);
  lv_img_set_src(program_tile2, &Black_bg1);

  smart_taskbar_create2(program_tile2);
  smart_backmainbtn[1] = lv_imgbtn_create(program_tile2, NULL);
  lv_obj_set_event_cb(smart_backmainbtn[1], program_backmain_click_event_cb);
  lv_imgbtn_set_src(smart_backmainbtn[1], LV_BTN_STATE_RELEASED, &BackMain);
  lv_imgbtn_set_src(smart_backmainbtn[1], LV_BTN_STATE_PRESSED, &BackMain);
  lv_obj_align(smart_backmainbtn[1], program_tile2, LV_ALIGN_IN_BOTTOM_MID, 0, -8);
  /* 鏄剧ず鍥炬爣 */
  i = 0;
  program_img2[i] = lv_imgbtn_create(program_tile2, NULL);
  lv_obj_set_event_cb(program_img2[i], program_img_click_event_cb);
  lv_imgbtn_set_src(program_img2[i], LV_BTN_STATE_RELEASED, &device);
  lv_imgbtn_set_src(program_img2[i], LV_BTN_STATE_PRESSED, &device);
  lv_obj_align(program_img2[i], program_tile2, LV_ALIGN_IN_TOP_LEFT, program_icon_pos[i][0], program_icon_pos[i][1]);

  i = 1;
  program_img2[i] = lv_imgbtn_create(program_tile2, NULL);
  lv_obj_set_event_cb(program_img2[i], program_img_click_event_cb);
  lv_imgbtn_set_src(program_img2[i], LV_BTN_STATE_RELEASED, &rfid);
  lv_imgbtn_set_src(program_img2[i], LV_BTN_STATE_PRESSED, &rfid);
  lv_obj_align(program_img2[i], program_tile2, LV_ALIGN_IN_TOP_LEFT, program_icon_pos[i][0], program_icon_pos[i][1]);

  i = 2;
  program_img2[i] = lv_imgbtn_create(program_tile2, NULL);
  lv_obj_set_event_cb(program_img2[i], program_img_click_event_cb);
  lv_imgbtn_set_src(program_img2[i], LV_BTN_STATE_RELEASED, &photo);
  lv_imgbtn_set_src(program_img2[i], LV_BTN_STATE_PRESSED, &photo);
  lv_obj_align(program_img2[i], program_tile2, LV_ALIGN_IN_TOP_LEFT, program_icon_pos[i][0], program_icon_pos[i][1]);

  i = 3;
  program_img2[i] = lv_imgbtn_create(program_tile2, NULL);
  lv_obj_set_event_cb(program_img2[i], program_img_click_event_cb);
  lv_imgbtn_set_src(program_img2[i], LV_BTN_STATE_RELEASED, &smartctrl);
  lv_imgbtn_set_src(program_img2[i], LV_BTN_STATE_PRESSED, &smartctrl);
  lv_obj_align(program_img2[i], program_tile2, LV_ALIGN_IN_TOP_LEFT, program_icon_pos[i][0], program_icon_pos[i][1]);

  for(i = 0; i < 4; i++)
  {
    program_imglabel2[i] = lv_label_create(program_tile2, NULL);
    lv_obj_add_style(program_imglabel2[i], LV_OBJ_PART_MAIN, &style_label);
    lv_label_set_text(program_imglabel2[i], program_img_name2[i]);
    lv_obj_align(program_imglabel2[i], program_img2[i], LV_ALIGN_OUT_BOTTOM_MID, 0, 8);
  }




}


// 鍒涘缓瀵艰埅鏍?
static void smart_taskbar_create1(lv_obj_t *par)
{

  smart_taskbar1[0] = lv_label_create(par, NULL);

  lv_obj_set_style_local_text_color(smart_taskbar1[0], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar1[0], LV_SYMBOL_WIFI);
  lv_obj_set_pos(smart_taskbar1[0], 12, 4);

  smart_taskbar1[1] = lv_label_create(par, NULL);

  lv_obj_set_style_local_text_color(smart_taskbar1[1], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar1[1], LV_SYMBOL_BLUETOOTH);
  lv_obj_set_pos(smart_taskbar1[1], 36, 4);

  smart_taskbar1[2] = lv_label_create(par, NULL);

  lv_obj_set_style_local_text_color(smart_taskbar1[2], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar1[2], LV_SYMBOL_BATTERY_FULL);
  lv_obj_set_pos(smart_taskbar1[2], 282, 4);

}

static void smart_taskbar_create2(lv_obj_t *par)
{

  smart_taskbar2[0] = lv_label_create(par, NULL);

  lv_obj_set_style_local_text_color(smart_taskbar2[0], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar2[0], LV_SYMBOL_WIFI);
  lv_obj_set_pos(smart_taskbar2[0], 12, 4);

  smart_taskbar2[1] = lv_label_create(par, NULL);

  lv_obj_set_style_local_text_color(smart_taskbar2[1], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar2[1], LV_SYMBOL_BLUETOOTH);
  lv_obj_set_pos(smart_taskbar2[1], 36, 4);

  smart_taskbar2[2] = lv_label_create(par, NULL);

  lv_obj_set_style_local_text_color(smart_taskbar2[2], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar2[2], LV_SYMBOL_BATTERY_FULL);
  lv_obj_set_pos(smart_taskbar2[2], 282, 4);

}


static lv_event_cb_t program_img_click_event_cb(lv_obj_t *icon, lv_event_t e)
{
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    if(icon == program_img1[0])
    {
      printf("Smart_Device_Create\r\n");
      Smart_Device_Create(lv_scr_act());    // 设备管理
    }
    else if(icon == program_img1[1])
    {
      printf("Smart_RFID_Create\r\n");
      Smart_Rfid_Create(lv_scr_act());    // 日历
    }
    else if(icon == program_img1[2])
    {
      printf("Smart_Photo_Create\r\n");
      Smart_Photo_Create(lv_scr_act());    // 相册管理
    }
    else if(icon == program_img1[3])
    {
      printf("Smart_SmartCtrl_Create\r\n");
      Smart_SmartCtrl_Create(lv_scr_act());    // 智能控制
    }
    else if(icon == program_img2[0])
    {
      printf("Smart_Phone_Create\r\n");
      Smart_Phone_Create(lv_scr_act());    // 电话管理
    }
    else if(icon == program_img2[1])
    {
      printf("Smart_Setting_Create\r\n");
      Smart_Setting_Create(lv_scr_act());   // 设置管理
    }
    else if(icon == program_img2[2])
    {
      printf("Smart_History_Create\r\n");
      Smart_History_Create(lv_scr_act());   // 历史记录
    }
    else if(icon == program_img2[3])  // 显示二维码
    {
      printf("Smart_Version_Create\r\n");
      Smart_Version_Create(lv_scr_act());
    }
    else
    {
      printf("program_img_click_event_cb\r\n");
    }
  }
}


static lv_event_cb_t program_backmain_click_event_cb(lv_obj_t *icon, lv_event_t e)
{
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    printf("program_backmain_click_event_cb\r\n");
    lv_obj_del(program_tileview);
  }
}




