/*!
 *****************************************************************************
 *
 *  Copyright ? 2017-2018 yifeng. All Rights Reserved.
 *
 * \file      smart_photo_page.c
 * \author    yifeng
 * \version   1.0
 * \date      2021年12月20日
 * \brief     相册管理
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
#include "Demo_1/Inc/smart_photo_page.h"


static int img_index = 0;

lv_obj_t *smartphoto_img;

lv_obj_t *smartphoto_imgbtn[3];  // 3个图标，左， 右，返回；


LV_IMG_DECLARE(Black_bg);
LV_IMG_DECLARE(Black_bg1);

LV_IMG_DECLARE(CLOSE);
LV_IMG_DECLARE(LEFT);
LV_IMG_DECLARE(RIGHT);


LV_IMG_DECLARE(pic1);
LV_IMG_DECLARE(pic2);
LV_IMG_DECLARE(pic3);
LV_IMG_DECLARE(pic4);
LV_IMG_DECLARE(pic5);
LV_IMG_DECLARE(pic6);
LV_IMG_DECLARE(pic7);
LV_IMG_DECLARE(pic8);
LV_IMG_DECLARE(pic9);
LV_IMG_DECLARE(pic10);


static const lv_img_dsc_t *smartphoto_pic_array[10] = 
{
  &pic1,
  &pic2,
  &pic3,
  &pic4,
  &pic5,
  &pic6,
  &pic7,
  &pic8,
  &pic9,
  &pic10,
};


static lv_event_cb_t smartphoto_click_event_cb(lv_obj_t * icon, lv_event_t e);



void Smart_Photo_Create(lv_obj_t* parent)
{
  smartphoto_img = lv_img_create(parent, NULL);
  lv_obj_set_size(smartphoto_img, 320, 320);
  lv_img_set_src(smartphoto_img,  smartphoto_pic_array[img_index]);
  lv_obj_align(smartphoto_img, parent, LV_ALIGN_CENTER, 0, 0);

  smartphoto_imgbtn[0] = lv_imgbtn_create(smartphoto_img, NULL);
  lv_imgbtn_set_src(smartphoto_imgbtn[0], LV_BTN_STATE_RELEASED, &LEFT);
  lv_imgbtn_set_src(smartphoto_imgbtn[0], LV_BTN_STATE_PRESSED, &LEFT);
  lv_obj_set_event_cb(smartphoto_imgbtn[0], smartphoto_click_event_cb);
  lv_obj_align(smartphoto_imgbtn[0], parent, LV_ALIGN_IN_LEFT_MID, 8, 0);

  smartphoto_imgbtn[1] = lv_imgbtn_create(smartphoto_img, NULL);
  lv_imgbtn_set_src(smartphoto_imgbtn[1], LV_BTN_STATE_RELEASED, &RIGHT);
  lv_imgbtn_set_src(smartphoto_imgbtn[1], LV_BTN_STATE_PRESSED, &RIGHT);
  lv_obj_set_event_cb(smartphoto_imgbtn[1], smartphoto_click_event_cb);
  lv_obj_align(smartphoto_imgbtn[1], parent, LV_ALIGN_IN_RIGHT_MID, -8, 0);
 
  smartphoto_imgbtn[2] = lv_imgbtn_create(smartphoto_img, NULL);
  lv_imgbtn_set_src(smartphoto_imgbtn[2], LV_BTN_STATE_RELEASED, &CLOSE);
  lv_imgbtn_set_src(smartphoto_imgbtn[2], LV_BTN_STATE_PRESSED, &CLOSE);
  lv_obj_set_event_cb(smartphoto_imgbtn[2], smartphoto_click_event_cb);
  lv_obj_align(smartphoto_imgbtn[2], parent, LV_ALIGN_IN_TOP_LEFT, 4, 4);
}


static lv_event_cb_t smartphoto_click_event_cb(lv_obj_t * icon, lv_event_t e)
{
  if(e == LV_EVENT_SHORT_CLICKED)
  {
    printf("smartphoto_click_event_cb\r\n");

    if(icon == smartphoto_imgbtn[0])
    {
      img_index++;
      if(img_index > 10)
      {
        img_index = 0;
      }
      lv_img_set_src(smartphoto_img,  smartphoto_pic_array[img_index]);
    }
    else if(icon == smartphoto_imgbtn[1])
    {
      if(img_index == 0)
      {
        img_index = 10;
      }
      img_index--;
      lv_img_set_src(smartphoto_img,  smartphoto_pic_array[img_index]);
    }
    else if(icon == smartphoto_imgbtn[2])  // 关闭
    {
      lv_obj_del(smartphoto_img);
    }
    else
    {
    }
  }
}

