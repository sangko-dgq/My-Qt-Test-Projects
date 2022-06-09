/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_device_page.c
 * \author    yifeng
 * \version   1.0
 * \date      2021年12月20日
 * \brief     设备管理
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
#include "Demo_1/Inc/smart_device_page.h"




LV_IMG_DECLARE(adddevice);
LV_IMG_DECLARE(device_bg);
LV_IMG_DECLARE(Remote);
LV_IMG_DECLARE(Sernos);
LV_IMG_DECLARE(Alarming);
LV_IMG_DECLARE(CLOSE1);
LV_IMG_DECLARE(Alarm_32x32);
LV_IMG_DECLARE(Remote_32x32);
LV_IMG_DECLARE(detector_64x64);
LV_IMG_DECLARE(detector_32x32);


static lv_obj_t *device_obj;
static lv_obj_t *device_tabview;


static lv_obj_t *device_btn[3];
static lv_obj_t *device_addimgbtn[3];
static lv_obj_t *device_imgbtn_name1[3];
static lv_obj_t *device_imgbtn_name2[3];
static lv_obj_t *device_imgbtn[3];


static lv_obj_t *add_msg;
static bool   add_status;
// 16+92+6+92+6+92+16

static lv_obj_t *device_list_page;
static lv_obj_t *device_list;
static lv_obj_t *device_list_btn[40];


static lv_event_cb_t device_tab_move_event_cb(lv_obj_t *tab, lv_event_t e);
static lv_event_cb_t device_imgbtn_event_handler(lv_obj_t *tab, lv_event_t e);



static void Device_Add_Create(lv_obj_t *parent, int num);
static void add_msg_event_handler(lv_obj_t * obj, lv_event_t event);


static void Device_devictlist_Create(lv_obj_t *parent, int num);
static void device_list_close_click_event_cb(lv_obj_t * obj, lv_event_t event);
static void device_list_sevent_handler(lv_obj_t * obj, lv_event_t event);


void Smart_Device_Create(lv_obj_t* parent)
{
  device_obj = lv_obj_create(parent, NULL);
  lv_obj_set_style_local_bg_color(device_obj,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_BLACK);
  lv_obj_set_width(device_obj,LV_HOR_RES_MAX);
  lv_obj_set_height(device_obj,LV_VER_RES_MAX);
  lv_obj_align(device_obj, parent, LV_ALIGN_IN_TOP_LEFT,0,0);

  device_tabview = lv_tabview_create(device_obj, NULL);
  lv_tabview_add_tab(device_tabview, "A PAGE");
  lv_tabview_add_tab(device_tabview, "B PAGE");
  
  lv_tabview_set_btns_pos(device_tabview, LV_TABVIEW_TAB_POS_NONE);
  lv_obj_set_style_local_bg_opa(device_tabview,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_0);
  lv_obj_set_size(device_tabview, lv_obj_get_width(lv_obj_get_parent(device_tabview)),lv_obj_get_height(lv_obj_get_parent(device_tabview)));


  /* 添加界面　*/
  device_btn[0] = lv_obj_create(lv_tabview_get_tab(device_tabview, 1), NULL);
  lv_obj_set_style_local_bg_opa(device_btn[0],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_50);
  lv_obj_set_style_local_bg_opa(device_btn[0],LV_PAGE_PART_BG,LV_STATE_PRESSED,LV_OPA_30);
  lv_obj_set_style_local_radius(device_btn[0],LV_PAGE_PART_BG,LV_STATE_DEFAULT, 5);
  lv_obj_set_style_local_bg_color(device_btn[0],LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_obj_set_style_local_border_color(device_btn[0],LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_YELLOW);
  lv_obj_set_size(device_btn[0], 92, 288);
  lv_obj_align(device_btn[0], lv_tabview_get_tab(device_tabview, 1), LV_ALIGN_IN_TOP_LEFT, 16, 16);
  
  device_imgbtn[0] = lv_imgbtn_create(device_btn[0], NULL);
  lv_imgbtn_set_src(device_imgbtn[0], LV_BTN_STATE_RELEASED, &Remote);
  lv_imgbtn_set_src(device_imgbtn[0], LV_BTN_STATE_PRESSED, &Remote);
  lv_obj_set_event_cb(device_imgbtn[0], device_imgbtn_event_handler);
  lv_obj_align(device_imgbtn[0], device_btn[0], LV_ALIGN_CENTER, 0, 0);

  device_imgbtn_name1[0] = lv_label_create(device_btn[0], NULL);
  lv_obj_set_style_local_text_color(device_imgbtn_name1[0],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_WHITE);
  lv_obj_set_style_local_text_font(device_imgbtn_name1[0],LV_PAGE_PART_BG,LV_STATE_DEFAULT,&lv_font_montserrat_16);
  lv_label_set_text(device_imgbtn_name1[0], "Remote");
  lv_obj_align(device_imgbtn_name1[0], device_imgbtn[0], LV_ALIGN_OUT_TOP_MID, 0, -8);

  device_addimgbtn[0] = lv_imgbtn_create(device_btn[0], NULL);
  lv_imgbtn_set_src(device_addimgbtn[0], LV_BTN_STATE_RELEASED, &adddevice);
  lv_imgbtn_set_src(device_addimgbtn[0], LV_BTN_STATE_PRESSED, &adddevice);
  lv_obj_set_event_cb(device_addimgbtn[0], device_imgbtn_event_handler);
  lv_obj_align(device_addimgbtn[0], device_btn[0], LV_ALIGN_IN_TOP_RIGHT, -4, 4);

  device_imgbtn_name2[0] = lv_label_create(device_btn[0], NULL);
  lv_obj_set_style_local_text_color(device_imgbtn_name2[0],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_WHITE);
  lv_obj_set_style_local_text_font(device_imgbtn_name2[0],LV_PAGE_PART_BG,LV_STATE_DEFAULT,&lv_font_montserrat_12);
  lv_label_set_text(device_imgbtn_name2[0], "Statue: 6/16");
  lv_obj_align(device_imgbtn_name2[0], device_imgbtn[0], LV_ALIGN_OUT_BOTTOM_MID, 0, 4);



  device_btn[1] = lv_obj_create(lv_tabview_get_tab(device_tabview, 1), NULL);
  lv_obj_set_style_local_bg_opa(device_btn[1],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_50);
  lv_obj_set_style_local_bg_opa(device_btn[1],LV_PAGE_PART_BG,LV_STATE_PRESSED,LV_OPA_30);
  lv_obj_set_style_local_radius(device_btn[1],LV_PAGE_PART_BG,LV_STATE_DEFAULT, 5);
  lv_obj_set_style_local_bg_color(device_btn[1],LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_obj_set_style_local_border_color(device_btn[1],LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_YELLOW);
  lv_obj_set_size(device_btn[1], 92, 288);
  lv_obj_align(device_btn[1], lv_tabview_get_tab(device_tabview, 1), LV_ALIGN_CENTER, 0, 0);
  
  device_imgbtn[1] = lv_imgbtn_create(device_btn[1], NULL);
  lv_imgbtn_set_src(device_imgbtn[1], LV_BTN_STATE_RELEASED, &detector_64x64);
  lv_imgbtn_set_src(device_imgbtn[1], LV_BTN_STATE_PRESSED, &detector_64x64);
  lv_obj_set_event_cb(device_imgbtn[1], device_imgbtn_event_handler);
  lv_obj_align(device_imgbtn[1], device_btn[1], LV_ALIGN_CENTER, 0, 0);

  device_imgbtn_name1[1] = lv_label_create(device_btn[1], NULL);
  lv_obj_set_style_local_text_color(device_imgbtn_name1[1],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_WHITE);
  lv_obj_set_style_local_text_font(device_imgbtn_name1[1],LV_PAGE_PART_BG,LV_STATE_DEFAULT,&lv_font_montserrat_16);
  lv_label_set_text(device_imgbtn_name1[1], "Detector");
  lv_obj_align(device_imgbtn_name1[1], device_imgbtn[1], LV_ALIGN_OUT_TOP_MID, 0, -8);

  device_addimgbtn[1] = lv_imgbtn_create(device_btn[1], NULL);
  lv_imgbtn_set_src(device_addimgbtn[1], LV_BTN_STATE_RELEASED, &adddevice);
  lv_imgbtn_set_src(device_addimgbtn[1], LV_BTN_STATE_PRESSED, &adddevice);
  lv_obj_set_event_cb(device_addimgbtn[1], device_imgbtn_event_handler);
  lv_obj_align(device_addimgbtn[1], device_btn[1], LV_ALIGN_IN_TOP_RIGHT, -4, 4);

  device_imgbtn_name2[1] = lv_label_create(device_btn[1], NULL);
  lv_obj_set_style_local_text_color(device_imgbtn_name2[1],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_WHITE);
  lv_obj_set_style_local_text_font(device_imgbtn_name2[1],LV_PAGE_PART_BG,LV_STATE_DEFAULT,&lv_font_montserrat_12);
  lv_label_set_text(device_imgbtn_name2[1], "Status: 99/999");
  lv_obj_align(device_imgbtn_name2[1], device_imgbtn[1], LV_ALIGN_OUT_BOTTOM_MID, 0, 4);
 


  device_btn[2] = lv_obj_create(lv_tabview_get_tab(device_tabview, 1), NULL);
  lv_obj_set_style_local_bg_opa(device_btn[2],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_50);
  lv_obj_set_style_local_bg_opa(device_btn[2],LV_PAGE_PART_BG,LV_STATE_PRESSED,LV_OPA_30);
  lv_obj_set_style_local_radius(device_btn[2],LV_PAGE_PART_BG,LV_STATE_DEFAULT, 5);
  lv_obj_set_style_local_bg_color(device_btn[2],LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_obj_set_style_local_border_color(device_btn[2],LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_YELLOW);
  lv_obj_set_size(device_btn[2], 92, 288);
  lv_obj_align(device_btn[2], lv_tabview_get_tab(device_tabview, 1), LV_ALIGN_IN_TOP_RIGHT, -16, 16);
  
  device_imgbtn[2] = lv_imgbtn_create(device_btn[2], NULL);
  lv_imgbtn_set_src(device_imgbtn[2], LV_BTN_STATE_RELEASED, &Alarming);
  lv_imgbtn_set_src(device_imgbtn[2], LV_BTN_STATE_PRESSED, &Alarming);
  lv_obj_set_event_cb(device_imgbtn[2], device_imgbtn_event_handler);
  lv_obj_align(device_imgbtn[2], device_btn[2], LV_ALIGN_CENTER, 0, 0);

  device_imgbtn_name1[2] = lv_label_create(device_btn[2], NULL);
  lv_obj_set_style_local_text_color(device_imgbtn_name1[2],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_WHITE);
  lv_obj_set_style_local_text_font(device_imgbtn_name1[2],LV_PAGE_PART_BG,LV_STATE_DEFAULT,&lv_font_montserrat_16);
  lv_label_set_text(device_imgbtn_name1[2], "Siren");
  lv_obj_align(device_imgbtn_name1[2], device_imgbtn[2], LV_ALIGN_OUT_TOP_MID, 0, -8);

  device_addimgbtn[2] = lv_imgbtn_create(device_btn[2], NULL);
  lv_imgbtn_set_src(device_addimgbtn[2], LV_BTN_STATE_RELEASED, &adddevice);
  lv_imgbtn_set_src(device_addimgbtn[2], LV_BTN_STATE_PRESSED, &adddevice);
  lv_obj_set_event_cb(device_addimgbtn[2], device_imgbtn_event_handler);
  lv_obj_align(device_addimgbtn[2], device_btn[2], LV_ALIGN_IN_TOP_RIGHT, -4, 4);

  device_imgbtn_name2[2] = lv_label_create(device_btn[2], NULL);
  lv_obj_set_style_local_text_color(device_imgbtn_name2[2],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_WHITE);
  lv_obj_set_style_local_text_font(device_imgbtn_name2[2],LV_PAGE_PART_BG,LV_STATE_DEFAULT,&lv_font_montserrat_12);
  lv_label_set_text(device_imgbtn_name2[2], "Status: 0/1");
  lv_obj_align(device_imgbtn_name2[2], device_imgbtn[2], LV_ALIGN_OUT_BOTTOM_MID, 0, 4);
 

 

  lv_tabview_set_tab_act(device_tabview, 1, LV_ANIM_OFF);
  lv_obj_set_event_cb(device_tabview, device_tab_move_event_cb);
}


static lv_event_cb_t device_tab_move_event_cb(lv_obj_t *tab, lv_event_t e)
{
  if(add_status == true)
    return NULL;

  if(tab == device_tabview)
  {
    if(e == LV_EVENT_VALUE_CHANGED)
    {
      printf("page_chage\n");
      lv_obj_del(device_obj);
    }
  }
}


static lv_event_cb_t device_imgbtn_event_handler(lv_obj_t *tab, lv_event_t e)
{
  if(add_status == true)
    return NULL;
    
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    printf("device_imgbtn_event_handler\n");
  
    if(tab == device_imgbtn[0])
    {
      Device_devictlist_Create(lv_scr_act(), 0);
    }
    else if(tab == device_imgbtn[1])
    {
      Device_devictlist_Create(lv_scr_act(), 1);
    }
    else if(tab == device_imgbtn[2])
    {
      Device_Add_Create(lv_scr_act(), 2);
    }
    else if(tab == device_addimgbtn[0])
    {
      Device_Add_Create(lv_scr_act(), 0);
    }
    else if(tab == device_addimgbtn[1])
    {
      Device_Add_Create(lv_scr_act(), 1);
    }
    else if(tab == device_addimgbtn[2])
    {
      Device_Add_Create(lv_scr_act(), 2);
    }
    else
    {
    }
  }
}

static void Device_Add_Create(lv_obj_t *parent, int num)
{
  static const char * btns[] ={"Cancel", "Enter", ""};
  
  add_msg = lv_msgbox_create(parent, NULL);

  if(num == 0)
    lv_msgbox_set_text(add_msg, "Please trigger remote.");
  else if(num == 1)
    lv_msgbox_set_text(add_msg, "Please trigger detector.");
  else
    lv_msgbox_set_text(add_msg, "Please trigger siren.");

  lv_obj_set_style_local_bg_opa(add_msg,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_50);
  lv_obj_set_style_local_radius(add_msg,LV_PAGE_PART_BG,LV_STATE_DEFAULT, 5);
  lv_obj_set_style_local_bg_color(add_msg,LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_obj_set_style_local_border_color(add_msg,LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_YELLOW);
  lv_obj_set_style_local_text_color(add_msg,LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_bg_grad_color(add_msg,LV_PAGE_PART_BG,LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_msgbox_add_btns(add_msg, btns);
  lv_obj_set_width(add_msg, 200);
  lv_obj_set_event_cb(add_msg, add_msg_event_handler);
  lv_obj_align(add_msg, NULL, LV_ALIGN_CENTER, 0, 0); /*Align to the corner*/

  add_status = true;
}

static void add_msg_event_handler(lv_obj_t * obj, lv_event_t event)
{
  if(event == LV_EVENT_VALUE_CHANGED) {
    printf("Button: %s\n", lv_msgbox_get_active_btn_text(obj));
    lv_obj_del(add_msg);

    add_status = false;
  }
}




static void Device_devictlist_Create(lv_obj_t *parent, int num)
{
  int i;
  
  device_list_page = lv_obj_create(parent, NULL);
  lv_obj_set_style_local_bg_color(device_list_page, LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_BLACK);
  lv_obj_set_size(device_list_page, LV_HOR_RES_MAX, LV_VER_RES_MAX);
  
  /* 显示标题和关闭按钮 */
  lv_obj_t *Setting_title = lv_label_create(device_list_page, NULL);
  lv_obj_set_style_local_text_color(Setting_title, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_font(Setting_title, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  if(num == 0)
    lv_label_set_text(Setting_title, "Remote list");
  else
    lv_label_set_text(Setting_title, "Detector list");

  lv_obj_set_size(Setting_title, 320, 60);
  lv_obj_align(Setting_title, parent, LV_ALIGN_IN_TOP_LEFT, 12, 12);
  
  lv_obj_t *Setting_close = lv_imgbtn_create(device_list_page, NULL);
  lv_imgbtn_set_src(Setting_close, LV_BTN_STATE_RELEASED, &CLOSE1);
  lv_imgbtn_set_src(Setting_close, LV_BTN_STATE_PRESSED, &CLOSE1);
  lv_obj_set_event_cb(Setting_close, device_list_close_click_event_cb);
  lv_obj_align(Setting_close, parent, LV_ALIGN_IN_TOP_RIGHT, -24, 12);
  
  
  /* 显示列表 */
  device_list = lv_list_create(device_list_page, NULL);
  lv_obj_set_pos(device_list, 0, 40);
  lv_obj_set_size(device_list, 320, 280);
  lv_obj_align(device_list, parent, LV_ALIGN_IN_TOP_MID, 0, 40);
  lv_list_set_edge_flash(device_list, true);
  lv_obj_set_style_local_bg_color(device_list, LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_BLACK);
  
  char buf[128];
  int number = 0;
  if(num == 0)
    number = 16;
  else 
    number = 32;
    
  for(i = 0; i < number; i++)
  {
    if(num == 0)
    {
      sprintf(&buf[0], "Remote %d", i+1);
      device_list_btn[i] = lv_list_add_btn(device_list, &Remote_32x32, buf);
    }
    else 
    {
      sprintf(&buf[0], "Detector %d", i+1);
      device_list_btn[i] = lv_list_add_btn(device_list, &detector_32x32, buf);
    }
    lv_obj_set_style_local_bg_color(device_list_btn[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_obj_set_style_local_bg_color(device_list_btn[i], LV_PAGE_PART_BG, LV_STATE_PRESSED, LV_COLOR_SILVER);
    lv_obj_set_style_local_bg_opa(device_list_btn[i], LV_PAGE_PART_BG, LV_STATE_PRESSED, LV_OPA_30);
    lv_obj_set_style_local_text_color(device_list_btn[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_event_cb(device_list_btn[i], device_list_sevent_handler);
  }
   
 
}


static void device_list_close_click_event_cb(lv_obj_t * obj, lv_event_t event)
{
  if(event == LV_EVENT_RELEASED)
  {
    lv_obj_del(device_list_page);
  }
}


static void device_list_sevent_handler(lv_obj_t * obj, lv_event_t event)
{
  int i;
  if(event == LV_EVENT_CLICKED)
  {
    for(i = 0; i < 64; i++)
    {
      if(device_list_btn[i] == obj)
      {
        break;
      }
    }
    printf("device_list_sevent_handler: %d\n", i);
  }
}






