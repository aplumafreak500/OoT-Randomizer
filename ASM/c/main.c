#include "triforce.h"
#include "dungeon_info.h"
#include "file_select.h"
#include "get_items.h"
#include "models.h"
#include "gfx.h"
#include "text.h"
#include "util.h"
#include "dpad.h"
#include "misc_colors.h"
#include "hud_colors.h"
#include "z64.h"
#include "chests.h"
#include "ganon.h"
#include "twinrova.h"
#include "extern_ctxt.h"
#include "fog.h"

void c_init() {
    heap_init();
    gfx_init();
    text_init();
    item_overrides_init();
    models_init();
}

void before_game_state_update() {
    handle_pending_items();
    handle_dpad();
    update_misc_colors();
    update_hud_colors();
    process_extern_ctxt();
    override_fog_state();
}

void after_game_state_update() {
    draw_dungeon_info(&(z64_ctxt.gfx->overlay));
    draw_triforce_count(&(z64_ctxt.gfx->overlay));
}

extern uint8_t START_TWINROVA_FIGHT;

void after_scene_init() {
    START_TWINROVA_FIGHT = 0;
    check_ganon_entry();
    clear_twinrova_vars();
    models_reset();
    extern_scene_init();
}
