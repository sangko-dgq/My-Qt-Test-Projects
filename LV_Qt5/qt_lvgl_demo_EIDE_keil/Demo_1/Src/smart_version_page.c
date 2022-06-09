/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_version_page.c
 * \author    yifeng
 * \version   1.0
 * \date      2021年12月20日
 * \brief     版本信息
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
#include "Demo_1/Inc/smart_version_page.h"

static lv_obj_t *version_win_obj;

static bool dragflag = false;

LV_IMG_DECLARE(vx);


static lv_event_cb_t lv_version_win_close_event_cb(lv_obj_t * icon, lv_event_t e);


/*!
 * \fn     Smart_Version_Create
 * \brief  版本信息
 *         弹窗显示二维码
 * \param  [in] lv_obj_t* parent   #
 * 
 * \retval void
 */
void Smart_Version_Create(lv_obj_t* parent)
{
  if(dragflag == true)
  {
    return ;
  }

  dragflag = true;
  version_win_obj = lv_win_create(parent, NULL);
  lv_obj_set_style_local_bg_opa(version_win_obj, LV_PAGE_PART_BG,  LV_STATE_DEFAULT, LV_OPA_60);
  lv_obj_set_style_local_radius(version_win_obj, LV_PAGE_PART_BG, LV_STATE_DEFAULT, 3);
  lv_obj_set_style_local_bg_color(version_win_obj, LV_WIN_PART_HEADER, LV_STATE_DEFAULT, LV_COLOR_GRAY);
  lv_obj_set_style_local_text_color(version_win_obj, LV_WIN_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_win_set_title(version_win_obj, "Version info");
  lv_obj_set_size(version_win_obj, 248, 284);
  lv_win_set_header_height(version_win_obj, 32);
  lv_win_set_drag(version_win_obj, true);
  lv_win_set_scrollbar_mode(version_win_obj, LV_SCROLLBAR_MODE_OFF);
  lv_obj_align(version_win_obj, NULL, LV_ALIGN_CENTER, 0, 0);

  /* 关闭按钮 */
  lv_obj_t *close_btn = lv_win_add_btn(version_win_obj, LV_SYMBOL_CLOSE);
  lv_obj_set_style_local_text_color(close_btn, LV_WIN_PART_BG, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_event_cb(close_btn, lv_version_win_close_event_cb);

  /* 显示二维码图片 */
  lv_obj_t *img = lv_img_create(version_win_obj, NULL);
  lv_img_set_src(img, &vx);
  lv_obj_align(img, version_win_obj, LV_ALIGN_IN_TOP_MID, 0, 36);
  
}


static lv_event_cb_t lv_version_win_close_event_cb(lv_obj_t * icon, lv_event_t e)
{
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    if(dragflag == true)
    {
      dragflag = false;
      lv_obj_del(version_win_obj);
    }
  }
}

