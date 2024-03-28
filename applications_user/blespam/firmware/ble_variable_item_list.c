#include "ble_variable_item_list.h"
#include <gui/elements.h>
#include <gui/canvas.h>
#include <furi.h>
#include <m-array.h>
#include <stdint.h>

struct VariableItem {
    const char* label;
    uint8_t current_value_index;
    FuriString* current_value_text;
    uint8_t values_count;
    VariableItemChangeCallback change_callback;
    void* context;
};

ARRAY_DEF(VariableItemArray, VariableItem, M_POD_OPLIST);

struct VariableItemList {
    View* view;
    VariableItemListEnterCallback callback;
    void* context;
};

typedef struct {
    VariableItemArray_t items;
    uint8_t position;
    uint8_t window_position;

    FuriString* header;
} VariableItemListModel;

void variable_item_list_set_header(VariableItemList* variable_item_list, const char* header) {
    furi_assert(variable_item_list);

    with_view_model(
        variable_item_list->view,
        VariableItemListModel * model,
        {
            if(header == NULL) {
                furi_string_reset(model->header);
            } else {
                furi_string_set_str(model->header, header);
            }
        },
        true);
}

VariableItem* variable_item_list_get(VariableItemList* variable_item_list, uint8_t position) {
    VariableItem* item = NULL;
    furi_assert(variable_item_list);

    with_view_model(
        variable_item_list->view,
        VariableItemListModel * model,
        {
            if(position < VariableItemArray_size(model->items)) {
                item = VariableItemArray_get(model->items, position);
            }
        },
        true);

    return item;
}