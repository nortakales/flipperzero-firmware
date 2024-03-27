/**
 * @file variable_item_list.h
 * GUI: VariableItemList view module API
 */

#pragma once

#include <gui/view.h>
#include <gui/modules/variable_item_list.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Get item in VariableItemList
 *
 * @param      variable_item_list  VariableItemList instance
 * @param      position            index of the item to get
 *
 * @return     VariableItem* item instance
 */
VariableItem* variable_item_list_get(VariableItemList* variable_item_list, uint8_t position);

/** Set optional header for variable item list
 * Must be called before adding items OR after adding items but also call set_selected_item() after set_header()
 *
 * @param      variable_item_list  VariableItemList instance
 * @param      header              header to set
 */
void variable_item_list_set_header(VariableItemList* variable_item_list, const char* header);

#ifdef __cplusplus
}
#endif
