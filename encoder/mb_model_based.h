/******************************************************************************
 *
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *****************************************************************************
 * Originally developed and contributed by Ittiam Systems Pvt. Ltd, Bangalore
*/
/*!
******************************************************************************
* \file mb_model_based.h
*
* \brief
*    This file contains all the necessary declarations for
*    mb level API functions
*
* \date
*
* \author
*    ittiam
*
******************************************************************************
*/
#ifndef _MB_MODEL_BASED_H_
#define _MB_MODEL_BASED_H_

/*****************************************************************************/
/* Structure                                                                 */
/*****************************************************************************/
typedef struct mb_rate_control_t *mb_rate_control_handle;

/*****************************************************************************/
/* Function Declarations                                                     */
/*****************************************************************************/
WORD32 mbrc_num_fill_use_free_memtab(
    mb_rate_control_handle *pps_mb_rate_control,
    itt_memtab_t *ps_memtab,
    ITT_FUNC_TYPE_E e_func_type);
/* Initialising the state structure */
void init_mb_level_rc(mb_rate_control_handle ps_mb_rate_control);
/* MB parameters that are to be initalised at a frame level */
void mb_init_frame_level(mb_rate_control_handle ps_mb_rate_control, UWORD8 u1_frame_qp);
/* MB Level call to get the mb_level QP */
void get_mb_qp(
    mb_rate_control_handle ps_mb_rate_control, WORD32 i4_cur_mb_activity, WORD32 *pi4_mb_qp);
/* MB Parameters that are to be updated at a frame level */
void mb_update_frame_level(mb_rate_control_handle ps_mb_rate_control, WORD32 i4_avg_activity);
/****************************************************************************
            CONTROL FUCNTIONS FROM FRAME LEVEL
****************************************************************************/
/* Returns the stored frame level QP */
UWORD8 get_frm_level_qp(mb_rate_control_handle ps_mb_rate_control);
/* Disables activity based qp modulation */
void reset_mb_activity(mb_rate_control_handle ps_mb_rate_control);

#endif
