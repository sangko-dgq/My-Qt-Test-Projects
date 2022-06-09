/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_app.c
 * \author    yifeng
 * \version   1.0
 * \date      2021年12月15日
 * \brief     86盒 智能控制面板
 *
 *----------------------------------------------------------------------------
 * \attention
 *
 *
 *****************************************************************************
 */

/*****************************************************************************
 change history: 
    1.date  : 2021年12月15日
      author: yifeng
      change: create file

*****************************************************************************/
#include "Demo_1/Inc/smart_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Demo_1/Inc/smart_app.h"
#include "Demo_1/Inc/smart_program.h"




LV_IMG_DECLARE(Black_bg);
LV_IMG_DECLARE(Arm_1);
LV_IMG_DECLARE(Arm_2);
LV_IMG_DECLARE(Disarm_1);
LV_IMG_DECLARE(Disarm_2);
LV_IMG_DECLARE(lampoff);
LV_IMG_DECLARE(lampon);



static lv_obj_t *smart_bg;

static lv_obj_t *smart_page[2];
static lv_obj_t *smart_taskbar[3];

/* 表1 显示的控件 */
static lv_obj_t *smart_tab1_img[4];
static lv_obj_t *smart_tab1_label[4];
static char smart_tab1_ledSta[4] = {0, 0, 0, 0};   // 0: 关

static const char *led_icon_name[4] =
{
  "Hall",
  "Living room",
  "Kitchen",
  "Room"
};

static int led_icon_pos[4][2] = 
{
  {64, 57},
  {192, 57},
  {64, 178},
  {192, 178},
};

/* 表2 显示控件 */
static lv_obj_t *smart_tab_icon;

static lv_obj_t *smart_tab2_time;
static lv_obj_t *smart_tab2_date;

static lv_obj_t *smart_tab2_armimg;
static lv_obj_t *smart_tab2_armlabel;

static lv_obj_t *smart_tab2_disarmimg;
static lv_obj_t *smart_tab2_disarmlabel;

static char ArmDisamStatus = 0;


/* 表3 密码登录界面 */
static const char *tab3_btnm_map[] = 
{
  "1", "2", "3", "\n",
  "4", "5", "6", "\n",
  "7", "8", "9", "\n",
  LV_SYMBOL_BACKSPACE, "0", LV_SYMBOL_OK, ""
};

static lv_obj_t *tab3_pwdTipinfo_label;  // 提示信息
static lv_obj_t *tab3_pwdTextArea;       // 输入框
static lv_obj_t *tab3_pwdInputBtnm;      // 键盘

static void smart_taskbar_create(lv_obj_t *par);
static void smart_taskbar_cb(lv_task_t *task);
static void smart_main_icon_create(lv_obj_t *par);

static void smart_tabl2_time_event_cb(void);
static lv_event_cb_t tab_move_event_cb(lv_obj_t *tab, lv_event_t e);
static lv_event_cb_t ArmDisarmicon_click_event_cb(lv_obj_t * icon, lv_event_t e);

static lv_event_cb_t LedCtrl_click_event_cb(lv_obj_t * icon, lv_event_t e);


static void tab3_pwdInputBtnm_click_event_cb(lv_obj_t * tab_btnm, lv_event_t event);

/*!
 * \fn     Smart_App_Demo
 * \brief  智能面板
 *          
 * \param  [in] void   #
 * 
 * \retval void
 */
void Smart_App_Demo(void)
{
  lv_obj_t *par_scr;
  par_scr = lv_scr_act();

  int i;
  smart_bg = lv_img_create(par_scr, NULL);
  lv_img_set_src(smart_bg, &Black_bg);
  lv_obj_set_size(smart_bg, LV_HOR_RES_MAX, LV_VER_RES_MAX);

  /* 创建两个容器 */
  for(i = 0; i < 2; i++)
  {
    smart_page[i] = lv_cont_create(par_scr, NULL);
    lv_obj_set_style_local_bg_opa(smart_page[i],LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_0);
    lv_obj_set_style_local_radius(smart_page[i],LV_PAGE_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_border_width(smart_page[i],LV_PAGE_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_width(smart_page[i],LV_HOR_RES_MAX);
  }

  lv_obj_set_height(smart_page[0], 20);
  lv_obj_set_height(smart_page[1], LV_VER_RES_MAX-20);

  lv_obj_align(smart_page[0],par_scr,LV_ALIGN_IN_TOP_LEFT,0,0);
  lv_obj_align(smart_page[1],par_scr,LV_ALIGN_IN_BOTTOM_LEFT,0,0);

  smart_taskbar_create(smart_page[0]);    // 创建导航栏
  smart_main_icon_create(smart_page[1]);


  lv_task_create(smart_taskbar_cb, 10, LV_TASK_PRIO_MID, NULL);
}

// 创建导航栏
static void smart_taskbar_create(lv_obj_t *par)
{
  if(smart_taskbar[0] == NULL)
  {
    smart_taskbar[0] = lv_label_create(par, NULL);
  }
  lv_obj_set_style_local_text_color(smart_taskbar[0], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar[0], LV_SYMBOL_WIFI);
  lv_obj_set_pos(smart_taskbar[0], 12, 4);

  if(smart_taskbar[1] == NULL)
  {
    smart_taskbar[1] = lv_label_create(par, NULL);
  }
  lv_obj_set_style_local_text_color(smart_taskbar[1], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar[1], LV_SYMBOL_BLUETOOTH);
  lv_obj_set_pos(smart_taskbar[1], 36, 4);

  if(smart_taskbar[2] == NULL)
  {
    smart_taskbar[2] = lv_label_create(par, NULL);
  }
  lv_obj_set_style_local_text_color(smart_taskbar[2], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(smart_taskbar[2], LV_SYMBOL_BATTERY_FULL);
  lv_obj_set_pos(smart_taskbar[2], 282, 4);

}

/* 更新状态栏 */
static void smart_taskbar_cb(lv_task_t *task)
{

}

/* 显示主界面图标， 创建3个Table, 分别显示控制，主界面，及密码 */
/* 主界面显示时间，日期星期，及布撤防状态  左页面：灯的控制  右页面：键盘输入密码界面 */
static void smart_main_icon_create(lv_obj_t *par)
{
  int i;
  lv_obj_t *tabA, *tabB, *tabC;
  static lv_style_t mystyle1, mystyle2, mystyle3;
  static lv_style_t pwdkeystyle;
  
  lv_style_init(&mystyle1);
  lv_style_set_text_font(&mystyle1, LV_STATE_DEFAULT, &lv_font_montserrat_48);
  lv_style_set_text_color(&mystyle1, LV_LABEL_PART_MAIN, LV_COLOR_WHITE);

  lv_style_init(&mystyle2);
  lv_style_set_text_font(&mystyle2, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  lv_style_set_text_color(&mystyle2, LV_LABEL_PART_MAIN, LV_COLOR_WHITE);

  lv_style_init(&mystyle3);
  lv_style_set_text_font(&mystyle3, LV_STATE_DEFAULT, &lv_font_montserrat_12);
  lv_style_set_text_color(&mystyle3, LV_LABEL_PART_MAIN, LV_COLOR_WHITE);

  if(smart_tab_icon == NULL)
  {
    smart_tab_icon = lv_tabview_create(par, NULL);
    tabA = lv_tabview_add_tab(smart_tab_icon, "A PAGE");
    tabB = lv_tabview_add_tab(smart_tab_icon, "B PAGE");
    tabC = lv_tabview_add_tab(smart_tab_icon, "C PAGE");

    lv_tabview_set_btns_pos(smart_tab_icon, LV_TABVIEW_TAB_POS_NONE);
    lv_obj_set_style_local_bg_opa(smart_tab_icon,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_OPA_0);
    lv_obj_set_size(smart_tab_icon,lv_obj_get_width(lv_obj_get_parent(smart_tab_icon)),lv_obj_get_height(lv_obj_get_parent(smart_tab_icon)));

    printf("smart_main_icon_create size width is %d, height is %d", lv_obj_get_width(lv_obj_get_parent(smart_tab_icon)), lv_obj_get_height(lv_obj_get_parent(smart_tab_icon)));
  }

  /*-------------------------------- A PAGE ---------------------------------*/
  /* 控制界面 */
  for(i = 0; i < 4; i++)
  {
    if(smart_tab1_img[i] == NULL)
    {
      smart_tab1_img[i] = lv_imgbtn_create(lv_tabview_get_tab(smart_tab_icon, 0), NULL);
      lv_obj_set_event_cb(smart_tab1_img[i], LedCtrl_click_event_cb);
    }
    
    if(smart_tab1_label[i] == NULL)
    {
      smart_tab1_label[i] = lv_label_create(lv_tabview_get_tab(smart_tab_icon, 0), NULL);
    }

    if(smart_tab1_ledSta[i] == 0x00)
    {
      lv_imgbtn_set_src(smart_tab1_img[i], LV_BTN_STATE_RELEASED, &lampoff);
      lv_imgbtn_set_src(smart_tab1_img[i], LV_BTN_STATE_PRESSED, &lampoff);
    }
    else
    {
      lv_imgbtn_set_src(smart_tab1_img[i], LV_BTN_STATE_RELEASED, &lampon);
      lv_imgbtn_set_src(smart_tab1_img[i], LV_BTN_STATE_PRESSED, &lampon);
    }

    /* 显示状态 */
    lv_obj_align(smart_tab1_img[i], lv_tabview_get_tab(smart_tab_icon, 0), LV_ALIGN_IN_TOP_LEFT, led_icon_pos[i][0], led_icon_pos[i][1]);

    /* 显示label */
    lv_obj_add_style(smart_tab1_label[i], LV_OBJ_PART_MAIN, &mystyle2);
    lv_label_set_text(smart_tab1_label[i], led_icon_name[i]);
    lv_obj_align(smart_tab1_label[i], smart_tab1_img[i], LV_ALIGN_OUT_TOP_MID, 0, -8);
  
  }

  /*---------------------------------- END  ---------------------------------*/


  /*-------------------------------- B PAGE ---------------------------------*/
  /* 显示时间，显示日期，显示星期，显示布撤防状态 */
  /* 时间 */
  if(smart_tab2_time == NULL)
  {
    smart_tab2_time  = lv_label_create(lv_tabview_get_tab(smart_tab_icon, 1), NULL);
    lv_obj_set_event_cb(smart_tab2_time, smart_tabl2_time_event_cb);
  }

  lv_obj_add_style(smart_tab2_time, LV_OBJ_PART_MAIN, &mystyle1);
  lv_label_set_text(smart_tab2_time, "2 3 : 5 9");
  lv_obj_align(smart_tab2_time, lv_tabview_get_tab(smart_tab_icon, 1), LV_ALIGN_IN_TOP_MID, 0, 40);

  /* 显示日期，显示星期 */
  if(smart_tab2_date == NULL)
  {
    smart_tab2_date  = lv_label_create(lv_tabview_get_tab(smart_tab_icon, 1), NULL);
  }

  lv_obj_add_style(smart_tab2_date, LV_OBJ_PART_MAIN, &mystyle2);
  lv_label_set_text(smart_tab2_date, "2021/12/31 Friday");
  lv_obj_align(smart_tab2_date, lv_tabview_get_tab(smart_tab_icon, 1), LV_ALIGN_IN_TOP_MID, 0, 104);

  /* 显示布撤防按钮图标及文字 */
  if(smart_tab2_armimg == NULL)
  {
    smart_tab2_armimg = lv_imgbtn_create(lv_tabview_get_tab(smart_tab_icon, 1), NULL);
    lv_obj_set_event_cb(smart_tab2_armimg, ArmDisarmicon_click_event_cb);
  }
  if(smart_tab2_disarmimg == NULL)
  {
    smart_tab2_disarmimg = lv_imgbtn_create(lv_tabview_get_tab(smart_tab_icon, 1), NULL);
    lv_obj_set_event_cb(smart_tab2_disarmimg, ArmDisarmicon_click_event_cb);
  }
  if(ArmDisamStatus == 0x00)  // 撤防
  {
    lv_imgbtn_set_src(smart_tab2_armimg, LV_BTN_STATE_RELEASED, &Arm_1);
    lv_imgbtn_set_src(smart_tab2_disarmimg, LV_BTN_STATE_RELEASED, &Disarm_2);
    
    lv_imgbtn_set_src(smart_tab2_armimg, LV_BTN_STATE_PRESSED, &Arm_1);
    lv_imgbtn_set_src(smart_tab2_disarmimg, LV_BTN_STATE_PRESSED, &Disarm_2);
  }
  else
  {
    lv_imgbtn_set_src(smart_tab2_armimg, LV_BTN_STATE_RELEASED, &Arm_2);
    lv_imgbtn_set_src(smart_tab2_disarmimg, LV_BTN_STATE_RELEASED, &Disarm_1);

    lv_imgbtn_set_src(smart_tab2_armimg, LV_BTN_STATE_PRESSED, &Arm_2);
    lv_imgbtn_set_src(smart_tab2_disarmimg, LV_BTN_STATE_PRESSED, &Disarm_1);
  }
  lv_obj_align(smart_tab2_armimg, lv_tabview_get_tab(smart_tab_icon, 1), LV_ALIGN_IN_BOTTOM_LEFT, 66, -80);
  lv_obj_align(smart_tab2_disarmimg, lv_tabview_get_tab(smart_tab_icon, 1), LV_ALIGN_IN_BOTTOM_RIGHT, -66, -80);

  if(smart_tab2_armlabel == NULL)
  {
    smart_tab2_armlabel = lv_label_create(lv_tabview_get_tab(smart_tab_icon, 1), NULL);
  }
  if(smart_tab2_disarmlabel == NULL)
  {
    smart_tab2_disarmlabel = lv_label_create(lv_tabview_get_tab(smart_tab_icon, 1), NULL);
  }

  lv_obj_add_style(smart_tab2_armlabel, LV_OBJ_PART_MAIN, &mystyle3);
  lv_obj_add_style(smart_tab2_disarmlabel, LV_OBJ_PART_MAIN, &mystyle3);

  lv_label_set_text(smart_tab2_armlabel, "Arm");
  lv_obj_align(smart_tab2_armlabel, smart_tab2_armimg, LV_ALIGN_OUT_BOTTOM_MID, 0, 8);

  lv_label_set_text(smart_tab2_disarmlabel, "Disarm");
  lv_obj_align(smart_tab2_disarmlabel, smart_tab2_disarmimg, LV_ALIGN_OUT_BOTTOM_MID, 0, 8);

  /*-------------------------------- End ---------------------------------*/

  /*-------------------------------- C PAGE ---------------------------------*/
  /* 密码登录界面 */
  /* 提示信息 */
  if(tab3_pwdTipinfo_label == NULL)
  {
    tab3_pwdTipinfo_label = lv_label_create(lv_tabview_get_tab(smart_tab_icon, 2), NULL);
  }
  lv_obj_add_style(tab3_pwdTipinfo_label, LV_OBJ_PART_MAIN, &mystyle2);
  lv_label_set_text(tab3_pwdTipinfo_label, "Please enter you password!");
  lv_obj_align(tab3_pwdTipinfo_label, lv_tabview_get_tab(smart_tab_icon, 2), LV_ALIGN_IN_TOP_MID, 0, 16);

  /* 密码输入框 */
  if(tab3_pwdTextArea == NULL)
  {
    tab3_pwdTextArea = lv_textarea_create(lv_tabview_get_tab(smart_tab_icon, 2), NULL);
  }
  lv_obj_set_width(tab3_pwdTextArea, 100);
  lv_textarea_set_one_line(tab3_pwdTextArea, true);
  lv_textarea_set_pwd_mode(tab3_pwdTextArea, true);
  lv_textarea_set_cursor_hidden(tab3_pwdTextArea, true);
  lv_textarea_set_text(tab3_pwdTextArea, "");
  lv_obj_align(tab3_pwdTextArea, tab3_pwdTipinfo_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

  /* 显示键盘 */
  if(tab3_pwdInputBtnm == NULL)
  {
    tab3_pwdInputBtnm = lv_btnmatrix_create(lv_tabview_get_tab(smart_tab_icon, 2), NULL);
    lv_obj_set_event_cb(tab3_pwdInputBtnm, tab3_pwdInputBtnm_click_event_cb);
  }
  lv_style_init(&pwdkeystyle);
  lv_style_set_bg_opa(&pwdkeystyle, LV_STATE_DEFAULT, LV_OPA_50);
  lv_style_set_bg_color(&pwdkeystyle, LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_style_set_text_font(&pwdkeystyle, LV_STATE_DEFAULT, &lv_font_montserrat_16);

  lv_obj_add_style(tab3_pwdInputBtnm, LV_OBJ_PART_MAIN, &pwdkeystyle);
  lv_obj_set_size(tab3_pwdInputBtnm, 240, 170);
  lv_btnmatrix_set_map(tab3_pwdInputBtnm, tab3_btnm_map);
  lv_obj_align(tab3_pwdInputBtnm, tab3_pwdTextArea, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
  
  
  /*---------------------------------- END  ---------------------------------*/
  lv_tabview_set_tab_act(smart_tab_icon, 1, LV_ANIM_OFF);
  lv_obj_set_event_cb(smart_tab_icon, tab_move_event_cb);

}

// 修改时间
static void smart_tabl2_time_event_cb(void)
{

}


static lv_event_cb_t tab_move_event_cb(lv_obj_t *tab, lv_event_t e)
{
  if(tab == smart_tab_icon)
  {
    if(e == LV_EVENT_VALUE_CHANGED)
    {
      printf("page_chage\n");
      lv_textarea_set_text(tab3_pwdTextArea, "");
      lv_label_set_text(tab3_pwdTipinfo_label, "Please enter you password!");
    }
  }
}

// 布撤防图标控制
static lv_event_cb_t ArmDisarmicon_click_event_cb(lv_obj_t * icon, lv_event_t e)
{
  char flg = 0;
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    if(icon == smart_tab2_armimg)
    {
      if(ArmDisamStatus == 0)
      {
        ArmDisamStatus = 1;
        flg = 1;
      }
    }
    if(icon == smart_tab2_disarmimg)
    {
      if(ArmDisamStatus == 1)
      {
        ArmDisamStatus = 0;
        flg = 1;
      }
    }

    if(flg == 1)
    {
      if(ArmDisamStatus == 0x00)  // 撤防
      {
        lv_imgbtn_set_src(smart_tab2_armimg, LV_BTN_STATE_RELEASED, &Arm_1);
        lv_imgbtn_set_src(smart_tab2_disarmimg, LV_BTN_STATE_RELEASED, &Disarm_2);
      }
      else
      {
        lv_imgbtn_set_src(smart_tab2_armimg, LV_BTN_STATE_RELEASED, &Arm_2);
        lv_imgbtn_set_src(smart_tab2_disarmimg, LV_BTN_STATE_RELEASED, &Disarm_1)  ;
      }
    }
  }
}

// 灯控回调
static lv_event_cb_t LedCtrl_click_event_cb(lv_obj_t * icon, lv_event_t e)
{
  char flg = 0;
  int i = 0;
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    for(i = 0; i < 4; i++)
    {
      if(icon == smart_tab1_img[i])
      {
        if(smart_tab1_ledSta[i] == 0x00)
          smart_tab1_ledSta[i] = 1;
        else 
          smart_tab1_ledSta[i] = 0;

        break;
      }
    }

    if(smart_tab1_ledSta[i] == 0x00)
    {
      lv_imgbtn_set_src(smart_tab1_img[i], LV_BTN_STATE_RELEASED, &lampoff);
      lv_imgbtn_set_src(smart_tab1_img[i], LV_BTN_STATE_PRESSED, &lampoff);
    }
    else
    {
      lv_imgbtn_set_src(smart_tab1_img[i], LV_BTN_STATE_RELEASED, &lampon);
      lv_imgbtn_set_src(smart_tab1_img[i], LV_BTN_STATE_PRESSED, &lampon);
    }
  }
}


/* 密码键盘回调 */
static void tab3_pwdInputBtnm_click_event_cb(lv_obj_t * tab_btnm, lv_event_t event)
{
  if(event == LV_EVENT_VALUE_CHANGED) 
  {
    const char * txt = lv_btnmatrix_get_active_btn_text(tab_btnm);
    
    printf("%s was pressed\n", txt);
    
    if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0)
    {
      lv_textarea_del_char(tab3_pwdTextArea);
    }
    else if(strcmp(txt, LV_SYMBOL_OK) == 0) 
    {
      const char *pwd = lv_textarea_get_text(tab3_pwdTextArea);
      if(strcmp(pwd, "888888") == 0)  // 密码正确
      {
        /* 进入编程界面 */
        lv_tabview_set_tab_act(smart_tab_icon, 1, LV_ANIM_OFF);
        Smart_Program_Create(lv_scr_act());

      }
      else  // 密码错误
      {
       // lv_label_set_text(tab3_pwdTipinfo_label, "Wrong password,Please re-enter!");
        //lv_textarea_add_char(tab_btnm, "");
      }
    }
    else 
    {
      lv_textarea_add_text(tab3_pwdTextArea, txt);
    }
  }
}

