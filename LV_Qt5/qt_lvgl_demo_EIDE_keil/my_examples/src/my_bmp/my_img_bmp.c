#include "my_examples.h"

typedef enum
{
    IMG_POS_LEFT,
    IMG_POS_RIGHT    
}img_pos_e;

typedef struct 
{
    char *img_path;
    char *label_text;
}img_info_t;

static const img_info_t img_gallery_0[] = 
{
    {"P:../my_examples/assets/hudieren_32.bmp", "32BPP"},
    {"P:../my_examples/assets/hudieren_24.bmp", "24BPP"},
    {"P:../my_examples/assets/hudieren_16.bmp", "16BPP"},
    {"P:../my_examples/assets/hudieren_8.bmp", "8BPP"},
    {"P:../my_examples/assets/hudieren_4.bmp", "4BPP"},
    {"P:../my_examples/assets/hudieren_1.bmp", "1BPP"},
};

static const img_info_t img_gallery_1[] = 
{
    {"P:../my_examples/assets/anime_32.bmp", "32BPP"},
    {"P:../my_examples/assets/anime_24.bmp", "24BPP"},
    {"P:../my_examples/assets/anime_16.bmp", "16BPP"},
    {"P:../my_examples/assets/anime_8.bmp", "8BPP"},
    {"P:../my_examples/assets/anime_4.bmp", "4BPP"},
    {"P:../my_examples/assets/anime_1.bmp", "1BPP"},
};


static lv_obj_t *bmp_show(const img_info_t *pimg, uint8_t img_num, lv_obj_t *align_base, img_pos_e pos)
{
    lv_obj_t *cont = lv_cont_create(lv_scr_act(), NULL);
    lv_obj_set_drag(cont, true);
    lv_obj_set_auto_realign(cont, true);                    /*Auto realign when the size changes*/
    lv_cont_set_fit(cont, LV_FIT_TIGHT);
    lv_cont_set_layout(cont, LV_LAYOUT_OFF);
    lv_obj_set_style_local_bg_opa(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_obj_set_style_local_border_opa(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_obj_set_style_local_pad_top(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 5);
    lv_obj_set_style_local_pad_bottom(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 5);

    lv_obj_t *prev_img = NULL;
    for(int i = 0; i < img_num; i++)
    {
        lv_obj_t *img = lv_img_create(cont, NULL);
        lv_img_set_src(img, pimg[i].img_path);
        if(i != 0)
        {
            lv_obj_align(img, prev_img, LV_ALIGN_OUT_LEFT_MID, -50, 0);
        }
        prev_img = img;

        lv_obj_t *label = lv_label_create(cont, NULL);
        lv_label_set_text(label, pimg[i].label_text);
        lv_obj_align(label, img, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);    
    }
    lv_obj_align(cont, align_base, (align_base == NULL) ? LV_ALIGN_IN_TOP_LEFT : LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);  /*This parametrs will be sued when realigned*/

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, cont);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_x);
    lv_anim_value_t start = (pos == IMG_POS_LEFT) ? (-lv_obj_get_width(cont)) : lv_obj_get_width(lv_scr_act());
    lv_anim_value_t end = (pos == IMG_POS_LEFT) ? lv_obj_get_width(lv_scr_act()) 
            : (-(lv_obj_get_width(cont) + lv_obj_get_width(lv_scr_act())));
    lv_anim_set_values(&a, start, end);
    lv_anim_set_time(&a, 30000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);

    return cont;
}

void my_bmp_1(void)
{
    lv_obj_t *cont = bmp_show(img_gallery_0, sizeof(img_gallery_0) / sizeof(img_gallery_0[0]), NULL, IMG_POS_LEFT);
    cont = bmp_show(img_gallery_1, sizeof(img_gallery_1) / sizeof(img_gallery_1[0]), cont, IMG_POS_RIGHT);
    // bmp_show(img_gallery_1, sizeof(img_gallery_1) / sizeof(img_gallery_1[0]), cont, IMG_POS_LEFT);
}

