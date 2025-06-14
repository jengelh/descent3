/*
* Descent 3
* Copyright (C) 2024 Parallax Software
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.

--- HISTORICAL COMMENTS FOLLOW ---

 * $Logfile: /DescentIII/Main/config.cpp $
 * $Revision: 178 $
 * $Date: 9/14/01 4:47p $
 * $Author: Matt $
 *
 * source to configuration functions (video,sound,etc)
 *
 * $Log: /DescentIII/Main/config.cpp $
 *
 * 178   9/14/01 4:47p Matt
 * Cleaned up problems when screen bit depth set to 32.
 *
 * 177   9/14/01 12:47p Matt
 * Took out center window missile view option since it didn't really work
 * (& wasn't supposed to be in the game).
 *
 * 176   9/14/01 11:06a Matt
 * Removed the mission goals item from the HUD config, since there's no
 * mission goal HUD item to be controlled.
 *
 * 175   4/25/00 3:15p Matt
 * Fixed math error (incorrect literal constant) in terrain detail
 * computation.
 *
 * 174   4/19/00 5:10p Matt
 * From Duane for 1.4
 * Added checks, asserts, and fixes for bad return values
 * Mac pragmas
 *
 * 173   3/20/00 12:02p Matt
 * Merge of Duane's post-1.3 changes.
 * Made some text localizable and changed default level settings (Mac
 * only)
 *
 * 172   10/29/99 5:25p Jeff
 * fixed for Linux (no gamma or 32/16 bit options)
 *
 * 171   10/25/99 11:56a Jeff
 * ifdef'd some Macintosh pragmas
 *
 * 170   10/22/99 10:42a Matt
 * Mac merge
 *
 * 169   5/22/99 1:16a Jason
 * change terrain detail level settings
 *
 * 168   5/11/99 4:37p Jason
 * made opengl work with 32 bit
 *
 * 167   5/11/99 1:44p Jason
 * fixed config screen bug
 *
 * 166   5/06/99 1:40a Samir
 * adjusted some text.
 *
 * 165   5/01/99 9:41a Kevin
 * FIxed compiler error
 *
 * 164   5/01/99 1:57a Samir
 * small change to where STAT_SCORE gets set.
 *
 * 163   5/01/99 1:56a Samir
 * STAT_SCORE for hud is always set now.
 *
 * 162   4/30/99 12:12p Samir
 * added strings for key ramping, other buttons in general config menu.
 *
 * 161   4/24/99 8:39p Samir
 * added ship sounds toggle.
 *
 * 160   4/21/99 3:46p Jason
 * made opengl only work with 16bit
 *
 * 159   4/20/99 11:44a Samir
 * brightness menu has default focus on the slider.
 *
 * 158   4/17/99 8:25p Samir
 * took out graphical option for inventory display.  no time.
 *
 * 157   4/14/99 2:50a Jeff
 * fixed some case mismatched #includes
 *
 * 156   4/13/99 11:15a Samir
 *
 * 155   4/13/99 10:28a Samir
 * don't call SetLLSoundPlayed if value doesn't change.
 *
 * 154   4/12/99 7:15p Samir
 * added ability to configure number of sounds played at one time.
 *
 * 153   3/29/99 7:29p Jason
 * made renderer handle default resolution more gracefully
 *
 * 152   3/23/99 9:03p Samir
 * fixed a bunch of sound mixer problems when configing mixer to none.
 *
 * 151   3/22/99 4:26p Samir
 * added toggles for guided missile view and reticle.
 *
 * 150   3/17/99 4:19p Samir
 * change music volume on the fly.
 *
 * 149   3/08/99 9:05p Samir
 * dont allow user to swtich sound quality while in game.
 *
 * 148   3/05/99 2:40p Samir
 * fixed potential bug
 *
 * 147   3/05/99 12:25p Jason
 * changed maximum terrain detail
 *
 * 146   3/04/99 6:08p Samir
 * added wait message for config screen.
 *
 * 145   3/03/99 5:07p Samir
 * music volume will shutoff music if 0, restart if greater only after a
 * change in vollume.
 *
 * 144   3/02/99 1:14p Samir
 * added joystick/mouse enable and gamma help.
 *
 * 143   3/02/99 12:27p Jason
 * changed terrain distance settings for the different details
 *
 * 142   3/01/99 8:11p Samir
 * adjust current stream volume with sound slider.
 *
 * 141   3/01/99 5:52p Samir
 * fixed slider bars and added render distance.
 *
 * 140   3/01/99 5:01a Samir
 * made sure NEWUIRES_FORCEQUIT was added to all new interfaces.
 *
 * 139   2/28/99 3:22a Samir
 * reformatted video menu.
 *
 * 138   2/26/99 2:09a Samir
 * gamma menu revised.
 *
 * 137   2/25/99 11:18a Jason
 * fixed gamma zbuffer problem
 *
 * 136   2/24/99 6:23p Samir
 * forgot to save default detail level var.
 *
 * 135   2/22/99 9:08p Samir
 * added AddSimpleOption to replace NULL sheet options.
 *
 * 134   2/22/99 7:12p Doug
 * temporarily removed txt_hudwarnings and replaced with a literal string
 * until Samir can make the fix needed (Jeff)
 *
 * 133   2/22/99 5:52p Samir
 * fixed another weird thing.
 *
 * 132   2/22/99 4:24p Samir
 * took out remaining powerupvoices code.
 *
 * 131   2/20/99 7:08p Matt
 * Removed a few items, and change the resolution strings to not be
 * localizable
 *
 * 130   2/19/99 10:31p Samir
 * added music volume.
 *
 * 129   2/19/99 6:56p Samir
 * fixed bug in video menu in options screen (resolution switch
 * sequencing.)
 *
 * 128   2/17/99 3:56p Jason
 * FROM SAMIR: Upped video optios gadget count
 *
 * 127   2/16/99 12:05p Samir
 * revamped ui for config menus.
 *
 * 126   2/15/99 7:47p Jeff
 * new pilot file class and read/write system checked in...should be more
 * robust than old
 *
 * 125   2/15/99 12:03p Jason
 * changed word "Gamma" to "Brightness"
 *
 * 124   2/07/99 1:17a Jeff
 * peppered UI dialogs that were missing NEWUIRES_FORCEQUIT to handle it
 *
 * 123   1/31/99 7:25p Matt
 * Renamed a bunch of functions to have HUD capitalized
 *
 * 122   1/28/99 3:58p Jeff
 * localization update
 *
 * 121   1/27/99 2:58p Jason
 * fixed center small view
 *
 * 120   1/24/99 3:13a Jason
 * changed max terrain detail
 *
 * 119   1/21/99 10:46a Jason
 * changed "weapon corona" text to "weapon effects"
 *
 * 118   1/12/99 5:29p Jason
 * another pass at getting this gamma stuff done
 *
 * 117   1/12/99 12:55p Jason
 * added gamma contrast boxes
 *
 * 116   1/11/99 5:52p Samir
 * added Creative EAX option.
 *
 * 115   1/11/99 11:18a Jason
 * first pass at autogamma
 *
 * 114   12/23/98 11:48a Samir
 * changed name of aureal mixer.
 *
 * 113   12/10/98 3:41p Jeff
 * implemented settings for 16 or 32 bit depth (in config)
 *
 * 112   12/09/98 6:54p Jason
 * changed default config settings
 *
 * 111   12/09/98 6:46p Jeff
 * added scorch marks and weapon coronas to detail menu
 *
 * 110   12/03/98 11:06a Samir
 * added axis sensitivity
 *
 * 109   12/02/98 11:36a Samir
 * readded joystick sensitivity.
 *
 * 108   11/30/98 6:00p Jeff
 * max terrain detail setting is now 26 (to the user...6 internally)
 *
 * 107   11/30/98 3:25p Jeff
 * fixed bug where game will crash if they enter graphics config with a
 * hacked resolution
 *
 * 106   11/30/98 3:12p Jeff
 * gamma goes 1->3 now
 *
 * 105   11/23/98 12:32p Jeff
 * no decimal on the gain slider of forcefeedback
 *
 * 104   11/10/98 5:14p Jeff
 * added Force Feedback configuration
 *
 * 103   10/22/98 4:37p Jeff
 * removed missile view for demo
 *
 * 102   10/22/98 2:40p Samir
 * took out joystick sensitivity for demo.
 *
 * 101   10/21/98 11:55p Samir
 * added sensitivity slider functionality.
 *
 * 100   10/21/98 4:48p Jeff
 * changed slider menu click sound
 *
 *
 * $NoKeywords: $
 */

#include <cstring>

#include "config.h"
#include "newui.h"
#include "3d.h"
#include "descent.h"
#include "log.h"
#include "cinematics.h"
#include "hlsoundlib.h"
#include "terrain.h"
#include "physics.h"
#include "pilot.h"
#include "pserror.h"
#include "hud.h"
#include "bitmap.h"
#include "game.h"
#include "stringtable.h"
#include "SmallViews.h"
#include "D3ForceFeedback.h"
#include "appdatabase.h"
#include "soundload.h"
#include "sounds.h"
#include "ctlconfig.h"
#include "d3music.h"
#include "gameloop.h"
#include "args.h"

#include <SDL3/SDL.h>

#include <algorithm>
#include <vector>
#include <set>

#define STAT_SCORE STAT_TIMER

// This list is only used if `ConfigureDisplayResolutions` fails
std::vector<tVideoResolution> Video_res_list = {{512, 384},
                                                {640, 480},
                                                {800, 600},
                                                {960, 720},
                                                {1024, 768},
                                                {1280, 960},
                                                {1600, 1200},
                                                // 16:9
                                                {1280, 720},
                                                {1366, 768},
                                                {1368, 768},
                                                {1680, 1050},
                                                {1920, 1080},
                                                {2560, 1440},
                                                {3840, 2160},
                                                // 16:10
                                                {1280, 800},
                                                {1920, 1200},
                                                {2560, 1600},
                                                // Ultrawide
                                                {2560, 1080},
                                                {2880, 1200},
                                                {3440, 1440},
                                                {3840, 1600}};

int Default_resolution_id = 7; // 1280x720 in the default list
int Current_video_resolution_id = Default_resolution_id;
float Render_FOV_setting = 72.0f;
bool Game_fullscreen = true;
int Display_id = 0;

void ConfigureDisplayResolutions() {
  int display_count = 0;
  SDL_DisplayID *displays = SDL_GetDisplays(&display_count);
  if (!displays) {
    return;
  }

  std::set<tVideoResolution> resolutions;
  for (int d = 0; d < display_count; d++) {
    SDL_DisplayID display_id = displays[d];

    int modes_count = 0;
    SDL_DisplayMode **modes = SDL_GetFullscreenDisplayModes(display_id, &modes_count);
    if (!modes) {
      return;
    }
    for (int modes_id = 0; modes_id < modes_count; modes_id++) {
      SDL_DisplayMode *mode = modes[modes_id];
      resolutions.emplace(tVideoResolution{static_cast<uint16_t>(mode->w), static_cast<uint16_t>(mode->h)});
    }

    SDL_free(modes);
  }

  // Take width and height argument into account
  int widtharg = FindArg("-Width");
  int heightarg = FindArg("-Height");

  if (widtharg && !heightarg) {
    LOG_ERROR << "Specify '-Height' argument when setting '-Width'";
  }
  if (heightarg && !widtharg) {
    LOG_ERROR << "Specify '-Width' argument when setting '-Height'";
  }

  // Use the first display by default, or the one specified by "-display"
  int display_arg = FindArg("-display");
  int display_num = 0;
  if (display_arg != 0) {
    if (const char *arg_index_str = GetArg(display_arg + 1); arg_index_str == nullptr) {
      LOG_WARNING << "No parameter for -display given";
    } else {
      int arg_index = atoi(arg_index_str);
      if ((arg_index < 0) || (arg_index >= display_count)) {
        LOG_WARNING.printf("Parameter for -display must be in the range 0..%i", display_count - 1);
      } else {
        display_num = arg_index;
      }
    }
  }

  Display_id = displays[display_num];

  // Use either the CLI-provided resolution or the current display resolution as default
  tVideoResolution current_resolution;
  if (widtharg && heightarg) {
    current_resolution.width = static_cast<unsigned short>(atoi(GameArgs[widtharg + 1]));
    current_resolution.height = static_cast<unsigned short>(atoi(GameArgs[heightarg + 1]));
    resolutions.emplace(current_resolution);
  } else {
    const SDL_DisplayMode *current_mode = SDL_GetCurrentDisplayMode(Display_id);
    current_resolution.width = static_cast<unsigned short>(current_mode->w);
    current_resolution.height = static_cast<unsigned short>(current_mode->h);
  }

  // Fill in Video_res_list from the set of unique resolutions
  std::vector<tVideoResolution> resolutions_vec;
  std::copy(resolutions.begin(), resolutions.end(), std::back_inserter(resolutions_vec));
  if (resolutions_vec.empty()) {
    return;
  }
  Video_res_list = std::move(resolutions_vec);
  SDL_free(displays);

  // Find the index of the current screen resolution in the list
  auto current_res_id = std::find(Video_res_list.begin(), Video_res_list.end(), current_resolution);
  if (current_res_id != Video_res_list.end()) {
    Default_resolution_id = static_cast<int>(current_res_id - Video_res_list.begin());
  } else {
    Default_resolution_id = Video_res_list.size() - 1; // default to the highest supported resolution
  }

  int tmp;
  if (!Database->read_int("RS_resolution", &tmp)) {
    // Only override resolution id if the value was not found in the settings
    Current_video_resolution_id = Default_resolution_id;
  }

  LOG_DEBUG << "Resolution configured to w=" << Video_res_list[Current_video_resolution_id].width
            << "h=" << Video_res_list[Current_video_resolution_id].height << " (id " << Current_video_resolution_id
            << ")";
}

tDetailSettings Detail_settings;
int Default_detail_level = DETAIL_LEVEL_MED;

tGameToggles Game_toggles = { // toggles specified in general settings.
    true, false, true};

#define IDV_VCONFIG 12 // video config
#define IDV_GCONFIG 13 // general config
#define IDV_SCONFIG 14 // audio config
#define IDV_DCONFIG 15 // detail level config
#define IDV_HCONFIG 16 // hud config
#define IDV_CCONFIG 17 // controller config
#define IDV_QUIT 0xff

#define UID_GAMMASLIDER 0x1000

/////////////////////////////////////////////////////////////////////////////
// Defines
#define IDV_OK 1
#define IDV_CANCEL 2

// video defines
#define VID_D3D 0
#define VID_GLIDE 1 // Unused
#define VID_OPENGL 2

// small view settings
#define SMVS_NONE 0
#define SMVS_MISSLE 1

// these are the default settings for each detail level
#define DL_LOW_TERRAIN_DISTANCE (MINIMUM_RENDER_DIST * TERRAIN_SIZE)
#define DL_LOW_PIXEL_ERROR 25.0
#define DL_LOW_SPECULAR_LIGHT false
#define DL_LOW_DYNAMIC_LIGHTING false
#define DL_LOW_FAST_HEADLIGHT true
#define DL_LOW_MIRRORED_SURFACES false
#define DL_LOW_FOG_ENABLED false
#define DL_LOW_CORONAS_ENABLES false
#define DL_LOW_PROCEDURALS false
#define DL_LOW_POWERUP_HALOS false
#define DL_LOW_SCORCH_MARKS false
#define DL_LOW_WEAPON_CORONAS false
#define DL_LOW_SPEC_MAPPING_TYPE 1
#define DL_LOW_OBJECT_COMPLEXITY 0

#define DL_MED_TERRAIN_DISTANCE (90 * TERRAIN_SIZE)
#define DL_MED_PIXEL_ERROR 18.0
#define DL_MED_SPECULAR_LIGHT false
#define DL_MED_DYNAMIC_LIGHTING false
#define DL_MED_FAST_HEADLIGHT true
#define DL_MED_MIRRORED_SURFACES false
#define DL_MED_FOG_ENABLED true
#define DL_MED_CORONAS_ENABLES true
#define DL_MED_PROCEDURALS false
#define DL_MED_POWERUP_HALOS true
#define DL_MED_SCORCH_MARKS true
#define DL_MED_WEAPON_CORONAS false
#define DL_MED_SPEC_MAPPING_TYPE 1
#define DL_MED_OBJECT_COMPLEXITY 1

#define DL_HIGH_TERRAIN_DISTANCE (100 * TERRAIN_SIZE)
#define DL_HIGH_PIXEL_ERROR 12.0
#define DL_HIGH_SPECULAR_LIGHT false
#define DL_HIGH_DYNAMIC_LIGHTING true
#define DL_HIGH_FAST_HEADLIGHT true
#define DL_HIGH_MIRRORED_SURFACES true
#define DL_HIGH_FOG_ENABLED true
#define DL_HIGH_CORONAS_ENABLES true
#define DL_HIGH_PROCEDURALS true
#define DL_HIGH_POWERUP_HALOS true
#define DL_HIGH_SCORCH_MARKS true
#define DL_HIGH_WEAPON_CORONAS true
#define DL_HIGH_SPEC_MAPPING_TYPE 1
#define DL_HIGH_OBJECT_COMPLEXITY 2

#define DL_VHI_TERRAIN_DISTANCE (120.0 * TERRAIN_SIZE)
#define DL_VHI_PIXEL_ERROR 10.0
#define DL_VHI_SPECULAR_LIGHT true
#define DL_VHI_DYNAMIC_LIGHTING true
#define DL_VHI_FAST_HEADLIGHT true
#define DL_VHI_MIRRORED_SURFACES true
#define DL_VHI_FOG_ENABLED true
#define DL_VHI_CORONAS_ENABLES true
#define DL_VHI_PROCEDURALS true
#define DL_VHI_POWERUP_HALOS true
#define DL_VHI_SCORCH_MARKS true
#define DL_VHI_WEAPON_CORONAS true
#define DL_VHI_SPEC_MAPPING_TYPE 1
#define DL_VHI_OBJECT_COMPLEXITY 2

#define MINIMUM_TERRAIN_DETAIL 4
#define MAXIMUM_TERRAIN_DETAIL 28
#define MINIMUM_RENDER_DIST 80
#define MAXIMUM_RENDER_DIST 200

static const tDetailSettings DetailPresetLow = {
    DL_LOW_TERRAIN_DISTANCE,  DL_LOW_PIXEL_ERROR,       DL_LOW_SPECULAR_LIGHT, DL_LOW_DYNAMIC_LIGHTING,
    DL_LOW_FAST_HEADLIGHT,    DL_LOW_MIRRORED_SURFACES, DL_LOW_FOG_ENABLED,    DL_LOW_CORONAS_ENABLES,
    DL_LOW_PROCEDURALS,       DL_LOW_POWERUP_HALOS,     DL_LOW_SCORCH_MARKS,   DL_LOW_WEAPON_CORONAS,
    DL_LOW_SPEC_MAPPING_TYPE, DL_LOW_OBJECT_COMPLEXITY};
static const tDetailSettings DetailPresetMed = {
    DL_MED_TERRAIN_DISTANCE,  DL_MED_PIXEL_ERROR,       DL_MED_SPECULAR_LIGHT, DL_MED_DYNAMIC_LIGHTING,
    DL_MED_FAST_HEADLIGHT,    DL_MED_MIRRORED_SURFACES, DL_MED_FOG_ENABLED,    DL_MED_CORONAS_ENABLES,
    DL_MED_PROCEDURALS,       DL_MED_POWERUP_HALOS,     DL_MED_SCORCH_MARKS,   DL_MED_WEAPON_CORONAS,
    DL_MED_SPEC_MAPPING_TYPE, DL_MED_OBJECT_COMPLEXITY};
static const tDetailSettings DetailPresetHigh = {
    DL_HIGH_TERRAIN_DISTANCE,  DL_HIGH_PIXEL_ERROR,       DL_HIGH_SPECULAR_LIGHT, DL_HIGH_DYNAMIC_LIGHTING,
    DL_HIGH_FAST_HEADLIGHT,    DL_HIGH_MIRRORED_SURFACES, DL_HIGH_FOG_ENABLED,    DL_HIGH_CORONAS_ENABLES,
    DL_HIGH_PROCEDURALS,       DL_HIGH_POWERUP_HALOS,     DL_HIGH_SCORCH_MARKS,   DL_HIGH_WEAPON_CORONAS,
    DL_HIGH_SPEC_MAPPING_TYPE, DL_HIGH_OBJECT_COMPLEXITY};
static const tDetailSettings DetailPresetVHi = {
    DL_VHI_TERRAIN_DISTANCE,  DL_VHI_PIXEL_ERROR,       DL_VHI_SPECULAR_LIGHT, DL_VHI_DYNAMIC_LIGHTING,
    DL_VHI_FAST_HEADLIGHT,    DL_VHI_MIRRORED_SURFACES, DL_VHI_FOG_ENABLED,    DL_VHI_CORONAS_ENABLES,
    DL_VHI_PROCEDURALS,       DL_VHI_POWERUP_HALOS,     DL_VHI_SCORCH_MARKS,   DL_VHI_WEAPON_CORONAS,
    DL_VHI_SPEC_MAPPING_TYPE, DL_VHI_OBJECT_COMPLEXITY};

void ConfigSetDetailLevel(int level) {
  switch (level) {
  case DETAIL_LEVEL_LOW:
    memcpy(&Detail_settings, &DetailPresetLow, sizeof(tDetailSettings));
    break;
  case DETAIL_LEVEL_MED:
    memcpy(&Detail_settings, &DetailPresetMed, sizeof(tDetailSettings));
    break;
  case DETAIL_LEVEL_HIGH:
    memcpy(&Detail_settings, &DetailPresetHigh, sizeof(tDetailSettings));
    break;
  case DETAIL_LEVEL_VERY_HIGH:
    memcpy(&Detail_settings, &DetailPresetVHi, sizeof(tDetailSettings));
    break;
  };

  Default_detail_level = level;
}

//////////////////////////////////////////////////////////////////////////////
// Gamma settings

// gamma configuration, window placement
#define GAMMA_MENU_H 320
#define GAMMA_MENU_W 416

#define GAMMA_SLICES 32
#define GAMMA_SLICE_WIDTH 256
#define GAMMA_SLICE_HEIGHT 128
#define GAMMA_SLICE_X ((GAMMA_MENU_W - GAMMA_SLICE_WIDTH) / 2);
#define GAMMA_SLICE_Y 64
#define GAMMA_SLIDER_UNITS 100

#define IDV_GAMMAAPPLY 5
#define IDV_AUTOGAMMA 6
#define IDV_CHANGE_RES_WINDOW 10
#define UID_RESOLUTION 110

static void gamma_callback(newuiTiledWindow *wnd, void *data) {
  int bm_handle = *((int *)data);

  g3Point pnts[4], *pntlist[4];
  rend_SetColorModel(CM_RGB);
  rend_SetAlphaType(AT_ALWAYS);
  rend_SetTextureType(TT_LINEAR);
  rend_SetLighting(LS_NONE);
  rend_SetOverlayType(OT_NONE);
  rend_SetWrapType(WT_WRAP);
  rend_SetZBufferState(0);

  // First draw checkboard
  int startx = GAMMA_SLICE_X;

  for (int i = 0; i < 4; i++) {
    pntlist[i] = &pnts[i];
    pnts[i].p3_z = 0;
    pnts[i].p3_r = 1;
    pnts[i].p3_g = 1;
    pnts[i].p3_b = 1;
    pnts[i].p3_flags = PF_PROJECTED;
  }

  pnts[0].p3_sx = static_cast<float>(startx);
  pnts[0].p3_sy = GAMMA_SLICE_Y;
  pnts[0].p3_u = 0;
  pnts[0].p3_v = 0;

  pnts[1].p3_sx = static_cast<float>(startx + GAMMA_SLICE_WIDTH);
  pnts[1].p3_sy = GAMMA_SLICE_Y;
  pnts[1].p3_u = 2;
  pnts[1].p3_v = 0;

  pnts[2].p3_sx = static_cast<float>(startx + GAMMA_SLICE_WIDTH);
  pnts[2].p3_sy = GAMMA_SLICE_Y + GAMMA_SLICE_HEIGHT;
  pnts[2].p3_u = 2;
  pnts[2].p3_v = 1;

  pnts[3].p3_sx = static_cast<float>(startx);
  pnts[3].p3_sy = GAMMA_SLICE_Y + GAMMA_SLICE_HEIGHT;
  pnts[3].p3_u = 0;
  pnts[3].p3_v = 1;

  rend_DrawPolygon2D(bm_handle, pntlist, 4);

  // Now draw grey in the center
  int int_val = 8;
  rend_SetFlatColor(GR_RGB(int_val, int_val, int_val));
  rend_SetTextureType(TT_FLAT);

  pnts[0].p3_sx += 64;
  pnts[0].p3_sy += 32;

  pnts[1].p3_sx -= 64;
  pnts[1].p3_sy += 32;

  pnts[2].p3_sx -= 64;
  pnts[2].p3_sy -= 32;

  pnts[3].p3_sx += 64;
  pnts[3].p3_sy -= 32;

  rend_DrawPolygon2D(0, pntlist, 4);

  rend_SetWrapType(WT_CLAMP);
  rend_SetZBufferState(1);
}

static void config_gamma() {
  newuiTiledWindow gamma_wnd;
  newuiSheet *sheet;
  tSliderSettings slider_set;
  int16_t *gamma_slider;
  int16_t curpos;
  int res, gamma_bitmap = -1;
  float init_gamma;

  // Make gamma bitmap
  gamma_bitmap = bm_AllocBitmap(128, 128, 0);
  if (gamma_bitmap <= 0) {
    gamma_bitmap = 0;
  } else {
    uint16_t *dest_data = (uint16_t *)bm_data(gamma_bitmap, 0);
    int addval = 0;
    int i, t;

    // This loop makes the checkerboard
    for (i = 0; i < 128; i++) {
      addval = (i & 1) ? 1 : 0;

      for (t = 0; t < 128; t++) {
        if (((t + addval) % 2) == 0) {
          dest_data[i * 128 + t] = OPAQUE_FLAG | (1 << 10) | (1 << 5) | (1);
        } else {
          dest_data[i * 128 + t] = OPAQUE_FLAG;
        }
      }
    }
  }

  // create ui.
  gamma_wnd.Create(TXT_AUTO_GAMMA, 0, 0, GAMMA_MENU_W, GAMMA_MENU_H);
  gamma_wnd.SetData(&gamma_bitmap);
  gamma_wnd.SetOnDrawCB(gamma_callback);

  sheet = gamma_wnd.GetSheet();

  // ok, cancel buttons.
  sheet->NewGroup(NULL, 130, 224, NEWUI_ALIGN_HORIZ);
  sheet->AddButton(TXT_APPLY, IDV_GAMMAAPPLY);
  sheet->AddText(" ");
  sheet->AddButton(TXT_OK, UID_OK);
  sheet->AddButton(TXT_CANCEL, UID_CANCEL);

  sheet->NewGroup(NULL, 0, 145);
  sheet->AddText(TXT_GAMMAADJUSTA);
  sheet->AddText(TXT_GAMMAADJUSTB);

  // add slider!
  sheet->NewGroup(NULL, 0, 175);
  slider_set.min_val.f = 1.0f;
  slider_set.max_val.f = 3.0f;
  slider_set.type = SLIDER_UNITS_FLOAT;

  init_gamma = Render_preferred_state.gamma;
  curpos = CALC_SLIDER_POS_FLOAT(init_gamma, &slider_set, GAMMA_SLIDER_UNITS);
  gamma_slider = sheet->AddSlider(TXT_GAMMA, 100, curpos, &slider_set, UID_GAMMASLIDER);
  sheet->SetInitialFocusedGadget(UID_GAMMASLIDER);

  // do ui.
  gamma_wnd.Open();

  do {
    res = gamma_wnd.DoUI();
    if (res == NEWUIRES_FORCEQUIT) {
      break;
    }
    if (res == IDV_GAMMAAPPLY) {
      // get & set the gamma
      Render_preferred_state.gamma =
          CALC_SLIDER_FLOAT_VALUE(*gamma_slider, slider_set.min_val.f, slider_set.max_val.f, GAMMA_SLIDER_UNITS);
      rend_SetPreferredState(&Render_preferred_state);
    }
  } while (res != UID_OK && res != UID_CANCEL);

  // handle results.
  if (res == UID_OK) {
    Render_preferred_state.gamma =
        CALC_SLIDER_FLOAT_VALUE(*gamma_slider, slider_set.min_val.f, slider_set.max_val.f, GAMMA_SLIDER_UNITS);
  } else {
    Render_preferred_state.gamma = init_gamma;
  }

  rend_SetPreferredState(&Render_preferred_state);

  // cleanup
  gamma_wnd.Close();
  gamma_wnd.Destroy();

  if (gamma_bitmap != 0) {
    bm_FreeBitmap(gamma_bitmap);
  }
}

//////////////////////////////////////////////////////////////////
// VIDEO MENU
//
struct video_menu {
  newuiSheet *sheet;

  // settings
  bool *filtering = nullptr;
  bool *fullscreen = nullptr;
  bool *mipmapping = nullptr;
  bool *vsync = nullptr;
  char *resolution_string = nullptr;
  short *fov = nullptr;
  bool resolution_changed = false;

  int *bitdepth = nullptr; // bitdepths

  // sets the menu up.
  newuiSheet *setup(newuiMenu *menu) {
    sheet = menu->AddOption(IDV_VCONFIG, TXT_OPTVIDEO, NEWUIMENU_MEDIUM);

    // video resolution
    sheet->NewGroup(TXT_RESOLUTION, 0, 0);
    std::string res = Video_res_list[Current_video_resolution_id].getName();
    auto alloc_size = std::max(res.size() + 1, static_cast<size_t>(15));
    resolution_string = sheet->AddChangeableText(alloc_size);
    snprintf(resolution_string, alloc_size, res.c_str());
    sheet->AddLongButton("Change", IDV_CHANGE_RES_WINDOW);

    fullscreen = sheet->AddLongCheckBox("Fullscreen", Game_fullscreen);

    // FOV setting 72deg -> 90deg
    tSliderSettings settings = {};
    settings.min_val.f = D3_DEFAULT_FOV;
    settings.max_val.f = 90.f;
    settings.type = SLIDER_UNITS_FLOAT;
    fov = sheet->AddSlider("FOV", static_cast<int16_t>(settings.max_val.f - settings.min_val.f),
                           static_cast<int16_t>(Render_FOV_setting - D3_DEFAULT_FOV), &settings);

#if !defined(POSIX)
    int iTemp = 0;
    // renderer bit depth
    switch (Render_preferred_bitdepth) {
    case 16:
      iTemp = 0;
      break;
    case 32:
      iTemp = 1;
      break;
    default:
      iTemp = -1;
    }

    if ((PreferredRenderer == RENDERER_DIRECT3D || PreferredRenderer == RENDERER_OPENGL) && iTemp != -1) {
      sheet->NewGroup(TXT_CFG_BITDEPTH, 200, 0);
      bitdepth = sheet->AddFirstRadioButton(TXT_CFG_SIXTEENBIT);
      sheet->AddRadioButton(TXT_CFG_THIRTYTWOBIT);
      *bitdepth = iTemp;
    } else {
      bitdepth = NULL;
    }
#endif
    // video settings
    sheet->NewGroup(TXT_TOGGLES, 0, 80);
    filtering = sheet->AddLongCheckBox(TXT_BILINEAR, (Render_preferred_state.filtering != 0));
    mipmapping = sheet->AddLongCheckBox(TXT_MIPMAPPING, (Render_preferred_state.mipping != 0));

    sheet->NewGroup(TXT_MONITOR, 0, 130);
    vsync = sheet->AddLongCheckBox(TXT_CFG_VSYNCENABLED, (Render_preferred_state.vsync_on != 0));

    sheet->AddText("");
    sheet->AddLongButton(TXT_AUTO_GAMMA, IDV_AUTOGAMMA);

    return sheet;
  };

  // retreive values from property sheet here.
  void finish() {
    if (filtering)
      Render_preferred_state.filtering = (*filtering) ? 1 : 0;
    if (mipmapping)
      Render_preferred_state.mipping = (*mipmapping) ? 1 : 0;
    if (vsync)
      Render_preferred_state.vsync_on = (*vsync) ? 1 : 0;
#if !defined(POSIX)
    if (bitdepth)
      Render_preferred_bitdepth = (*bitdepth) == 1 ? 32 : 16;
#endif

    if (*fullscreen != Game_fullscreen || Render_preferred_state.bit_depth != Render_preferred_bitdepth ||
        resolution_changed) {
      resolution_changed = false;
      Game_fullscreen = *fullscreen;
      SetScreenMode(GetScreenMode(), true);
      Render_preferred_state.bit_depth = Render_preferred_bitdepth;
      rend_SetPreferredState(&Render_preferred_state, true);

      int temp_w = Video_res_list[Current_video_resolution_id].width;
      int temp_h = Video_res_list[Current_video_resolution_id].height;
      Current_pilot.set_hud_data(NULL, NULL, NULL, &temp_w, &temp_h);
    }

    Render_FOV_setting = static_cast<float>(fov[0]) + D3_DEFAULT_FOV;
    if (Render_FOV != Render_FOV_setting) {
      Render_FOV = Render_FOV_setting; // ISB: this may cause discontinuities if FOV is changed while zoomed.
    }

    sheet = NULL;
  };

  // process
  void process(int res) {
    switch (res) {
    case IDV_CHANGE_RES_WINDOW: {
      // Resolution configuration window
      newuiTiledWindow menu;
      newuiSheet *select_sheet;
      newuiListBox *resolution_list;

      menu.Create("Resolution", 0, 0, 300, 400);
      select_sheet = menu.GetSheet();
      select_sheet->NewGroup(NULL, 10, 0);
      resolution_list = select_sheet->AddListBox(208, 257, UID_RESOLUTION, UILB_NOSORT);
      select_sheet->NewGroup(NULL, 100, 300, NEWUI_ALIGN_HORIZ);
      select_sheet->AddButton(TXT_OK, UID_OK);
      select_sheet->AddButton(TXT_CANCEL, UID_CANCEL);

      for (auto &resolution : Video_res_list) {
        resolution_list->AddItem(resolution.getName().c_str());
      }

      menu.Open();

      resolution_list->SetCurrentIndex(Current_video_resolution_id);

      int res;
      do {
        res = menu.DoUI();
      } while (res != UID_OK && res != UID_CANCEL);

      if (res == UID_OK) {
        int newindex = resolution_list->GetCurrentIndex();
        if (static_cast<size_t>(newindex) < Video_res_list.size() && Current_video_resolution_id != newindex) {
          resolution_changed = true;
          Current_video_resolution_id = newindex;
          std::string res = Video_res_list[Current_video_resolution_id].getName();
          snprintf(resolution_string, res.size() + 1, res.c_str());
        }
      }

      menu.Close();
      menu.Destroy();
      break;
    }
    case IDV_AUTOGAMMA:
      config_gamma();
      break;
    }
  };
};

//////////////////////////////////////////////////////////////////
// SOUND MENU
//
struct sound_menu {
  newuiSheet *sheet;
  newuiMenu *parent_menu;
  int ls_sound_id, sound_id;

  int16_t *fxvolume, *musicvolume; // volume sliders
  int16_t *fxquantity;             // sound fx quantity limit
  int *fxquality;                  // sfx quality low/high

  int16_t old_fxquantity;

#ifdef _DEBUG
  int *sndmixer;
#endif

  // sets the menu up.
  newuiSheet *setup(newuiMenu *menu) {
    tSliderSettings slider_set;

    sheet = menu->AddOption(IDV_SCONFIG, TXT_OPTSOUND, NEWUIMENU_MEDIUM);
    parent_menu = menu;
    ls_sound_id = -1;
    sound_id = FindSoundName("Menu Slider Click");
    ASSERT(sound_id != -1); // DAJ -1FIX

    // volume sliders
    sheet->NewGroup(NULL, 0, 0);

    slider_set.type = SLIDER_UNITS_PERCENT;
    fxvolume = sheet->AddSlider(TXT_SOUNDVOL, 10, (int16_t)(Sound_system.GetMasterVolume() * 10), &slider_set);

    slider_set.type = SLIDER_UNITS_PERCENT;
    musicvolume = sheet->AddSlider(TXT_SNDMUSVOL, 10, (int16_t)(D3MusicGetVolume() * 10), &slider_set);

    // sound fx quality radio list.
    if (GetFunctionMode() != GAME_MODE && GetFunctionMode() != EDITOR_GAME_MODE) {
      sheet->NewGroup(TXT_SNDQUALITY, 0, 95);
      fxquality = sheet->AddFirstRadioButton(TXT_SNDNORMAL);
      sheet->AddRadioButton(TXT_SNDHIGH);
      *fxquality = Sound_system.GetSoundQuality() == SQT_HIGH ? 1 : 0;
      slider_set.min_val.i = MIN_SOUNDS_MIXED;
      slider_set.max_val.i = MAX_SOUNDS_MIXED;
      slider_set.type = SLIDER_UNITS_INT;
      fxquantity = sheet->AddSlider(TXT_SNDCFG_SFXQUANTITY, (slider_set.max_val.i - slider_set.min_val.i),
                                    Sound_system.GetLLSoundQuantity() - MIN_SOUNDS_MIXED, &slider_set);
      old_fxquantity = (Sound_system.GetLLSoundQuantity() - MIN_SOUNDS_MIXED);

    } else {
      fxquality = NULL;
      fxquantity = NULL;
    }

#if defined(_DEBUG)
    int iTemp;
    // add sound stats group
    sheet->NewGroup("MIXER SETTINGS", 180, 85);
    switch (Sound_system.GetSoundMixer()) {
    case SOUND_MIXER_NONE:
      iTemp = 0;
      break;
    case SOUND_MIXER_SOFTWARE_16:
      iTemp = 1;
      break;
    case SOUND_MIXER_DS_8:
      iTemp = 2;
      break;
    case SOUND_MIXER_DS_16:
      iTemp = 3;
      break;
    case SOUND_MIXER_DS3D_16:
      iTemp = 4;
      break;
    case SOUND_MIXER_CREATIVE_EAX:
      iTemp = 5;
      break;
    default:
      Int3(); //-wtf?
    }
    sndmixer = sheet->AddFirstRadioButton("NONE");
    sheet->AddRadioButton("SOFTWARE");
    sheet->AddRadioButton("DS 8");
    sheet->AddRadioButton("DS 16");
    sheet->AddRadioButton("DS 3D");
    sheet->AddRadioButton("EAX");
    *sndmixer = iTemp;
#endif

    return sheet;
  };

  // retreive values from property sheet here.
  void finish() {
#if defined(_DEBUG)
    char mixer_type = SOUND_MIXER_NONE;
    int iTemp;

    iTemp = *sndmixer;

    switch (iTemp) {
    case 0:
      mixer_type = SOUND_MIXER_NONE;
      break;
    case 1:
      mixer_type = SOUND_MIXER_SOFTWARE_16;
      break;
    case 2:
      mixer_type = SOUND_MIXER_DS_8;
      break;
    case 3:
      mixer_type = SOUND_MIXER_DS_16;
      break;
    case 4:
      mixer_type = SOUND_MIXER_DS3D_16;
      break;
    case 5:
      mixer_type = SOUND_MIXER_CREATIVE_EAX;
      break;
    default:
      Int3(); // -wtf?
    }

    if (Sound_system.GetSoundMixer() == SOUND_MIXER_NONE) {
      Sound_system.InitSoundLib(Descent, mixer_type, Sound_quality, false);
    } else {
      Sound_system.SetSoundMixer(mixer_type);
    }
#endif

    Sound_system.SetMasterVolume((*fxvolume) / 10.0f);
    D3MusicSetVolume((*musicvolume) / 10.0f);

    if (fxquantity) {
      LOG_DEBUG.printf("oldquant %d newquant %d", old_fxquantity, *fxquantity);
      if (old_fxquantity != (*fxquantity)) {
        Sound_system.SetLLSoundQuantity((*fxquantity) + MIN_SOUNDS_MIXED);
      }
    }

    if (fxquality) {
      Sound_system.SetSoundQuality((*fxquality == 1) ? SQT_HIGH : SQT_NORMAL);
    }

    //@@		iTemp = (*powerupvoices);
    //@@		if (iTemp == 2) {
    //@@			PlayVoices = true;
    //@@			PlayPowerupVoice = true;
    //@@		}
    //@@		else if (iTemp == 1) {
    //@@			PlayPowerupVoice = false;
    //@@			PlayVoices = true;
    //@@		}
    //@@		else {
    //@@			PlayVoices = false;
    //@@			PlayPowerupVoice = false;
    //@@		}
  };

  // process output and do stuff accordintly
  void process(int res) {
    if (sheet->HasChanged(fxvolume)) {
      Sound_system.SetMasterVolume((*fxvolume) / 10.0f);
      Sound_system.BeginSoundFrame(false);
      Sound_system.StopSoundImmediate(ls_sound_id);
      ls_sound_id = Sound_system.Play2dSound(sound_id);
      Sound_system.EndSoundFrame();
    }
    if (sheet->HasChanged(musicvolume)) {
      D3MusicSetVolume((*musicvolume) / 10.0f);
    }
  };
};

//////////////////////////////////////////////////////////////////
// GENERAL SETTINGS (TOGGLES) MENU
//

#define UID_SHORTCUT_JOYSETTINGS 0x1000
#define UID_SHORTCUT_KEYSETTINGS 0x1001
#define UID_SHORTCUT_FORCEFEED 0x1002
#define UID_SHORTCUT_NETSETTINGS 0x1003

struct toggles_menu {
  newuiSheet *sheet;
  newuiMenu *parent_menu;

  int *terrain_autolevel; // auto leveling radios
  int *mine_autolevel;
  int *missile_view; // missile view radio
  bool *joy_enabled, *mse_enabled;
  bool *reticle_toggle, *guided_toggle;
  bool *shipsnd_toggle;

  // sets the menu up.
  newuiSheet *setup(newuiMenu *menu) {
    sheet = menu->AddOption(IDV_GCONFIG, TXT_OPTGENERAL, NEWUIMENU_MEDIUM);
    parent_menu = menu;
    bool ff_found = false;

    sheet->NewGroup(TXT_TERRAUTOLEV, 0, 0);
    terrain_autolevel = sheet->AddFirstRadioButton(TXT_NONE);
    sheet->AddRadioButton(TXT_CFG_MEDIUM);
    sheet->AddRadioButton(TXT_CFG_HIGH);
    *terrain_autolevel = Default_player_terrain_leveling;

    sheet->NewGroup(TXT_MINEAUTOLEV, 0, 70);
    mine_autolevel = sheet->AddFirstRadioButton(TXT_NONE);
    sheet->AddRadioButton(TXT_CFG_MEDIUM);
    sheet->AddRadioButton(TXT_CFG_HIGH);
    *mine_autolevel = Default_player_room_leveling;

    sheet->NewGroup(TXT_MISSILEVIEW, 0, 140);
    missile_view = sheet->AddFirstRadioButton(TXT_NONE);
    sheet->AddRadioButton(TXT_LEFT);
    //@@		sheet->AddRadioButton(TXT_CENTER);
    sheet->AddRadioButton(TXT_RIGHT);
    //@@		*missile_view = (Missile_camera_window==SVW_LEFT) ? 1 : (Missile_camera_window==SVW_CENTER) ? 2
    //: (Missile_camera_window==SVW_RIGHT) ? 3 : 0;
    *missile_view = (Missile_camera_window == SVW_LEFT) ? 1 : (Missile_camera_window == SVW_RIGHT) ? 2 : 0;

    sheet->NewGroup(TXT_CONTROL_TOGGLES, 110, 0);
    joy_enabled = sheet->AddLongCheckBox(TXT_JOYENABLED);
    mse_enabled = sheet->AddLongCheckBox(TXT_CFG_MOUSEENABLED);
    *joy_enabled = CHECK_FLAG(Current_pilot.read_controller, READF_JOY) ? true : false;
    *mse_enabled = CHECK_FLAG(Current_pilot.read_controller, READF_MOUSE) ? true : false;

    sheet->NewGroup(TXT_TOGGLES, 110, 70);
    reticle_toggle = sheet->AddLongCheckBox(TXT_TOG_SHOWRETICLE);
    guided_toggle = sheet->AddLongCheckBox(TXT_TOG_GUIDEDMISSILE);
    shipsnd_toggle = sheet->AddLongCheckBox(TXT_TOG_SHIPSOUNDS);
    *reticle_toggle = Game_toggles.show_reticle;
    *guided_toggle = Game_toggles.guided_mainview;
    *shipsnd_toggle = Game_toggles.ship_noises;

    ddio_ff_GetInfo(&ff_found, NULL);
    sheet->NewGroup(TXT_ADJUSTCONTROLSETTINGS, 110, 140);
    sheet->AddLongButton(TXT_JOYSENSBTN, UID_SHORTCUT_JOYSETTINGS);
    sheet->AddLongButton(TXT_KEYRAMPING, UID_SHORTCUT_KEYSETTINGS);

    if (ff_found) {
      sheet->AddLongButton(TXT_CFG_CONFIGFORCEFEEDBACK, UID_SHORTCUT_FORCEFEED);
    }

    sheet->NewGroup("Misc", 110, ff_found ? 200 : 190);
    sheet->AddLongButton("Network Settings", UID_SHORTCUT_NETSETTINGS);

    return sheet;
  };

  // retreive values from property sheet here.
  void finish() {
    int iTemp;

    Default_player_terrain_leveling = *terrain_autolevel;
    Default_player_room_leveling = *mine_autolevel;

    iTemp = (*missile_view);
    //@@		Missile_camera_window = (iTemp==1) ? SVW_LEFT : (iTemp==2) ? SVW_CENTER : (iTemp==3) ? SVW_RIGHT
    //: -1;
    Missile_camera_window = (iTemp == 1) ? SVW_LEFT : (iTemp == 2) ? SVW_RIGHT : -1;
    Current_pilot.read_controller = (*joy_enabled) ? READF_JOY : 0;
    Current_pilot.read_controller |= (*mse_enabled) ? READF_MOUSE : 0;
    Game_toggles.show_reticle = (*reticle_toggle);
    Game_toggles.guided_mainview = (*guided_toggle);
    Game_toggles.ship_noises = (*shipsnd_toggle);
  };

  // process
  void process(int res) {
    switch (res) {
    case UID_SHORTCUT_JOYSETTINGS:
    case UID_SHORTCUT_FORCEFEED:
      LoadControlConfig();
      joystick_settings_dialog();
      SaveControlConfig();
      break;
    case UID_SHORTCUT_KEYSETTINGS:
      LoadControlConfig();
      key_settings_dialog();
      SaveControlConfig();
      break;
    case UID_SHORTCUT_NETSETTINGS:
      net_settings_dialog();
      break;
    }
  };
};

//////////////////////////////////////////////////////////////////
//  HUD CONFIG MENU
//
struct hud_menu {
  newuiSheet *sheet;
  newuiMenu *parent_menu;

  int *ship_status;
  int *shield_energy;
  int *weapon_loads;
  int *afterburner;
  int *inventory;
  int *warnings;
  int *countermeasures;
  //	int *goals;

  int add_hud_option(const char *title, int **ptr, int y, int sel, bool graphical) {
    const int y_line = 29;

    sheet->NewGroup(title, 0, y, NEWUI_ALIGN_HORIZ);
    *ptr = sheet->AddFirstRadioButton(TXT_OFF);
    if (graphical) {
      sheet->AddRadioButton(TXT_TEXT);
      sheet->AddRadioButton(TXT_GRAPHICAL);
    } else {
      sheet->AddRadioButton(TXT_ON);
    }
    *(*ptr) = sel;
    return y + y_line;
  };

  // sets the menu up.
  newuiSheet *setup(newuiMenu *menu) {
    int y, sel;
    uint16_t stat, grstat;

    sheet = menu->AddOption(IDV_HCONFIG, TXT_OPTHUD, NEWUIMENU_MEDIUM);
    parent_menu = menu;

    Current_pilot.get_hud_data(NULL, &stat, &grstat);

    sel = (stat & STAT_SHIP) ? 1 : (grstat & STAT_SHIP) ? 2 : 0;
    y = add_hud_option(TXT_HUDSHIPSTATUS, &ship_status, 0, sel, true);

    sel = (stat & (STAT_SHIELDS + STAT_ENERGY)) ? 1 : (grstat & (STAT_SHIELDS + STAT_ENERGY)) ? 2 : 0;
    y = add_hud_option(TXT_HUDSHIELDENERGY, &shield_energy, y, sel, true);

    sel = (stat & (STAT_PRIMARYLOAD + STAT_SECONDARYLOAD))     ? 1
          : (grstat & (STAT_PRIMARYLOAD + STAT_SECONDARYLOAD)) ? 2
                                                               : 0;
    y = add_hud_option(TXT_HUDWEAPONS, &weapon_loads, y, sel, true);

    sel = (stat & STAT_AFTERBURN) ? 1 : (grstat & STAT_AFTERBURN) ? 2 : 0;
    y = add_hud_option(TXT_HUDAFTERBURN, &afterburner, y, sel, true);

    sel = (stat & STAT_WARNING) ? 1 : (grstat & STAT_WARNING) ? 2 : 0;
    y = add_hud_option(TXT_HUDWARNINGS, &warnings, y, sel, true);

    sel = (stat & STAT_CNTRMEASURE) ? 1 : (grstat & STAT_CNTRMEASURE) ? 2 : 0;
    y = add_hud_option(TXT_HUDCNTRMEASURE, &countermeasures, y, sel, true);

    //		sel = (stat & STAT_GOALS) ? 1 : 0;
    //		y = add_hud_option(TXT_HUDMISSIONSTATUS, &goals, y, sel, false);

    sel = (stat & STAT_INVENTORY) ? 1 : 0;
    y = add_hud_option(TXT_HUDINVENTORY, &inventory, y, sel, false);

    return sheet;
  };

  // retreive values from property sheet here.
  void finish() {
    int sel;
    uint16_t hud_new_stat = STAT_MESSAGES + STAT_CUSTOM;
    uint16_t hud_new_grstat = 0;

    sel = *ship_status;
    if (sel == 1)
      hud_new_stat |= STAT_SHIP;
    else if (sel == 2)
      hud_new_grstat |= STAT_SHIP;
    sel = *shield_energy;
    if (sel == 1)
      hud_new_stat |= (STAT_SHIELDS + STAT_ENERGY);
    else if (sel == 2)
      hud_new_grstat |= (STAT_SHIELDS + STAT_ENERGY);
    sel = *weapon_loads;
    if (sel == 1)
      hud_new_stat |= (STAT_PRIMARYLOAD + STAT_SECONDARYLOAD);
    else if (sel == 2)
      hud_new_grstat |= (STAT_PRIMARYLOAD + STAT_SECONDARYLOAD);
    sel = *afterburner;
    if (sel == 1)
      hud_new_stat |= STAT_AFTERBURN;
    else if (sel == 2)
      hud_new_grstat |= STAT_AFTERBURN;
    sel = *warnings;
    if (sel == 1)
      hud_new_stat |= STAT_WARNING;
    else if (sel == 2)
      hud_new_grstat |= STAT_WARNING;
    sel = *countermeasures;
    if (sel == 1)
      hud_new_stat |= STAT_CNTRMEASURE;
    else if (sel == 2)
      hud_new_grstat |= STAT_CNTRMEASURE;
    //		sel = *goals;
    //		if (sel==1) hud_new_stat |= STAT_GOALS;
    sel = *inventory;
    if (sel == 1)
      hud_new_stat |= STAT_INVENTORY;

    Current_pilot.set_hud_data(NULL, &hud_new_stat, &hud_new_grstat);

    // modify current hud stats if in game.
    if ((GetFunctionMode() == EDITOR_GAME_MODE || GetFunctionMode() == GAME_MODE) && GetHUDMode() == HUD_FULLSCREEN) {
      SetHUDState(hud_new_stat | STAT_SCORE | (Hud_stat_mask & STAT_FPS), hud_new_grstat);
    }
  };
};

//////////////////////////////////////////////////////////////////
// DETAILS MENU
//
struct details_menu {
  newuiSheet *sheet;
  newuiMenu *parent_menu;

  int *detail_level;                  // detail level radio
  int *objcomp;                       // object complexity radio
  bool *specmap, *headlight, *mirror, // check boxes
      *dynamic, *fog, *coronas, *procedurals, *powerup_halo, *scorches, *weapon_coronas;
  int16_t *pixel_err, // 0-27 (1-28)
      *rend_dist;     // 0-120 (80-200)

  int *texture_quality;

  // sets the menu up.
  newuiSheet *setup(newuiMenu *menu) {
    int iTemp;
    sheet = menu->AddOption(IDV_DCONFIG, TXT_OPTDETAIL, NEWUIMENU_MEDIUM);
    parent_menu = menu;

    // detail level radio
    Database->read_int("PredefDetailSetting", &Default_detail_level);
    iTemp = Default_detail_level;
    sheet->NewGroup(TXT_CFG_PRESETDETAILS, 0, 0);
    detail_level = sheet->AddFirstRadioButton(TXT_LOW);
    sheet->AddRadioButton(TXT_CFG_MEDIUM);
    sheet->AddRadioButton(TXT_CFG_HIGH);
    sheet->AddRadioButton(TXT_CFG_VERYHIGH);
    sheet->AddRadioButton(TXT_CFG_CUSTOM);
    *detail_level = iTemp;

    // toggles
    sheet->NewGroup(TXT_TOGGLES, 0, 87);
    specmap = sheet->AddLongCheckBox(TXT_SPECMAPPING, Detail_settings.Specular_lighting);
    headlight = sheet->AddLongCheckBox(TXT_FASTHEADLIGHT, Detail_settings.Fast_headlight_on);
    mirror = sheet->AddLongCheckBox(TXT_MIRRORSURF, Detail_settings.Mirrored_surfaces);
    dynamic = sheet->AddLongCheckBox(TXT_DYNLIGHTING, Detail_settings.Dynamic_lighting);
    fog = sheet->AddLongCheckBox(TXT_CFG_ENABLEFOG, Detail_settings.Fog_enabled);
    coronas = sheet->AddLongCheckBox(TXT_CFG_ENABLELIGHTCORONA, Detail_settings.Coronas_enabled);
    procedurals = sheet->AddLongCheckBox(TXT_CFG_PROCEDURALS, Detail_settings.Procedurals_enabled);
    powerup_halo = sheet->AddLongCheckBox(TXT_CFG_POWERUPHALOS, Detail_settings.Powerup_halos);
    scorches = sheet->AddLongCheckBox(TXT_CFG_SCORCHMARKS, Detail_settings.Scorches_enabled);
    weapon_coronas = sheet->AddLongCheckBox(TXT_CFG_WEAPONEFFECTS, Detail_settings.Weapon_coronas_enabled);

    // sliders
    tSliderSettings slider_set;
    sheet->NewGroup(TXT_GEOMETRY, 90, 0);
    iTemp = static_cast<int>(MAXIMUM_TERRAIN_DETAIL - Detail_settings.Pixel_error - MINIMUM_TERRAIN_DETAIL);
    if (iTemp < 0)
      iTemp = 0;
    slider_set.min_val.i = MINIMUM_TERRAIN_DETAIL;
    slider_set.max_val.i = MAXIMUM_TERRAIN_DETAIL;
    slider_set.type = SLIDER_UNITS_INT;
    pixel_err = sheet->AddSlider(TXT_TERRDETAIL, MAXIMUM_TERRAIN_DETAIL - MINIMUM_TERRAIN_DETAIL, iTemp, &slider_set);

    slider_set.min_val.i = MINIMUM_RENDER_DIST / 2;
    slider_set.max_val.i = MAXIMUM_RENDER_DIST / 2;
    slider_set.type = SLIDER_UNITS_INT;
    iTemp = (int)(Detail_settings.Terrain_render_distance / ((float)TERRAIN_SIZE)) - MINIMUM_RENDER_DIST;
    if (iTemp < 0)
      iTemp = 0;
    rend_dist = sheet->AddSlider(TXT_RENDDIST, (MAXIMUM_RENDER_DIST - MINIMUM_RENDER_DIST) / 2, iTemp / 2, &slider_set);

    // object complexity radio
    sheet->NewGroup(TXT_CFG_OBJECTCOMPLEXITY, 174, 87);
    objcomp = sheet->AddFirstRadioButton(TXT_LOW);
    sheet->AddRadioButton(TXT_CFG_MEDIUM);
    sheet->AddRadioButton(TXT_CFG_HIGH);
    *objcomp = Detail_settings.Object_complexity;

    return sheet;
  };

  // retreive values from property sheet here.
  void finish() {
    Detail_settings.Coronas_enabled = *coronas;
    Detail_settings.Dynamic_lighting = *dynamic;
    Detail_settings.Fast_headlight_on = *headlight;
    Detail_settings.Fog_enabled = *fog;
    Detail_settings.Mirrored_surfaces = *mirror;
    Detail_settings.Object_complexity = *objcomp;
    Detail_settings.Pixel_error = static_cast<float>(MAXIMUM_TERRAIN_DETAIL - ((*pixel_err) + MINIMUM_TERRAIN_DETAIL));
    Detail_settings.Powerup_halos = *powerup_halo;
    Detail_settings.Procedurals_enabled = *procedurals;
    Detail_settings.Scorches_enabled = *scorches;
    Detail_settings.Specular_lighting = *specmap;
    Detail_settings.Terrain_render_distance = (((*rend_dist) * 2) + MINIMUM_RENDER_DIST) * ((float)TERRAIN_SIZE);
    Detail_settings.Weapon_coronas_enabled = *weapon_coronas;

    Default_detail_level = *detail_level;
    Database->write("PredefDetailSetting", Default_detail_level);

    sheet = NULL;
  };

  // process output and do stuff accordintly
  void process(int res) {
    bool changed;

    // check here if the detail level currently set should be custom
    changed = sheet->HasChanged(specmap) || sheet->HasChanged(headlight) || sheet->HasChanged(mirror) ||
              sheet->HasChanged(dynamic) || sheet->HasChanged(fog) || sheet->HasChanged(coronas) ||
              sheet->HasChanged(procedurals) || sheet->HasChanged(powerup_halo) || sheet->HasChanged(scorches) ||
              sheet->HasChanged(weapon_coronas) || sheet->HasChanged(objcomp) || sheet->HasChanged(pixel_err) ||
              sheet->HasChanged(rend_dist);

    if (changed) {
      // enable custom radio button
      *detail_level = DETAIL_LEVEL_CUSTOM;
    } else {
      // check if any preset detail has been selected.
      if (sheet->HasChanged(detail_level)) {
        set_preset_details(*detail_level);
      }
    }
  };

  //	sets detail presets
  void set_preset_details(int setting);
};

//	sets detail presets
void details_menu::set_preset_details(int setting) {
  tDetailSettings ds;

  switch (setting) {
  case DETAIL_LEVEL_LOW:
    memcpy(&ds, &DetailPresetLow, sizeof(tDetailSettings));
    break;
  case DETAIL_LEVEL_MED:
    memcpy(&ds, &DetailPresetMed, sizeof(tDetailSettings));
    break;
  case DETAIL_LEVEL_HIGH:
    memcpy(&ds, &DetailPresetHigh, sizeof(tDetailSettings));
    break;
  case DETAIL_LEVEL_VERY_HIGH:
    memcpy(&ds, &DetailPresetVHi, sizeof(tDetailSettings));
    break;
  default:
    return;
  };

  // now go through all the config items and set to the new values
  int iTemp;

  iTemp = static_cast<int>(MAXIMUM_TERRAIN_DETAIL - ds.Pixel_error - MINIMUM_TERRAIN_DETAIL);
  if (iTemp < 0)
    iTemp = 0;
  *pixel_err = (int16_t)(iTemp);
  iTemp = (int)((ds.Terrain_render_distance / ((float)TERRAIN_SIZE)) - MINIMUM_RENDER_DIST);
  if (iTemp < 0)
    iTemp = 0;
  iTemp = iTemp / 2;
  *rend_dist = (int16_t)(iTemp);
  *objcomp = ds.Object_complexity;
  *specmap = ds.Specular_lighting;
  *headlight = ds.Fast_headlight_on;
  *mirror = ds.Mirrored_surfaces;
  *dynamic = ds.Dynamic_lighting;
  *fog = ds.Fog_enabled;
  *coronas = ds.Coronas_enabled;
  *procedurals = ds.Procedurals_enabled;
  *powerup_halo = ds.Powerup_halos;
  *scorches = ds.Scorches_enabled;
  *weapon_coronas = ds.Weapon_coronas_enabled;
}

//////////////////////////////////////////////////////////////////
//	new Gamma menu
//

//////////////////////////////////////////////////////////////////
//	new Options menu
//

#include "init.h"

void OptionsMenu() {
  newuiMenu menu;
  video_menu video;
  details_menu details;
  sound_menu sound;
  toggles_menu toggles;
  hud_menu hud;

  int res = -1, state = 0; // state = 0, options menu, 1 = controller config, 2 = quitting.

  while (state != 2) {
    if (state == 1) {
      // enter controller config menu
      LOG_DEBUG << "CONTROLLER CONFIG MENU HERE!";
      CtlConfig(CTLCONFIG_KEYBOARD);
      state = 0; // goto options menu.
    } else {
      // open menu

      DoWaitMessage(true);

      menu.Create();
      menu.Open();

      video.setup(&menu);   // setup video menu IDV_VCONFIG
      details.setup(&menu); // setup details menu.  IDV_DCONFIG
      sound.setup(&menu);   // setup sound menu. IDV_SCONFIG
      toggles.setup(&menu); // setup general menu. IDV_GCONFIG
      hud.setup(&menu);     // setup hud menu. IDV_HCONFIG

      menu.AddSimpleOption(IDV_CCONFIG, TXT_OPTCONFIG);
      menu.AddSimpleOption(UID_CANCEL, TXT_DONE);

      menu.SetCurrentOption(IDV_VCONFIG);

      DoWaitMessage(false);

      // run menu
      do {
        res = menu.DoUI();

        // immediate checking of any option ids.
        if (res == UID_CANCEL || res == NEWUIRES_FORCEQUIT) {
          state = 2;
          break; // next pass will quit
        } else if (res == IDV_CCONFIG) {
          state = 1;
          break; // next pass will enter controller menu
        }

        // handle any processing needed by current option.
        switch (menu.GetCurrentOption()) {
        case IDV_DCONFIG:
          details.process(res);
          break;
        case IDV_SCONFIG:
          sound.process(res);
          break;
        case IDV_VCONFIG:
          video.process(res);
          break;
        case IDV_GCONFIG:
          toggles.process(res);
          break;
        }
      } while (1);

      // get settings
      hud.finish();
      toggles.finish();
      sound.finish();
      details.finish();
      video.finish();

      // write them out and close.
      PltWriteFile(&Current_pilot);

      menu.Close();
      menu.Destroy();
    }
  }

  SaveGameSettings();
}
