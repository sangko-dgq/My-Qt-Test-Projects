/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_setting_page.c
 * \author    yifeng
 * \version   1.0
 * \date      2021年12月20日
 * \brief     设置管理
 *
 *----------------------------------------------------------------------------
 * \attention
 *
 *
 *****************************************************************************
 */

/*****************************************************************************
 change history: 
    1.date  : 2021年12月20日
      author: yifeng
      change: create file

*****************************************************************************/
#include "Demo_1/Inc/smart_setting_page.h"


static lv_obj_t *Setting_page;
static lv_obj_t *Setting_list;

static lv_obj_t * list_btn[12];


void setting_close_click_event_cb(lv_obj_t * obj, lv_event_t event);

static void Setting_list_sevent_handler(lv_obj_t * obj, lv_event_t event);


LV_IMG_DECLARE(CLOSE1);
LV_IMG_DECLARE(RIGHT_1);
LV_IMG_DECLARE(list1);
LV_IMG_DECLARE(list2);
LV_IMG_DECLARE(list3);
LV_IMG_DECLARE(list4);
LV_IMG_DECLARE(list5);
LV_IMG_DECLARE(list6);
LV_IMG_DECLARE(list7);
LV_IMG_DECLARE(list8);
LV_IMG_DECLARE(list9);
LV_IMG_DECLARE(list10);
LV_IMG_DECLARE(list11);
LV_IMG_DECLARE(list12);

static const lv_img_dsc_t *Settinglist_pic_array[12] = 
{
  &list1,
  &list2,
  &list3,
  &list4,
  &list5,
  &list6,
  &list7,
  &list8,
  &list9,
  &list10,
  &list11,
  &list12,
};

// 40+35*8

void Smart_Setting_Create(lv_obj_t* parent)
{
  Setting_page = lv_obj_create(parent, NULL);
  lv_obj_set_style_local_bg_color(Setting_page, LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_BLACK);
  lv_obj_set_size(Setting_page, LV_HOR_RES_MAX, LV_VER_RES_MAX);

  /* 显示标题和关闭按钮 */
  lv_obj_t *Setting_title = lv_label_create(Setting_page, NULL);
  lv_obj_set_style_local_text_color(Setting_title, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_font(Setting_title, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  lv_label_set_text(Setting_title, "Setting");
  lv_obj_set_size(Setting_title, 320, 60);
  lv_obj_align(Setting_title, parent, LV_ALIGN_IN_TOP_LEFT, 12, 12);

  lv_obj_t *Setting_close = lv_imgbtn_create(Setting_page, NULL);
  lv_imgbtn_set_src(Setting_close, LV_BTN_STATE_RELEASED, &CLOSE1);
  lv_imgbtn_set_src(Setting_close, LV_BTN_STATE_PRESSED, &CLOSE1);
  lv_obj_set_event_cb(Setting_close, setting_close_click_event_cb);
  lv_obj_align(Setting_close, parent, LV_ALIGN_IN_TOP_RIGHT, -24, 12);

  
  /* 显示列表 */
  Setting_list = lv_list_create(Setting_page, NULL);
  lv_obj_set_pos(Setting_list, 0, 40);
  lv_obj_set_size(Setting_list, 320, 280);
  lv_obj_align(Setting_list, parent, LV_ALIGN_IN_TOP_MID, 0, 40);
  lv_list_set_edge_flash(Setting_list, true);
  lv_obj_set_style_local_bg_color(Setting_list, LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_BLACK);


  int i;
  lv_obj_t *right_img[12];
  lv_obj_t *label;
  for(i = 0; i < 12; i++)
  {
    list_btn[i] = lv_list_add_btn(Setting_list, Settinglist_pic_array[i], NULL);
    lv_obj_set_style_local_bg_color(list_btn[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_obj_set_style_local_bg_color(list_btn[i], LV_PAGE_PART_BG, LV_STATE_PRESSED, LV_COLOR_SILVER);
    lv_obj_set_style_local_bg_opa(list_btn[i], LV_PAGE_PART_BG, LV_STATE_PRESSED, LV_OPA_30);
    lv_obj_set_style_local_text_color(list_btn[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_event_cb(list_btn[i], Setting_list_sevent_handler);
  }

  
}

void setting_close_click_event_cb(lv_obj_t * obj, lv_event_t event)
{
  if(event == LV_EVENT_RELEASED)
  {
    lv_obj_del(Setting_page);
  }
}


static void Setting_list_sevent_handler(lv_obj_t * obj, lv_event_t event)
{
  int i;
  if(event == LV_EVENT_CLICKED)
  {
    for(i = 0; i < 12; i++)
    {
      if(list_btn[i] == obj)
      {
        break;
      }
    }
    printf("Clicked: %d\n", i);
  }
}
 
 
 
