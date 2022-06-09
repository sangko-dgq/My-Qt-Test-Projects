/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_smartctrl_page.c
 * \author    yifeng
 * \version   1.0
 * \date      2021年12月20日
 * \brief     智能控制
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

#include "Demo_1/Inc/smart_smartctrl_page.h"



LV_IMG_DECLARE(Black_bg);

LV_IMG_DECLARE(Siesta);     // 午休
LV_IMG_DECLARE(Shutters);
LV_IMG_DECLARE(Rollerblind);
LV_IMG_DECLARE(Floorheating);
LV_IMG_DECLARE(Dimming);               // 调光器  
LV_IMG_DECLARE(Curtain);
LV_IMG_DECLARE(chandelier);            // 吊灯
LV_IMG_DECLARE(Air);

static const lv_img_dsc_t *smartctrl_img_array1[8] = 
{
  &chandelier,
  &Dimming,
  &Siesta,
  &Air,
};

static const lv_img_dsc_t *smartctrl_img_array2[8] = 
{
  &Floorheating,
  &Rollerblind,
  &Shutters,
  &Curtain
};

static const char *smartctrl_img_name_array1[4] = 
{
  "Droplight",
  "Dimming",
  "Siesta",
  "AC",
};

static const char *smartctrl_img_name_array2[4] = 
{
  "Heating",
  "Rollerblind",
  "Shutters",
  "Curtain"
};

static const int smartctrl_img_pos[4][2] = 
{
  {42, 32},
  {168, 32},
  {42, 164},
  {168, 164},
};


static lv_obj_t *smartctrl_tab_bg; 

static lv_obj_t *smartctrl_tab_icon;
static lv_obj_t *smartctrl_page[3];

static lv_task_t *smartctrl_task;


static lv_obj_t *smartctrl_tabB_img[4];
static lv_obj_t *smartctrl_tabC_img[4];
static lv_obj_t *smartctrl_imgB_name[4];
static lv_obj_t *smartctrl_imgC_name[4];

static void smartctrl_taskbar_cb(lv_task_t *task);
static void smartctrl_taskbar_create(lv_obj_t *par);
static void smartctrl_main_icon_create(lv_obj_t *par);
static lv_event_cb_t smartctrl_tab_move_event_cb(lv_obj_t *tab, lv_event_t e);

static lv_event_cb_t smartctrl_click_event_cb(lv_obj_t * icon, lv_event_t e);

void Smart_SmartCtrl_Create(lv_obj_t* parent)
{
   unsigned char i;
   smartctrl_tab_bg = lv_obj_create(parent, NULL);
   lv_obj_set_style_local_bg_color(smartctrl_tab_bg, LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(7, 12, 30));
   lv_obj_set_size(smartctrl_tab_bg, LV_HOR_RES_MAX, LV_VER_RES_MAX);
   
   /* 创建两个容器 */
   for(i = 0; i < 2; i++)
   {
     smartctrl_page[i] = lv_cont_create(smartctrl_tab_bg, NULL);
     lv_obj_set_style_local_bg_opa(smartctrl_page[i],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_0);
     lv_obj_set_style_local_radius(smartctrl_page[i],LV_PAGE_PART_BG,LV_STATE_DEFAULT,0);
     lv_obj_set_style_local_border_width(smartctrl_page[i],LV_PAGE_PART_BG,LV_STATE_DEFAULT,0);
     lv_obj_set_width(smartctrl_page[i],LV_HOR_RES_MAX);
   }
   
   lv_obj_set_height(smartctrl_page[0], 20);
   lv_obj_set_height(smartctrl_page[1], LV_VER_RES_MAX-20);
   
   lv_obj_align(smartctrl_page[0],parent,LV_ALIGN_IN_TOP_LEFT,0,0);
   lv_obj_align(smartctrl_page[1],parent,LV_ALIGN_IN_BOTTOM_LEFT,0,0);
   
   smartctrl_taskbar_create(smartctrl_page[0]);    // 创建导航栏
   smartctrl_main_icon_create(smartctrl_page[1]);  // 创建页面
   
   smartctrl_task = lv_task_create(smartctrl_taskbar_cb, 10, LV_TASK_PRIO_MID, NULL);
}


/* 更新状态栏 */
static void smartctrl_taskbar_cb(lv_task_t *task)
{

}


// 创建导航栏
static void smartctrl_taskbar_create(lv_obj_t *par)
{
  static lv_style_t mystyle1;
  lv_obj_t *time_label ;
  
  lv_style_init(&mystyle1);
  lv_style_set_text_font(&mystyle1, LV_STATE_DEFAULT, &lv_font_montserrat_14);
  lv_style_set_text_color(&mystyle1, LV_LABEL_PART_MAIN, LV_COLOR_WHITE);

  time_label = lv_label_create(par, NULL);
  lv_obj_add_style(time_label, LV_OBJ_PART_MAIN, &mystyle1);
  lv_label_set_text(time_label, "2021/12/31  Friday");
  lv_obj_align(time_label, par, LV_ALIGN_IN_TOP_LEFT, 12, 4);
}


static void smartctrl_main_icon_create(lv_obj_t *par)
{
  unsigned char i;
  static lv_style_t mystyle1;
  lv_obj_t *time_label ;
  
  lv_style_init(&mystyle1);
  lv_style_set_text_font(&mystyle1, LV_STATE_DEFAULT, &lv_font_montserrat_12);
  lv_style_set_text_color(&mystyle1, LV_LABEL_PART_MAIN, LV_COLOR_WHITE);
  

  smartctrl_tab_icon = lv_tabview_create(par, NULL);
  smartctrl_page[0] = lv_tabview_add_tab(smartctrl_tab_icon, "A PAGE");
  smartctrl_page[1] = lv_tabview_add_tab(smartctrl_tab_icon, "B PAGE");
  smartctrl_page[2] = lv_tabview_add_tab(smartctrl_tab_icon, "C PAGE");
    
  lv_tabview_set_btns_pos(smartctrl_tab_icon, LV_TABVIEW_TAB_POS_NONE);
  lv_obj_set_style_local_bg_opa(smartctrl_tab_icon,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_0);
  lv_obj_set_size(smartctrl_tab_icon,lv_obj_get_width(lv_obj_get_parent(smartctrl_tab_icon)),lv_obj_get_height(lv_obj_get_parent(smartctrl_tab_icon)));
    
  printf("smart_main_icon_create size width is %d, height is %d", lv_obj_get_width(lv_obj_get_parent(smartctrl_tab_icon)), lv_obj_get_height(lv_obj_get_parent(smartctrl_tab_icon)));


  /*-------------------------------- A PAGE ---------------------------------*/

  /*---------------------------------- END  ---------------------------------*/
  
 
  /*-------------------------------- B PAGE ---------------------------------*/
  for(i = 0; i < 4; i++)
  {
    smartctrl_tabB_img[i] = lv_imgbtn_create(lv_tabview_get_tab(smartctrl_tab_icon, 1), NULL);
    lv_obj_set_event_cb(smartctrl_tabB_img[i], smartctrl_click_event_cb);

    lv_imgbtn_set_src(smartctrl_tabB_img[i], LV_BTN_STATE_RELEASED, smartctrl_img_array1[i]);
    lv_imgbtn_set_src(smartctrl_tabB_img[i], LV_BTN_STATE_PRESSED, smartctrl_img_array1[i]);
    lv_obj_align(smartctrl_tabB_img[i], lv_tabview_get_tab(smartctrl_tab_icon, 1), LV_ALIGN_IN_TOP_LEFT, smartctrl_img_pos[i][0], smartctrl_img_pos[i][1]);
    
    smartctrl_imgB_name[i] = lv_label_create(lv_tabview_get_tab(smartctrl_tab_icon, 1), NULL);
    lv_obj_add_style(smartctrl_imgB_name[i], LV_OBJ_PART_MAIN, &mystyle1);
    lv_label_set_text(smartctrl_imgB_name[i], smartctrl_img_name_array1[i]);
    lv_obj_align(smartctrl_imgB_name[i], smartctrl_tabB_img[i], LV_ALIGN_IN_BOTTOM_MID, 0, -8);
  }

  
  /*---------------------------------- END  ---------------------------------*/



  /*-------------------------------- C PAGE ---------------------------------*/
  for(i = 0; i < 4; i++)
  {
    smartctrl_tabC_img[i] = lv_imgbtn_create(lv_tabview_get_tab(smartctrl_tab_icon, 2), NULL);
    lv_obj_set_event_cb(smartctrl_tabC_img[i], smartctrl_click_event_cb);

    lv_imgbtn_set_src(smartctrl_tabC_img[i], LV_BTN_STATE_RELEASED, smartctrl_img_array2[i]);
    lv_imgbtn_set_src(smartctrl_tabC_img[i], LV_BTN_STATE_PRESSED, smartctrl_img_array2[i]);
    lv_obj_align(smartctrl_tabC_img[i], lv_tabview_get_tab(smartctrl_tab_icon, 2), LV_ALIGN_IN_TOP_LEFT, smartctrl_img_pos[i][0], smartctrl_img_pos[i][1]);
    
    smartctrl_imgC_name[i] = lv_label_create(lv_tabview_get_tab(smartctrl_tab_icon, 2), NULL);
    lv_obj_add_style(smartctrl_imgC_name[i], LV_OBJ_PART_MAIN, &mystyle1);
    lv_label_set_text(smartctrl_imgC_name[i], smartctrl_img_name_array2[i]);
    lv_obj_align(smartctrl_imgC_name[i], smartctrl_tabC_img[i], LV_ALIGN_IN_BOTTOM_MID, 0, -8);
  }

  /*---------------------------------- END  ---------------------------------*/
  lv_tabview_set_tab_act(smartctrl_tab_icon, 1, LV_ANIM_OFF);
  lv_obj_set_event_cb(smartctrl_tab_icon, smartctrl_tab_move_event_cb);
}



static lv_event_cb_t smartctrl_click_event_cb(lv_obj_t * icon, lv_event_t e)
{
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    printf("smartctrl_click_event_cb\r\n");
    if(icon == smartctrl_tabB_img[0])
    {
    }
    else if(icon == smartctrl_tabB_img[1])
    {
    }
    else if(icon == smartctrl_tabB_img[2])
    {
    }
    else if(icon == smartctrl_tabB_img[3])
    {
    }
    else if(icon == smartctrl_tabC_img[0])
    {
    }
    else if(icon == smartctrl_tabC_img[1])
    {
    }
    else if(icon == smartctrl_tabC_img[2])
    {
    }
    else if(icon == smartctrl_tabC_img[3])
    {
    }
    else
    {
    }
  }
}

static lv_event_cb_t smartctrl_tab_move_event_cb(lv_obj_t *tab, lv_event_t e)
{
  int index;
  
  if(tab == smartctrl_tab_icon)
  {
    if(e == LV_EVENT_VALUE_CHANGED)
    {
      index = lv_tabview_get_tab_act(tab);
      printf("Current page : %d\r\n", index);

      if(index == 0)
      {
        // 返回上一层界面，删除当前ojb和任务
        lv_obj_del(smartctrl_tab_bg);
        lv_tabview_clean_tab(smartctrl_tab_icon);
        lv_task_del(smartctrl_task);
      }
    }
  }
}



