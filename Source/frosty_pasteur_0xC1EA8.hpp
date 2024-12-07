#pragma once

#include "Function.hpp"
#include "miss2_0x11C.hpp"
#include <windows.h>

#pragma pack(push)
#pragma pack(1)
struct str_table_entry
{
    s16 field_0_str_id;
    s16 field_2_zone_idx;
    s16 field_4_type;
    s16 field_6;
    u8 field_8_length;
};
#pragma pack(pop)

struct str_table_normalized
{
    s16 field_0_string_count;
    s16 field_2; // pad ?
    str_table_entry* field_4[999];
};

enum SCRCMD
{
    SCRCMD_0 = 0, // 0000 - this seems to be FORWARD command, the end of IF and some other random crap.
    SCRCMD_1 = 1, // 0100
    SCRCMD_2 = 2, // 0200
    SCRCMD_3 = 3, // 0300
    SCRCMD_4 = 4, // 0400
    SCRCMD_PLAYER_PED = 5, // 0500
    SCRCMD_CHAR_DEC = 6, // 0600
    SCRCMD_CHAR_DECSET_2D = 7, // 0700
    SCRCMD_CHAR_DECSET_3D = 8, // 0800
    SCRCMD_CAR_DEC = 9, // 0900
    SCRCMD_CAR_DECSET_2D = 10, // 0A00
    SCRCMD_CAR_DECSET_3D = 11, // 0B00
    SCRCMD_CAR_DECSET_2D_STR = 12, // 0C00
    SCRCMD_CAR_DECSET_3D_STR = 13, // 0D00
    SCRCMD_OBJ_DEC = 14, // 0E00
    SCRCMD_OBJ_DECSET_2D = 15, // 0F00
    SCRCMD_OBJ_DECSET_3D = 16, // 1000
    SCRCMD_OBJ_DECSET_2D_s32 = 17, // 1100
    SCRCMD_OBJ_DECSET_3D_s32 = 18, // 1200
    SCRCMD_OBJ_DECSET_2D_STR = 19, // 1300
    SCRCMD_OBJ_DECSET_3D_STR = 20, // 1400
    SCRCMD_COUNTER = 21, // 1500
    SCRCMD_COUNTER_SET = 22, // 1600
    SCRCMD_ARROW_DEC = 23, // 1700
    SCRCMD_THREAD_ID = 24, // 1800
    SCRCMD_CONVEYOR_DEC = 25, // 1900
    SCRCMD_CONVEYOR_DECSET1 = 26, // 1A00
    SCRCMD_CONVEYOR_DECSET2 = 27, // 1B00
    SCRCMD_GENERATOR_DEC = 28, // 1C00
    SCRCMD_GENERATOR_DECSET1 = 29, // 1D00
    SCRCMD_GENERATOR_DECSET2 = 30, // 1E00
    SCRCMD_GENERATOR_DECSET3 = 31, // 1F00
    SCRCMD_GENERATOR_DECSET4 = 32, // 2000
    SCRCMD_DESTRUCTOR_DEC = 33, // 2100
    SCRCMD_DESTRUCTOR_DECSET1 = 34, // 2200
    SCRCMD_DESTRUCTOR_DECSET2 = 35, // 2300
    SCRCMD_CRANE_DEC = 36, // 2400
    SCRCMD_CRANE_BASIC_DEC = 37, // 2500
    SCRCMD_CRANE_TARGET_DEC = 38, // 2600
    SCRCMD_CRANE2TARGET_DEC = 39, // 2700
    SCRCMD_CRUSHER_BASIC = 40, // 2800
    SCRCMD_CREATE_CHAR_2D = 41, // 2900
    SCRCMD_CREATE_CHAR_3D = 42, // 2A00
    SCRCMD_CREATE_CAR_2D = 43, // 2B00
    SCRCMD_CREATE_CAR_3D = 44, // 2C00
    SCRCMD_CREATE_CAR_2D_STR = 45, // 2D00
    SCRCMD_CREATE_CAR_3D_STR = 46, // 2E00
    SCRCMD_CREATE_OBJ_2D = 47, // 2F00
    SCRCMD_CREATE_OBJ_3D = 48, // 3000
    SCRCMD_CREATE_OBJ_3D_s32 = 49, // 3100
    SCRCMD_CREATE_OBJ_2D_s32 = 50, // 3200
    SCRCMD_CREATE_OBJ_3D_STR = 51, // 3300
    SCRCMD_CREATE_OBJ_2D_STR = 52, // 3400
    SCRCMD_CREATE_CONVEYOR_2D = 53, // 3500
    SCRCMD_CREATE_CONVEYOR_3D = 54, // 3600
    SCRCMD_CREATE_GENERATOR_2D = 55, // 3700
    SCRCMD_CREATE_GENERATOR_3D = 56, // 3800
    SCRCMD_CREATE_DESTRUCTOR_2D = 57, // 3900
    SCRCMD_CREATE_DESTRUCTOR_3D = 58, // 3A00
    SCRCMD_LEVELSTART = 59, // 3B00
    SCRCMD_LEVELEND = 60, // 3C00
    SCRCMD_CREATE_THREAD = 61, // 3D00
    SCRCMD_STOP_THREAD = 62, // 3E00
    SCRCMD_START_EXEC = 63, // 3F00
    SCRCMD_STOP_EXEC = 64, // 4000
    SCRCMD_FOR_LOOP = 65, // 4100
    SCRCMD_DO_WHILE = 66, // 4200
    SCRCMD_FUNCTION = 67, // 4300
    SCRCMD_RETURN = 68, // 4400
    SCRCMD_WHILE = 69, // 4500
    SCRCMD_WHILE_EXEC = 70, // 4600
    SCRCMD_NOT = 71, // 4700
    SCRCMD_AND = 72, // 4800
    SCRCMD_OR = 73, // 4900
    SCRCMD_IF = 74, // 4A00
    SCRCMD_THEN = 75, // 4B00
    SCRCMD_ELSE = 76, // 4C00
    SCRCMD_GOTO = 77, // 4D00
    SCRCMD_GOSUB = 78, // 4E00
    SCRCMD_S_PLUS_I = 79, // 4F00
    SCRCMD_I_PLUS_S = 80, // 5000
    SCRCMD_S_PLUS_S = 81, // 5100
    SCRCMD_S_MINUS_I = 82, // 5200
    SCRCMD_I_MINUS_S = 83, // 5300
    SCRCMD_S_MINUS_S = 84, // 5400
    SCRCMD_SET = 85, // 5500
    SCRCMD_S_LESS_I = 86, // 5600
    SCRCMD_S_LESS_S = 87, // 5700
    SCRCMD_S_LEQUAL_I = 88, // 5800
    SCRCMD_S_LEQUAL_S = 89, // 5900
    SCRCMD_S_GREATER_I = 90, // 5A00
    SCRCMD_S_GREATER_S = 91, // 5B00
    SCRCMD_S_GEQUAL_I = 92, // 5C00
    SCRCMD_S_GEQUAL_S = 93, // 5D00
    SCRCMD_S_EQUAL_I = 94, // 5E00
    SCRCMD_S_EQUAL_S = 95, // 5F00
    SCRCMD_INCREMENT = 96, // 6000
    SCRCMD_DECREMENT = 97, // 6100
    SCRCMD_IF_JUMP = 98, // 6200
    SCRCMD_FORWARD_DECLARE = 99, // 6300
    SCRCMD_MAKE_CAR_DUMMY = 100, // 6400
    SCRCMD_MAP_ZONE1 = 101, // 6500
    SCRCMD_MAP_ZONE_SET = 102, // 6600
    SCRCMD_SET_CAR_DENSITY = 103, // 6700
    SCRCMD_SET_GOOD_CAR = 104, // 6800
    SCRCMD_SET_BAD_CAR = 105, // 6900
    SCRCMD_SET_POLICE_CAR = 106, // 6A00
    SCRCMD_SET_PED_DENSITY = 107, // 6B00
    SCRCMD_SET_MUGGER = 108, // 6C00
    SCRCMD_SET_CARTHIEF = 109, // 6D00
    SCRCMD_SET_ELVIS = 110, // 6E00
    SCRCMD_SET_GANG = 111, // 6F00
    SCRCMD_SET_POLICE_PED = 112, // 7000
    SCRCMD_POINT_ARROW_AT = 113, // 7100
    SCRCMD_POINT_ARROW_3D = 114, // 7200
    SCRCMD_ARROW_COLOUR = 115, // 7300
    SCRCMD_REMOVE_ARROW = 116, // 7400
    SCRCMD_DISPLAY_MESSAGE = 117, // 7500
    SCRCMD_DISPLAY_BRIEF = 118, // 7600
    SCRCMD_DISPLAY_TIMER = 119, // 7700
    SCRCMD_CLEAR_TIMERS = 120, // 7800
    SCRCMD_IS_CHAR_IN_CAR = 121, // 7900
    SCRCMD_IS_CHAR_IN_MODEL = 122, // 7A00
    SCRCMD_IS_CHAR_IN_ANY_CAR = 123, // 7B00
    SCRCMD_IS_CHAR_STOPPED = 124, // 7C00
    SCRCMD_IS_CHAR_STUNNED = 125, // 7D00
    SCRCMD_CHECK_HEALTH = 126, // 7E00
    SCRCMD_HAS_CHAR_DIED = 127, // 7F00
    SCRCMD_STORE_CAR_INFO = 128, // 8000
    SCRCMD_CHECK_CAR_DAMAGE = 129, // 8100
    SCRCMD_CHECK_CAR_DRIVER = 130, // 8200
    SCRCMD_SET_CHAR_OBJ1 = 131, // 8300
    SCRCMD_SET_CHAR_OBJ2 = 132, // 8400
    SCRCMD_SET_CHAR_OBJ3 = 133, // 8500
    SCRCMD_IS_CHAR_OBJ_PASS = 134, // 8600
    SCRCMD_IS_CHAR_OBJ_FAIL = 135, // 8700
    SCRCMD_SEND_CHAR_FOOT = 136, // 8800
    SCRCMD_SEND_CHAR_CAR = 137, // 8900
    SCRCMD_GIVE_WEAPON1 = 138, // 8A00
    SCRCMD_IS_CAR_IN_BLOCK = 139, // 8B00
    SCRCMD_DELETE_ITEM = 140, // 8C00
    SCRCMD_ADD_SCORE1 = 141, // 8D00
    SCRCMD_EXPLODE = 142, // 8E00
    SCRCMD_EXPLODE_BUILDING = 143, // 8F00
    SCRCMD_EXPLODE_ITEM = 144, // 9000
    SCRCMD_LOCATE_CHAR_ANY = 145, // 9100
    SCRCMD_LOCATE_CHAR_ONFOOT = 146, // 9200
    SCRCMD_LOCATE_CHAR_BY_CAR = 147, // 9300
    SCRCMD_STOP_LOCATE_CHAR_ANY = 148, // 9400
    SCRCMD_STOP_LOCATE_CHAR_FOOT = 149, // 9500
    SCRCMD_STOP_LOCATE_CHAR_CAR = 150, // 9600
    SCRCMD_SET_THREAT_SEARCH = 151, // 9700
    SCRCMD_SET_THREAT_REACT = 152, // 9800
    SCRCMD_ADD_GROUP = 153, // 9900
    SCRCMD_IS_CAR_WRECKED = 154, // 9A00
    SCRCMD_CHANGE_CAR_REMAP = 155, // 9B00
    SCRCMD_CHANGE_CHAR_REMAP = 156, // 9C00
    SCRCMD_CHECK_CAR_MODEL = 157, // 9D00
    SCRCMD_CHECK_CAR_REMAP = 158, // 9E00
    SCRCMD_CHECK_CAR_BOTH = 159, // 9F00
    SCRCMD_IS_ITEM_ONSCREEN = 160, // A000
    SCRCMD_DELAY_HERE = 161, // A100
    SCRCMD_DELAY = 162, // A200
    SCRCMD_CLEAR_WANTED_LEVEL = 163, // A300
    SCRCMD_ALT_WANTED_LEVEL = 164, // A400
    SCRCMD_IS_CHAR_FIRE_ONSCREEN = 165, // A500
    SCRCMD_DRIVER_OUT_CAR = 166, // A600
    SCRCMD_CHAR_TO_DRIVE_CAR = 167, // A700
    SCRCMD_ANSWER_PHONE = 168, // A800
    SCRCMD_SEND_CAR_TO_BLOCK = 169, // A900
    SCRCMD_GIVE_DRIVER_BRAKE = 170, // AA00
    SCRCMD_CHAR_TO_BACKDOOR = 171, // AB00
    SCRCMD_PLAY_SOUND = 172, // AC00
    SCRCMD_SET_NO_COLLIDE = 173, // AD00
    SCRCMD_CLEAR_NO_COLLIDE = 174, // AE00
    SCRCMD_CAR_DRIVE_AWAY = 175, // AF00
    SCRCMD_IS_CHAR_FIRING_AREA = 176, // B000
    SCRCMD_OPEN_DOOR = 177, // B100
    SCRCMD_CLOSE_DOOR = 178, // B200
    SCRCMD_SET_DOOR_AUTO = 179, // B300
    SCRCMD_SET_DOOR_MANUAL = 180, // B400
    SCRCMD_ROAD_ON_OFF = 181, // B500
    SCRCMD_ADD_NEW_BLOCK = 182, // B600
    SCRCMD_REMOVE_BLOCK = 183, // B700
    SCRCMD_LOWER_LEVEL = 184, // B800
    SCRCMD_CHANGE_BLOCK_SIDE = 185, // B900
    SCRCMD_CHANGE_BLOCK_LID = 186, // BA00
    SCRCMD_CHANGE_BLOCK_TYPE = 187, // BB00
    SCRCMD_GET_CAR_FROM_CRANE = 188, // BC00
    SCRCMD_CAR_WRECK_IN_LOCATION = 189, // BD00
    SCRCMD_CAR_SUNK = 190, // BE00
    SCRCMD_CAR_IN_AIR = 191, // BF00
    SCRCMD_CHECK_NUM_LIVES = 192, // C000
    SCRCMD_GET_NUM_LIVES = 193, // C100
    SCRCMD_CHECK_SCORE = 194, // C200
    SCRCMD_GET_SCORE = 195, // C300
    SCRCMD_CHECK_MULT = 196, // C400
    SCRCMD_GET_MULT = 197, // C500
    SCRCMD_CHECK_RESPECT_GREATER = 198, // C600
    SCRCMD_CHECK_RESPECT_LESS = 199, // C700
    SCRCMD_CAR_DAMAGE_POS = 200, // C800
    SCRCMD_GET_PASSENGER_NUM = 201, // C900
    SCRCMD_CHAR_IN_AIR = 202, // CA00
    SCRCMD_CHAR_SUNK = 203, // CB00
    SCRCMD_LAST_WEAPON_HIT = 204, // CC00
    SCRCMD_ADD_PATROL_POs32 = 205, // CD00
    SCRCMD_GET_CAR_SPEED = 206, // CE00
    SCRCMD_GET_CHAR_CAR_SPEED = 207, // CF00
    SCRCMD_CHECK_CAR_SPEED = 208, // D000
    SCRCMD_GET_MAX_SPEED = 209, // D100
    SCRCMD_THREAD_DECLARE1 = 210, // D200
    SCRCMD_THREAD_DECLARE2 = 211, // D300
    SCRCMD_THREAD_DECLARE3 = 212, // D400
    SCRCMD_THREAD_DECLARE4 = 213, // D500
    SCRCMD_THREAD_DECLARE5 = 214, // D600
    SCRCMD_ENABLE_THREAD = 215, // D700
    SCRCMD_DISABLE_THREAD = 216, // D800
    SCRCMD_LIGHT_DEC = 217, // D900
    SCRCMD_LIGHT_DECSET1 = 218, // DA00
    SCRCMD_CREATE_LIGHT1 = 219, // DB00
    SCRCMD_CHANGE_INTENSITY = 220, // DC00
    SCRCMD_CHANGE_COLOUR = 221, // DD00
    SCRCMD_CHANGE_RADIUS = 222, // DE00
    SCRCMD_SET_GANG_INFO1 = 223, // DF00
    SCRCMD_SET_CHAR_MOM_FAT = 448, // DF00
    SCRCMD_SET_GANG_RESPECT = 224, // E000
    SCRCMD_SET_CHAR_RESPECT = 225, // E100
    SCRCMD_SET_AMBIENT = 226, // E200
    SCRCMD_CHECK_PHONE = 227, // E300
    SCRCMD_CHECK_PHONETIMER = 228, // E400
    SCRCMD_STOP_PHONE_RING = 229, // E500
    SCRCMD_SET_DOOR_INFO = 230, // E600
    SCRCMD_CHECK_RESPECT_IS = 231, // E700
    SCRCMD_IS_CHAR_IN_GANG = 232, // E800
    SCRCMD_TIMER_DECLARE = 233, // E900
    SCRCMD_CHECK_NUM_ALIVE = 234, // EA00
    SCRCMD_ADD_CHAR_TO_GROUP = 235, // EB00
    SCRCMD_REMOVE_char_type = 236, // EC00
    SCRCMD_SET_MIN_ALIVE = 237, // ED00
    SCRCMD_SET_CHAR_SHOOT = 238, // EE00
    SCRCMD_SET_CHAR_BRAVERY = 239, // EF00
    SCRCMD_DECLARE_MISSION = 240, // F000
    SCRCMD_HAS_CAR_WEAPON = 241, // F100
    SCRCMD_IS_CHAR_IN_ZONE = 242, // F200
    SCRCMD_IS_CHAR_HORN = 243, // F300
    SCRCMD_CHECK_MAX_PASS = 244, // F400
    SCRCMD_SET_PHONE_DEAD = 245, // F500
    SCRCMD_IS_TRAILER_ATT = 246, // F600
    SCRCMD_IS_CAR_ON_TRAIL = 247, // F700
    SCRCMD_ENABLE_CRANE = 248, // F800
    SCRCMD_DISABLE_CRANE = 249, // F900
    SCRCMD_CAR_GOT_DRIVER = 250, // FA00
    SCRCMD_SPOTTED_PLAYER = 251, // FB00
    SCRCMD_GET_LAST_PUNCHED = 252, // FC00
    SCRCMD_KILL_ALL_PASSENG = 253, // FD00
    SCRCMD_IS_GROUP_IN_CAR = 254, // FE00
    SCRCMD_PUNCHED_SOMEONE = 255, // FF00
    SCRCMD_REMOVE_WEAPON = 256, // 0001
    SCRCMD_DO_NOWT = 257, // 0101
    SCRCMD_ADD_CHAR_TO_GANG = 258, // 0201
    SCRCMD_MAKE_LEADER = 259, // 0301
    SCRCMD_PARK = 260, // 0401
    SCRCMD_PARK_FINISHED = 261, // 0501
    SCRCMD_CHANGE_RESPECT = 262, // 0601
    SCRCMD_PHONE_TEMPLATE = 263, // 0701
    SCRCMD_BEEN_PUNCHED_BY = 264, // 0801
    SCRCMD_UPDATE_DOOR = 265, // 0901
    SCRCMD_GIVE_WEAPON2 = 266, // 0A01
    SCRCMD_IS_CAR_CRUSHED = 267, // 0B01
    SCRCMD_SWITCH_GENERATOR1 = 268, // 0C01
    SCRCMD_SWITCH_GENERATOR2 = 269, // 0D01
    SCRCMD_CAR_IN_AREA = 270, // 0E01
    SCRCMD_REMOTE_CONTROL = 271, // 0F01
    SCRCMD_MISSIONSTART = 272, // 1001
    SCRCMD_MISSIONEND = 273, // 1101
    SCRCMD_LAUNCH_MISSION = 274, // 1201
    SCRCMD_COUNTER_SAVE = 275, // 1301
    SCRCMD_COUNTER_SET_SAVE = 276, // 1401
    SCRCMD_SAVE_GAME = 277, // 1501
    SCRCMD_CHANGE_CAR_LOCK = 278, // 1601
    SCRCMD_DISPLAY_BRIEF_NOW = 279, // 1701
    SCRCMD_PARK_NO_RESPAWN = 280, // 1801
    SCRCMD_ADD_LIVES = 281, // 1901
    SCRCMD_ADD_MULTIPLIER = 282, // 1A01
    SCRCMD_SET_DIR_OF_TVVAN = 283, // 1B01
    SCRCMD_POINT_ONSCREEN = 284, // 1C01
    SCRCMD_SET_STATION = 285, // 1D01
    SCRCMD_SET_EMPTY_STATION = 286, // 1E01
    SCRCMD_RADIOSTATION_DEC = 287, // 1F01
    SCRCMD_START_BONUS1 = 288, // 2001
    SCRCMD_START_BONUS2 = 289, // 2101
    SCRCMD_START_BONUS3 = 290, // 2201
    SCRCMD_START_BONUS4 = 291, // 2301
    SCRCMD_CHECK_BONUS1 = 292, // 2401
    SCRCMD_CHECK_BONUS2 = 293, // 2501
    SCRCMD_CHECK_BONUS3 = 294, // 2601
    SCRCMD_SET_STATION_4 = 295, // 2701
    SCRCMD_SET_STATION_3 = 296, // 2801
    SCRCMD_SET_STATION_2 = 297, // 2901
    SCRCMD_SET_STATION_1 = 298, // 2A01
    SCRCMD_SETUP_MODEL_CHECK = 299, // 2B01
    SCRCMD_MODEL_CHECK = 300, // 2C01
    SCRCMD_LIGHT_DECSET2 = 301, // 2D01
    SCRCMD_CREATE_LIGHT2 = 302, // 2E01
    SCRCMD_SET_CAR_GRAPHIC = 303, // 2F01
    SCRCMD_DECLARE_POLICE = 304, // 3001
    SCRCMD_CARBOMB_ACTIVE = 305, // 3101
    SCRCMD_CHAR_DRIVE_AGGR = 306, // 3201
    SCRCMD_CHAR_DRIVE_SPEED = 307, // 3301
    SCRCMD_S_IS_S_MINUS_S = 308, // 3401
    SCRCMD_S_IS_S_PLUS_S = 309, // 3501
    SCRCMD_GIVE_CAR_ALARM = 310, // 3601
    SCRCMD_CAR_BULLETPROOF = 311, // 3701
    SCRCMD_CAR_ROCKETPROOF = 312, // 3801
    SCRCMD_CAR_FLAMEPROOF = 313, // 3901
    SCRCMD_IS_ALARM_RINGING = 314, // 3A01
    SCRCMD_SET_CHAR_OBJ_FOLLOW = 315, // 3B01
    SCRCMD_PUT_CAR_ON_TRAILER = 316, // 3C01
    SCRCMD_CLEAR_BRIEFS = 317, // 3D01
    SCRCMD_CHECK_HEADS = 318, // 3E01
    SCRCMD_FINISH_LEVEL = 319, // 3F01
    SCRCMD_CHECK_WEAPONHIT = 320, // 4001
    SCRCMD_DISPLAY_BRIEF_SOON = 321, // 4101
    SCRCMD_SET_GANG_INFO2 = 322, // 4201
    SCRCMD_MAP_ZONE2 = 323, // 4301
    SCRCMD_IS_CHAR_ON_FIRE = 324, // 4401
    SCRCMD_BRIEF_ONSCREEN = 325, // 4501
    SCRCMD_SOUND = 326, // 4601
    SCRCMD_SOUND_DECSET = 327, // 4701
    SCRCMD_CREATE_SOUND = 328, // 4801
    SCRCMD_DO_EASY_PHONE = 329, // 4901
    SCRCMD_CHAR_INTO_CAR = 330, // 4A01
    SCRCMD_DEL_GROUP_IN_CAR = 331, // 4B01
    SCRCMD_S_IS_S_MINUS_I = 332, // 4C01
    SCRCMD_S_IS_S_PLUS_I = 333, // 4D01
    SCRCMD_S_IS_S_DIV_I = 334, // 4E01
    SCRCMD_S_IS_S_MULT_I = 335, // 4F01
    SCRCMD_S_IS_S_MOD_I = 336, // 5001
    SCRCMD_S_IS_S_DIV_S = 337, // 5101
    SCRCMD_S_IS_S_MULT_S = 338, // 5201
    SCRCMD_S_IS_S_MOD_S = 339, // 5301
    SCRCMD_SET_COUNTER_s32 = 340, // 5401
    SCRCMD_SET_COUNTER_VAR = 341, // 5501
    SCRCMD_ADD_SCORE2 = 342, // 5601
    SCRCMD_FINISH_SCORE = 343, // 5701
    SCRCMD_TOTAL_MISSIONS = 344, // 5801
    SCRCMD_TOTAL_SECRETS = 345, // 5901
    SCRCMD_PASSED_FLAG = 346, // 5A01
    SCRCMD_1_PASSED_FLAG = 347, // 5B01
    SCRCMD_2_PASSED_FLAG = 348, // 5C01
    SCRCMD_3_PASSED_FLAG = 349, // 5D01
    SCRCMD_SUPPRESS_MODEL = 350, // 5E01
    SCRCMD_SWITCH_GENERATOR3 = 351, // 5F01
    SCRCMD_SWITCH_GENERATOR4 = 352, // 6001
    SCRCMD_DECLARE_CARLIST = 353, // 6101
    SCRCMD_DECIDE_POWERUP = 354, // 6201
    SCRCMD_CHAR_ARRESTED = 355, // 6301
    SCRCMD_ONSCREEN_ACCURACY = 356, // 6401
    SCRCMD_WARP_char_type = 357, // 6501
    SCRCMD_WEAP_HIT_CAR = 358, // 6601
    SCRCMD_SET_GROUP_TYPE = 359, // 6701
    SCRCMD_CHAR_DO_NOTHING = 360, // 6801
    SCRCMD_EMERG_LIGHTS = 361, // 6901
    SCRCMD_CHECK_OBJ_MODEL = 362, // 6A01
    SCRCMD_CHAR_INVINCIBLE = 363, // 6B01
    SCRCMD_PED_GRAPHIC = 364, // 6C01
    SCRCMD_MAKE_MUGGERS = 365, // 6D01
    SCRCMD_ANY_WEAPON_HIT_CAR = 366, // 6E01
    SCRCMD_LOC_SECOND_char_type = 367, // 6F01
    SCRCMD_STOP_CAR_DRIVE = 368, // 7001
    SCRCMD_IS_CHAR_MOM_FAT = 449, // 7101
    SCRCMD_IS_BUS_FULL = 369, // 7101
    SCRCMD_NO_CHARS_OFF_BUS = 370, // 7201
    SCRCMD_KILL_char_type = 371, // 7301
    SCRCMD_SET_GANGCARRATIO = 372, // 7401
    SCRCMD_SET_SHADING_LEV = 373, // 7501
    SCRCMD_SET_CAR_JAMMED = 374, // 7601
    SCRCMD_DOOR_DECLARE_S1 = 375, // 7701
    SCRCMD_DOOR_DECLARE_S2 = 376, // 7801
    SCRCMD_DOOR_DECLARE_S3 = 377, // 7901
    SCRCMD_DOOR_DECLARE_D1 = 378, // 7A01
    SCRCMD_DOOR_DECLARE_D2 = 379, // 7B01
    SCRCMD_DOOR_DECLARE_D3 = 380, // 7C01
    SCRCMD_LOC_SEC_CHAR_CAR = 381, // 7D01
    SCRCMD_LOC_SEC_CHAR_ANY = 382, // 7E01
    SCRCMD_SET_RUN_SPEED = 383, // 7F01
    SCRCMD_SET_STAY_IN_CAR = 384, // 8001
    SCRCMD_SET_USE_CAR_WEAPON = 385, // 8101
    SCRCMD_GANG_1_MISSION_TOTAL = 386, // 8201
    SCRCMD_GANG_2_MISSION_TOTAL = 387, // 8301
    SCRCMD_GANG_3_MISSION_TOTAL = 388, // 8401
    SCRCMD_SECRETS_PASSED = 389, // 8501
    SCRCMD_SECRETS_FAILED = 390, // 8601
    SCRCMD_FINISH_MISSION = 391, // 8701
    SCRCMD_ADDSCORE_NO_MULT = 392, // 8801
    SCRCMD_CHANGE_GANG_RESP = 393, // 8901
    SCRCMD_CREATE_GANG_CAR1 = 394, // 8A01
    SCRCMD_CREATE_GANG_CAR2 = 395, // 8B01
    SCRCMD_CREATE_GANG_CAR3 = 396, // 8C01
    SCRCMD_CREATE_GANG_CAR4 = 397, // 8D01
    SCRCMD_EXPLODE_LARGE1 = 398, // 8E01
    SCRCMD_EXPLODE_LARGE2 = 399, // 8F01
    SCRCMD_SET_ENTER_STATUS = 400, // 9001
    SCRCMD_BONUS_DECLARE = 401, // 9101
    SCRCMD_STORE_BONUS = 402, // 9201
    SCRCMD_EXPLODE_SMALL1 = 403, // 9301
    SCRCMD_EXPLODE_SMALL2 = 404, // 9401
    SCRCMD_EXPLODE_NO_RING1 = 405, // 9501
    SCRCMD_EXPLODE_NO_RING2 = 406, // 9601
    SCRCMD_SET_ALL_CONTROLS = 407, // 9701
    SCRCMD_SET_FAV_CAR = 408, // 9801
    SCRCMD_GROUP_IN_AREA = 409, // 9901
    SCRCMD_SET_CHAR_OCCUPATION = 410, // 9A01
    SCRCMD_SET_KF_WEAPON = 411, // 9B01
    SCRCMD_CLEAR_KF_WEAPON = 412, // 9C01
    SCRCMD_ONSCREEN_COUNTER_DEC = 413, // 9D01
    SCRCMD_ADD_ONSCREEN_COUNTER = 414, // 9E01
    SCRCMD_CLEAR_COUNTER = 415, // 9F01
    SCRCMD_CLEAR_CLOCK_ONLY = 416, // A001
    SCRCMD_EMERG_LIGHTS_ON = 417, // A101
    SCRCMD_CHANGE_POLICE = 418, // A201
    SCRCMD_DESTROY_GROUP = 419, // A301
    SCRCMD_CHECK_CURRENT_WEAPON = 420, // A401
    SCRCMD_ALTER_WANTED_LEVEL = 421, // A501
    SCRCMD_START_BASIC_KF = 422, // A601
    SCRCMD_DO_BASIC_KF = 423, // A701
    SCRCMD_SET_BONUS_RATING = 424, // A801
    SCRCMD_PARKED_CAR_DECSET_2D = 425, // A901
    SCRCMD_PARKED_CAR_DECSET_3D = 426, // AA01
    SCRCMD_PARKED_CAR_DECSET_2D_STR = 427, // AB01
    SCRCMD_PARKED_CAR_DECSET_3D_STR = 428, // AC01
    SCRCMD_DEC_GANG_1_FLAG = 429, // AD01
    SCRCMD_DEC_GANG_2_FLAG = 430, // AE01
    SCRCMD_DEC_GANG_3_FLAG = 431, // AF01
    SCRCMD_DEATH_ARR_STATE = 432, // B001
    SCRCMD_ADD_TIME = 433, // B101
    SCRCMD_CHAR_AREA_ANY_MEANS = 434, // B201
    SCRCMD_DEC_DEATH_BASE_1 = 435, // B301
    SCRCMD_DEC_DEATH_BASE_2 = 436, // B401
    SCRCMD_DEC_DEATH_BASE_3 = 437, // B501
    SCRCMD_DO_SAVE_GAME = 438, // B601
    SCRCMD_DO_CRANE_POWERUP = 439, // B701
    SCRCMD_LEVEL_END_ARROW1 = 440, // B801
    SCRCMD_LEVEL_END_ARROW2 = 441, // B901
    SCRCMD_SET_MODEL_WANTED = 442, // BA01
    SCRCMD_CHECK_DEATH_ARR = 443, // BB01
    SCRCMD_FORCE_CLEANUP = 444, // BC01
    SCRCMD_SAVE_RESPECT = 445, // BD01
    SCRCMD_RESTORE_RESPECT = 446, // BE01
};

class frosty_pasteur_0xC1EA8
{
  public:
    EXPORT str_table_entry* FindStringById_503080(s16 stringId);
    EXPORT str_table_entry* StrEntryByString_5030B0(char_type* strToFind);
    EXPORT char_type sub_511B10(s32 idx);
    EXPORT void sub_511B90();
    EXPORT void sub_511C30();
    EXPORT void sub_511D40();
    EXPORT void sub_511E10(char_type* FileName);
    EXPORT s32 sub_511F80(s32 FileName);
    EXPORT SCR_CMD_HEADER* sub_512100(s16 toFind, u16 startOff);
    EXPORT void Update_512160();
    EXPORT void LoadStringTbl_5121E0(u16 tableSize);
    EXPORT void GetScrFileName_5122D0();
    EXPORT void Load_512330(const char_type* pScrName);
    EXPORT void sub_512400(s32 String1, u16* a3);
    EXPORT void LoadSubScripts_5125F0();
    EXPORT SCR_CMD_HEADER* GetBasePointer_512770(u16 idx);
    EXPORT void sub_5127A0();
    EXPORT s32* sub_5128A0(s32 a2, s32 a3);
    EXPORT s32* sub_5128D0(s32 a2, s32 a3, s16 a4);
    EXPORT char_type sub_512910(s32 a2, s32 a3);
    EXPORT s32* sub_512980(s32 a2, s32 a3);
    EXPORT s32* sub_5129B0(s32 a2, s32 a3, s16 a4);
    EXPORT char_type sub_5129F0(s32 a2, s32 a3);
    EXPORT s32* sub_512A70(s32 a2, s32 a3);
    EXPORT char_type* sub_512AA0(s32 a2);
    EXPORT char_type* sub_512AD0(s32 a2);
    EXPORT char_type sub_512AF0(s32 a2, char_type a3, char_type a4);
    EXPORT char_type* sub_512BA0(s32 a2, char_type a3);
    EXPORT s32 sub_512C00(s32 a2, s32 a3, char_type a4);
    EXPORT bool sub_512C70(s32 a2, char_type a3, char_type a4);
    EXPORT frosty_pasteur_0xC1EA8();
    EXPORT ~frosty_pasteur_0xC1EA8();

    s16 field_0;
    s16 field_2;
    s32 field_4[96];
    s16 field_184;
    s16 field_186;
    s32 field_188[60];
    s16 field_278;
    s16 field_27A;
    BYTE field_27C[120];
    s32 field_2F4;
    s32 field_2F8;
    s32 field_2FC;
    s32 field_300;
    s32 field_304;
    s32 field_308;
    s32 field_30C;
    s32 field_310;
    s32 field_314;
    s32 field_318;
    s32 field_31C;
    s32 field_320;
    s32 field_324;
    s32 field_328;
    s32 field_32C;
    s32 field_330;
    s32 field_334;
    s32 field_338;
    s32 field_33C;
    s32 field_340;
    s32 field_344;
    s32 field_348;
    s32 field_34C;
    s32 field_350;
    char_type field_354;
    char_type field_355;
    s16 field_356;
    s16 field_358;
    s16 field_35A;
    char_type field_35C_full_scr_file_name[256];
    char_type field_45C_scr_file_name[9];
    char_type field_465;
    char_type field_466;
    char_type field_467;
    s32 field_468;
    u16 field_46C_base_pointers[6000];
    BYTE field_334C_script_data[65536];
    str_table_entry* field_1334C_strings;
    str_table_normalized* field_13350_pStringTbl;
    BYTE field_13354[620000];
    BYTE field_AA934[95232];
    s16 field_C1D34[30];
    s16 field_C1D70;
    s16 field_C1D72[30];
    s16 field_C1DAE;
    s32 field_C1DB0[31];
    char_type field_C1E2C;
    char_type field_C1E2D;
    char_type field_C1E2E;
    char_type field_C1E2F;
    char_type field_C1E30;
    char_type field_C1E31;
    u16 field_C1E32[32];
    s16 field_C1E72;
    u16 field_C1E74[25];
    s16 field_C1EA6;
};

EXPORT_VAR extern frosty_pasteur_0xC1EA8* gfrosty_pasteur_6F8060;
