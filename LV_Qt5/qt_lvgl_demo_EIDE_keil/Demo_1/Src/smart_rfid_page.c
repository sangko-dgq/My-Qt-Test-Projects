/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_rfid_page.c
 * \author    yifeng
 * \version   1.0
 * \date      2021年12月20日
 * \brief     RFID管理
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
#include "Demo_1/Inc/smart_rfid_page.h"


static lv_obj_t *time_page;
static lv_obj_t *close_btn;
static lv_obj_t *calendar;




static void calendar_close_event_cb(lv_obj_t *obj, lv_event_t e)
{
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    lv_obj_del(time_page);
  }
}



void Smart_Rfid_Create(lv_obj_t* parent)
{
  int i;
  time_page = lv_page_create(parent,NULL);
  lv_obj_set_size(time_page,LV_HOR_RES_MAX-10,LV_VER_RES_MAX-10);
  lv_obj_set_style_local_bg_opa(time_page,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_50);
  lv_obj_set_style_local_bg_color(time_page, LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_GRAY);
  lv_obj_set_style_local_radius(time_page,LV_PAGE_PART_BG,LV_STATE_DEFAULT,0);
  lv_obj_set_style_local_border_width(time_page,LV_PAGE_PART_BG,LV_STATE_DEFAULT,0);
  lv_page_set_scrollable_fit(time_page, LV_FIT_PARENT);
  lv_obj_align(time_page,parent,LV_ALIGN_CENTER,0,0);
  
  close_btn = lv_btn_create(time_page,NULL);
  lv_obj_set_style_local_bg_color(close_btn,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_WHITE);
  lv_obj_set_style_local_bg_opa(close_btn,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_60);
  lv_obj_set_style_local_radius(close_btn,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,3);
  lv_obj_set_style_local_border_width(close_btn,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,1);
  lv_obj_set_size(close_btn,32,24);
  lv_obj_align(close_btn,time_page,LV_ALIGN_IN_TOP_RIGHT,-15,15);
  
  lv_obj_t * label = lv_label_create(close_btn,NULL);
  lv_label_set_text(label,&LV_SYMBOL_CLOSE);
  lv_obj_set_style_local_text_color(label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_RED);
  lv_obj_set_event_cb(close_btn, calendar_close_event_cb);

  lv_calendar_date_t today;
  today.year = 2021;
  today.month = 12;
  today.day = 31;
  calendar = lv_calendar_create(time_page,NULL);
  lv_calendar_set_today_date(calendar,  &today);
  lv_calendar_set_showed_date(calendar, &today);
  lv_obj_set_style_local_radius(calendar,LV_CALENDAR_PART_BG,LV_STATE_DEFAULT,3);
  lv_obj_set_style_local_border_width(calendar,LV_CALENDAR_PART_BG,LV_STATE_DEFAULT,1);
  lv_obj_set_size(calendar, 220, 220);
  lv_obj_align(calendar,time_page,LV_ALIGN_IN_TOP_MID,0,50);
  
}



