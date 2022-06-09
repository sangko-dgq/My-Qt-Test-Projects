/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_phone_page.c
 * \author    yifeng
 * \version   1.0
 * \date      2021年12月20日
 * \brief     电话管理
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
#include "Demo_1/Inc/smart_phone_page.h"


LV_IMG_DECLARE(BACK);
LV_IMG_DECLARE(phonenumber);
LV_IMG_DECLARE(phoneset);




static lv_obj_t *phone_page;

static lv_obj_t *back_btn;
static lv_obj_t *phone_title;
static lv_obj_t *phonenumber_widget[8];
static lv_obj_t *phonenumber_label[8];
static lv_obj_t *phonenumber_label1[8];
static lv_obj_t *phoneset_img[8];

unsigned char phone_number[8][64];
unsigned char currentnumId;

static const char *index_name[8] = 
{
  "No 1:",
  "No 2:",
  "No 3:",
  "No 4:",
  "No 5:",
  "No 6:",
  "No 7:",
  "No 8:",
};



static int phone_btn_pos[8][2] = 
{
  {24,64},  {168,64},
  {24,120}, {168,120},
  {24,176}, {168,176},
  {24,232}, {168,232},
};


static lv_obj_t *phone_type_set;
static bool typestatus = false;
static bool numberstatus = false;

static int numberInputCnt = 0; 

// 输入号码
static lv_obj_t *phonenumin_page;
static lv_obj_t *phonenumin_back_btn;
static lv_obj_t *phonenumin_title;
static lv_obj_t *phonenumin_pwdTextArea;
static lv_obj_t *phonenumin_pwdInputBtnm;

/* 表3 密码登录界面 */
static const char *phonenumin_btnm_map[] = 
{
  "1", "2", "3", "\n",
  "4", "5", "6", "\n",
  "7", "8", "9", "\n",
  LV_SYMBOL_BACKSPACE, "0", LV_SYMBOL_OK, ""
};


static lv_event_cb_t smartphone_back_click_event_cb(lv_obj_t * icon, lv_event_t e);
static lv_event_cb_t smartphoneset_click_event_cb(lv_obj_t * icon, lv_event_t e);
static lv_event_cb_t smartphonenumberinput_click_event_cb(lv_obj_t *icon, lv_event_t e);
static void Smart_PhoneType_Create(lv_obj_t *parent);
static lv_event_cb_t smartphone_close_click_event_cb(lv_obj_t * icon, lv_event_t e);

static void roller_event_handler(lv_obj_t * obj, lv_event_t event);

static void Smart_PhoneNumberInput_Create(lv_obj_t *parent);

static void smartphonenum_back_click_event_cb(lv_obj_t * tab_btnm, lv_event_t event);
static void phonenumin_pwdInputBtnm_click_event_cb(lv_obj_t * tab_btnm, lv_event_t event);


void Smart_Phone_Create(lv_obj_t* parent)
{
  int i;
  
  phone_page = lv_obj_create(parent, NULL);
  lv_obj_set_style_local_bg_color(phone_page, LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(7, 12, 30));
  lv_obj_set_size(phone_page, LV_HOR_RES_MAX, LV_VER_RES_MAX);

  /* 显示返回按钮 */
  back_btn = lv_imgbtn_create(phone_page, NULL);
  lv_imgbtn_set_src(back_btn, LV_BTN_STATE_RELEASED, &BACK);
  lv_obj_set_event_cb(back_btn, smartphone_back_click_event_cb);
  lv_obj_align(back_btn, parent, LV_ALIGN_IN_TOP_LEFT, 12, 6);

  /* 显示标题 */
  phone_title = lv_label_create(phone_page, NULL);
  lv_obj_set_style_local_text_color(phone_title, LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(phone_title, "Phone number settings");
  lv_obj_align(phone_title, back_btn, LV_ALIGN_OUT_RIGHT_MID, 2, 0);

  /* 显示8组号码 */
  for(i = 0; i < 8; i++)
  {
    /* 背景 */
    phonenumber_widget[i] = lv_obj_create(phone_page, NULL);
    lv_obj_set_style_local_bg_color(phonenumber_widget[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(19, 28, 60));
    lv_obj_set_style_local_radius(phonenumber_widget[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, 3);
    lv_obj_set_style_local_shadow_width(phonenumber_widget[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, 3);
    lv_obj_set_style_local_shadow_spread(phonenumber_widget[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, 3);
    lv_obj_set_style_local_shadow_color(phonenumber_widget[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    lv_obj_set_style_local_border_color(phonenumber_widget[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(19, 28, 60));
    lv_obj_set_size(phonenumber_widget[i], 128, 40); 
    lv_obj_set_event_cb(phonenumber_widget[i], smartphonenumberinput_click_event_cb);
    lv_obj_align(phonenumber_widget[i], parent, LV_ALIGN_IN_TOP_LEFT, phone_btn_pos[i][0], phone_btn_pos[i][1]);
    

    /* 设置图标 */
    phoneset_img[i] = lv_imgbtn_create(phone_page, NULL);
    lv_obj_set_event_cb(phoneset_img[i], smartphoneset_click_event_cb);
    lv_imgbtn_set_src(phoneset_img[i], LV_BTN_STATE_RELEASED, &phoneset);
    lv_imgbtn_set_src(phoneset_img[i], LV_BTN_STATE_PRESSED, &phoneset);
    lv_obj_align(phoneset_img[i], phonenumber_widget[i], LV_ALIGN_IN_LEFT_MID, 4, 0);

    /* 显示序号 */
    phonenumber_label1[i] = lv_label_create(phone_page, NULL);
    lv_obj_set_style_local_text_font(phonenumber_label1[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, &lv_font_montserrat_12);
    lv_obj_set_style_local_text_opa(phonenumber_label1[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_OPA_80);
    lv_obj_set_style_local_text_color(phonenumber_label1[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_label_set_text(phonenumber_label1[i], index_name[i]);
    lv_obj_align(phonenumber_label1[i], phoneset_img[i], LV_ALIGN_OUT_RIGHT_TOP, 4, 0);
    
    /* 显示电话号码 */
    phonenumber_label[i] = lv_label_create(phone_page, NULL);
    lv_obj_set_style_local_text_font(phonenumber_label[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, &lv_font_montserrat_12);
    lv_obj_set_style_local_text_opa(phonenumber_label[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_OPA_100);
    lv_obj_set_style_local_text_color(phonenumber_label[i], LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_label_set_text(phonenumber_label[i], &phone_number[i][0]);
    lv_obj_align(phonenumber_label[i], phoneset_img[i], LV_ALIGN_OUT_RIGHT_BOTTOM, 4, 0);
    
  }

}



// 返回回调 删除当前对象
static lv_event_cb_t smartphone_back_click_event_cb(lv_obj_t * icon, lv_event_t e)
{
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    if(icon == back_btn)
    {
      // 删除
      lv_obj_del(phone_page);
    }
  }
}

/* 电话设置 */
static lv_event_cb_t smartphoneset_click_event_cb(lv_obj_t * icon, lv_event_t e)
{
  
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    if(numberstatus == true)
    {
      numberstatus = false;
      
    }
    else
    {
      printf("smartphomeset_click_event_cb\r\n");
      if(typestatus == false)
      {
        Smart_PhoneType_Create(lv_scr_act());
      }
    }
  }
}

/* 电话号码输入 */
static lv_event_cb_t smartphonenumberinput_click_event_cb(lv_obj_t *icon, lv_event_t e)
{
  char i;

  if(typestatus == true)
  {
    return ;
  }
  
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    if(numberstatus == true)
    {
      numberstatus = false;
    }
    else
    {
      for(i = 0; i < 8; i++)
      {
        if(icon == phonenumber_widget[i])
        {
          currentnumId = i;
          printf("smartphonenumberinput_click_event_cb : %d\r\n", i);
          Smart_PhoneNumberInput_Create(lv_scr_act());
          break;
        } 
      }
    }
  }
}


/*!
 * \fn     Smart_PhoneType_Create
 * \brief  电话类型
 *          
 * \param  [in] lv_obj_t *par   #
 * 
 * \retval static void
 */
static void Smart_PhoneType_Create(lv_obj_t *parent)
{
  if(typestatus == true)
  {
    return ;
  }

  typestatus = true;
  phone_type_set = lv_win_create(parent, NULL);
  lv_obj_set_style_local_bg_opa(phone_type_set, LV_PAGE_PART_BG,  LV_STATE_DEFAULT, LV_OPA_80);
  lv_obj_set_style_local_radius(phone_type_set, LV_PAGE_PART_BG, LV_STATE_DEFAULT, 5);
  lv_obj_set_style_local_bg_color(phone_type_set, LV_WIN_PART_HEADER, LV_STATE_DEFAULT, LV_COLOR_SILVER);
  lv_obj_set_style_local_text_color(phone_type_set, LV_WIN_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_win_set_title(phone_type_set, "Type Sel");
  lv_obj_set_size(phone_type_set, 110, 138);
  lv_win_set_header_height(phone_type_set, 30);
  lv_win_set_drag(phone_type_set, true);
  lv_win_set_scrollbar_mode(phone_type_set, LV_SCROLLBAR_MODE_OFF);
  lv_obj_align(phone_type_set, NULL, LV_ALIGN_CENTER, 0, 0);
  
  /* 关闭按钮 */
  lv_obj_t *close_btn = lv_win_add_btn(phone_type_set, LV_SYMBOL_CLOSE);
  lv_obj_set_style_local_bg_color(close_btn, LV_WIN_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_align(close_btn, phone_type_set, LV_ALIGN_IN_TOP_RIGHT, 8, 0);
  lv_obj_set_event_cb(close_btn, smartphone_close_click_event_cb);

  /* 显示列表 */
  lv_obj_t *type_roller1 = lv_roller_create(phone_type_set, NULL);
  lv_roller_set_options(type_roller1,
                      "SMS\n"
                      "Dail\n"
                      "SMS & Dail\n"
                      "CID",
                      LV_ROLLER_MODE_INFINITE);
  
  lv_roller_set_visible_row_count(type_roller1, 3);
  lv_roller_set_fix_width(type_roller1, 110);
  lv_roller_set_selected(type_roller1, 0, true);
  lv_obj_set_style_local_bg_color(type_roller1, LV_WIN_PART_HEADER, LV_STATE_DEFAULT, LV_COLOR_SILVER);
  lv_obj_align(type_roller1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
  lv_obj_set_event_cb(type_roller1, roller_event_handler);
}

static void roller_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        printf("type_roller1: %s\n", buf);
    }
}


static lv_event_cb_t smartphone_close_click_event_cb(lv_obj_t * icon, lv_event_t e)
{
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    // 删除
    lv_obj_del(phone_type_set);
    typestatus = false;
  }
}



// 输入键盘
static void Smart_PhoneNumberInput_Create(lv_obj_t *parent)
{
  static lv_style_t pwdkeystyle;
  
  numberInputCnt = 0;
  
  phonenumin_page = lv_obj_create(parent, NULL);
  lv_obj_set_style_local_bg_color(phonenumin_page, LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(7, 12, 30));
  lv_obj_set_size(phonenumin_page, LV_HOR_RES_MAX, LV_VER_RES_MAX);
  
  /* 显示返回按钮 */
  phonenumin_back_btn = lv_imgbtn_create(phonenumin_page, NULL);
  lv_imgbtn_set_src(phonenumin_back_btn, LV_BTN_STATE_RELEASED, &BACK);
  lv_obj_set_event_cb(phonenumin_back_btn, smartphonenum_back_click_event_cb);
  lv_obj_align(phonenumin_back_btn, parent, LV_ALIGN_IN_TOP_LEFT, 12, 6);
  
  /* 显示标题 */
  phonenumin_title = lv_label_create(phonenumin_page, NULL);
  lv_obj_set_style_local_text_color(phonenumin_title, LV_PAGE_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(phonenumin_title, "Phone Enter Number");
  lv_obj_align(phonenumin_title, phonenumin_back_btn, LV_ALIGN_OUT_RIGHT_MID, 2, 0);

  /* 显示输入框 */
  phonenumin_pwdTextArea = lv_textarea_create(phonenumin_page, NULL);
  lv_obj_set_width(phonenumin_pwdTextArea, 100);
  lv_textarea_set_one_line(phonenumin_pwdTextArea, true);
  lv_textarea_set_cursor_hidden(phonenumin_pwdTextArea, true);
  lv_textarea_set_text(phonenumin_pwdTextArea, "");
  lv_obj_align(phonenumin_pwdTextArea, phonenumin_title, LV_ALIGN_OUT_BOTTOM_MID, 45, 20);
  
  /* 显示键盘 */
  phonenumin_pwdInputBtnm = lv_btnmatrix_create(phonenumin_page, NULL);
  lv_obj_set_event_cb(phonenumin_pwdInputBtnm, phonenumin_pwdInputBtnm_click_event_cb);
  
  lv_style_init(&pwdkeystyle);
  lv_style_set_bg_opa(&pwdkeystyle, LV_STATE_DEFAULT, LV_OPA_50);
  lv_style_set_bg_color(&pwdkeystyle, LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_style_set_text_font(&pwdkeystyle, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  
  lv_obj_add_style(phonenumin_pwdInputBtnm, LV_OBJ_PART_MAIN, &pwdkeystyle);
  lv_obj_set_size(phonenumin_pwdInputBtnm, 240, 170);
  lv_btnmatrix_set_map(phonenumin_pwdInputBtnm, phonenumin_btnm_map);
  lv_obj_align(phonenumin_pwdInputBtnm, phonenumin_pwdTextArea, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

  numberstatus = true;
}


static void smartphonenum_back_click_event_cb(lv_obj_t * tab_btnm, lv_event_t event)
{
  if(event == LV_EVENT_SHORT_CLICKED)
   {
     // 删除
     lv_obj_del(phonenumin_page);
     numberstatus = false;
   }
}

/* 密码键盘回调 */
static void phonenumin_pwdInputBtnm_click_event_cb(lv_obj_t * tab_btnm, lv_event_t event)
{
  if(event == LV_EVENT_VALUE_CHANGED) 
  {
    const char * txt = lv_btnmatrix_get_active_btn_text(tab_btnm);
    
    printf("%s was pressed\n", txt);

      if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0)
      {
        lv_textarea_del_char(phonenumin_pwdTextArea);
        numberInputCnt--;
      }
      else if(strcmp(txt, LV_SYMBOL_OK) == 0) 
      {
        /* 保存参数，删除窗口 */
        const char *pwd = lv_textarea_get_text(phonenumin_pwdTextArea);
        memcpy(&phone_number[currentnumId][0], &pwd[0], 16);
        lv_obj_del(phonenumin_page);
        lv_label_set_text(phonenumber_label[currentnumId], &phone_number[currentnumId][0]);
      }
      else 
      {
        if(numberInputCnt < 11)
        {
          lv_textarea_add_text(phonenumin_pwdTextArea, txt);
          numberInputCnt++;
        }
      }
  }
}


